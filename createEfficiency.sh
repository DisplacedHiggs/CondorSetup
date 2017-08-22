#!/bin/bash


MAINDIR=`pwd`
SCRIPTDIR=`pwd`
LOGDIR=$MAINDIR/logs
CMSDIR=$CMSSW_BASE/src

source /cvmfs/cms.cern.ch/cmsset_default.sh
cd $CMSSW_BASE
eval `scramv1 runtime -sh`

cd $CMSSW_BASE/..
tar  --exclude-caches-all -czf ${SCRIPTDIR}/${CMSSW_VERSION}.tar.gz ${CMSSW_VERSION}/
cd $MAINDIR

runScript=$SCRIPTDIR/runEfficiency.sh
if [ -e $runScript ]
then
    rm -rf $runScript
fi
touch $runScript
chmod a+x $runScript

echo "#!/bin/bash" >> $runScript
echo "export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch" >> $runScript
echo "export COIN_FULL_INDIRECT_RENDERING=1" >> $runScript
echo 'echo $VO_CMS_SW_DIR' >> $runScript
echo 'source $VO_CMS_SW_DIR/cmsset_default.sh' >> $runScript
echo "export SCRAM_ARCH=$SCRAM_ARCH" >> $runScript
echo "tar xzf ${CMSSW_VERSION}.tar.gz" >> $runScript
echo "cd ${CMSSW_VERSION}/src" >> $runScript
echo "scram b ProjectRename" >> $runScript
echo 'eval `scramv1 runtime -sh` ' >> $runScript
#echo "cd $SCRIPTDIR/Datacards/coNLSP" >> $runScript
echo "cd -" >> $runScript
echo 'root -q -b -l dijetAnalysis.C\(\"$1\",\"$2\",$3,$7,$4,1000000,\"./$6\"\)' >> $runScript
echo 'xrdcp -f $2 root://cmseos.fnal.gov/$5/$2' >> $runScript
echo 'rm $2' >> $runScript
echo "" >> $runScript

processlist=processes_backgroundMC_SmallGammaTest.list 

while read process
do
    sample=`echo $process | sed 's/--//g'`
    echo $sample
    isSignal=false
    isMC=false
    jsonFile="Cert_271036-282037_13TeV_PromptReco_Collisions16_JSON_NoL1T.txt"
    mode=0

    OUTDIR=/store/group/lpchbb/mwalker/AnalysisTrees/${sample}/
    eos root://cmseos.fnal.gov mkdir $OUTDIR

    dir1=`eos root://cmseos.fnal.gov ls -l /store/group/lpchbb/mwalker/2016/DisplacedDijet/${process}/ | awk '{print $9}'`
    dir2=`eos root://cmseos.fnal.gov ls -l /store/group/lpchbb/mwalker/2016/DisplacedDijet/${process}/${dir1}/ | awk '{print $9}'`
    tmplist2=tmp2.tmp
    echo $dir2| tr " " "\n" > $tmplist2
    while read subdir2
    do

	dir3=`eos root://cmseos.fnal.gov ls -l /store/group/lpchbb/mwalker/2016/DisplacedDijet/${process}/${dir1}/${subdir2}/ | awk '{print $9}'`
	tmplist3=tmp3.tmp
	echo $dir3 | tr " " "\n" > $tmplist3

	while read subdir
	do
	    indir=/store/group/lpchbb/mwalker/2016/DisplacedDijet/${process}/${dir1}/${subdir2}/${subdir}/
	    echo $indir
	    filelist=${process}_${subdir2}_${subdir}.list

	    if [ -e $filelist ]
	    then
		rm -rf $filelist
	    fi

	    eos root://cmseos.fnal.gov ls -l $indir | grep root | awk -v indir="root://cmseos.fnal.gov/$indir" '{print indir $9}' > $filelist
    
	    condorFile=$SCRIPTDIR/submitEfficiency_${sample}_${subdir2}_${subdir}.condor
        
	    if [ -e $condorFile ]
	    then
		rm -rf $condorFile
	    fi
	    touch $condorFile
    
	    echo "universe = vanilla" >> $condorFile
	    echo 'Requirements = OpSys == "LINUX" && (Arch != "DUMMY" )' >> $condorFile
	    echo "Executable = $runScript" >> $condorFile
	    echo "Should_Transfer_Files = YES" >> $condorFile
	    echo "request_disk = 10000000" >> $condorFile
	    echo "request_memory = 2100" >> $condorFile
	    echo "WhenToTransferOutput  = ON_EXIT_OR_EVICT" >> $condorFile
	    echo "Notification=never" >> $condorFile
	    echo "notify_user = mwalker@physics.rutgers.edu" >> $condorFile
	    echo 'x509userproxy = $ENV(X509_USER_PROXY)' >> $condorFile
	    echo "Transfer_Input_Files = runEfficiency.sh, ${CMSSW_VERSION}.tar.gz, dijetAnalysis.C, helperDisplacedDijets.C, helperDisplacedDijetTriggers.C,$jsonFile" >> $condorFile
	    echo "" >> $condorFile
	    echo "" >> $condorFile
	    i=0
	    
	    while read line
	    do
		base=`echo $line | awk '{split($1,array,"results_"); split(array[2],array2,".");print array2[1]}'`
		ifname=$line
		mode=0
		ofile=histo_${sample}_${subdir2}_${base}.root
		echo "output = $LOGDIR/\$(Cluster)_efficiency_${sample}_${subdir2}_${base}.out" >> $condorFile
		echo "error = $LOGDIR/\$(Cluster)_efficiency_${sample}_${subdir2}_${base}.err" >> $condorFile
		echo "log = $LOGDIR/\$(Cluster)_efficiency_${sample}_${subdir2}_${base}.log" >> $condorFile
		echo "arguments = $ifname $ofile $isSignal $isMC $OUTDIR $jsonFile $mode" >> $condorFile
		echo "queue" >> $condorFile
		echo "" >> $condorFile
	    done < $filelist
	done < $tmplist3
	rm $tmplist3
    done < $tmplist2
    rm $tmplist2
done < $processlist

