#!/bin/bash


MAINDIR=`pwd`
SCRIPTDIR=`pwd`
LOGDIR=$MAINDIR/logs
CMSDIR=$CMSSW_BASE/src

source /cvmfs/cms.cern.ch/cmsset_default.sh
cd $CMSSW_BASE
pwd
eval `scramv1 runtime -sh`

cd $CMSSW_BASE/..
tar  --exclude-caches-all -czf ${SCRIPTDIR}/${CMSSW_VERSION}.tar.gz ${CMSSW_VERSION}/
cd $MAINDIR
pwd
runScript=$SCRIPTDIR/runHaddR.sh
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
echo 'sample=$1' >> $runScript
echo 'OUTDIR=$2' >> $runScript
echo 'head=$3' >> $runScript
echo 'tail=$4' >> $runScript
echo 'base=$5' >> $runScript
echo 'INDIR=$6' >> $runScript
echo 'xrdfs root://cmseos.fnal.gov ls -u $OUTDIR | grep "\.root" | grep histo | head -${head} | tail -${tail}' >> $runScript
echo 'haddR -f -c "(hasGoodVertex && (hasSingleElTriggers || hasSingleMuTriggers) && (NGOODMUONS[0] + NGOODELECTRONS[0]) > 0)" allHistos_${sample}_${base}.root `xrdfs root://cmseos.fnal.gov ls -u $INDIR | grep "\.root" | grep histo | head -${head} | tail -${tail}`' >> $runScript
echo 'xrdcp -f allHistos_${sample}_${base}.root root://cmseos.fnal.gov/$OUTDIR/allHistos_${sample}_${base}.root' >> $runScript
echo 'rm -rf allHistos_${sample}_${base}.root' >> $runScript
echo "" >> $runScript

condorFile=$SCRIPTDIR/submitHaddR.condor
        
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
echo "WhenTOTransferOutput  = ON_EXIT_OR_EVICT" >> $condorFile
echo "Notification=never" >> $condorFile
echo "notify_user = mwalker@physics.rutgers.edu" >> $condorFile
echo 'x509userproxy = $ENV(X509_USER_PROXY)' >> $condorFile
echo "Transfer_Input_Files = runHaddR.sh, ${CMSSW_VERSION}.tar.gz" >> $condorFile
echo "" >> $condorFile
echo "" >> $condorFile

processlist=processes.list
filesPerJob=300

while read process
do
    #sample=$process
    #sample="gluinoGMSB_"`echo $filelist | awk '{split($1,array,"_"); split(array[2],array2,".");print array2[1]}'`
    sample=$process
    INDIR=/store/group/lpchbb/mwalker/AnalysisTrees/${sample}/
    nFiles=`eos root://cmseos.fnal.gov ls $INDIR | grep root | wc -l`
    echo $sample
    i=0
    nCounter=0
    OUTDIR=$INDIR/addedHistos/

    while [ $nCounter -lt $nFiles ]
    do
	nTail=$filesPerJob
	nHead=$((($i + 1) * $filesPerJob))
	nCounter=$nHead
	if [ $nHead -gt $nFiles ]
	then
	    nHead=$nFiles
	    nTail=$(($nFiles - ($filesPerJob * $i)))
	fi
	echo $i $nHead $nTail
	echo "output = $LOGDIR/\$(Cluster)_haddR_${sample}_${i}.out" >> $condorFile
	echo "error = $LOGDIR/\$(Cluster)_haddR_${sample}_${i}.err" >> $condorFile
	echo "log = $LOGDIR/\$(Cluster)_haddR_${sample}_${i}.log" >> $condorFile
	echo "arguments = $sample $OUTDIR $nHead $nTail $i $INDIR" >> $condorFile
	echo "queue" >> $condorFile
	echo "" >> $condorFile
	let i++
    done
done < $processlist

