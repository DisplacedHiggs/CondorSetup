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

  ObjectVariableValueInList<TString>* isSinglePhoton22Trigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_Photon22_R9Id90_HE10_IsoM_v1");
  isSinglePhoton22Trigger->addValue("HLT_Photon22_R9Id90_HE10_IsoM_v2");
  isSinglePhoton22Trigger->addValue("HLT_Photon22_R9Id90_HE10_IsoM_v3");
  isSinglePhoton22Trigger->addValue("HLT_Photon22_R9Id90_HE10_IsoM_v4");
  isSinglePhoton22Trigger->addValue("HLT_Photon22_R9Id90_HE10_IsoM_v5");
  isSinglePhoton22Trigger->addValue("HLT_Photon22_R9Id90_HE10_IsoM_v6");
  isSinglePhoton22Trigger->addValue("HLT_Photon22_R9Id90_HE10_IsoM_v7");
  isSinglePhoton22Trigger->addValue("HLT_Photon22_R9Id90_HE10_IsoM_v8");
  isSinglePhoton22Trigger->addValue("HLT_Photon22_R9Id90_HE10_IsoM_v9");
  isSinglePhoton22Trigger->addValue("HLT_Photon22_R9Id90_HE10_IsoM_v10");
  handler->addObjectVariable("isSinglePhoton22Trigger",isSinglePhoton22Trigger);

  ObjectVariableValueInList<TString>* isSinglePhoton30Trigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_Photon30_R9Id90_HE10_IsoM_v1");
  isSinglePhoton30Trigger->addValue("HLT_Photon30_R9Id90_HE10_IsoM_v2");
  isSinglePhoton30Trigger->addValue("HLT_Photon30_R9Id90_HE10_IsoM_v3");
  isSinglePhoton30Trigger->addValue("HLT_Photon30_R9Id90_HE10_IsoM_v4");
  isSinglePhoton30Trigger->addValue("HLT_Photon30_R9Id90_HE10_IsoM_v5");
  isSinglePhoton30Trigger->addValue("HLT_Photon30_R9Id90_HE10_IsoM_v6");
  isSinglePhoton30Trigger->addValue("HLT_Photon30_R9Id90_HE10_IsoM_v7");
  isSinglePhoton30Trigger->addValue("HLT_Photon30_R9Id90_HE10_IsoM_v8");
  isSinglePhoton30Trigger->addValue("HLT_Photon30_R9Id90_HE10_IsoM_v9");
  isSinglePhoton30Trigger->addValue("HLT_Photon30_R9Id90_HE10_IsoM_v10");
  isSinglePhoton30Trigger->addValue("HLT_Photon30_R9Id90_HE10_IsoM_v11");
  handler->addObjectVariable("isSinglePhoton30Trigger",isSinglePhoton30Trigger);

  ObjectVariableValueInList<TString>* isSinglePhoton36Trigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_Photon36_R9Id90_HE10_IsoM_v1");
  isSinglePhoton36Trigger->addValue("HLT_Photon36_R9Id90_HE10_IsoM_v2");
  isSinglePhoton36Trigger->addValue("HLT_Photon36_R9Id90_HE10_IsoM_v3");
  isSinglePhoton36Trigger->addValue("HLT_Photon36_R9Id90_HE10_IsoM_v4");
  isSinglePhoton36Trigger->addValue("HLT_Photon36_R9Id90_HE10_IsoM_v5");
  isSinglePhoton36Trigger->addValue("HLT_Photon36_R9Id90_HE10_IsoM_v6");
  isSinglePhoton36Trigger->addValue("HLT_Photon36_R9Id90_HE10_IsoM_v7");
  isSinglePhoton36Trigger->addValue("HLT_Photon36_R9Id90_HE10_IsoM_v8");
  isSinglePhoton36Trigger->addValue("HLT_Photon36_R9Id90_HE10_IsoM_v9");
  isSinglePhoton36Trigger->addValue("HLT_Photon36_R9Id90_HE10_IsoM_v10");
  isSinglePhoton36Trigger->addValue("HLT_Photon36_R9Id90_HE10_IsoM_v11");
  handler->addObjectVariable("isSinglePhoton36Trigger",isSinglePhoton36Trigger);

  ObjectVariableValueInList<TString>* isSinglePhoton50Trigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_Photon50_R9Id90_HE10_IsoM_v1");
  isSinglePhoton50Trigger->addValue("HLT_Photon50_R9Id90_HE10_IsoM_v2");
  isSinglePhoton50Trigger->addValue("HLT_Photon50_R9Id90_HE10_IsoM_v3");
  isSinglePhoton50Trigger->addValue("HLT_Photon50_R9Id90_HE10_IsoM_v4");
  isSinglePhoton50Trigger->addValue("HLT_Photon50_R9Id90_HE10_IsoM_v5");
  isSinglePhoton50Trigger->addValue("HLT_Photon50_R9Id90_HE10_IsoM_v6");
  isSinglePhoton50Trigger->addValue("HLT_Photon50_R9Id90_HE10_IsoM_v7");
  isSinglePhoton50Trigger->addValue("HLT_Photon50_R9Id90_HE10_IsoM_v8");
  isSinglePhoton50Trigger->addValue("HLT_Photon50_R9Id90_HE10_IsoM_v9");
  isSinglePhoton50Trigger->addValue("HLT_Photon50_R9Id90_HE10_IsoM_v10");
  isSinglePhoton50Trigger->addValue("HLT_Photon50_R9Id90_HE10_IsoM_v11");
  handler->addObjectVariable("isSinglePhoton50Trigger",isSinglePhoton50Trigger);

  ObjectVariableValueInList<TString>* isSinglePhoton75Trigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_Photon75_R9Id90_HE10_IsoM_v1");
  isSinglePhoton75Trigger->addValue("HLT_Photon75_R9Id90_HE10_IsoM_v2");
  isSinglePhoton75Trigger->addValue("HLT_Photon75_R9Id90_HE10_IsoM_v3");
  isSinglePhoton75Trigger->addValue("HLT_Photon75_R9Id90_HE10_IsoM_v4");
  isSinglePhoton75Trigger->addValue("HLT_Photon75_R9Id90_HE10_IsoM_v5");
  isSinglePhoton75Trigger->addValue("HLT_Photon75_R9Id90_HE10_IsoM_v6");
  isSinglePhoton75Trigger->addValue("HLT_Photon75_R9Id90_HE10_IsoM_v7");
  isSinglePhoton75Trigger->addValue("HLT_Photon75_R9Id90_HE10_IsoM_v8");
  isSinglePhoton75Trigger->addValue("HLT_Photon75_R9Id90_HE10_IsoM_v9");
  isSinglePhoton75Trigger->addValue("HLT_Photon75_R9Id90_HE10_IsoM_v10");
  isSinglePhoton75Trigger->addValue("HLT_Photon75_R9Id90_HE10_IsoM_v11");
  handler->addObjectVariable("isSinglePhoton75Trigger",isSinglePhoton75Trigger);

  ObjectVariableValueInList<TString>* isSinglePhoton90Trigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_Photon90_R9Id90_HE10_IsoM_v1");
  isSinglePhoton90Trigger->addValue("HLT_Photon90_R9Id90_HE10_IsoM_v2");
  isSinglePhoton90Trigger->addValue("HLT_Photon90_R9Id90_HE10_IsoM_v3");
  isSinglePhoton90Trigger->addValue("HLT_Photon90_R9Id90_HE10_IsoM_v4");
  isSinglePhoton90Trigger->addValue("HLT_Photon90_R9Id90_HE10_IsoM_v5");
  isSinglePhoton90Trigger->addValue("HLT_Photon90_R9Id90_HE10_IsoM_v6");
  isSinglePhoton90Trigger->addValue("HLT_Photon90_R9Id90_HE10_IsoM_v7");
  isSinglePhoton90Trigger->addValue("HLT_Photon90_R9Id90_HE10_IsoM_v8");
  isSinglePhoton90Trigger->addValue("HLT_Photon90_R9Id90_HE10_IsoM_v9");
  isSinglePhoton90Trigger->addValue("HLT_Photon90_R9Id90_HE10_IsoM_v10");
  isSinglePhoton90Trigger->addValue("HLT_Photon90_R9Id90_HE10_IsoM_v11");
  handler->addObjectVariable("isSinglePhoton90Trigger",isSinglePhoton90Trigger);

  ObjectVariableValueInList<TString>* isSinglePhoton120Trigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_Photon120_R9Id90_HE10_IsoM_v1");
  isSinglePhoton120Trigger->addValue("HLT_Photon120_R9Id90_HE10_IsoM_v2");
  isSinglePhoton120Trigger->addValue("HLT_Photon120_R9Id90_HE10_IsoM_v3");
  isSinglePhoton120Trigger->addValue("HLT_Photon120_R9Id90_HE10_IsoM_v4");
  isSinglePhoton120Trigger->addValue("HLT_Photon120_R9Id90_HE10_IsoM_v5");
  isSinglePhoton120Trigger->addValue("HLT_Photon120_R9Id90_HE10_IsoM_v6");
  isSinglePhoton120Trigger->addValue("HLT_Photon120_R9Id90_HE10_IsoM_v7");
  isSinglePhoton120Trigger->addValue("HLT_Photon120_R9Id90_HE10_IsoM_v8");
  isSinglePhoton120Trigger->addValue("HLT_Photon120_R9Id90_HE10_IsoM_v9");
  isSinglePhoton120Trigger->addValue("HLT_Photon120_R9Id90_HE10_IsoM_v10");
  isSinglePhoton120Trigger->addValue("HLT_Photon120_R9Id90_HE10_IsoM_v11");
  handler->addObjectVariable("isSinglePhoton120Trigger",isSinglePhoton120Trigger);

  ObjectVariableValueInList<TString>* isSinglePhoton165Trigger = new ObjectVariableValueInList<TString>("TRIGGERNAME","HLT_Photon165_R9Id90_HE10_IsoM_v1");
  isSinglePhoton165Trigger->addValue("HLT_Photon165_R9Id90_HE10_IsoM_v2");
  isSinglePhoton165Trigger->addValue("HLT_Photon165_R9Id90_HE10_IsoM_v3");
  isSinglePhoton165Trigger->addValue("HLT_Photon165_R9Id90_HE10_IsoM_v4");
  isSinglePhoton165Trigger->addValue("HLT_Photon165_R9Id90_HE10_IsoM_v5");
  isSinglePhoton165Trigger->addValue("HLT_Photon165_R9Id90_HE10_IsoM_v6");
  isSinglePhoton165Trigger->addValue("HLT_Photon165_R9Id90_HE10_IsoM_v7");
  isSinglePhoton165Trigger->addValue("HLT_Photon165_R9Id90_HE10_IsoM_v8");
  isSinglePhoton165Trigger->addValue("HLT_Photon165_R9Id90_HE10_IsoM_v9");
  isSinglePhoton165Trigger->addValue("HLT_Photon165_R9Id90_HE10_IsoM_v10");
  isSinglePhoton165Trigger->addValue("HLT_Photon165_R9Id90_HE10_IsoM_v11");
  isSinglePhoton165Trigger->addValue("HLT_Photon165_R9Id90_HE10_IsoM_v12");
  handler->addObjectVariable("isSinglePhoton165Trigger",isSinglePhoton165Trigger);

  //handler->addObjectVariable("Accepted", new ObjectVariableValue<bool>("ACCEPT", true));
  //handler->addObjectVariable("WasRun", new ObjectVariableValue<bool>("wasrun", true));

  handler->addProduct("goodtriggers", "TRIGGERS");
  handler->addProductCut("goodtriggers", "ACCEPT");
  handler->addProductCut("goodtriggers", "WASRUN");

  handler->addProduct("singlePhoton165Trigger","goodtriggers");
  handler->addProductCut("singlePhoton165Trigger","isSinglePhoton165Trigger");
  handler->addEventVariable("NSinglePhoton165Triggers", new EventVariableN("NSinglePhoton165Triggers","singlePhoton165Triggers"));
  handler->addEventVariable("hasSinglePhoton165Triggers",new EventVariableInRange<int>("NSinglePhoton165Triggers",1,10000));

  handler->addProduct("singlePhoton120Trigger","goodtriggers");
  handler->addProductCut("singlePhoton120Trigger","isSinglePhoton120Trigger");
  handler->addEventVariable("NSinglePhoton120Triggers", new EventVariableN("NSinglePhoton120Triggers","singlePhoton120Triggers"));
  handler->addEventVariable("hasSinglePhoton120Triggers",new EventVariableInRange<int>("NSinglePhoton120Triggers",1,10000));

  handler->addProduct("singlePhoton90Trigger","goodtriggers");
  handler->addProductCut("singlePhoton90Trigger","isSinglePhoton90Trigger");
  handler->addEventVariable("NSinglePhoton90Triggers", new EventVariableN("NSinglePhoton90Triggers","singlePhoton90Triggers"));
  handler->addEventVariable("hasSinglePhoton90Triggers",new EventVariableInRange<int>("NSinglePhoton90Triggers",1,10000));

  handler->addProduct("singlePhoton75Trigger","goodtriggers");
  handler->addProductCut("singlePhoton75Trigger","isSinglePhoton75Trigger");
  handler->addEventVariable("NSinglePhoton75Triggers", new EventVariableN("NSinglePhoton75Triggers","singlePhoton75Triggers"));
  handler->addEventVariable("hasSinglePhoton75Triggers",new EventVariableInRange<int>("NSinglePhoton75Triggers",1,10000));

  handler->addProduct("singlePhoton50Trigger","goodtriggers");
  handler->addProductCut("singlePhoton50Trigger","isSinglePhoton50Trigger");
  handler->addEventVariable("NSinglePhoton50Triggers", new EventVariableN("NSinglePhoton50Triggers","singlePhoton50Triggers"));
  handler->addEventVariable("hasSinglePhoton50Triggers",new EventVariableInRange<int>("NSinglePhoton50Triggers",1,10000));

  handler->addProduct("singlePhoton36Trigger","goodtriggers");
  handler->addProductCut("singlePhoton36Trigger","isSinglePhoton36Trigger");
  handler->addEventVariable("NSinglePhoton36Triggers", new EventVariableN("NSinglePhoton36Triggers","singlePhoton36Triggers"));
  handler->addEventVariable("hasSinglePhoton36Triggers",new EventVariableInRange<int>("NSinglePhoton36Triggers",1,10000));

  handler->addProduct("singlePhoton30Trigger","goodtriggers");
  handler->addProductCut("singlePhoton30Trigger","isSinglePhoton30Trigger");
  handler->addEventVariable("NSinglePhoton30Triggers", new EventVariableN("NSinglePhoton30Triggers","singlePhoton30Triggers"));
  handler->addEventVariable("hasSinglePhoton30Triggers",new EventVariableInRange<int>("NSinglePhoton30Triggers",1,10000));

  handler->addProduct("singlePhoton22Trigger","goodtriggers");
  handler->addProductCut("singlePhoton22Trigger","isSinglePhoton22Trigger");
  handler->addEventVariable("NSinglePhoton22Triggers", new EventVariableN("NSinglePhoton22Triggers","singlePhoton22Triggers"));
  handler->addEventVariable("hasSinglePhoton22Triggers",new EventVariableInRange<int>("NSinglePhoton22Triggers",1,10000));

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
