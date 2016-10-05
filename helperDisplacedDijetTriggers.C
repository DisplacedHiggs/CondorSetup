void setupTriggers(AdvancedHandler* handler)
{
  EventVariableThreshold* singleMuThresh = new EventVariableThreshold("smutrig","goodMuons");
  singleMuThresh->addThreshold(20);
  //handler->addEventVariable("SINGMUTRIGTHRESHOLD",singleMuThresh);

  handler->addEventVariable("HLTHT450", new EventVariableInRange<double>("HLTHT",450,1e6));
  handler->addEventVariable("MET200", new EventVariableInRange<double>("MET",200,1e6));

  ObjectVariableValueInList<TString>* isHTMETTrigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_PFHT350_PFMET100_v1");
  isHTMETTrigger->addValue("HLT_PFHT350_PFMET100_JetIdCleaned_v1");
  isHTMETTrigger->addValue("HLT_PFHT350_PFMET100_JetIdCleaned_v2");
  handler->addObjectVariable("isHTMETTrigger",isHTMETTrigger);

  ObjectVariableValueInList<TString>* isSingleMuTrigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_IsoMu22_v1");
  isSingleMuTrigger->addValue("HLT_IsoMu22_v2");
  isSingleMuTrigger->addValue("HLT_IsoMu22_v3");
  isSingleMuTrigger->addValue("HLT_IsoMu22_v4");
  isSingleMuTrigger->addValue("HLT_IsoMu22_v5");
  isSingleMuTrigger->addValue("HLT_IsoMu22_v6");
  isSingleMuTrigger->addValue("HLT_IsoMu22_v7");
  isSingleMuTrigger->addValue("HLT_IsoTkMu22_v1");
  isSingleMuTrigger->addValue("HLT_IsoTkMu22_v2");
  isSingleMuTrigger->addValue("HLT_IsoTkMu22_v3");
  isSingleMuTrigger->addValue("HLT_IsoTkMu22_v4");
  isSingleMuTrigger->addValue("HLT_IsoTkMu22_v5");
  isSingleMuTrigger->addValue("HLT_IsoTkMu22_v6");
  isSingleMuTrigger->addValue("HLT_IsoTkMu22_v7");
  isSingleMuTrigger->addValue("HLT_IsoTkMu22_v8");
  isSingleMuTrigger->addValue("HLT_IsoTkMu22_v9");
  isSingleMuTrigger->addValue("HLT_IsoTkMu22_v10");
  handler->addObjectVariable("isSingleMuTrigger",isSingleMuTrigger);

  ObjectVariableValueInList<TString>* isSingleElTrigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_Ele23_WPLoose_Gsf_v1");
  isSingleElTrigger->addValue("HLT_Ele23_WPLoose_Gsf_v2");
  isSingleElTrigger->addValue("HLT_Ele23_WPLoose_Gsf_v3");
  isSingleElTrigger->addValue("HLT_Ele23_WPLoose_Gsf_v4");
  isSingleElTrigger->addValue("HLT_Ele23_WPLoose_Gsf_v5");
  isSingleElTrigger->addValue("HLT_Ele23_WPLoose_Gsf_v6");
  isSingleElTrigger->addValue("HLT_Ele23_WPLoose_Gsf_v7");
  isSingleElTrigger->addValue("HLT_Ele23_WPLoose_Gsf_v8");
  isSingleElTrigger->addValue("HLT_Ele23_WPLoose_Gsf_v9");
  isSingleElTrigger->addValue("HLT_Ele23_WPLoose_Gsf_v10");
  isSingleElTrigger->addValue("HLT_Ele23_WPLoose_Gsf_v11");
  isSingleElTrigger->addValue("HLT_Ele23_WPLoose_Gsf_v12");
  isSingleElTrigger->addValue("HLT_Ele27_WPTight_Gsf_v1");
  isSingleElTrigger->addValue("HLT_Ele27_WPTight_Gsf_v2");
  isSingleElTrigger->addValue("HLT_Ele27_WPTight_Gsf_v3");
  isSingleElTrigger->addValue("HLT_Ele27_WPTight_Gsf_v4");
  isSingleElTrigger->addValue("HLT_Ele27_WPTight_Gsf_v5");
  isSingleElTrigger->addValue("HLT_Ele27_WPTight_Gsf_v6");
  isSingleElTrigger->addValue("HLT_Ele27_WPTight_Gsf_v7");
  isSingleElTrigger->addValue("HLT_Ele27_WPTight_Gsf_v8");
  isSingleElTrigger->addValue("HLT_Ele27_WPTight_Gsf_v9");
  handler->addObjectVariable("isSingleElTrigger",isSingleElTrigger);

  ObjectVariableValueInList<TString>* isDoubleMuTrigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v2");
  isDoubleMuTrigger->addValue("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v2");
  isDoubleMuTrigger->addValue("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1");
  isDoubleMuTrigger->addValue("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1");
  isDoubleMuTrigger->addValue("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v3");
  isDoubleMuTrigger->addValue("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v3");
  isDoubleMuTrigger->addValue("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v4");
  isDoubleMuTrigger->addValue("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v4");
  isDoubleMuTrigger->addValue("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v5");
  isDoubleMuTrigger->addValue("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v5");
  isDoubleMuTrigger->addValue("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v6");
  isDoubleMuTrigger->addValue("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v6");
  handler->addObjectVariable("isDoubleMuTrigger",isDoubleMuTrigger);

  ObjectVariableValueInList<TString>* isDoubleElTrigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3");
  isDoubleElTrigger->addValue("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v2");
  isDoubleElTrigger->addValue("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1");
  isDoubleElTrigger->addValue("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4");
  isDoubleElTrigger->addValue("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v5");
  isDoubleElTrigger->addValue("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v6");
  isDoubleElTrigger->addValue("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v7");
  isDoubleElTrigger->addValue("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8");
  isDoubleElTrigger->addValue("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v9");
  isDoubleElTrigger->addValue("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v10");
  isDoubleElTrigger->addValue("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1");
  isDoubleElTrigger->addValue("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v2");
  isDoubleElTrigger->addValue("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3");
  isDoubleElTrigger->addValue("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4");
  isDoubleElTrigger->addValue("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v5");
  isDoubleElTrigger->addValue("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v6");
  isDoubleElTrigger->addValue("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v7");
  isDoubleElTrigger->addValue("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8");
  isDoubleElTrigger->addValue("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v9");
  isDoubleElTrigger->addValue("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v10");
  handler->addObjectVariable("isDoubleElTrigger",isDoubleElTrigger);

  //handler->addObjectVariable("Accepted", new ObjectVariableValue<bool>("ACCEPT", true));
  //handler->addObjectVariable("WasRun", new ObjectVariableValue<bool>("wasrun", true));

  handler->addProduct("goodtriggers", "TRIGGERS");
  handler->addProductCut("goodtriggers", "ACCEPT");
  handler->addProductCut("goodtriggers", "WASRUN");

  handler->addProduct("singleMuTriggers","goodtriggers");
  handler->addProductCut("singleMuTriggers","isSingleMuTrigger");
  handler->addEventVariable("NSingleMuTriggers", new EventVariableN("NSingleMuTriggers","singleMuTriggers"));
  handler->addEventVariable("hasSingleMuTriggers",new EventVariableInRange<int>("NSingleMuTriggers",1,10000));

  handler->addProduct("singleElTriggers","goodtriggers");
  handler->addProductCut("singleElTriggers","isSingleElTrigger");
  handler->addEventVariable("NSingleElTriggers", new EventVariableN("NSingleElTriggers","singleElTriggers"));
  handler->addEventVariable("hasSingleElTriggers",new EventVariableInRange<int>("NSingleElTriggers",1,10000));

  handler->addProduct("doubleElTriggers","goodtriggers");
  handler->addProductCut("doubleElTriggers","isDoubleElTrigger");
  handler->addEventVariable("NDoubleElTriggers", new EventVariableN("NDoubleElTriggers","doubleElTriggers"));
  handler->addEventVariable("hasDoubleElTriggers", new EventVariableInRange<int>("NDoubleElTriggers",1,100000));

  handler->addProduct("doubleMuTriggers","goodtriggers");
  handler->addProductCut("doubleMuTriggers","isDoubleMuTrigger");
  handler->addEventVariable("NDoubleMuTriggers", new EventVariableN("NDoubleMuTriggers","doubleMuTriggers"));
  handler->addEventVariable("hasDoubleMuTriggers", new EventVariableInRange<int>("NDoubleMuTriggers",1,100000));

  handler->addProduct("htmetTriggers","goodtriggers");
  handler->addProductCut("htmetTriggers","isHTMETTrigger");
  handler->addEventVariable("NHTMETTriggers",new EventVariableN("NHTMETTriggers","htmetTriggers"));
  handler->addEventVariable("hasHTMETTriggers",new EventVariableInRange<int>("NHTMETTriggers",1,10000));
  
}
