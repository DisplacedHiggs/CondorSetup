# CondorSetup
Scripts for running and submitting jobs to condor (AnalysisTree workflow)

#createEfficiency.sh
This file creates condor job files for creating the analysis trees. It looks for a file called processes.list that directs it to the directories that contain the ntuples. It generates one condor file for each process and one task per ntuple file. You can run the script by executing `./createEfficiency.sh`. You need to still submit the files to condor using condor_submit.

#createHaddR.sh
This file creates condor job files for adding up analysis trees using the same processes.list (the script also assumes a base directory). This adds the analysistree files in batches of 300 files (you can edit this).

#dijetAnalysis.C
The macro that actually gets run over ntuples to create analysistrees.

#helperDisplacedDijets.C
A configuration setup for our analysis

#helperDisplacedDijetTriggers.C
Configuration setup containing trigger specific settings

#dumpMacro.C
This macro prints a lot of debugging information. As it's set it up, it's highly recommended to run over a single event (there are some examples inside about how to run over specific events by event number or event index in the file).

#How to Run
Follow instructions in https://github.com/DisplacedHiggs/CrabSetup to setup CMSSW area and environment, including cmsenv and voms-proxy-init. Then,

```
cd $CMSSW_BASE/../
git clone git@github.com:DisplacedHiggs/CondorSetup.git
cd CondorSetup
mkdir logs
```

Edit isSignal, isMC, jsonFile, OUTDIR, dir1, dir2, dir3, indir and notify_user as needed.  Create processes.list file listing all sample names (e.g. ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10_TuneCUETP8M1_13TeV-powheg-pythia8), one per line.  Then,

```
./createEfficiency.sh 
```

Then submit each condor task.  This is how you submit one:
```
condor_submit submitEfficiency_ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10_TuneCUETP8M1_13TeV-powheg-pythia8_161018_172618_0000.condor 
```
