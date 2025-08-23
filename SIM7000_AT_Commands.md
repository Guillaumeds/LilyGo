# SIM7000 Series AT Command Manual V1.06

**Total Pages:** 281

## Page 1

SIM7000Series_
ATCommandManual
SIMComWirelessSolutionsLimited
BuildingB,SIMTechnologyBuilding,No.633,JinzhongRoad
ChangningDistrict,ShanghaiP.R.China
Tel:86-21-31575100
support@simcom.com
www.simcom.comLPWAModule

---

## Page 2

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 2/281
DocumentTitle: SIM7000Series_ATCommandManual
Version: 1.06
Date: 2020.7.28
Status: Released
GENERALNOTES
SIMCOMOFFERSTHISINFORMATIONASASERVICETOITSCUSTOMERS,TOSUPPORT
APPLICATIONANDENGINEERINGEFFORTSTHATUSETHEPRODUCTSDESIGNEDBYSIMCOM.
THEINFORMATIONPROVIDEDISBASEDUPONREQUIREMENTSSPECIFICALLYPROVIDEDTO
SIMCOMBYTHECUSTOMERS.SIMCOMHASNOTUNDERTAKENANYINDEPENDENTSEARCH
FORADDITIONALRELEVANTINFORMATION,INCLUDINGANYINFORMATIONTHATMAYBEINTHE
CUSTOMER’SPOSSESSION.FURTHERMORE,SYSTEMVALIDATIONOFTHISPRODUCT
DESIGNEDBYSIMCOMWITHINALARGERELECTRONICSYSTEMREMAINSTHERESPONSIBILITY
OFTHECUSTOMERORTHECUSTOMER’SSYSTEMINTEGRATOR.ALLSPECIFICATIONS
SUPPLIEDHEREINARESUBJECTTOCHANGE.
COPYRIGHT
THISDOCUMENTCONTAINSPROPRIETARYTECHNICALINFORMATIONWHICHISTHEPROPERTY
OFSIMCOMWIRELESSSOLUTIONSLIMITEDCOPYING,TOOTHERSANDUSINGTHISDOCUMENT,
AREFORBIDDENWITHOUTEXPRESSAUTHORITYBYSIMCOM.OFFENDERSARELIABLETOTHE
PAYMENTOFINDEMNIFICATIONS.ALLRIGHTSRESERVEDBYSIMCOMINTHEPROPRIETARY
TECHNICALINFORMATION，INCLUDINGBUTNOTLIMITEDTOREGISTRATIONGRANTINGOFA
PATENT,AUTILITYMODELORDESIGN.ALLSPECIFICATIONSUPPLIEDHEREINARESUBJECTTO
CHANGEWITHOUTNOTICEATANYTIME.
SIMComWirelessSolutionsLimited
BuildingB,SIMTechnologyBuilding,No.633JinzhongRoad,ChangningDistrict,ShanghaiP.R.China
Tel:+862131575100
Email:simcom@simcom.com
Formoreinformation,pleasevisit:
https://www.simcom.com/download/list-863-en.html
Fortechnicalsupport,ortoreportdocumentationerrors,pleasevisit:
https://www.simcom.com/ask/oremailto:support@simcom.com
Copyright©2020SIMComWirelessSolutionsLimitedAllRightsReserved.

---

## Page 3

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 3/281
VersionHistory
VersionDateChapter Whatisnew
V1.002017.06.22 Newversion
V1.012017.09.085.2.22AT+CPSI AddATcommand
5.2.23AT+CGNAPN AddATcommand
5.2.24AT+CSDP AddATcommand
5.2.25AT+MCELLLOCKAddATcommand
5.2.26AT+NCELLLOCKAddATcommand
5.2.27AT+NBSC AddATcommand
Chapter7 AddIP
Chapter9 AddHTTP
Chapter10 AddPINGs
Chapter13 AddGNSS
V1.022017.12.18DeleteATZ,AT&F,AT&V
AllModifyparametersavemodeandmax
responsetime
1.7.1 AddAUTO_SAVE_REBOOT
1.7.2 AddMaxresponsetime
2.2.2ATD Deleteparameters<;>
3.2.14AT+CREG Changedescriptionofparameters
5.2.28AT+CAPNMODEAddATcommand
5.2.29AT+CRRCSTATEAddATcommand
5.2.30AT+CBANDCFG AddATcommand
8.2.2AT+CIPSTARTChangerangeofparameter<n>from0…5
to0…7
8.2.32AT+CIPTKA AddATcommand
8.2.33AT+CIPOPTION AddATcommand
Chapter11 AddFTP
Chapter12 AddNTP
13.3.10AT+CGNSTST AddATCommand
V1.032018.05.083.2.17AT+CPOL Modifyparameters
3.2.24AT+CNUM AddATCommand
5.2.1AT+CEDRXS Modifyrangeof<AcT-type>
5.2.31AT+CNACT AddATCommand
5.2.32AT+CEDUMP AddATCommand
5.2.33AT+CNBS AddATCommand
5.2.34AT+CNDS AddATCommand
5.2.35AT+CENG AddATCommand

---

## Page 4

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 4/281
9.2.9AT+HTTPTOFS AddATCommand
Chapter13 AddOneNet
Chapter14 AddTelecomIOT
Chapter15 AddGNSS
Chapter16 AddFilesystem
Chapter17 AddSAT
Chapter18 AddSSL
V1.042108.12.25DeleteAT+CASSL
5.2.36AT+CNACTCFG AddATCommand
5.2.37AT+CTLIIC AddATCommand
5.2.38AT+CWIIC AddATCommand
5.2.39AT+CRIIC AddATCommand
5.2.40AT+CMCFG AddATCommand
5.2.41AT+CSIMLOCK AddATCommand
5.2.42AT+CRATSRCH AddATCommand
5.2.43AT+SPWM AddATCommand
5.2.44AT+CASRIP AddATCommand
5.2.45AT+CEDRX AddATCommand
6.2.7AT+CEREG AddATCommand
9.2.10AT+HTTPTOFSRLAddATCommand
13.2.16
AT+MIPLBOOTSTRAPAddATCommand
13.2.17+MIPLREAD AddATCommand
13.2.18+MIPLWRITE AddATCommand
13.2.19+MIPLEXECUTEAddATCommand
13.2.20+MIPLOBSERVEAddATCommand
13.2.21+MIPLDISCOVERAddATCommand
13.2.22
+MIPLPARAMETERAddATCommand
13.2.23+MIPLEVENT AddATCommand
15.2.13AT+CGNSRTMSAddATCommand
18.2.2AT+CASSLCFG ExtendATcommand
18.2.8AT+CACFG AddATCommand
18.2.9AT+CASWITCHAddATCommand
Chapter19 AddPING
Chapter20 AddSupportedUnsolicitedResultCodes
V1.052020.01.20AT+CNBP DeleteATCommand
5.2.45AT+CPSMRDP AddATCommand
5.2.46AT+CPSMCFG AddATCommand
5.2.47AT+CPSMCFGEXTAddATCommand
5.2.48AT+CPSMSTATUSAddATCommand

---

## Page 5

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 5/281
5.2.49AT+CEDRXRDPAddATCommand
5.2.50AT+CRAI AddATCommand
15.2.14AT+CGNSHORAddATCommand
15.2.15AT+CGNSUTIPRAddATCommand
15.2.16AT+CGNSNMEAAddATCommand
15.2.17AT+CGTP AddATCommand
15.2.18AT+CGNSSUPLCFGAddATCommand
15.2.19AT+CGNSSUPLAddATCommand
V1.062020.07.28All

---

## Page 6

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 6/281
Contents
VersionHistory.....................................................................................................................................3
Contents.................................................................................................................................................6
1Introduction..................................................................................................................................15
1.1Scopeofthedocument........................................................................................................................15
1.2Relateddocuments...............................................................................................................................15
1.3Conventionsandabbreviations..........................................................................................................15
1.4ATCommandsyntax............................................................................................................................15
1.4.1Basicsyntax...................................................................................................................................16
1.4.2SParametersyntax......................................................................................................................16
1.4.3ExtendedSyntax...........................................................................................................................16
1.4.4CombiningATcommandsonthesameCommandline........................................................17
1.4.5EnteringsuccessiveATcommandsonseparatelines...........................................................17
1.5Supportedcharactersets....................................................................................................................17
1.6Flowcontrol............................................................................................................................................18
1.6.1Softwareflowcontrol(XON/XOFFflowcontrol)......................................................................18
1.6.2Hardwareflowcontrol(RTS/CTSflowcontrol)........................................................................18
1.7Definitions...............................................................................................................................................19
1.7.1ParameterSavingMode..............................................................................................................19
1.7.2MaxResponseTime.....................................................................................................................19
2ATCommandsAccordingtoV.25TER...................................................................................20
2.1OverviewofATCommandsAccordingtoV.25TER........................................................................20
2.2DetailedDescriptionofATCommandsAccordingtoV.25TER.....................................................21
2.2.1A/Re-issuestheLastCommandGiven.................................................................................21
2.2.2ATDMobileOriginatedCalltoDialANumber......................................................................21
2.2.3ATESetCommandEchoMode..............................................................................................22
2.2.4ATHDisconnectExistingConnection.....................................................................................23
2.2.5ATIDisplayProductIdentificationInformation......................................................................23
2.2.6ATLSetMonitorspeakerloudness.........................................................................................24
2.2.7ATMSetMonitorSpeakerMode.............................................................................................24
2.2.8+++SwitchfromDataModeorPPPOnlineModetoCommandMode...........................24
2.2.9ATOSwitchfromCommandModetoDataMode................................................................25
2.2.10ATQSetResultCodePresentationMode.............................................................................25
2.2.11ATS0SetNumberofRingsbeforeAutomaticallyAnsweringtheCall..............................26
2.2.12ATS3SetCommandLineTerminationCharacter................................................................26
2.2.13ATS4SetResponseFormattingCharacter...........................................................................27
2.2.14ATS5SetCommandLineEditingCharacter.........................................................................28
2.2.15ATS6PauseBeforeBlindDialing...........................................................................................28
2.2.16ATS7SetNumberofSecondstoWaitforConnectionCompletion..................................29

---

## Page 7

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 7/281
2.2.17ATS8SetNumberofSecondstoWaitforCommaDialModifierEncounteredinDial
StringofDCommand...................................................................................................................................29
2.2.18ATS10SetDisconnectDelayafterIndicatingtheAbsenceofDataCarrier....................30
2.2.19ATVTAResponseFormat........................................................................................................30
2.2.20ATXSetCONNECTResultCodeFormatandMonitorCallProgress..............................31
2.2.21AT&CSetDCDFunctionMode...............................................................................................32
2.2.22AT&DSetDTRFunctionMode................................................................................................32
2.2.23AT&ESetCONNECTResultCodeFormatAboutSpeed..................................................33
2.2.24AT+GCAPRequestCompleteTACapabilitiesList..............................................................33
2.2.25AT+GMIRequestManufacturerIdentification.......................................................................34
2.2.26AT+GMMRequestTAModelIdentification............................................................................34
2.2.27AT+GMRRequestTARevisionIdentificationofSoftwareRelease..................................35
2.2.28AT+GOIRequestGlobalObjectIdentification......................................................................35
2.2.29AT+GSNRequestTASerialNumberIdentification(IMEI)..................................................36
2.2.30AT+ICFSetTE-TAControlCharacterFraming....................................................................36
2.2.31AT+IFCSetTE-TALocalDataFlowControl.........................................................................37
2.2.32AT+IPRSetTE-TAFixedLocalRate......................................................................................38
3ATCommandsAccordingto3GPPTS27.007....................................................................40
3.1OverviewofATCommandAccordingto3GPPTS27.007............................................................40
3.2DetailedDescriptionsofATCommandAccordingto3GPPTS27.007......................................41
3.2.1AT+CGMIRequestManufacturerIdentification....................................................................41
3.2.2AT+CGMMRequestModelIdentification..............................................................................41
3.2.3AT+CGMRRequestTARevisionIdentificationofSoftwareRelease...............................42
3.2.4AT+CGSNRequestProductSerialNumberIdentification..................................................42
3.2.5AT+CSCSSelectTECharacterSet.......................................................................................42
3.2.6AT+CIMIRequestInternationalMobileSubscriberIdentity................................................43
3.2.7AT+CLCKFacilityLock.............................................................................................................44
3.2.8AT+CMEEReportMobileEquipmentError...........................................................................45
3.2.9AT+COPSOperatorSelection.................................................................................................46
3.2.10AT+CPASPhoneActivityStatus.............................................................................................48
3.2.11AT+CPINEnterPIN...................................................................................................................48
3.2.12AT+CPWDChangePassword.................................................................................................49
3.2.13AT+CRCSetCellularResultCodesforIncomingCallIndication.....................................50
3.2.14AT+CREGNetworkRegistration.............................................................................................51
3.2.15AT+CRSMRestrictedSIMAccess..........................................................................................52
3.2.16AT+CSQSignalQualityReport...............................................................................................53
3.2.17AT+CPOLPreferredOperatorList..........................................................................................54
3.2.18AT+COPNReadOperatorNames..........................................................................................55
3.2.19AT+CFUNSetPhoneFunctionality........................................................................................56
3.2.20AT+CCLKClock.........................................................................................................................57
3.2.21AT+CSIMGenericSIMAccess................................................................................................58
3.2.22AT+CBCBatteryCharge..........................................................................................................58
3.2.23AT+CUSDUnstructuredSupplementaryServiceData.......................................................59
3.2.24AT+CNUMSubscriberNumber...............................................................................................60
4ATCommandsAccordingto3GPPTS27.005....................................................................61

---

## Page 8

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 8/281
4.1OverviewofATCommandsAccordingto3GPPTS27.005..........................................................61
4.2DetailedDescriptionsofATCommandsAccordingto3GPPTS27.005....................................61
4.2.1AT+CMGDDeleteSMSMessage...........................................................................................61
4.2.2AT+CMGFSelectSMSMessageFormat..............................................................................62
4.2.3AT+CMGLListSMSMessagesfromPreferredStore.........................................................63
4.2.4AT+CMGRReadSMSMessage.............................................................................................66
4.2.5AT+CMGSSendSMSMessage.............................................................................................69
4.2.6AT+CMGWWriteSMSMessagetoMemory........................................................................70
4.2.7AT+CMSSSendSMSMessagefromStorage.....................................................................72
4.2.8AT+CNMINewSMSMessageIndications............................................................................73
4.2.9AT+CPMSPreferredSMSMessageStorage.......................................................................75
4.2.10AT+CRESRestoreSMSSettings...........................................................................................76
4.2.11AT+CSASSaveSMSSettings................................................................................................77
4.2.12AT+CSCASMSServiceCenterAddress...............................................................................77
4.2.13AT+CSDHShowSMSTextModeParameters.....................................................................78
4.2.14AT+CSMPSetSMSTextModeParameters.........................................................................79
4.2.15AT+CSMSSelectMessageService.......................................................................................80
5ATCommandsSpecialforSIMCom.......................................................................................82
5.1Overview.................................................................................................................................................82
5.2DetailedDescriptionsofCommands.................................................................................................83
5.2.1AT+CPOWDPoweroff..............................................................................................................83
5.2.2AT+CADCReadADC................................................................................................................84
5.2.3AT+CFGRIIndicateRIWhenUsingURC.............................................................................84
5.2.4AT+CLTSGetLocalTimestamp..............................................................................................85
5.2.5AT+CBANDGetandSetMobileOperationBand................................................................87
5.2.6AT+CNSMODShowNetworkSystemMode...........................................................................87
5.2.7AT+CSCLKConfigureSlowClock..........................................................................................88
5.2.8AT+CCIDShowICCID..............................................................................................................89
5.2.9AT+CDEVICEViewCurrentFlashDeviceType...................................................................89
5.2.10AT+GSVDisplayProductIdentificationInformation............................................................90
5.2.11AT+SGPIOControltheGPIO..................................................................................................90
5.2.12AT+SLEDSSettheTimerPeriodofNetLight......................................................................91
5.2.13AT+CNETLIGHTClosetheNetLightorOpenIttoShining...............................................92
5.2.14AT+CSGSNetlightIndicationofGPRSStatus.....................................................................92
5.2.15AT+CGPIOControltheGPIObyPINIndex..........................................................................93
5.2.16AT+CBATCHKSetVBATCheckingFeatureON/OFF........................................................94
5.2.17AT+CNMPPreferredModeSelection....................................................................................95
5.2.18AT+CMNBPreferredSelectionbetweenCAT-MandNB-IoT............................................95
5.2.19AT+CPSMSPowerSavingModeSetting..............................................................................96
5.2.20AT+CEDRXSExtended-DRXSetting.....................................................................................97
5.2.21AT+CPSIInquiringUESystemInformation...........................................................................98
5.2.22AT+CGNAPNGetNetworkAPNinCAT-MOrNB-IOT.....................................................100
5.2.23AT+CSDPServiceDomainPreference...............................................................................100
5.2.24AT+MCELLLOCKLockthespecialCAT-Mcell.....................................................................101
5.2.25AT+NCELLLOCKLockthespecialNB-IOTcell....................................................................102

---

## Page 9

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 9/281
5.2.26AT+NBSCConfigureNB-IOTScramblingFeature............................................................102
5.2.27AT+CAPNMODESelecttheModeofApplicationConfigureAPN..................................103
5.2.28AT+CRRCSTATEQueryRRCState....................................................................................104
5.2.29AT+CBANDCFGConfigureCAT-MOrNB-IOTBand.......................................................104
5.2.30AT+CNACTAPPNetworkActive..........................................................................................105
5.2.31AT+CNCFGPDPConfigure...................................................................................................106
5.2.32AT+CEDUMPSetWhethertheModuleResetWhenTheModuleisCrashed.............107
5.2.33AT+CNBSConfigureBandScanOptimizationForNB-IOT.............................................108
5.2.34AT+CNDSConfigureServiceDomainPreferenceForNB-IOT......................................109
5.2.35AT+CENGSwitchOnorOffEngineeringMode.................................................................109
5.2.36AT+CNACTCFGConfigureIPProtocolType......................................................................111
5.2.37AT+CTLIICControltheSwitchofIIC....................................................................................112
5.2.38AT+CWIICWriteValuestoRegisterofIICDevice.............................................................113
5.2.39AT+CRIICReadValuesfromRegisterofIICDevice.........................................................113
5.2.40AT+CMCFGManageMobileOperatorConfiguration........................................................114
5.2.41AT+CSIMLOCKSIMLock......................................................................................................115
5.2.42AT+CRATSRCHConfigureParameterforBetterRATSearch........................................117
5.2.43AT+SPWMGeneratethePulse-Width-Modulation............................................................118
5.2.44AT+CASRIPShowRemoteIPaddressandPortWhenReceivedData........................118
5.2.45AT+CEDRXConfigureEDRXparameters...........................................................................119
5.2.46AT+CPSMRDPReadPSMDynamicParameters.............................................................120
5.2.47AT+CPSMCFGConfigurePSMversionandMinimumThresholdValue.......................121
5.2.48AT+CPSMCFGEXTConfigureModemOptimizationofPSM..........................................122
5.2.49AT+CPSMSTATUSEnableDeepSleepWakeupIndication............................................123
5.2.50AT+CEDRXRDPeDRXReadDynamicParameters.........................................................124
5.2.51AT+CRAIConfigureReleaseAssistanceIndicationinNB-IOTnetwork........................125
6ATCommandsforGPRSSupport........................................................................................127
6.1Overview..............................................................................................................................................127
6.2DetailedDescriptionsofATCommandsforGPRSSupport.......................................................127
6.2.1AT+CGATTAttachorDetachfromGPRSService............................................................127
6.2.2AT+CGDCONTDefinePDPContext...................................................................................128
6.2.3AT+CGACTPDPContextActivateorDeactivate..............................................................130
6.2.4AT+CGPADDRShowPDPAddress.....................................................................................130
6.2.5AT+CGREGNetworkRegistrationStatus...........................................................................132
6.2.6AT+CGSMSSelectServiceforMOSMSMessages........................................................134
6.2.7AT+CEREGEPSNetworkRegistrationStatus..................................................................134
7ATCommandsforIPApplication.........................................................................................137
7.1Overview..............................................................................................................................................137
7.2DetailedDescriptionsofCommands...............................................................................................137
7.2.1AT+SAPBRBearerSettingsforApplicationsBasedonIP...............................................137
8ATCommandsforTCPIPApplicationToolkit...................................................................139
8.1Overview..............................................................................................................................................139
8.2DetailedDescriptionsofCommands...............................................................................................140
8.2.1AT+CIPMUXStartUpMulti-IPConnection.........................................................................140

---

## Page 10

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 10/281
8.2.2AT+CIPSTARTStartUpTCPorUDPConnection.............................................................140
8.2.3AT+CIPSENDSendDataThroughTCPorUDPConnection..........................................143
8.2.4AT+CIPQSENDSelectDataTransmittingMode................................................................144
8.2.5AT+CIPACKQueryPreviousConnectionDataTransmittingState................................145
8.2.6AT+CIPCLOSECloseTCPorUDPConnection................................................................146
8.2.7AT+CIPSHUTDeactivateGPRSPDPContext..................................................................147
8.2.8AT+CLPORTSetLocalPort..................................................................................................147
8.2.9AT+CSTTStartTaskandSetAPN,USERNAME,PASSWORD...................................148
8.2.10AT+CIICRBringUpWirelessConnectionwithGPRS......................................................149
8.2.11AT+CIFSRGetLocalIPAddress..........................................................................................150
8.2.12AT+CIFSREXGetLocalIPAddressextend.......................................................................150
8.2.13AT+CIPSTATUSQueryCurrentConnectionStatus..........................................................151
8.2.14AT+CDNSCFGConfigureDomainNameServer..............................................................152
8.2.15AT+CDNSGIPQuerytheIPAddressofGivenDomainName........................................153
8.2.16AT+CIPHEADAddanIPHeadattheBeginningofaPackageReceived.....................154
8.2.17AT+CIPATSSetAutoSendingTimer...................................................................................155
8.2.18AT+CIPSPRTSetPromptof‘>’WhenModuleSendsData............................................155
8.2.19AT+CIPSERVERConfigureModuleasServer..................................................................156
8.2.20AT+CIPCSGPSetGPRSforConnectionMode.................................................................157
8.2.21AT+CIPSRIPShowRemoteIPAddressandPortWhenReceivedData......................158
8.2.22AT+CIPDPDPSetWhethertoCheckStateofGPRSNetworkTiming..........................158
8.2.23AT+CIPMODESelectTCPIPApplicationMode.................................................................159
8.2.24AT+CIPCCFGConfigureTransparentTransferMode......................................................160
8.2.25AT+CIPSHOWTPDisplayTransferProtocolinIPHeadWhenReceivedData...........161
8.2.26AT+CIPUDPMODEUDPExtendedMode...........................................................................162
8.2.27AT+CIPRXGETGetDatafromNetworkManually.............................................................163
8.2.28AT+CIPRDTIMERSetRemoteDelayTimer.......................................................................165
8.2.29AT+CIPSGTXTSelectGPRSPDPcontext........................................................................166
8.2.30AT+CIPSENDHEXSetCIPSENDDataFormattoHex....................................................166
8.2.31AT+CIPHEXSSetOutput-dataFormatwithsuffix.............................................................167
8.2.32AT+CIPTKASetTCPKeepaliveParameters......................................................................167
8.2.33AT+CIPOPTIONEnableorDisableTCPnaglealgorithm................................................168
9ATCommandsforHTTP(S)Application.............................................................................170
9.1Overview..............................................................................................................................................170
9.2DetailedDescriptionsofCommands...............................................................................................170
9.2.1AT+SHSSLSelectSSLConfigure........................................................................................171
9.2.2AT+SHCONFSetHTTP(S)Parameter................................................................................171
9.2.3AT+SHCONNHTTP(S)Connection.....................................................................................172
9.2.4AT+SHBODSetBody.............................................................................................................172
9.2.5AT+SHBODEXTSetExtensionBody..................................................................................173
9.2.6AT+SHAHEADAddHead.......................................................................................................173
9.2.7AT+SHCHEADClearHead....................................................................................................174
9.2.8AT+SHPARASetHTTP(S)Para...........................................................................................174
9.2.9AT+SHCPARAClearHTTP(S)Para..................................................................................175

---

## Page 11

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 11/281
9.2.10AT+SHSTATEQueryHTTP(S)ConnectionStatus............................................................175
9.2.11AT+SHREQSetRequestType.............................................................................................176
9.2.12AT+SHREADReadResponseValue...................................................................................177
9.2.13AT+SHDISCDisconnectHTTP(S)........................................................................................178
9.2.14AT+HTTPTOFSDownloadFiletoAPFileSystem............................................................179
9.2.15AT+HTTPTOFSRLStateofDownloadFiletoAPFileSystem........................................180
10ATCommandsforFTPApplication..............................................................................181
10.1Overview..............................................................................................................................................181
10.2DetailedDescriptionsofCommands...............................................................................................182
10.2.1AT+FTPPORTSetFTPControlPort....................................................................................182
10.2.2AT+FTPMODESetActiveorPassiveFTPMode..............................................................182
10.2.3AT+FTPTYPESettheTypeofDatatoBeTransferred.....................................................183
10.2.4AT+FTPPUTOPTSetFTPPutType....................................................................................184
10.2.5AT+FTPCIDSetFTPBearerProfileIdentifier....................................................................184
10.2.6AT+FTPRESTSetResumeBrokenDownload..................................................................185
10.2.7AT+FTPSERVSetFTPServerAddress..............................................................................185
10.2.8AT+FTPUNSetFTPUserName..........................................................................................186
10.2.9AT+FTPPWSetFTPPassword............................................................................................186
10.2.10AT+FTPGETNAMESetDownloadFileName............................................................187
10.2.11AT+FTPGETPATHSetDownloadFilePath...............................................................188
10.2.12AT+FTPPUTNAMESetUploadFileName.................................................................188
10.2.13AT+FTPPUTPATHSetUploadFilePath.....................................................................189
10.2.14AT+FTPGETDownloadFile..........................................................................................189
10.2.15AT+FTPPUTSetUploadFile.........................................................................................191
10.2.16AT+FTPDELEDeleteSpecifiedFileinFTPServer...................................................192
10.2.17AT+FTPSIZEGettheSizeofSpecifiedFileinFTPServer.....................................192
10.2.18AT+FTPSTATEGettheFTPState...............................................................................193
10.2.19AT+FTPEXTPUTExtendUploadFile.............................................................................194
10.2.20AT+FTPMKDMakeDirectoryontheRemoteMachine............................................194
10.2.21AT+FTPRMDRemoveDirectoryontheRemoteMachine.......................................195
10.2.22AT+FTPLISTListContentsofDirectoryontheRemoteMachine..........................196
10.2.23AT+FTPEXTGETExtendDownloadFile.....................................................................197
10.2.24AT+FTPETPUTUploadFile...........................................................................................198
10.2.25AT+FTPETGETDownloadFile.....................................................................................199
10.2.26AT+FTPQUITQuitCurrentFTPSession....................................................................200
10.2.27AT+FTPRENAMERenametheSpecifiedFileontheRemoteMachine................200
10.2.28AT+FTPMDTMGettheLastModificationTimestampofSpecifiedFileonthe
RemoteMachine.........................................................................................................................................201
11ATCommandforNTPfunction......................................................................................203
11.1Overview..............................................................................................................................................203
11.2DetailedDescriptionsofCommands...............................................................................................203
11.2.1AT+CNTPCIDSetGPRSBearerProfile’sID.....................................................................203
11.2.2AT+CNTPSynchronizeNetworkTime.................................................................................204
12ATCommandsforOneNetApplication........................................................................206

---

## Page 12

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 12/281
12.1Overview..............................................................................................................................................206
12.2DetailedDescriptionsofCommands...............................................................................................207
12.2.1AT+MIPLCREATECreateOneNetconfiguration...............................................................207
12.2.2AT+MIPLDELETEDeleteOneNetconfiguration................................................................207
12.2.3AT+MIPLOPENConnecttoOneNet....................................................................................208
12.2.4AT+MIPLADDOBJAddobject...............................................................................................208
12.2.5AT+MIPLDELOBJDeleteObject..........................................................................................209
12.2.6AT+MIPLCLOSEDisconnecttoOneNet.............................................................................209
12.2.7AT+MIPLNOTIFYNotifyDatatoOneNet............................................................................210
12.2.8AT+MIPLREADRSPSendResponseonReadCommand..............................................211
12.2.9AT+MIPLWRITERSPSendResponseonWriteCommand.............................................211
12.2.10AT+MIPLEXECUTERSPSendResponseonExecuteCommand.........................212
12.2.11AT+MIPLOBSERVERSPSendResponseOnObserveCommand.......................212
12.2.12AT+MIPLDISCOVERRSPSendResponseonDiscoverCommand......................213
12.2.13AT+MIPLPARAMETERRSPSendResponseonParameterCommand...............213
12.2.14AT+MIPLUPDATEUpdateRegistration.......................................................................214
12.2.15AT+MIPLVERVersionofOneNetSDK........................................................................214
12.2.16AT+MIPLBOOTSTRAPBootstrapMode.....................................................................215
12.2.17+MIPLREADReadRequesttoUser............................................................................215
12.2.18+MIPLWRITEWriteRequesttoUser...........................................................................216
12.2.19+MIPLEXECUTEExecuteRequesttoUser...............................................................216
12.2.20+MIPLOBSERVEObserveRequesttoUser..............................................................217
12.2.21+MIPLDISCOVERDiscoverRequesttoUser............................................................217
12.2.22+MIPLPARAMETERSetParameterRequesttoUser..............................................217
12.2.23+MIPLEVENTEventIndicationtoUser.......................................................................218
13ATCommandsforTelecomIOTApplication..............................................................219
13.1Overview..............................................................................................................................................219
13.2DetailedDescriptionsofCommands...............................................................................................219
13.2.1AT+SIMLCREATECreateConfiguration.............................................................................219
13.2.2AT+SIMLMODEConnectionMode.......................................................................................220
13.2.3AT+SIMLOPENConnecttoTelecomIOT............................................................................220
13.2.4AT+SIMLSENDSendDatatoTelecomIOT........................................................................221
13.2.5AT+SIMLCLOSEDisconnecttoTelecomIOT....................................................................221
14ATCommandsforGNSSApplication...........................................................................222
14.1Overview..............................................................................................................................................222
14.2DetailedDescriptionsofCommands...............................................................................................222
14.2.1AT+CGNSPWRGNSSPowerControl.................................................................................222
14.2.2AT+CGNSINFGNSSNavigationInformationParsedFromNMEASentences...........223
14.2.3AT+CGNSURCGNSSNavigationURCReport.................................................................225
14.2.4AT+CGNSPORTGNSSNMEAOutPortSet......................................................................226
14.2.5AT+CGNSCOLDGNSSColdStart......................................................................................226
14.2.6AT+CGNSWARMGNSSWarmStart...................................................................................227
14.2.7AT+CGNSHOTGNSSHotStart...........................................................................................227
14.2.8AT+CGNSMODGNSSWorkModeSet..............................................................................228
14.2.9AT+CGNSCFGGNSSNMEAOutConfigure.....................................................................228

---

## Page 13

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 13/281
14.2.10AT+CGNSTSTGNSSNMEADataOutputtoATPort...............................................229
14.2.11AT+CGNSXTRAGNSSXTRAFunctionOpen...........................................................230
14.2.12AT+CGNSCPYGNSSXTRAFileCopy.......................................................................231
14.2.13AT+CGNSRTMSGNSSNMEAOutFrequencyConfigure......................................231
14.2.14AT+CGNSHORConfigurePositioningDesiredAccuracy......................................232
14.2.15AT+CGNSUTIPRConfigureBaudRateWhenNMEAOutputfromUART3.......233
14.2.16AT+CGNSNMEAConfigureNMEAOutputSentences.............................................233
14.2.17AT+CGTPIZATGNSSConfigure.................................................................................235
14.2.18AT+CGNSSUPLCFGGNSSSUPLConfigure..........................................................237
14.2.19AT+CGNSSUPLGNSSSUPLControl.......................................................................238
15ATCommandsforFileSystem......................................................................................239
15.1Overview..............................................................................................................................................239
15.2DetailedDescriptionsofCommands...............................................................................................239
15.2.1AT+CFSINITGetFlashDataBuffer.....................................................................................239
15.2.2AT+CFSWFILEWriteFiletotheFlashBufferAllocatedbyCFSINIT.............................240
15.2.3AT+CFSRFILEReadFilefromFlash...................................................................................241
15.2.4AT+CFSDFILEDeletetheFilefromtheFlash...................................................................241
15.2.5AT+CFSGFISGetFileSize...................................................................................................242
15.2.6AT+CFSRENRenameaFile.................................................................................................243
15.2.7AT+CFSGFRSGettheSizeofFileSystem........................................................................244
15.2.8AT+CFSTERMFreetheFlashBufferAllocatedbyCFSINIT...........................................244
15.2.9AT+CBAINITInitializetheAPBackupFileSystem............................................................245
15.2.10AT+CBALISTSetthefilesWhichWanttoBackup....................................................245
15.2.11AT+CBAPPSStarttoBackupAPFileSystemAllocatedbyCBAINITandCBALIST
246
15.2.12AT+CBARTRestoretheFileintoAPFileSystem......................................................246
16ATCommandsforSIMApplicationToolkit.................................................................247
16.1Overview..............................................................................................................................................247
16.2DetailedDescriptionsofCommands...............................................................................................247
16.2.1AT+STINSATIndication.........................................................................................................247
16.2.2AT+STGIGetSATInformation..............................................................................................248
16.2.3AT+STGRSATRespond........................................................................................................250
16.2.4AT+STKSTKSwitch...............................................................................................................251
17ATCommandsforSSLApplication..............................................................................252
17.1OverviewofATCommandsforSSLApplication...........................................................................252
17.2DetailedDescriptionsofATCommandsforSSLApplication......................................................252
17.2.1AT+CSSLCFGConfigureSSLParametersofContextIdentifier.....................................252
18ATCommandsforTCP/UDPApplication....................................................................257
18.1Overview..............................................................................................................................................257
18.2DetailedDescriptionsofCommands...............................................................................................257
18.2.1AT+CACIDSetTCP/UDPIdentifier......................................................................................257
18.2.2AT+CASSLCFGSetSSLCertificateandTimeoutParameters.......................................258
18.2.3AT+CAOPENOpenaTCP/UDPConnection.....................................................................260
18.2.4AT+CASERVEROpenaTCP/UDPServer.........................................................................261

---

## Page 14

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 14/281
18.2.5AT+CASENDSendDataviaanEstablishedConnection................................................263
18.2.6AT+CARECVReceiveDataviaanEstablishedConnection...........................................264
18.2.7AT+CAACKQuerySendDataInformation.........................................................................264
18.2.8AT+CASTATEQueryTCP/UDPConnectionState............................................................265
18.2.9AT+CACLOSECloseaTCP/UDPConnection...................................................................265
18.2.10AT+CACFGConfigureTransparentTransmissionParameters...............................266
18.2.11AT+CASWITCHSwitchtoTransparentTransportMode..........................................269
19ATCommandsforPING...................................................................................................271
19.1Overview..............................................................................................................................................271
19.2DetailedDescriptionsofCommands...............................................................................................271
19.2.1AT+SNPING4SendsanIPv4ping.......................................................................................271
19.2.2AT+SNPING6SendsanIPv6ping.......................................................................................272
20SupportedErrorCodesandUnsolicitedResultCodes..........................................273
20.1SummaryofCMEERRORCodes...................................................................................................273
20.2SummaryofCMSERRORCodes...................................................................................................276
20.3SummaryofUnsolicitedResultCodes...........................................................................................279

---

## Page 15

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 15/281
THISDOCUMENTISAREFERENCEGUIDETOALLTHEATCOMMANDS.
1Introduction
1.1Scopeofthedocument
ThisdocumentpresentstheATCommandSetforSIMComSIM7000Series,includingSIM7000A,SIM700C,
SIM7000E,SIM7000C-N,SIM7000E-N,SIM7000JCandSIM7000G.
1.2Relateddocuments
YoucanvisittheSIMComWebsiteusingthefollowinglink:
http://www.simcom.com
1.3Conventionsandabbreviations
Inthisdocument,theGSMenginesarereferredtoasfollowingterm:
ME(MobileEquipment);
MS(MobileStation);
TA(TerminalAdapter);
DCE(DataCommunicationEquipment)orfacsimileDCE(FAXmodem,FAXboard);
Inapplication,controllingdevicecontrolstheGSMenginebysendingATCommandviaitsserialinterface.
Thecontrollingdeviceattheotherendoftheseriallineisreferredtoasfollowingterm:
TE(TerminalEquipment);
DTE(DataTerminalEquipment)orplainly"theapplication"whichisrunningonanembeddedsystem;
1.4ATCommandsyntax
The"AT"or"at"or"aT"or"At"prefixmustbesetatthebeginningofeachCommandline.Toterminatea

---

## Page 16

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 16/281
Commandlineenter<CR>.
Commandsareusuallyfollowedbyaresponsethatincludes."<CR><LF><response><CR><LF>"
Throughoutthisdocument,onlytheresponsesarepresented,<CR><LF>areomittedintentionally.
TheATCommandsetimplementedbySIM7080Seriesisacombinationof3GPPTS27.005,3GPPTS
27.007andITU-TrecommendationV.25terandtheATcommandsdevelopedbySIMCom.
OnlyenterATCommandthroughserialportafterSIM7080SeriesispoweredonandUnsolicitedResult
Code"RDY"isreceivedfromserialport.Ifauto-baudingisenabled,theUnsolicitedResultCodes
"RDY"andsoonarenotindicatedwhenyoustartuptheME,andthe"AT"prefix,or"at"prefixmustbe
setatthebeginningofeachcommandline.
AlltheseATcommandscanbesplitintothreecategoriessyntactically:"basic","Sparameter",and
"extended".Theseareasfollows:
1.4.1Basicsyntax
TheseATcommandshavetheformatof"AT<x><n>",or"AT&<x><n>",where"<x>"istheCommand,and
"<n>"is/aretheargument(s)forthatCommand.Anexampleofthisis"ATE<n>",whichtellstheDCE
whetherreceivedcharactersshouldbeechoedbacktotheDTEaccordingtothevalueof"<n>"."<n>"is
optionalandadefaultwillbeusedifmissing.
1.4.2SParametersyntax
TheseATcommandshavetheformatof"ATS<n>=<m>",where"<n>"istheindexoftheSregistertoset,
and"<m>"isthevaluetoassigntoit."<m>"isoptional;ifitismissing,thenadefaultvalueisassigned.
1.4.3ExtendedSyntax
Thesecommandscanoperateinseveralmodes,asinthefollowingtable:
Table1:TypesofATcommandsandresponses
TestCommand
AT+<x>=?Themobileequipmentreturnsthelistofparametersandvalue
rangessetwiththecorrespondingWriteCommandorbyinternal
processes.
ReadCommand
AT+<x>?Thiscommandreturnsthecurrentlysetvalueoftheparameteror
parameters.NOTE

---

## Page 17

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 17/281
WriteCommand
AT+<x>=<…>Thiscommandsetstheuser-definableparametervalues.
ExecutionCommand
AT+<x>Theexecutioncommandreadsnon-variableparametersaffected
byinternalprocessesintheGSMengine.
1.4.4CombiningATcommandsonthesameCommandline
YoucanenterseveralATcommandsonthesameline.Inthiscase,youdonotneedtotypethe"AT"or"at"
prefixbeforeeverycommand.Instead,youonlyneedtype"AT"or"at"thebeginningofthecommandline.
Pleasenotetouseasemicolonasthecommanddelimiterafteranextendedcommand;inbasicsyntaxorS
parametersyntax,thesemicolonneednotenter,forexample:
ATE1Q0S0=1S3=13V1X4;+IFC=0,0;+IPR=115200.
TheCommandlinebuffercanacceptamaximumof559characters(countedfromthefirstcommand
without"AT"or"at"prefix)or39ATcommands.Ifthecharactersenteredexceededthisnumberthennone
oftheCommandwillexecutedandTAwillreturn"ERROR".
1.4.5EnteringsuccessiveATcommandsonseparatelines
WhenyouneedtoenteraseriesofATcommandsonseparatelines,pleaseNotethatyouneedtowaitthe
finalresponse(forexampleOK,CMEerror,CMSerror)oflastATCommandyouenteredbeforeyouenter
thenextATCommand.
1.5Supportedcharactersets
TheSIM7080SeriesATCommandinterfacedefaultstotheIRAcharacterset.TheSIM7080Series
supportsthefollowingcharactersets:
GSMformat
UCS2
IRA
Thecharactersetcanbesetandinterrogatedusingthe"AT+CSCS"Command(3GPPTS27.007).The
charactersetisdefinedinGSMspecification3GPPTS27.005.
ThecharactersetaffectstransmissionandreceptionofSMSandSMSCellBroadcastmessages,theentry
anddisplayofphonebookentriestextfieldandSIMApplicationToolkitalphastrings.

---

## Page 18

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 18/281
1.6Flowcontrol
FlowcontrolisveryimportantforcorrectcommunicationbetweentheGSMengineandDTE.Forinthe
casesuchasadataorfaxcall,thesendingdeviceistransferringdatafasterthanthereceivingsideisready
toaccept.Whenthereceivingbufferreachesitscapacity,thereceivingdeviceshouldbecapabletocause
thesendingdevicetopauseuntilitcatchesup.
Therearebasicallytwoapproachestoachievedataflowcontrol:softwareflowcontrolandhardwareflow
control.SIM7080Seriessupportbothtwokindsofflowcontrol.
InMultiplexmode,itisrecommendedtousethehardwareflowcontrol.
1.6.1Softwareflowcontrol(XON/XOFFflowcontrol)
Softwareflowcontrolsendsdifferentcharacterstostop(XOFF,decimal19)andresume(XON,decimal17)
dataflow.Itisquiteusefulinsomeapplicationsthatonlyusethreewiresontheserialinterface.
ThedefaultflowcontrolapproachofSIM7080Seriesishardwareflowcontrol(RTS/CTSflowcontrol),to
enablesoftwareflowcontrolintheDTEinterfaceandwithinGSMengine,typethefollowingATCommand:
AT+IFC=1,1
Ensurethatanycommunicationssoftwarepackage(e.g.Hyperterminal)usessoftwareflowcontrol.
SoftwareFlowcontrolshouldnotbeusedfordatacallswherebinarydatawillbetransmittedor
received(e.g.TCP/IP)astheDTEinterfacemayinterpretbinarydataasflowcontrolcharacters.
1.6.2Hardwareflowcontrol(RTS/CTSflowcontrol)
HardwareflowcontrolachievesthedataflowcontrolbycontrollingtheRTS/CTSline.Whenthedata
transfershouldbesuspended,theCTSlineissetinactiveuntilthetransferfromthereceivingbufferhas
completed.Whenthereceivingbufferisoktoreceivemoredata,CTSgoesactiveonceagain.
Toachievehardwareflowcontrol,ensurethattheRTS/CTSlinesarepresentonyourapplicationplatform.NOTE

---

## Page 19

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 19/281
1.7Definitions
1.7.1ParameterSavingMode
Forthepurposesofthepresentdocument,thefollowingsyntacticaldefinitionsapply:
NO_SAVE:TheparameterofthecurrentATcommandwillbelostifmoduleisrebootedorcurrentAT
commanddoesn'thaveparameter.
AUTO_SAVE:TheparameterofthecurrentATcommandwillbekeptinNVRAMautomaticallyand
takeineffectimmediately,anditwon'tbelostifmoduleisrebooted.
AUTO_SAVE_REBOOT:TheparameterofthecurrentATcommandwillbekeptinNVRAM
automaticallyandtakeineffectafterreboot,anditwon'tbelostifmoduleisrebooted.
-:"-"meansthisATcommanddoesn'tcaretheparametersavingmode.
1.7.2MaxResponseTime
Maxresponsetimeisestimatedmaximumtimetogetresponse,theunitisseconds.
"-"meansthisATcommanddoesn'tcaretheresponsetime.

---

## Page 20

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 20/281
2ATCommandsAccordingto
V.25TER
TheseATCommandsaredesignedaccordingtotheITU-T(InternationalTelecommunicationUnion,
Telecommunicationsector)V.25terdocument.
2.1OverviewofATCommandsAccordingtoV.25TER
Command Description
A/ Re-issuesthelastcommandgiven
ATD Mobileoriginatedcalltodialanumber
ATE Setcommandechomode
ATH Disconnectexistingconnection
ATI Displayproductidentificationinformation
ATL Setmonitorspeakerloudness
ATM Setmonitorspeakermode
+++ Switchfromdatamodeorppponlinemodetocommandmode
ATO Switchfromcommandmodetodatamode
ATQ Setresultcodepresentationmode
ATS0 Setnumberofringsbeforeautomaticallyansweringthecall
ATS3 Setcommandlineterminationcharacter
ATS4 Setresponseformattingcharacter
ATS5 Setcommandlineeditingcharacter
ATS6 Pausebeforeblinddialing
ATS7 Setnumberofsecondstowaitforconnectioncompletion
ATS8Setnumberofsecondstowaitforcommadialmodifierencounteredindial
stringofDcommand
ATS10 Setdisconnectdelayafterindicatingtheabsenceofdatacarrier
ATV TAresponseformat
ATX Setconnectresultcodeformatandmonitorcallprogress
ATZ Resetdefaultconfiguration
AT&C SetDCDfunctionmode
AT&D SetDTRfunctionmode
AT&F Factorydefinedconfiguration
AT&V Displaycurrentconfiguration
AT&E SetCONNECTResultCodeFormatAboutSpeed

---

## Page 21

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 21/281
AT+GCAP RequestcompleteTAcapabilitieslist
AT+GMI Requestmanufactureridentification
AT+GMM RequestTAmodelidentification
AT+GMR RequestTArevisionidentificationofsoftwarerelease
AT+GOI Requestglobalobjectidentification
AT+GSN RequestTAserialnumberidentification(IMEI)
AT+ICF SetTE-TAcontrolcharacterframing
AT+IFC SetTE-TAlocaldataflowcontrol
AT+IPR SetTE-TAfixedlocalrate
2.2DetailedDescriptionofATCommandsAccordingtoV.25TER
2.2.1A/Re-issuestheLastCommandGiven
A/Re-issuestheLastCommandGiven
ExecutionCommand
A/Response
Re-issuesthepreviousCommand
Reference
V.25terNote
2.2.2ATDMobileOriginatedCalltoDialANumber
ATDMobileOriginatedCalltoDialANumber
ExecutionCommand
ATD<n>[<mgsm]Response
Thiscommandcanbeusedtosetupoutgoingdatacalls.Italsoservesto
controlsupplementaryservices.
Note:ThiscommandmaybeabortedgenerallybyreceivinganATH
Commandoracharacterduringexecution.Theabortingisnotpossible
duringsomestatesofconnectionestablishmentsuchashandshaking.
IferrorisrelatedtoMEfunctionality
+CMEERROR:<err>
Ifnodialtoneand(parametersettingATX2orATX4)
NODIALTONE

---

## Page 22

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 22/281
Ifbusyand(parametersettingATX3orATX4)
BUSY
Ifaconnectioncannotbeestablished
NOCARRIER
Iftheremotestationdoesnotanswer
NOANSWER
Ifconnectionsuccessfulandnon-voicecall.
CONNECT<text>TAswitchestodatamode.
Note:<text>outputonlyifATX<value>parametersettingwiththe
<value>>0
WhenTAreturnstocommandmodeaftercallrelease
Parameters
<n>StringofdialingdigitsandoptionallyV.25termodifiersdialing
digits:0-9,*,#,+,A,B,C
FollowingV.25termodifiersareignored:
,(comma),T,P,!,W,@
Emergencycall:
<n> Standardizedemergencynumber112(noSIMneeded)
<mgsm>StringofGSMmodifiers:
IActivesCLIR(Disablespresentationofownnumberto
calledparty)
iDeactivatesCLIR(Enablepresentationofownnumber
tocalledparty)
GActivatesClosedUserGroupinvocationforthiscallonly
gDeactivatesClosedUserGroupinvocationforthiscall
only
ParameterSavingModeNO_SAVE
MaxResponseTimeTimeoutsetwithATS7(datacall)
Reference
V.25terNote
2.2.3ATESetCommandEchoMode
ATESetCommandEchoMode
ExecutionCommandResponse
ThissettingdetermineswhetherornottheTAechoescharactersreceived

---

## Page 23

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 23/281
ATE<value> fromTEduringCommandstate.
Parameters
<value>0Echomodeoff
1Echomodeon
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
2.2.4ATHDisconnectExistingConnection
ATHDisconnectExistingConnection
ExecutionCommand
ATHResponse
DisconnectexistingcallbylocalTEfromCommandlineandterminatecall
Note:OKisissuedaftercircuit109(DCD)isturnedoff,ifitwaspreviously
on.
ParameterSavingModeNO_SAVE
MaxResponseTime20s
Reference
V.25terNote
2.2.5ATIDisplayProductIdentificationInformation
ATIDisplayProductIdentificationInformation
ExecutionCommand
ATIResponse
TAissuesproductinformationtext
Example:
SIM7000R1351
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote

---

## Page 24

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 24/281
2.2.6ATLSetMonitorspeakerloudness
ATLSetMonitorspeakerloudness
ExecutionCommand
ATL<value>Response
Parameters
<value>0..3Volume
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
NoeffectinGSM
2.2.7ATMSetMonitorSpeakerMode
ATMSetMonitorSpeakerMode
ExecutionCommand
ATM<value>Response
Parameters
<value>0..2Mode
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
NoeffectinGSM
2.2.8+++SwitchfromDataModeorPPPOnlineModetoCommandMode
+++SwitchfromDataModeorPPPOnlineModetoCommandMode
ExecutionCommand
+++Response
The+++charactersequencecausestheTAtocancelthedataflowoverthe
ATinterfaceandswitchtoCommandmode.ThisallowsyoutoenterAT
Commandwhilemaintainingthedataconnectiontotheremoteserver.
Topreventthe+++escapesequencefrombeingmisinterpretedasdata,it
shouldcomplytofollowingsequence:
NocharactersenteredforT1time(1second)
"+++"charactersenteredwithnocharactersinbetween(1second)
NocharactersenteredforT1timer(1second)
SwitchtoCommandmode,otherwisegotostep1.

---

## Page 25

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 25/281
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
ToreturnfromCommandmodebacktodatamode:EnterATO.
2.2.9ATOSwitchfromCommandModetoDataMode
ATOSwitchfromCommandModetoDataMode
ExecutionCommand
ATO[n]Response
TAresumestheconnectionandswitchesbackfromcommandmodetodata
mode.
CONNECT
Ifconnectionisnotsuccessfullyresumed
ERROR
else
TAreturnstodatamodefromcommandmodeCONNECT<text>
Note:<text>onlyifparametersettingATX>0
Parameter
<n>0Switchfromcommandmodetodatamode.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
2.2.10ATQSetResultCodePresentationMode
ATQSetResultCodePresentationMode
ExecutionCommand
ATQ<n>Response
ThisparametersettingdetermineswhetherornottheTAtransmitsany
resultcodetotheTE.Informationtexttransmittedinresponseisnot
affectedbythissetting.
If<n>=0:
If<n>=1:
(none)
Parameters
<n>0TAtransmitsresultcode
1Resultcodesaresuppressedandnottransmitted

---

## Page 26

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 26/281
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
2.2.11ATS0SetNumberofRingsbeforeAutomaticallyAnsweringtheCall
ATS0SetNumberofRingsbeforeAutomaticallyAnsweringtheCall
ReadCommand
ATS0?Response
<n>
Parameters
SeeWriteCommand
WriteCommand
ATS0=<n>Response
Thisparametersettingdeterminesthenumberofringsbeforeauto-answer.
ERROR
Parameters
<n>0Automaticansweringisdisable.
1-255Numberofringsthemodemwillwaitforbeforeanswering
thephoneifaringisdetected.
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
If<n>issettoohigh,thecallingpartymayhangupbeforethecallcanbe
answeredautomatically.
Ifusingcmuxport,ATHandAT+CHUPcanhangupthecall(automatically
answering)onlyintheCMUXchannel0.
Ifusingdual-physicalserialport,ATHandAT+CHUPcanhangupthecall
(automaticallyanswering)onlyinUART1.
2.2.12ATS3SetCommandLineTerminationCharacter
ATS3SetCommandLineTerminationCharacter
ReadCommand
ATS3?Response
<n>

---

## Page 27

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 27/281
Parameters
SeeWriteCommand
WriteCommand
ATS3=<n>Response
ThisparametersettingdeterminesthecharacterrecognizedbyTAto
terminateanincomingcommandline.TheTAalsoreturnsthischaracterin
output.
ERROR
Parameters
<n>13Commandlineterminationcharacter
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
Default13=CR.Itonlysupportsdefaultvalue.
2.2.13ATS4SetResponseFormattingCharacter
ATS4SetResponseFormattingCharacter
ReadCommand
ATS4?Response
<n>
Parameters
SeeWriteCommand
WriteCommand
ATS4=<n>Response
ThisparametersettingdeterminesthecharactergeneratedbytheTAfor
resultcodeandinformationtext.
ERROR
Parameters
<n>10Responseformattingcharacter
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
Default10=LF.Itonlysupportsdefaultvalue.

---

## Page 28

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 28/281
2.2.14ATS5SetCommandLineEditingCharacter
ATS5SetCommandLineEditingCharacter
ReadCommand
ATS5?Response
<n>
Parameters
SeeWriteCommand
WriteCommand
ATS5=<n>Response
ThisparametersettingdeterminesthecharacterrecognizedbyTAasa
requesttodeletefromthecommandlinetheimmediatelypreceding
character.
ERROR
Parameters
<n>0-8-127Responseformattingcharacter
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
Default8=Backspace.
2.2.15ATS6PauseBeforeBlindDialing
ATS6PauseBeforeBlindDialing
ReadCommand
ATS6?Response
<n>
WriteCommand
ATS6=<n>Response
ERROR
Parameters
<n>0-2-999Time
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
NoeffectinGSM

---

## Page 29

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 29/281
2.2.16ATS7SetNumberofSecondstoWaitforConnectionCompletion
ATS7SetNumberofSecondstoWaitforConnectionCompletion
ReadCommand
ATS7?Response
<n>
Parameters
SeeWriteCommand
WriteCommand
ATS7=<n>Response
Thisparametersettingdeterminestheamountoftimetowaitforthe
connectioncompletionincaseofansweringororiginatingacall.
ERROR
Parameters
<n>0-255Numberofsecondstowaitforconnectioncompletion
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
IfcalledpartyhasspecifiedahighvalueforATS0=<n>,callsetupmayfail.
ThecorrelationbetweenATS7andATS0isimportant
Example:CallmayfailifATS7=30andATS0=20.
ATS7isonlyapplicabletodatacall.
2.2.17ATS8SetNumberofSecondstoWaitforCommaDialModifierEncounteredin
DialStringofDCommand
ATS8SetNumberofSecondstoWaitforCommaDialModifierEncounteredinDial
StringofDCommand
ReadCommand
ATS8?Response
<n>
Parameters
SeeWriteCommand
WriteCommand
ATS8=<n>Response
ERROR

---

## Page 30

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 30/281
Parameters
<n>0-2-255Thevalueofthisregisterdetermineshowlongthe
modemshouldpausewhenitseesacommainthedialingstring.
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
NoeffectinGSM
2.2.18ATS10SetDisconnectDelayafterIndicatingtheAbsenceofDataCarrier
ATS10SetDisconnectDelayafterIndicatingtheAbsenceofDataCarrier
ReadCommand
ATS10?Response
<n>
Parameters
SeeWriteCommand
WriteCommand
ATS10=<n>Response
ThisparametersettingdeterminestheamountoftimethattheTAwill
remainconnectedinabsenceofdatacarrier.Ifthedatacarrierisoncemore
detectedbeforedisconnecting,theTAremainsconnected.
ERROR
Parameters
<n>1-14-255Numberoftenthssecondsofdelay
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
2.2.19ATVTAResponseFormat
ATVTAResponseFormat
ExecutionCommand
ATV<value>Response
Thisparametersettingdeterminesthecontentsoftheheaderandtrailer
transmittedwithresultcodesandinformationresponses.
When<value>=0

---

## Page 31

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 31/281
When<value>=1
Parameters
<value>
0Informationresponse:<text><CR><LF>
Shortresultcodeformat:<numericcode><CR>
1Informationresponse:<CR><LF><text><CR><LF>
Longresultcodeformat:<CR><LF><verbosecode><CR><LF>
Theresultcodes,theirnumericequivalentsandbriefdescriptionsoftheuse
ofeacharelistedinthefollowingtable.
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
ATV1 ATV0 Description
OK 0 AcknowledgesexecutionofaCommand
CONNECT 1Aconnectionhasbeenestablished;theDCEismovingfrom
Commandstatetoonlinedatastate
RING 2 TheDCEhasdetectedanincomingcallsignalfromnetwork
NOCARRIER3Theconnectionhasbeenterminatedortheattempttoestablish
aconnectionfailed
ERROR 4Commandnotrecognized,Commandlinemaximumlength
exceeded,parametervalueinvalid,orotherproblemwith
processingtheCommandline
NODIALTONE6 Nodialtonedetected
BUSY 7 Engaged(busy)signaldetected
NOANSWER8"@"(WaitforQuietAnswer)dialmodifierwasused,butremote
ringingfollowedbyfivesecondsofsilencewasnotdetected
beforeexpirationoftheconnectiontimer(S7)
PROCEEDING9 AnATcommandisbeingprocessed
CONNECT<text>Manufacturer-
specificSameasCONNECT,butincludesmanufacturer-specifictext
thatmayspecifyDTEspeed,linespeed,errorcontrol,data
compression,orotherstatus
2.2.20ATXSetCONNECTResultCodeFormatandMonitorCallProgress
ATXSetCONNECTResultCodeFormatandMonitorCallProgress
ExecutionCommand
ATX<value>Response
ThisparametersettingdetermineswhetherornottheTAdetectedthe
presenceofdialtoneandbusysignalandwhetherornotTAtransmits
particularresultcodes.

---

## Page 32

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 32/281
ERROR
Parameters
<value>0CONNECTresultcodeonlyreturned,dialtoneandbusy
detectionarebothdisabled.
1CONNECT<text>resultcodeonlyreturned,dialtoneand
busydetectionarebothdisabled.
2CONNECT<text>resultcodereturned,dialtonedetection
isenabled,busydetectionisdisabled.
3CONNECT<text>resultcodereturned,dialtonedetection
isdisabled,busydetectionisenabled.
4CONNECT<text>resultcodereturned,dialtoneandbusy
detectionarebothenabled.
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
2.2.21AT&CSetDCDFunctionMode
AT&CSetDCDFunctionMode
ExecutionCommand
AT&C<value>Response
Thisparameterdetermineshowthestateofcircuit109(DCD)relatestothe
detectionofreceivedlinesignalfromthedistantend.
ERROR
Parameters
<value>0DCDlineisalwaysON
1DCDlineisONonlyinthepresenceofdatacarrier
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
2.2.22AT&DSetDTRFunctionMode
AT&DSetDTRFunctionMode

---

## Page 33

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 33/281
ExecutionCommand
AT&D[<value>]Response
ThisparameterdetermineshowtheTArespondswhencircuit108/2(DTR)
ischangedfromtheONtotheOFFconditionduringdatamode.
ERROR
Parameters
<value>0TAignoresstatusonDTR.
1ON->OFFonDTR:ChangetoCommandmodewith
remainingtheconnectedcall.
2ON->OFFonDTR:Disconnectcall,changetoCommand
mode.DuringstateDTR=OFFisauto-answeroff.
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
2.2.23AT&ESetCONNECTResultCodeFormatAboutSpeed
AT&ESetCONNECTResultCodeFormatAboutSpeed
ExecutionCommand
AT&E[<value>]ThisparametersettingdeterminestoreportSerialconnectionrateor
Wirelessconnectionspeed.ItisvalidonlyATXabove0.
Response
ERROR
Parameters
<value>
0Wirelessconnectionspeedinintegerformat.
1Serialconnectionrateinintegerformat.Suchas:"115200"
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
2.2.24AT+GCAPRequestCompleteTACapabilitiesList
AT+GCAPRequestCompleteTACapabilitiesList
ExecutionCommandResponse

---

## Page 34

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 34/281
AT+GCAP TAreportsalistofadditionalcapabilities.
+GCAP:listofsupported<name>s
Parameters
<name>+CGSMGSMfunctionissupported
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
2.2.25AT+GMIRequestManufacturerIdentification
AT+GMIRequestManufacturerIdentification
TestCommand
AT+GMI=?Response
Parameters
ExecutionCommand
AT+GMITAreportsoneormorelinesofinformationtextwhichpermittheuserto
identifythemanufacturer.
SIMCOM_Ltd
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
2.2.26AT+GMMRequestTAModelIdentification
AT+GMMRequestTAModelIdentification
TestCommand
AT+GMM=?Response
ExecutionCommand
AT+GMMTAreportsoneormorelinesofinformationtextwhichpermittheuserto
identifythespecificmodelofdevice.
<model>

---

## Page 35

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 35/281
Parameters
<model>Productmodelidentificationtext
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
2.2.27AT+GMRRequestTARevisionIdentificationofSoftwareRelease
AT+GMRRequestTARevisionIdentificationofSoftwareRelease
TestCommand
AT+GMR=?Response
ExecutionCommand
AT+GMRTAreportsoneormorelinesofinformationtextwhichpermittheuserto
identifytherevisionofsoftwarerelease.
Revision:<revision>
Parameters
<revision>Revisionofsoftwarerelease
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
2.2.28AT+GOIRequestGlobalObjectIdentification
AT+GOIRequestGlobalObjectIdentification
TestCommand
AT+GOI=?Response
ExecutionCommand
AT+GOIResponse
TAreportsoneormorelinesofinformationtextwhichpermittheuserto
identifythedevice,basedontheISOsystemforregisteringuniqueobject
identifiers.
<ObjectId>
Parameters
<ObjectId>Identifierofdevicetype
seeX.208,209fortheformatof<ObjectId>

---

## Page 36

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 36/281
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
2.2.29AT+GSNRequestTASerialNumberIdentification(IMEI)
AT+GSNRequestTASerialNumberIdentification(IMEI)
TestCommand
AT+GSN=?Response
ExecutionCommand
AT+GSNResponse
TAreportstheIMEI(internationalmobileequipmentidentifier)numberin
informationtextwhichpermittheusertoidentifytheindividualMEdevice.
<sn>
Parameters
<sn>IMEIofthetelephone(InternationalMobilestationEquipment
Identity)
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote
Theserialnumber(IMEI)isvariedbyindividualMEdevice.
2.2.30AT+ICFSetTE-TAControlCharacterFraming
AT+ICFSetTE-TAControlCharacterFraming
TestCommand
AT+ICF=?Response
+ICF:(listofsupported<format>s),(listofsupported<parity>s)
Parameters
SeeWriteCommand
ReadCommand
AT+ICF?Response
+ICF:<format>,<parity>
Parameters
SeeWriteCommand

---

## Page 37

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 37/281
WriteCommand
AT+ICF=<format>[,<pa
rity>]Response
Thisparametersettingdeterminestheserialinterfacecharacterframing
formatandparityreceivedbyTAfromTE.
Parameters
<format>18data0parity2stop
28data1parity1stop
38data0parity1stop
47data0parity2stop
57data1parity1stop
67data0parity1stop
<parity>0odd
1even
3space(0)
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
TheCommandisappliedforCommandstate;
In<format>parameter,"0parity"meansnoparity;
The<parity>fieldisignoredifthe<format>fieldspecifiesnoparityand
string"+ICF:<format>,255"willberesponseto"AT+ICF?"Command.
2.2.31AT+IFCSetTE-TALocalDataFlowControl
AT+IFCSetTE-TALocalDataFlowControl
TestCommand
AT+IFC=?Response
+IFC:(listofsupported<dce_by_dte>s),(listofsupported<dte_by_dce>s)
Parameters
SeeWriteCommand
ReadCommand
AT+IFC?Response
+IFC:<dce_by_dte>,<dte_by_dce>
Parameters
SeeWriteCommand
WriteCommand
AT+IFC=<dce_by_dte>
[,<dte_by_dce>]Response
Thisparametersettingdeterminesthedataflowcontrolontheserial
interfacefordatamode.

---

## Page 38

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 38/281
Parameters
<dce_by_dte>SpecifiesthemethodwillbeusedbyTEatreceiveof
datafromTA
0Noflowcontrol
1Softwareflowcontrol
2Hardwareflowcontrol
<dte_by_dce>SpecifiesthemethodwillbeusedbyTAatreceiveofdata
fromTE
0Noflowcontrol
1Softwareflowcontrol
2Hardwareflowcontrol
ParameterSavingMode-
MaxResponseTime-
Reference
V.25terNote
2.2.32AT+IPRSetTE-TAFixedLocalRate
AT+IPRSetTE-TAFixedLocalRate
TestCommand
AT+IPR=?Response
+IPR:(listofsupportedautodetectable<rate>s),(listofsupported
fixed-only<rate>s)
Parameters
SeeWriteCommand
ReadCommand
AT+IPR?Response
+IPR:<rate>
Parameters
SeeWriteCommand
WriteCommand
AT+IPR=<rate>Response
ThisparametersettingdeterminesthedatarateoftheTAontheserial
interface.TherateofCommandtakeseffectfollowingtheissuanceofany
resultcodeassociatedwiththecurrentCommandline.
Parameters
<rate>Baudratepersecond
300

---

## Page 39

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 39/281
600
1200
2400
4800
9600
19200
38400
57600
115200
230400
921600
2000000
2900000
3000000
3200000
3686400
4000000
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
Reference
V.25terNote

---

## Page 40

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 40/281
3ATCommandsAccordingto3GPP
TS27.007
3.1OverviewofATCommandAccordingto3GPPTS27.007
Command Description
AT+CGMI Requestmanufactureridentification
AT+CGMM Requestmodelidentification
AT+CGMR RequestTArevisionidentificationofsoftwarerelease
AT+CGSN Requestproductserialnumberidentification(identicalwith+GSN)
AT+CSCS SelectTEcharacterset
AT+CIMI Requestinternationalmobilesubscriberidentity
AT+CLCK Facilitylock
AT+CMEE Reportmobileequipmenterror
AT+COPS Operatorselection
AT+CPAS Phoneactivitystatus
AT+CPIN EnterPIN
AT+CPWD Changepassword
AT+CRC Setcellularresultcodesforincomingcallindication
AT+CREG Networkregistration
AT+CRSM RestrictedSIMaccess
AT+CSQ Signalqualityreport
AT+CPOL Preferredoperatorlist
AT+COPN Readoperatornames
AT+CFUN Setphonefunctionality
AT+CCLK Clock
AT+CSIM GenericSIMaccess
AT+CBC Batterycharge
AT+CUSD Unstructuredsupplementaryservicedata
AT+CNUM SubscriberNumber

---

## Page 41

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 41/281
3.2DetailedDescriptionsofATCommandAccordingto3GPPTS27.007
3.2.1AT+CGMIRequestManufacturerIdentification
AT+CGMIRequestManufacturerIdentification
TestCommand
AT+CGMI=?Response
ExecutionCommand
AT+CGMIResponse
TAreturnsmanufactureridentificationtext.
<manufacturer>
Parameters
<manufacturer>TheIDofmanufacturer
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.2AT+CGMMRequestModelIdentification
AT+CGMMRequestModelIdentification
TestCommand
AT+CGMM=?Response
ExecutionCommand
AT+CGMMResponse
TAreturnsproductmodelidentificationtext.
<model>
Parameters
<model>Productmodelidentificationtext
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note

---

## Page 42

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 42/281
3.2.3AT+CGMRRequestTARevisionIdentificationofSoftwareRelease
AT+CGMRRequestTARevisionIdentificationofSoftwareRelease
TestCommand
AT+CGMR=?Response
ExecutionCommand
AT+CGMRResponse
TAreturnsproductsoftwareversionidentificationtext.
Revision:<revision>
Parameters
<revision>Productsoftwareversionidentificationtext
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.4AT+CGSNRequestProductSerialNumberIdentification
AT+CGSNRequestProductSerialNumberIdentification(Identicalwith+GSN)
TestCommand
AT+CGSN=?Response
ExecutionCommand
AT+CGSNResponse
see+GSN
<sn>
Parameters
<sn>Internationalmobileequipmentidentity(IMEI)
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.5AT+CSCSSelectTECharacterSet
AT+CSCSSelectTECharacterSet
TestCommandResponse
+CSCS:(listofsupported<chset>s)

---

## Page 43

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 43/281
AT+CSCS=?
Parameters
<chset>"GSM"GSM7bitdefaultalphabet(3GPPTS23.038);
"UCS2"16-bituniversalmultiple-octetcodedcharacterset
(ISO/IEC10646);UCS2characterstringsareconvertedto
hexadecimalnumbersfrom0000toFFFF;e.g."004100620063"
equalsthree16-bitcharacterswithdecimalvalues65,98and
"IRA"Internationalreferencealphabet(ITU-TT.50)
ReadCommand
AT+CSCS?Response
+CSCS:<chset>
Parameters
SeeTestCommand
WriteCommand
AT+CSCS=<chset>Response
Setswhichcharacterset<chset>areusedbytheTE.TheTAcanthen
convertcharacterstringscorrectlybetweentheTEandMEcharactersets.
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
SeeTestCommand
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.6AT+CIMIRequestInternationalMobileSubscriberIdentity
AT+CIMIRequestInternationalMobileSubscriberIdentity
TestCommand
AT+CIMI=?Response
ExecutionCommand
AT+CIMIResponse
TAreturns<IMSI>foridentifyingtheindividualSIMwhichisattachedtoME.
<IMSI>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<IMSI>InternationalMobileSubscriberIdentity(stringwithoutdouble

---

## Page 44

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 44/281
quotes)
ParameterSavingModeNO_SAVE
MaxResponseTime20s
Reference
3GPPTS27.007[13]Note
3.2.7AT+CLCKFacilityLock
AT+CLCKFacilityLock
TestCommand
AT+CLCK=?Response
+CLCK:(listofsupported<fac>s)
Parameters
SeeWriteCommand
WriteCommand
AT+CLCK=<fac>,<mod
e>[,<passwd>[,<class>
]]Response
ThisCommandisusedtolock,unlockorinterrogateaMEoranetwork
facility<fac>.Passwordisnormallyneededtodosuchactions.When
queryingthestatusofanetworkservice(<mode>=2)theresponselinefor
‘notactive’case(<status>=0)shouldbereturnedonlyifserviceisnot
activeforany<class>.
If<mode>≠2andCommandissuccessful
If<mode>=2andCommandissuccessful
+CLCK:<status>[,<class1>[<CR><LF>+CLCK:
<status>,<class2>[…]]
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<fac>
"AB"AllBarringservices(onlyfor<mode>=0)
"AC"AllinComingbarringservices(onlyfor<mode>=0)"AG"
AlloutGoingbarringservices(onlyfor<mode>=0)
"AI"BAIC(BarrAllIncomingCalls)
"AO"BAOC(BarrAllOutgoingCalls)
"IR"BIC-Roam(BarrIncomingCallswhenRoaming
outsidethehomecountry)
"OI"BOIC(BarrOutgoingInternationalCalls)
"OX"BOIC-exHC(BarrOutgoingInternationalCallsexceptto
HomeCountry)

---

## Page 45

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 45/281
"SC"SIM(lockSIM/UICCcard)(SIM/UICCaskspasswordin
MTpower-upandwhenthislockcommandissued)Correspondto
PIN1code.
"FD"SIMcardoractiveapplicationintheUICC(GSMor
USIM)fixeddiallingmemoryfeature(ifPIN2authenticationhasnot
beendoneduringthecurrentsession,PIN2isrequiredas<passwd>)
"PN"NetworkPersonalization,CorrespondtoNCKcode
"PU"NetworksubsetPersonalizationCorrespondtoNSCK
code
"PP"ServiceProviderPersonalizationCorrespondtoSPCK
code
<mode>
0unlock
1lock
2querystatus
<passwd>Stringtype(Shallbethesameaspasswordspecifiedforthe
facilityfromtheMTuserinterfaceorwithcommandChangePassword
+CPWD)
<class>1-255
1Voice(telephony)
2Datareferstoallbearerservices;with<mode>=2thismayrefer
onlytosomebearerserviceifTAdoesnotsupportvalues16,32,64and
128)
4Fax(facsimileservices)
7Allclasses
<status>
0Notactive
1Active
ParameterSavingModeNO_SAVE
MaxResponseTime15s
Reference
3GPPTS27.007[14]Note
CMEerrorsifSIMnotinsertedorPINisnotentered.
3.2.8AT+CMEEReportMobileEquipmentError
AT+CMEEReportMobileEquipmentError
TestCommand
AT+CMEE=?Response
+CMEE:(listofsupported<n>s)
Parameters
SeeWriteCommand
ReadCommand Response

---

## Page 46

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 46/281
AT+CMEE? +CMEE:<n>
Parameters
SeeWriteCommand
WriteCommand
AT+CMEE=[<n>]Response
TAdisablesorenablestheuseofresultcode+CMEERROR:<err>asan
indicationofanerrorrelatingtothefunctionalityoftheME.
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<n>0Disable+CMEERROR:<err>resultcodeanduseERROR
instead.
1Enable+CMEERROR:<err>resultcodeandusenumeric
<err>
2Enable+CMEERROR:<err>resultcodeanduseverbose
<err>values
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.9AT+COPSOperatorSelection
AT+COPSOperatorSelection
TestCommand
AT+COPS=?Response
TAreturnsalistofquadruplets,eachrepresentinganoperatorpresentin
thenetwork.Anyoftheformatsmaybeunavailableandshouldthenbean
emptyfield.Thelistofoperatorsshallbeinorder:homenetwork,networks
referencedinSIM,andothernetworks.
+COPS:(listofsupported<stat>,longalphanumeric<oper>,short
alphanumeric<oper>,numeric<oper>,<netact>)s[,,(listofsupported
<mode>s),(listofsupported<format>s)]
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
SeeWriteCommand
ReadCommandResponse
TAreturnsthecurrentmodeandthecurrentlyselectedoperator.Ifno

---

## Page 47

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 47/281
AT+COPS? operatorisselected,<format>and<oper>areomitted.
+COPS:<mode>[,<format>,<oper>,<netact>]
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
SeeWriteCommand
WriteCommand
AT+COPS=<mode>,[<f
ormat>[,<oper>]]Response
TAforcesanattempttoselectandregistertheGSMnetworkoperator.Ifthe
selectedoperatorisnotavailable,nootheroperatorshallbeselected
(except<mode>=4).Theselectedoperatornameformatshallapplyto
furtherreadcommands(AT+COPS?).
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<stat>0Unknown
1Operatoravailable
2Operatorcurrent
3Operatorforbidden
<oper>Referto[27.007]
operatorinformatasper<format>
<mode>0Automaticmode;<oper>fieldisignored
1Manual(<oper>fieldshallbepresent,and<AcT>optionally)
2manualderegisterfromnetwork
3setonly<format>(forreadCommand+COPS?)-not
showninReadCommandresponse
4Manual/automatic(<oper>fieldshallbepresent);if
manualselectionfails,automaticmode(<mode>=0)is
entered
<format>0Longformatalphanumeric<oper>
1Shortformatalphanumeric<oper>
2Numeric<oper>;GSMLocationAreaIdentification
number
<netact>0User-specifiedGSMaccesstechnology
1GSMcompact
3GSMEGPRS
7User-specifiedLTEM1AGBaccesstechnology
9User-specifiedLTENBS1accesstechnology
ParameterSavingModeAUTO_SAVE
MaxResponseTimeTestcommand:45seconds
Writecommand:120seconds
Reference
3GPPTS27.007[14]Note

---

## Page 48

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 48/281
3.2.10AT+CPASPhoneActivityStatus
AT+CPASPhoneActivityStatus
TestCommand
AT+CPAS=?Response
+CPAS:(listofsupported<pas>s)
Parameters
SeeExecutionCommand
ExecutionCommand
AT+CPASResponse
TAreturnstheactivitystatusofME.
+CPAS:<pas>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<pas>
0Ready(MTallowscommandsfromTA/TE)
3Ringing(MTisreadyforcommandsfromTA/TE,buttheringeris
active)
4Callinprogress(MTisreadyforcommandsfromTA/TE,butacall
isinprogress)
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.11AT+CPINEnterPIN
AT+CPINEnterPIN
TestCommand
AT+CPIN=?Response
ReadCommand
AT+CPIN?Response
TAreturnsanalphanumericstringindicatingwhethersomepasswordis
requiredornot.
+CPIN:<code>

---

## Page 49

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 49/281
Parameters
<code>
READYMTisnotpendingforanypassword
SIMPINMTiswaitingSIMPINtobegiven
SIMPUKMTiswaitingforSIMPUKtobegiven
PH_SIMPINMEiswaitingforphonetoSIMcard(antitheft)
PH_SIMPUKMEiswaitingforSIMPUK(antitheft)
SIMPIN2PIN2,e.g.foreditingtheFDNbookpossibleonlyif
precedingCommandwasacknowledgedwith+CMEERROR:17
SIMPUK2PossibleonlyifprecedingCommandwas
acknowledgedwitherror+CMEERROR:18.
WriteCommand
AT+CPIN=<pin>[,<new
pin>]Response
TAstoresapasswordwhichisnecessarybeforeitcanbeoperated(SIM
PIN,SIMPUK,PH-SIMPIN,etc.).
IfthePINrequiredisSIMPUKorSIMPUK2,thesecondpinisrequired.
Thissecondpin<newpin>,isusedtoreplacetheoldpinintheSIM.
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<pin> Stringtype;password
<newpin>Stringtype;IfthePINrequiredisSIMPUKorSIMPUK2:
newpassword
ParameterSavingModeNO_SAVE
MaxResponseTime5s
Reference
3GPPTS27.007[13]Note
3.2.12AT+CPWDChangePassword
AT+CPWDChangePassword
TestCommand
AT+CPWD=?Response
TAreturnsalistofpairswhichpresenttheavailablefacilitiesandthe
maximumlengthoftheirpassword.
+CPWD:(listofsupported<fac>s,listofsupported<pwdlength>s)
Parameters
<fac> SeeWriteCommand
<pwdlength> Integermax.lengthofpassword
WriteCommand
AT+CPWD=<fac>,<oldResponse
TAsetsanewpasswordforthefacilitylockfunction.

---

## Page 50

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 50/281
pwd>,<newpwd> Parameters
<fac>
"AB"AllBarringservices
"AC"AllinComingbarringservices(onlyfor
<mode>=0)
"AG"AlloutGoingbarringservices(onlyfor
<mode>=0)
"AI"BAIC(BarrAllIncomingCalls)
"AO"BAOC(BarrAllOutgoingCalls)
"IR"BIC-Roam(BarrIncomingCallswhen
Roamingoutsidethehomecountry)
"OI"BOIC(BarrOutgoingInternationalCalls)
"OX"BOIC-exHC(BarrOutgoingInternationalCalls
excepttoHomeCountry)
"SC"SIM(lockSIM/UICCcard)(SIM/UICCasks
passwordinMTpower-upandwhenthislock
commandissued)CorrespondtoPIN1code.
"P2"SIMPIN2
<oldpwd>Stringtype(stringshouldbeincludedinquotationmarks):
passwordspecifiedforthefacilityfromtheuserinterfaceorwithcommand.
Ifanoldpasswordhasnotyetbeenset,<oldpwd>isnottoenter.
<newpwd>Stringtype(stringshouldbeincludedinquotationmarks):
newpassword
ParameterSavingModeNO_SAVE
MaxResponseTime15s
Reference
3GPPTS27.007[13]Note
3.2.13AT+CRCSetCellularResultCodesforIncomingCallIndication
AT+CRCSetCellularResultCodesforIncomingCallIndication
TestCommand
AT+CRC=?Response
+CRC:(listofsupported<mode>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CRC?Response
+CRC:<mode>
Parameters
SeeWriteCommand

---

## Page 51

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 51/281
WriteCommand
AT+CRC=[<mode>]Response
TAcontrolswhetherornottheextendedformatofincomingcallindicationis
used.
Parameters
<mode>0Disableextendedformat
1Enableextendedformat
OmittedUsepreviousvalue
UnsolicitedResultCode
Whenenabled,anincomingcallisindicatedtotheTEwithunsolicitedresult
code+CRING:<type>insteadofthenormalRING.
Parameters
<type>ASYNCAsynchronoustransparent
SYNCSynchronoustransparent
RELASYNCAsynchronousnon-transparent
RELSYNCSynchronousnon-transparent
FAX Facsimile
VOICEVoice
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.14AT+CREGNetworkRegistration
AT+CREGNetworkRegistration
TestCommand
AT+CREG=?Response
+CREG:(listofsupported<n>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CREG?Response
TAreturnsthestatusofresultcodepresentationandaninteger<stat>
whichshowswhetherthenetworkhascurrentlyindicatedtheregistrationof
theME.Locationinformationelements<lac>and<ci>arereturnedonly
when<n>=2andMEisregisteredinthenetwork.
+CREG:<n>,<stat>[,<lac>,<ci>,<netact>]
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
WriteCommand Response

---

## Page 52

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 52/281
AT+CREG[=<n>] TAcontrolsthepresentationofanunsolicitedresultcode+CREG:<stat>
when<n>=1andthereisachangeintheMEnetworkregistrationstatus.
Parameters
<n> 0Disablenetworkregistrationunsolicitedresultcode
1Enablenetworkregistrationunsolicitedresultcode
+CREG:<stat>
2Enablenetworkregistrationunsolicitedresultcodewith
locationinformation(2isonlyfor7000seriesmodulewhich
supportGPRS.)
CREG:<stat>[,<lac>,<ci>,<netact>]
<stat>0Notregistered,MTisnotcurrentlysearchinganew
operatortoregisterto
1Registered,homenetwork
2Notregistered,butMTiscurrentlysearchinganew
operatortoregisterto
3Registrationdenied
4Unknown
5Registered,roaming
<lac>Stringtype(stringshouldbeincludedinquotationmarks);two
bytelocationareacodeinhexadecimalformat
<ci> Stringtype(stringshouldbeincludedinquotationmarks);two
bytecellIDinhexadecimalformat
<netact>0User-specifiedGSMaccesstechnology
1GSMcompact
3GSMEGPRS
7User-specifiedLTEM1AGBaccesstechnology
9User-specifiedLTENBS1accesstechnology
UnsolicitedResultCode
If<n>=1andthereisachangeintheMTnetworkregistrationstatus
+CREG:<stat>
If<n>=2andthereisachangeintheMTnetworkregistrationstatusora
changeofthenetworkcell:
+CREG:<stat>[,<lac>,<ci>,<netact>]
Parameters
SeeWriteCommand
ParameterSavingMode-
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.15AT+CRSMRestrictedSIMAccess

---

## Page 53

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 53/281
AT+CRSMRestrictedSIMAccess
TestCommand
AT+CRSM=?Response
WriteCommand
AT+CRSM=<Command
>[,<fileId>[,<P1>,<P2>,
<P3>[,<data>]]]Response
+CRSM:<sw1>,<sw2>[,<response>]
ERROR
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<Command>
176READBINARY
178READRECORD
192GETRESPONSE
214UPDATEBINARY
220UPDATERECORD
242STATUS
Allothervaluesarereserved;referGSM11.11.
<fileId>Integertype;thisistheidentifierforanelementarydatafileon
SIM.MandatoryforeveryCommandexceptSTATUS
<P1>,<P2>,<P3>Integertype,range0–255
ParameterstobepassedonbytheMEtotheSIM;referGSM
11.11.
<data>InformationwhichshallbewrittentotheSIM(hex-decimal
characterformat)
<sw1>,<sw2>Integertype,range0-255
StatusinformationfromtheSIMabouttheexecutionofthe
actualCommand.TheseparametersaredeliveredtotheTEin
bothcases,onsuccessfulorfailedexecutionoftheCommand;
referGSM11.11.
<response>ResponseofasuccessfulcompletionoftheCommand
previouslyissued(hexadecimalcharacterformat)
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007
GSM11.11Note
3.2.16AT+CSQSignalQualityReport
AT+CSQSignalQualityReport
TestCommand
AT+CSQ=?Response
+CSQ:(listofsupported<rssi>s),(listofsupported<ber>s)

---

## Page 54

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 54/281
ExecutionCommand
AT+CSQResponse
+CSQ:<rssi>,<ber>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
ExecutionCommandreturnsreceivedsignalstrengthindication<rssi>and
channelbiterrorrate<ber>fromtheME.TestCommandreturnsvalues
supportedbytheTA.
Parameters
<rssi>
0-115dBmorless
1-111dBm
2...30-110...-54dBm
31-52dBmorgreater
99notknownornotdetectable
<ber>(inpercent):
0...7AsRXQUALvaluesinthetableinGSM05.08[20]
subclause7.2.4
99Notknownornotdetectable
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.17AT+CPOLPreferredOperatorList
AT+CPOLPreferredOperatorList
TestCommand
AT+CPOL=?Response
+CPOL:(listofsupported<index>s),(listofsupported<format>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CPOL?Response
+CPOL:
<index1>,<format>,<oper1>[,<GSM>,<GSM_compact>,<UTRAN>,<E-U
TRAN>][<CR><LF>+CPOL:
<index2>,<format>,<oper2>[,<GSM,<GSM_compact>,<UTRAN>,<E-UT
RAN>][…]]

---

## Page 55

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 55/281
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
SeeWriteCommand
WriteCommand
AT+CPOL=<index>[,<f
ormat>[,<oper>[<GSM
>,<GSM_compact>,<U
TRAN>,<E-UTRAN>]]]Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<index>Integertype:ordernumberofoperatorinSIMpreferred
operatorlist
<format>Indicateswhetheralphanumericornumeric
formatused(see+COPSCommand)
0Longformatalphanumeric<oper>
1Shortformatalphanumeric<oper>
2Numeric<oper>
<oper>Stringtype(stringshouldbeincludedinquotationmarks)
<GSM>GSMaccesstechnology
0 Accesstechnologyisnotselected
1 Accesstechnologyisselected
<GSM_compact>GSMcompactaccesstechnology
0Accesstechnologyisnotselected
1Accesstechnologyisselected
<UTRAN> UTRANaccesstechnology
0Accesstechnologyisnotselected
1Accesstechnologyisselected
<E-UTRAN>E-UTRANaccesstechnology
0Accesstechnologyisnotselected
1Accesstechnologyisselected
ParameterSavingMode-
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.18AT+COPNReadOperatorNames
AT+COPNReadOperatorNames
TestCommand
AT+COPN=?Response
ExecutionCommandResponse

---

## Page 56

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 56/281
AT+COPN +COPN:<numeric1>,<alpha1>
[<CR><LF>+COPN:<numeric2>,<alpha2>
[…]]
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<numericn>Stringtype(stringshouldbeincludedinquotationmarks):
operatorinnumericformat(see+COPS)
<alphan>Stringtype(stringshouldbeincludedinquotationmarks):
operatorinlongalphanumericformat(see+COPS)
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.19AT+CFUNSetPhoneFunctionality
AT+CFUNSetPhoneFunctionality
TestCommand
AT+CFUN=?Response
+CFUN:(listofsupported<fun>s),(listofsupported<rst>s)
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
SeeWriteCommand
ReadCommand
AT+CFUN?Response
+CFUN:<fun>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
SeeWriteCommand
WriteCommand
AT+CFUN=<fun>[,<rst
>]Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<fun>

---

## Page 57

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 57/281
0Minimumfunctionality
1Fullfunctionality(Default)
4DisablephonebothtransmitandreceiveRFcircuits.
5FactoryTestMode
6Reset
7OfflineMode
<rst>
0DonotResettheMTbeforesettingitto<fun>powerlevel.
1ResettheMTbeforesettingitto<fun>powerlevel.
ParameterSavingMode-
MaxResponseTime10s
Reference
3GPPTS27.007[13]Note
The<fun>powerlevelwillbewrittentoflashexceptminimum
functionality.
AT+CFUN=1,1canbeusedtoresetmodulepurposelyatminimum/full
functionalitymode.
Responsestring"OK"willbereturnedaftermoduleresetsifbaudrate
issettofixedbaudrate.
3.2.20AT+CCLKClock
AT+CCLKClock
TestCommand
AT+CCLK=?Response
ReadCommand
AT+CCLK?Response
+CCLK:<time>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
SeeWriteCommand
WriteCommand
AT+CCLK=<time>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<time>Stringtype(stringshouldbeincludedinquotationmarks)value;
formatis"yy/MM/dd,hh:mm:ss±zz",wherecharactersindicateyear(twolast
digits),month,day,hour,minutes,secondsandtimezone(indicatesthe
difference,expressedinquartersofanhour,betweenthelocaltimeand
GMT;range-47...+48).E.g.6thofMay2010,00:01:52GMT+2hours

---

## Page 58

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 58/281
equalsto"10/05/06,00:01:52+08".
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
Onlytimezoneisautosaved.
3.2.21AT+CSIMGenericSIMAccess
AT+CSIMGenericSIMAccess
TestCommand
AT+CSIM=?Response
WriteCommand
AT+CSIM=<length>,<C
ommand>Response
+CSIM:<length>,<response>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<length>Integertype:lengthofcharacterssenttotheTEin
<Command>or<response>(i.e.twicethenumberofoctetsintheraw
data).
<Command>Stringtype(stringshouldbeincludedinquotationmarks):
hexformat:GSM11.11SIMCommandsentfromtheMEtotheSIM.
<response>Stringtype(stringshouldbeincludedinquotationmarks):
hexformat:GSM11.11responsefromSIMto<Command>.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.22AT+CBCBatteryCharge
AT+CBCBatteryCharge
TestCommand
AT+CBC=?Response
+CBC:(listofsupported<bcs>s),(listofsupported<bcl>s),(<voltage>)
Parameters
SeeExecutionCommand
ExecutionCommandResponse

---

## Page 59

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 59/281
AT+CBC +CBC:<bcs>,<bcl>,<voltage>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<bcs>Chargestatus
0MEisnotcharging
1MEischarging
2Charginghasfinished
<bcl>Batteryconnectionlevel
1...100batteryhas1-100percentofcapacityremainingvent
<voltage>Batteryvoltage(mV)
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note
3.2.23AT+CUSDUnstructuredSupplementaryServiceData
AT+CUSDUnstructuredSupplementaryServiceData
TestCommand
AT+CUSD=?Response
+CUSD:(listofsupported<n>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CUSD?Response
+CUSD:<n>
Parameters
SeeWriteCommand
WriteCommand
AT+CUSD=<n>,<str>,<
dcs>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<n>Anumericparameterwhichindicatescontroloftheunstructured
supplementaryservicedata
0disabletheresultcodepresentationintheTE
1enabletheresultcodepresentationintheTE
2cancelsession(notapplicabletoreadCommandresponse)

---

## Page 60

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 60/281
<str>Stringtype(stringshouldbeincludedinquotationmarks)
USSD-string
<dcs>CellBroadcastDataCodingSchemeinintegerformat
(default0)
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
GSM03.38[25]Note
Whenussdisnotsuportorreturnerror,TEwillprint+CUSD:4.
3.2.24AT+CNUMSubscriberNumber
AT+CNUMSubscriberNumber
TestCommand
AT+CNUM=?Response
ExecutionCommand
AT+CNUMResponse
+CNUM:"",<number1>,<type1>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<numberx>Stringtype(stringshouldbeincludedinquotationmarks)
phonenumberofformatspecifiedby<typex>
<typex>Typeofaddressoctetinintegerformat(referGSM04.08[8]
subclause10.5.4.7)
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.007[13]Note

---

## Page 61

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 61/281
4ATCommandsAccordingto3GPP
TS27.005
The3GPPTS27.005commandsareforperformingSMSandCBSrelatedoperations.SIM7000Series
supportsbothTextandPDUmodes.
4.1OverviewofATCommandsAccordingto3GPPTS27.005
Command Description
AT+CMGD DeleteSMSmessage
AT+CMGF SelectSMSmessageformat
AT+CMGL ListSMSmessagesfrompreferredstore
AT+CMGR ReadSMSmessage
AT+CMGS SendSMSmessage
AT+CMGW WriteSMSmessagetomemory
AT+CMSS SendSMSmessagefromstorage
AT+CNMI NewSMSmessageindications
AT+CPMS PreferredSMSmessagestorage
AT+CRES RestoreSMSsettings
AT+CSAS SaveSMSsettings
AT+CSCA SMSservicecenteraddress
AT+CSDH ShowSMStextmodeparameters
AT+CSMP SetSMStextmodeparameters
AT+CSMS Selectmessageservice
4.2DetailedDescriptionsofATCommandsAccordingto3GPPTS
27.005
4.2.1AT+CMGDDeleteSMSMessage
AT+CMGDDeleteSMSMessage
TestCommand Response

---

## Page 62

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 62/281
AT+CMGD=? +CMGD:(listofsupported<index>s),(listofsupported<delflag>s)
Parameters
SeeWriteCommand
WriteCommand
AT+CMGD=<index>[,<
delflag>]Response
TAdeletesmessagefrompreferredmessagestorage<mem1>location
<index>.
ERROR
IferrorisrelatedtoMEfunctionality:
+CMSERROR:<err>
Parameters
<index>Integertype;valueintherangeoflocationnumberssupportedby
theassociatedmemory
<delflag>0Deletethemessagespecifiedin<index>
1Deleteallreadmessagesfrompreferredmessagestorage,
leavingunreadmessagesandstoredmobileoriginated
messages(whethersentornot)untouched
2Deleteallreadmessagesfrompreferredmessagestorage
andsentmobileoriginatedmessages,leavingunread
messagesandunsentmobileoriginatedmessages
untouched
3Deleteallreadmessagesfrompreferredmessagestorage,
sentandunsentmobileoriginatedmessagesleaving
unreadmessagesuntouched
4Deleteallmessagesfrompreferredmessagestorage
includingunreadmessages
ParameterSavingModeNO_SAVE
MaxResponseTime5s(delete1message)
25s(delete50messages)
25s(delete150messages)
Reference
3GPPTS27.005Note
4.2.2AT+CMGFSelectSMSMessageFormat
AT+CMGFSelectSMSMessageFormat
TestCommand
AT+CMGF=?Response
+CMGF:(listofsupported<mode>s)
Parameter

---

## Page 63

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 63/281
SeeWriteCommand
ReadCommand
AT+CMGF?Response
+CMGF:<mode>
Parameter
SeeWriteCommand
WriteCommand
AT+CMGF=[<mode>]Response
TAsetsparametertodenotewhichinputandoutputformatofmessagesto
use.
Parameter
<mode>0PDUmode
1Textmode
ParameterSavingMode-
MaxResponseTime-
Reference
3GPPTS27.005Note
4.2.3AT+CMGLListSMSMessagesfromPreferredStore
AT+CMGLListSMSMessagesfromPreferredStore
TestCommand
AT+CMGL=?Response
+CMGL:(listofsupported<stat>s)
Parameter
SeeWriteCommand
WriteCommand
AT+CMGL=<stat>[,<m
ode>]Parameters
1)Iftextmode:
<stat>"RECUNREAD"Receivedunreadmessages
"RECREAD"Receivedreadmessages
"STOUNSENT"Storedunsentmessages
"STOSENT"Storedsentmessages
"ALL" Allmessages
<mode>0Normal
1NotchangestatusofthespecifiedSMSrecord
2)IfPDUmode:
<stat>0Receivedunreadmessages
1Receivedreadmessages
2Storedunsentmessages
3Storedsentmessages
4Allmessages

---

## Page 64

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 64/281
<mode>0Normal
1NotchangestatusofthespecifiedSMSrecord
Response
TAreturnsmessageswithstatusvalue<stat>frommessagestorage
<mem1>totheTE.Ifstatusofthemessageis'receivedunread',statusin
thestoragechangesto'receivedread'.
1)Iftextmode(+CMGF=1)andCommandsuccessful:
forSMS-SUBMITsand/orSMS-DELIVERs:
+CMGL:<index>,<stat>,<oa/da>[,<alpha>][,<scts>]
[,<tooa/toda>,<length>]<CR><LF><data>
[<CR><LF>+CMGL:<index>,<stat>,<da/oa>
[,<alpha>][,<scts>][,<tooa/toda>,<length>]<CR><LF><data>[...]]
forSMS-STATUS-REPORTs:
+CMGL:<index>,<stat>,<fo>,<mr>[,<ra>][,<tora>],<scts>,<dt>,<st>
[<CR><LF>+CMGL:<index>,<stat>,<fo>,<mr>
[,<ra>][,<tora>],<scts>,<dt>,<st>[...]]
forSMS-COMMANDs:
+CMGL:<index>,<stat>,<fo>,<ct>[<CR><LF>
+CMGL:<index>,<stat>,<fo>,<ct>[...]]
forCBMstorage:
+CMGL:<index>,<stat>,<sn>,<mid>,<page>,<pages>
<CR><LF><data>
<CR><LF>+CMGL:<index>,<stat>,<sn>,<mid>,<page>,<pages>
<CR><LF><data>[...]]
2)IfPDUmode(+CMGF=0)andCommandsuccessful:
+CMGL:<index>,<stat>[,<alpha>],<length>
<CR><LF><pdu><CR><LF>
+CMGL:<index>,<stat>[,alpha],<length>
<CR><LF><pdu>[...]]
3)IferrorisrelatedtoMEfunctionality:
+CMSERROR:<err>
Parameters
<alpha>Stringtype(stringshouldbeincludedinquotationmarks)
alphanumericrepresentationof<da>or<oa>correspondingtotheentry
foundinMTphonebook;implementationofthisfeatureismanufacturer
specific;usedcharactersetshouldbetheoneselectedwithCommand
SelectTECharacterSet+CSCS(seedefinitionofthisCommandin3GPP

---

## Page 65

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 65/281
TS27.007)
<da>GSM03.40TP-Destination-AddressAddress-Valuefieldin
stringformat;BCDnumbers(orGSMdefaultalphabetcharacters)are
convertedtocharactersofthecurrentlyselectedTEcharacterset(refer
Command+CSCSin3GPPTS27.007);typeofaddressgivenby<toda>
<data>InthecaseofSMS:GSM03.40TP-User-Dataintextmode
responses;format:
-if<dcs>indicatesthatGSM03.38defaultalphabetisusedand
<fo>indicatesthatGSM03.40TPUser-Data-Header-Indication
isnotset:
-ifTEcharactersetotherthan"HEX"(referCommandSelectTE
CharacterSet+CSCSin3GPPTS27.007):ME/TAconverts
GSMalphabetintocurrentTEcharactersetaccordingtorulesof
AnnexA
-ifTEcharactersetis"HEX":ME/TAconvertseach7-bit
characterofGSMalphabetintotwoIRAcharacterlong
hexadecimalnumber(e.g.characterP(GSM23)ispresentedas
17(IRA49and55))
-if<dcs>indicatesthat8-bitorUCS2datacodingschemeis
used,or<fo>indicatesthatGSM03.40
TP-User-Data-Header-Indicationisset:ME/TAconvertseach
8-bitoctetintotwoIRAcharacterlonghexadecimalnumber(e.g.
octetwithintegervalue42ispresentedtoTEastwocharacters
2A(IRA50and65))InthecaseofCBS:GSM03.41CBM
ContentofMessageintextmoderesponses;format:
-if<dcs>indicatesthatGSM03.38defaultalphabetisused:
-ifTEcharactersetotherthan"HEX"(referCommand+CSCSin
3GPPTS27.007):ME/TAconvertsGSMalphabetintocurrent
TEcharactersetaccordingtorulesofAnnexA
-ifTEcharactersetis"HEX":ME/TAconvertseach7-bit
characterofGSMalphabetintotwoIRAcharacterlong
hexadecimalnumber
-if<dcs>indicatesthat8-bitorUCS2datacodingschemeis
used:ME/TAconvertseach8-bitoctetintotwoIRAcharacter
longhexadecimalnumber
<length>Integertypevalueindicatinginthetextmode(+CMGF=1)the
lengthofthemessagebody<data>(or<cdata>)incharacters;orinPDU
mode(+CMGF=0),thelengthoftheactualTPdataunitinoctets(i.e.theRP
layerSMSCaddressoctetsarenotcountedinthelength)
<index>Integertype;valueintherangeoflocationnumberssupported
bytheassociatedmemory
<oa>GSM03.40TP-Originating-AddressAddress-Valuefieldin
stringformat;BCDnumbers(orGSMdefaultalphabetcharacters)are
convertedtocharactersofthecurrentlyselectedTEcharacterset(refer
Command+CSCSin3GPPTS27.007);typeofaddressgivenby<tooa>
<pdu>InthecaseofSMS:GSM04.11SCaddressfollowedby

---

## Page 66

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 66/281
GSM03.40TPDUinhexadecimalformat:ME/TAconvertseachoctetofTP
dataunitintotwoIRAcharacterlonghexadecimalnumber(e.g.octetwith
integervalue42ispresentedtoTEastwocharacters2A(IRA50and65)).
InthecaseofCBS:GSM03.41TPDUinhexadecimalformat.
<scts>GSM03.40TP-Service-Center-Time-Stampintime-string
format(refer<dt>)
<toda>GSM04.11TP-Destination-AddressType-of-Addressoctetin
integerformat(whenfirstcharacterof<da>is+(IRA43)defaultis145,
otherwisedefaultis129)
<tooa>GSM04.11TP-Originating-AddressType-of-Addressoctetin
integerformat(defaultrefer<toda>)
ExecutionCommand
AT+CMGL1)Iftextmode:
thesameasAT+CMGL="RECUNREAD",receivedunreadmessages
2)IfPDUmode:
thesameasAT+CMGL=0,receivedunreadmessages
SeemoremessagespleaserefertoWriteCommand.
Parameters
SeeWriteCommand
ParameterSavingModeNO_SAVE
MaxResponseTime20s(list50messages)
20s(list150messages)
Reference
3GPPTS27.005Note
4.2.4AT+CMGRReadSMSMessage
AT+CMGRReadSMSMessage
TestCommand
AT+CMGR=?Response
WriteCommand
AT+CMGR=<index>[,<
mode>]Parameters
<index>Integertype;valueintherangeoflocationnumberssupported
bytheassociatedmemory
<mode>0Normal
1NotchangestatusofthespecifiedSMSrecord
Response
TAreturnsSMSmessagewithlocationvalue<index>frommessage
storage<mem1>totheTE.Ifstatusofthemessageis'receivedunread',
statusinthestoragechangesto'receivedread'.
1)Iftextmode(+CMGF=1)andCommandsuccessful:
forSMS-DELIVER:
+CMGR:<stat>,<oa>[,<alpha>],<scts>[,<tooa>,<fo>,<pid>,<dcs>

---

## Page 67

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 67/281
,<sca>,<tosca>,<length>]<CR><LF><data>
forSMS-SUBMIT:
+CMGR:<stat>,<da>[,<alpha>][,<toda>,<fo>,<pid>,<dcs>[,<vp>]
,<sca>,<tosca>,<length>]<CR><LF><data>
forSMS-STATUS-REPORTs:
+CMGR:<stat>,<fo>,<mr>[,<ra>][,<tora>],<scts>,<dt>,<st>
forSMS-COMMANDs:
+CMGR:<stat>,<fo>,<ct>[,<pid>[,<mn>][,<da>][,<toda>]
,<length><CR><LF><cdata>]
forCBMstorage:
+CMGR:<stat>,<sn>,<mid>,<dcs>,<page>,<pages><CR><LF><data>
2)IfPDUmode(+CMGF=0)andCommandsuccessful:
+CMGR:<stat>[,<alpha>],<length><CR><LF><pdu>
3)IferrorisrelatedtoMEfunctionality:
+CMSERROR:<err>
Parameters
<alpha>Stringtype(stringshouldbeincludedinquotationmarks)
alphanumericrepresentationof<da>or<oa>correspondingtotheentry
foundinMTphonebook;implementationofthisfeatureismanufacturer
specific
<da>GSM03.40TP-Destination-AddressAddress-Valuefieldin
stringformat;BCDnumbers(orGSMdefaultalphabetcharacters)are
convertedtocharactersofthecurrentlyselectedTEcharacterset(specified
by+CSCSin3GPPTS27.007);typeofaddressgivenby<toda>
<data>InthecaseofSMS:GSM03.40TP-User-Dataintextmode
responses;format:
-if<dcs>indicatesthatGSM03.38defaultalphabetisusedand
<fo>indicatesthatGSM03.40TPUser-Data-Header-Indication
isnotset:
-ifTEcharactersetotherthan"HEX"(referCommandSelectTE
CharacterSet+CSCSin3GPPTS27.007):ME/TAconverts
GSMalphabetintocurrentTEcharactersetaccordingtorulesof
AnnexA
-ifTEcharactersetis"HEX":ME/TAconvertseach7-bit
characterofGSMalphabetintotwoIRAcharacterlong
hexadecimalnumber(e.g.characterP(GSM23)ispresentedas
17(IRA49and55))
-if<dcs>indicatesthat8-bitorUCS2datacodingschemeis
used,or<fo>indicatesthatGSM03.40
TP-User-Data-Header-Indicationisset:ME/TAconvertseach
8-bitoctetintotwoIRAcharacterlonghexadecimalnumber(e.g.

---

## Page 68

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 68/281
octetwithintegervalue42ispresentedtoTEastwocharacters
2A(IRA50and65))InthecaseofCBS:GSM03.41CBM
ContentofMessageintextmoderesponses;format:
-if<dcs>indicatesthatGSM03.38defaultalphabetisused:
-ifTEcharactersetotherthan"HEX"(referCommand+CSCSin
3GPPTS27.007):ME/TAconvertsGSMalphabetintocurrent
TEcharactersetaccordingtorulesofAnnexA
-ifTEcharactersetis"HEX":ME/TAconvertseach7-bit
characterofGSMalphabetintotwoIRAcharacterlong
hexadecimalnumber
-if<dcs>indicatesthat8-bitorUCS2datacodingschemeis
used:ME/TAconvertseach8-bitoctetintotwoIRAcharacter
longhexadecimalnumber
<dcs>DependingontheCommandorresultcode:GSM03.38SMS
DataCodingScheme(default0),orCellBroadcastDataCodingSchemein
integerformat
<fo>DependingontheCommandorresultcode:firstoctetofGSM
03.40SMS-DELIVER,SMS-SUBMIT(default17),
SMS-STATUS-REPORT,orSMS-COMMAND(default2)inintegerformat
<length>integertypevalueindicatinginthetextmode(+CMGF=1)the
lengthofthemessagebody<data>(or<cdata>)incharacters;orin
PDUmode(+CMGF=0),thelengthoftheactualTPdataunitinoctets(i.e.
theRPlayerSMSCaddressoctetsarenotcountedinthelength)
<mid>GSM03.41CBMMessageIdentifierinintegerformat
<oa>GSM03.40TP-Originating-AddressAddress-Valuefieldin
stringformat;BCDnumbers(orGSMdefaultalphabetcharacters)are
convertedcharactersofthecurrentlyselectedTEcharacterset(specified
by+CSCSin3GPPTS27.007);typeofaddressgivenby<tooa>
<pdu>InthecaseofSMS:GSM04.11SCaddressfollowedbyGSM
03.40TPDUinhexadecimalformat:ME/TAconvertseachoctetofTPdata
unitintotwoIRAcharacterlonghexadecimalnumber(e.g.octetwithinteger
value42ispresentedtoTEastwocharacters2A(IRA50and65)).Inthe
caseofCBS:GSM03.41TPDUinhexadecimalformat.
<pid>GSM03.40TP-Protocol-Identifierinintegerformat
(default0)
<sca>GSM04.11RPSCaddressAddress-Valuefieldinstring
format;BCDnumbers(orGSMdefaultalphabetcharacters)areconverted
tocharactersofthecurrentlyselectedTEcharacterset(specifiedby
+CSCSin3GPPTS27.007);typeofaddressgivenby<tosca>
<scts>GSM03.40TP-Service-Centre-Time-Stampintime-string
format(refer<dt>)
<stat>0"RECUNREAD"Receivedunreadmessages
1"RECREAD"Receivedreadmessages
2"STOUNSENT"Storedunsentmessages
3"STOSENT"Storedsentmessages
4"ALL" Allmessages

---

## Page 69

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 69/281
<toda>GSM04.11TP-Destination-AddressType-of-Addressoctet
inintegerformat(whenfirstcharacterof<da>is+(IRA43)defaultis145,
otherwisedefaultis129)
<tooa>GSM04.11TP-Originating-AddressType-of-Addressoctetin
integerformat(defaultrefer<toda>)
<tosca>GSM04.11RPSCaddressType-of-Addressoctetininteger
format(defaultrefer<toda>)
<vp>DependingonSMS-SUBMIT<fo>setting:GSM03.40
TP-Validity-Periodeitherinintegerformat(default167)orintime-string
format(refer<dt>)
ParameterSavingModeNO_SAVE
MaxResponseTime5s
Reference
3GPPTS27.005Note
4.2.5AT+CMGSSendSMSMessage
AT+CMGSSendSMSMessage
TestCommand
AT+CMGS=?Response
WriteCommand
1)Iftextmode
(+CMGF=1):
AT+CMGS=<da>[,<tod
a>]
<CR>textisentered
<ctrl-Z/ESC>
ESCquitswithout
sending
2)IfPDUmode
(+CMGF=0):
AT+CMGS=<length>
<CR>PDUisgiven
<ctrl-Z/ESC>Parameters
<da> GSM03.40TP-Destination-AddressAddress-Valuefieldin
stringformat(stringshouldbeincludedinquotationmarks);BCDnumbers
(orGSMdefaultalphabetcharacters)areconvertedtocharactersofthe
currentlyselectedTEcharacterset(specifiedby+CSCSin3GPPTS
27.007);typeofaddressgivenby<toda>
<toda>GSM04.11TP-Destination-AddressType-of-Addressoctetin
integerformat(whenfirstcharacterof<da>is+(IRA43)defaultis145,
otherwisedefaultis129)
<length>Integertypevalue(notexceed160bytes)indicatinginthetext
mode(+CMGF=1)thelengthofthemessagebody<data>(or<cdata>)in
characters;orinPDUmode(+CMGF=0),thelengthoftheactualTPdata
unitinoctets(i.e.theRPlayerSMSCaddressoctetsarenotcountedinthe
length)
Response
TAsendsmessagefromaTEtothenetwork(SMS-SUBMIT).Message
referencevalue<mr>isreturnedtotheTEonsuccessfulmessagedelivery.
Optionally(when+CSMS<service>valueis1andnetworksupports)
<scts>isreturned.Valuescanbeusedtoidentifymessageupon
unsoliciteddeliverystatusreportresultcode.
1)Iftextmode(+CMGF=1)andsendingsuccessful:
+CMGS:<mr>

---

## Page 70

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 70/281
2)IfPDUmode(+CMGF=0)andsendingsuccessful:
+CMGS:<mr>
3)IferrorisrelatedtoMEfunctionality:
+CMSERROR:<err>
Parameter
<mr>GSM03.40TP-Message-Referenceinintegerformat
ParameterSavingModeNO_SAVE
MaxResponseTime60s
Reference
3GPPTS27.005Note
Rejectincomingcallwhensendingmessages.
4.2.6AT+CMGWWriteSMSMessagetoMemory
AT+CMGWWriteSMSMessagetoMemory
TestCommand
AT+CMGW=?Response
WriteCommand
1)Iftextmode
(+CMGF=1):
AT+CMGW=<oa/da>[,<
tooa/toda>][,<stat>]
<CR>textisentered
<ctrl-Z/ESC>
<ESC>quitswithout
sending
2)IfPDUmode
(+CMGF=0):
AT+CMGW=<length>[,
<stat>]
<CR>PDUisgiven
<ctrl-Z/ESC>Response
TAtransmitsSMSmessage(eitherSMS-DELIVERorSMS-SUBMIT)from
TEtomemorystorage<mem2>.Memorylocation<index>ofthestored
messageisreturned.Bydefaultmessagestatuswillbesetto'stored
unsent',butparameter<stat>allowsalsootherstatusvaluestobegiven.
Ifwritingissuccessful:
+CMGW:<index>
IferrorisrelatedtoMEfunctionality:
+CMSERROR:<err>
Parameters
<oa>GSM03.40TP-Originating-AddressAddress-Valuefieldin
stringformat(stringshouldbeincludedinquotationmarks);BCDnumbers
(orGSMdefaultalphabetcharacters)areconvertedtocharactersofthe
currentlyselectedTEcharacterset(specifiedby+CSCSin3GPPTS
27.007);typeofaddressgivenby<tooa>
<da>GSM03.40TP-Destination-AddressAddress-Valuefieldin
stringformat(stringshouldbeincludedinquotationmarks);BCDnumbers
(orGSMdefaultalphabetcharacters)areconvertedtocharactersofthe
currentlyselectedTEcharacterset(specifiedby+CSCSin3GPPTS
27.007);typeofaddressgivenby<toda>
<tooa>GSM04.11TP-Originating-AddressType-of-Addressoctetin

---

## Page 71

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 71/281
integerformat(defaultrefer<toda>)
<toda>GSM04.11TP-Destination-AddressType-of-Addressoctetin
integerformat(whenfirstcharacterof<da>is+(IRA43)defaultis145,
otherwisedefaultis129)
129Unknowntype(IDSNformatnumber)
161Nationalnumbertype(IDSNformat)
145Internationalnumbertype(ISDNformat)
177Networkspecificnumber(ISDNformat)
<length>Integertypevalue(notexceed160bytes)indicatinginthetext
mode(+CMGF=1)thelengthofthemessagebody<data>(or<cdata>)in
characters;
orinPDUmode(+CMGF=0),thelengthoftheactualTPdata
unitinoctets(i.e.theRPlayerSMSCaddressoctetsarenot
countedinthelength)
<stat>inthetextmode(+CMGF=1):
"STOUNSENT"Storedunsentmessages
"STOSENT"Storedsentmessages
inPDUmode(+CMGF=0):
0Receivedunreadmessages
1Receivedreadmessages
2Storedunsentmessages
3Storedsentmessages
<pdu>InthecaseofSMS:GSM04.11SCaddressfollowedbyGSM
03.40TPDUinhexadecimalformat:ME/TAconvertseachoctetofTPdata
unitintotwoIRAcharacterlonghexadecimalnumber(e.g.octetwithinteger
value42ispresentedtoTEastwocharacters2A(IRA50and65)).Inthe
caseofCBS:GSM03.41TPDUinhexadecimalformat.
<index>Indexofmessageinselectedstorage<mem2>
ExecutionCommand
AT+CMGWResponse
TAtransmitsSMSmessage(eitherSMS-DELIVERorSMS-SUBMIT)from
TEtomemorystorage<mem2>.Memorylocation<index>ofthestored
messageisreturned.Bydefaultmessagestatuswillbesetto'stored
unsent',butparameter<stat>allowsalsootherstatusvaluestobegiven.
Ifwritingissuccessful:
+CMGW:<index>
IferrorisrelatedtoMEfunctionality:
+CMSERROR:<err>
ParameterSavingModeNO_SAVE
MaxResponseTime5s
Reference
3GPPTS27.005Note

---

## Page 72

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 72/281
4.2.7AT+CMSSSendSMSMessagefromStorage
AT+CMSSSendSMSMessagefromStorage
TestCommand
AT+CMSS=?Response
WriteCommand
AT+CMSS=<index>[,<
da>,<toda>]Response
TAsendsmessagewithlocationvalue<index>frommessagestorage
<mem2>tothenetwork(SMS-SUBMIT).Ifnewrecipientaddress<da>is
given,itshallbeusedinsteadoftheonestoredwiththemessage.
Referencevalue<mr>isreturnedtotheTEonsuccessfulmessage
delivery.Valuescanbeusedtoidentifymessageuponunsoliciteddelivery
statusreportresultcode.
1)Iftextmode(+CMGF=1)andsendingsuccessful:
+CMSS:<mr>
2)IfPDUmode(+CMGF=0)andsendingsuccessful:
+CMSS:<mr>
3)IferrorisrelatedtoMEfunctionality:
+CMSERROR:<err>
Parameters
<index>Integertype;valueintherangeoflocationnumberssupported
bytheassociatedmemory
<da>GSM03.40TP-Destination-AddressAddress-Valuefieldin
stringformat(stringshouldbeincludedinquotationmarks);BCDnumbers
(orGSMdefaultalphabetcharacters)areconvertedtocharactersofthe
currentlyselectedTEcharacterset(specifiedby+CSCSin3GPPTS
27.007);typeofaddressgivenby<toda>
<toda>GSM04.11TP-Destination-AddressType-of-Addressoctet
inintegerformat(whenfirstcharacterof<da>is+(IRA43)defaultis145,
otherwisedefaultis129)
<mr>GSM03.40TP-Message-Referenceinintegerformat
ParameterSavingModeNO_SAVE
MaxResponseTime60s
Reference
3GPPTS27.005Note

---

## Page 73

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 73/281
4.2.8AT+CNMINewSMSMessageIndications
AT+CNMINewSMSMessageIndications
TestCommand
AT+CNMI=?Response
+CNMI:(listofsupported<mode>s),(listofsupported<mt>s),(listof
supported<bm>s),(listofsupported<ds>s),(listofsupported<bfr>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CNMI?Response
+CNMI:<mode>,<mt>,<bm>,<ds>,<bfr>
Parameters
SeeWriteCommand
WriteCommand
AT+CNMI=<mode>[,<
mt>[,<bm>[,<ds>[,<bfr
>]]]]Response
TAselectstheprocedureforhowthereceivingofnewmessagesfromthe
networkisindicatedtotheTEwhenTEisactive,e.g.DTRsignalisON.If
TEisinactive(e.g.DTRsignalisOFF),messagereceivingshouldbedone
asspecifiedinGSM03.38.
ERROR
Parameters
<mode>0BufferunsolicitedresultcodesintheTA.IfTAresultcode
bufferisfull,indicationscanbebufferedinsomeotherplaceortheoldest
indicationsmaybediscardedandreplacedwiththenewreceived
indications.
1Discardindicationandrejectnewreceivedmessage
unsolicitedresultcodeswhenTA-TElinkisreserved(e.g.inon-linedata
mode).OtherwiseforwardthemdirectlytotheTE.
2BufferunsolicitedresultcodesintheTAwhenTA-TElink
isreserved(e.g.inon-linedatamode)andflushthemtotheTEafter
reservation.OtherwiseforwardthemdirectlytotheTE.
<mt>(therulesforstoringreceivedSMsdependonitsdatacoding
scheme(referGSM03.38[2]),preferredmemorystorage(+CPMS)setting
andthisvalue):
0NoSMS-DELIVERindicationsareroutedtotheTE.
1IfSMS-DELIVERisstoredintoME/TA,indicationofthe
memorylocationisroutedtotheTEusingunsolicitedresultcode:+CMTI:
<mem>,<index>
2SMS-DELIVERs(exceptclass2)arerouteddirectlytothe
TEusingunsolicitedresultcode:

---

## Page 74

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 74/281
+CMT:[<alpha>],<length><CR><LF><pdu>(PDUmodeenabled)
+CMT:
<oa>,[<alpha>],<scts>[,<tooa>,<fo>,<pid>,<dcs>,<sca>,<tosca>,<lengt
h>]<CR><LF><data>(textmodeenabled;aboutparametersinitalics,refer
CommandShowTextModeParameters+CSDH).Class2messagesresult
inindicationasdefinedin<mt>=1.
3Class3SMS-DELIVERsarerouteddirectlytoTE
usingunsolicitedresultcodesdefinedin<mt>=2.Messagesofother
classes
resultinindicationasdefinedin<mt>=1.
<bm>(therulesforstoringreceivedCBMsdependonitsdatacoding
scheme(referGSM03.38[2]),thesettingofSelectCBMTypes(+CSCB)
andthisvalue):
0NoCBMindicationsareroutedtotheTE.
2NewCBMsarerouteddirectlytotheTEusingunsolicited
resultcode:
+CBM:<length><CR><LF><pdu>(PDUmodeenabled)
+CBM:<sn>,<mid>,<dcs>,<page>,<pages><CR><LF><data>(text
modeenabled).
<ds>0NoSMS-STATUS-REPORTsareroutedtotheTE.
1SMS-STATUS-REPORTsareroutedtotheTEusing
unsolicitedresultcode:
+CDS:<length><CR><LF><pdu>(PDUmodeenabled)
+CDS:<fo>,<mr>[,<ra>][,<tora>],<scts>,<dt>,<st>(textmodeenabled)
2IfSMS-STATUS-REPORTisstoredintoME/TA,indication
ofthememorylocationisroutedtotheTEusingunsolicitedresultcode:
+CDSI:<mem3>,<index>
<bfr>0TAbufferofunsolicitedresultcodesdefinedwithinthis
CommandisflushedtotheTEwhen<mode>1...3isentered(OKresponse
shallbegivenbeforeflushingthecodes).
1TAbufferofunsolicitedresultcodesdefinedwithinthis
commandisclearedwhen<mode>1…3isentered
Unsolicitedresultcode
1.Indicatesthatnewmessagehasbeenreceived
If<mt>=1:
+CMTI:<mem3>,<index>
If<mt>=2(PDUmodeenabled):
+CMT:[<alpha>],<length><CR><LF><pdu>
If<mt>=2(textmodeenabled):
+CMT:
<oa>,<scts>[,<tooa>,<fo>,<pid>,<dcs>,<sca>,<tosca>,<length>]<CR><
LF><data>

---

## Page 75

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 75/281
2.Indicatesthatnewcellbroadcastmessagehasbeenreceived
If<bm>=2(PDUmodeenabled):
+CBM:<length><CR><LF><pdu>
If<bm>=2(textmodeenabled):
+CBM:<sn>,<mid>,<dcs>,<page>,<pages><CR><LF><data>
3.IndicatesthatnewSMSstatusreporthasbeenreceived
If<ds>=1(PDUmodeenabled):
+CDS:<length><CR><LF><pdu>
If<ds>=1(textmodeenabled):
+CDS:<fo>,<mr>[,<ra>][,<tora>],<scts>,<dt>,<st>
ParameterSavingMode-
MaxResponseTime-
Reference
3GPPTS27.005Note
Thiscommandisusedtoselecttheprocedurehowreceivingofnew
messagesfromthenetworkisindicatedtotheTEwhenTEisactive,
e.g.DTRsignalisON.IfTEisinactive(e.g.DTRsignalisOFF).Ifset
<mt>＝2,<mt>＝3or<ds>＝1,makesure<mode>＝1,otherwiseitwill
returnerror..
4.2.9AT+CPMSPreferredSMSMessageStorage
AT+CPMSPreferredSMSMessageStorage
TestCommand
AT+CPMS=?Response
+CPMS:(listofsupported<mem1>s),(listofsupported<mem2>s),(listof
supported<mem3>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CPMS?Response
+CPMS:<mem1>,<used1>,<total1>,<mem2>,<used2>,<total2>,
<mem3>,<used3>,<total3>
ERROR
Parameters
SeeWriteCommand
WriteCommand
AT+CPMS=<mem1>[,<
mem2>[,<mem3>]]Response
TAselectsmemorystorages<mem1>,<mem2>and<mem3>tobeusedfor
reading,writing,etc.
+CPMS:<used1>,<total1>,<used2>,<total2>,<used3>,<total3>

---

## Page 76

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 76/281
ERROR
Parameters
<mem1>Messagestobereadanddeletedfromthismemorystorage
"SM"SIMmessagestorage
<mem2>Messageswillbewrittenandsenttothismemorystorage
"SM"SIMmessagestorage
<mem3>Receivedmessageswillbeplacedinthismemorystorageif
routingtoPCisnotset("+CNMI")
"SM"SIMmessagestorage
<usedx>Integertype;Numberofmessagescurrentlyin<memx>
<totalx>Integertype;Numberofmessagesstorablein<memx>
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.005Note
4.2.10AT+CRESRestoreSMSSettings
AT+CRESRestoreSMSSettings
TestCommand
AT+CRES=?Response
+CRES:listofsupported<profile>s
Parameter
SeeWriteCommand
WriteCommand
AT+CRES=<profile>Response
Executioncommandrestoresmessageservicesettingsfromnon-volatile
memorytoactivememory.ATAcancontainseveralprofilesofsettings.
SettingsspecifiedincommandsServiceCentreAddress+CSCAandSet
MessageParameters+CSMParerestored.Certainsettingsmaynotbe
supportedbythestorage(e.g.(U)SIMSMSparameters)andthereforecan
notberestored.
ERROR
Parameter
<profile>0RestoreSMservicesettingsfromprofile0
ExecutionCommand
AT+CRESResponse
SameasAT+CRES=0.
IferrorisrelatedtoMEfunctionality:
+CMSERROR<err>
ParameterSavingModeNO_SAVE

---

## Page 77

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 77/281
MaxResponseTime5s
Reference
3GPPTS27.005Note
4.2.11AT+CSASSaveSMSSettings
AT+CSASSaveSMSSettings
TestCommand
AT+CSAS=?Response
+CSAS:listofsupported<profile>s
Parameter
SeeWriteCommand
WriteCommand
AT+CSAS=<profile>Response
Executioncommandsavesactivemessageservicesettingstoa
non-volatilememory.SettingsspecifiedincommandsServiceCentre
Address+CSCAandSetMessageParameters+CSMParesaved.Certain
settingsmaynotbesupportedbythestorage(e.g.(U)SIMSMS
parameters)andthereforecannotbesaved.
ERROR
Parameter
<profile>0SaveSMservicesettinginprofile0
ExecutionCommand
AT+CSASResponse
SameasAT+CSAS=0
IferrorisrelatedtoMEfunctionality:
+CMSERROR<err>
ParameterSavingModeNO_SAVE
MaxResponseTime5s
Reference
3GPPTS27.005Note
4.2.12AT+CSCASMSServiceCenterAddress
AT+CSCASMSServiceCenterAddress
TestCommand
AT+CSCA=?Response
ReadCommand Response

---

## Page 78

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 78/281
AT+CSCA? +CSCA:<sca>,<tosca>[,<scaAlpha>]
Parameters
SeeWriteCommand
WriteCommand
AT+CSCA=<sca>[,<tos
ca>]Response
TAupdatestheSMSCaddress,throughwhichmobileoriginatedSMSare
transmitted.Intextmode,settingisusedbysendandwritescommands.In
PDUmode,settingisusedbythesamecommands,butonlywhenthe
lengthoftheSMSCaddresscodedinto<pdu>parameterequalszero.
Note:TheCommandwritestheparametersinNON-VOLATILEmemory.
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<sca>GSM04.11RPSCaddressAddress-Valuefieldinstring
format(stringshouldbeincludedinquotationmarks);BCDnumbers(or
GSMdefaultalphabetcharacters)areconvertedtocharactersofthe
currentlyselectedTEcharacterset(specifiedby+CSCSin3GPPTS
27.007);typeofaddressgivenby<tosca>
<tosca>ServicecenteraddressformatGSM04.11RPSCaddress
Type-of-Addressoctetinintegerformat(defaultrefer<toda>)
<scaAlpha>Stringtype(stringshouldbeincludedinquotation
marks)
Servicecenteraddressalphadata
ParameterSavingModeNO_SAVE
MaxResponseTime5s
Reference
3GPPTS27.005Note
4.2.13AT+CSDHShowSMSTextModeParameters
AT+CSDHShowSMSTextModeParameters
TestCommand
AT+CSDH=?Response
+CSDH:(listofsupported<show>s)
Parameter
SeeWriteCommand
ReadCommand
AT+CSDH?Response
+CSDH:<show>

---

## Page 79

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 79/281
Parameter
SeeWriteCommand
WriteCommand
AT+CSDH=<show>Response
TAdetermineswhetherdetailedheaderinformationisshownintextmode
resultcodes.
Parameter
<show>0Donotshowheadervaluesdefinedincommands+CSCA
and+CSMP(<sca>,<tosca>,<fo>,<vp>,<pid>and<dcs>)nor
<length>,<toda>or<tooa>in+CMT,+CMGL,+CMGRresultcodesfor
SMS-DELIVERsandSMS-SUBMITsintextmode
1Showthevaluesinresultcodes
ExecutionCommand
AT+CSDHResponse
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.005Note
4.2.14AT+CSMPSetSMSTextModeParameters
AT+CSMPSetSMSTextModeParameters
TestCommand
AT+CSMP=?Response
Parameters
SeeWriteCommand
ReadCommand
AT+CSMP?Response
+CSMP:<fo>,<vp>,<pid>,<dcs>
Parameters
SeeWriteCommand
WriteCommand
AT+CSMP=[<fo>[,<vp>
,<pid>,<dcs>]]Response
TAselectsvaluesforadditionalparametersneededwhenSMissenttothe
networkorplacedinastoragewhentextmodeisselected(+CMGF=1).Itis
possibletosetthevalidityperiodstartingfromwhentheSMisreceivedby
theSMSC(<vp>isinrange0...255)ordefinetheabsolutetimeofthe
validityperiodtermination(<vp>isastring).
Note:TheCommandwritestheparameter<fo>inNON-VOLATILEmemory.

---

## Page 80

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 80/281
Parameters
<fo>Dependingonthecommandorresultcode:firstoctetofGSM
03.40SMS-DELIVER,SMS-SUBMIT(default17),
SMS-STATUS-REPORT,orSMS-COMMAND(default2)inintegerformat.
SMSstatusreportissupportedundertextmodeif<fo>issetto49.
<vp>DependingonSMS-SUBMIT<fo>setting:GSM03.40
TP-Validity-Periodeitherinintegerformat(default167)orintime-string
format(refer<dt>)
<pid>GSM03.40TP-Protocol-Identifierinintegerformat(default0).
<dcs>GSM03.38SMSDataCodingSchemeinIntegerformat.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.005Note
4.2.15AT+CSMSSelectMessageService
AT+CSMSSelectMessageService
TestCommand
AT+CSMS=?Response
+CSMS:(listofsupported<service>s)
Parameter
SeeWriteCommand
ReadCommand
AT+CSMS?Response
+CSMS:<service>,<mt>,<mo>,<bm>
Parameters
SeeWriteCommand
WriteCommand
AT+CSMS=<service>Response
+CSMS:<mt>,<mo>,<bm>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<service>0GSM03.40and03.41(thesyntaxofSMSATcommands
iscompatiblewith3GPPTS27.005Phase2version4.7.0;Phase2+
featureswhichdonotrequirenewCommandsyntaxmaybesupported(e.g.
correctroutingofmessageswithnewPhase2+datacodingschemes))
1GSM03.40and03.41(thesyntaxofSMSATcommands
iscompatiblewith3GPPTS27.005Phase2+

---

## Page 81

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 81/281
version;therequirementof<service>setting1is
mentionedundercorrespondingcommanddescriptions)
<mt>MobileTerminatedMessages:
0Typenotsupported
1Typesupported
<mo>MobileOriginatedMessages:
0Typenotsupported
1Typesupported
<bm>BroadcastTypeMessages:
0Typenotsupported
1Typesupported
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
3GPPTS27.005Note

---

## Page 82

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 82/281
5ATCommandsSpecialforSIMCom
5.1Overview
Command Description
AT+CPOWD Poweroff
AT+CADC ReadADC
AT+CFGRI IndicateRIwhenusingURC
AT+CLTS Getlocaltimestamp
AT+CBAND Getandsetmobileoperationband
AT+CNSMOD Shownetworksystemmode
AT+CSCLK Configureslowclock
AT+CCID ShowICCID
AT+CDEVICE ViewCurrentFlashDeviceType
AT+GSV Displayproductidentificationinformation
AT+SGPIO ControltheGPIO
AT+SLEDS Setthetimerperiodofnetlight
AT+CNETLIGHT Closethenetlightoropenittoshining
AT+CSGS NetlightindicationofGPRSstatus
AT+CGPIO ControltheGPIObyPINIndex
AT+CBATCHK SetVBATcheckingfeatureON/OFF
AT+CNMP Preferredmodeselection
AT+CMNB PreferredselectionbetweenCAT-MandNB-IoT
AT+CPSMS PowerSavingModeSetting
AT+CEDRXS Extended-DRXSetting
AT+CPSI InquiringUEsysteminformation
AT+CGNAPN GetNetworkAPNinCAT-MOrNB-IOT
AT+CSDP ServiceDomainPreference
AT+MCELLLOCK LockthespecialCAT-Mcell
AT+NCELLLOCK LockthespecialNB-IOTcell
AT+NBSC ConfigureNB-IOTScramblingFeature
AT+CAPNMODE SelectthemodeofapplicationconfigureAPN
AT+CRRCSTATE QueryRRCState
AT+CBANDCFG ConfigureCAT-MOrNB-IOTBand
AT+CNACT APPNetworkActive
AT+CNCFG PDPConfigure

---

## Page 83

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 83/281
AT+CEDUMP Setwhetherthemoduleresetwhenthemoduleiscrashed
AT+CNBS ConfigureBandScanOptimizationforNB-IOT
AT+CNDS ConfigureServiceDomainPreferenceForNB-IOT
AT+CENG SwitchonoroffEngineeringMode
AT+CNACTCFG ConfigureIPProtocolType
AT+CTLIIC ControltheSwitchofIIC
AT+CWIIC WriteValuestoRegisterofIICDevice
AT+CRIIC ReadValuesfromRegisterofIICDevice
AT+CMCFG ManageMobileOperatorConfiguration
AT+CSIMLOCK SIMLock
AT+CRATSRCH ConfigureparameterforbetterRATsearch
AT+SPWM GeneratethePulse-Width-Modulation
AT+CASRIP ShowRemoteIPAddressandPortWhenReceivedData
AT+CEDRX ConfigureEDRXparameters
AT+CPSMRDP ReadPSMDynamicParameters
AT+CPSMCFG ConfigurePSMversionandMinimumThresholdValue
AT+CPSMCFGEXTConfigureModemOptimizationofPSM
AT+CPSMSTATUSEnableDeepSleepWakeupIndication
AT+CEDRXRDP eDRXReadDynamicParameters
AT+CRAI ConfigureReleaseAssistanceIndicationinNB-IOTnetwork
5.2DetailedDescriptionsofCommands
5.2.1AT+CPOWDPoweroff
AT+CPOWDPowerOff
WriteCommand
AT+CPOWD=<n>Response
[NORMALPOWERDOWN]
Parameter
<n>
0Poweroffurgently(WillnotsendoutNORMALPOWERDOWN)
1Normalpoweroff(WillsendoutNORMALPOWERDOWN)
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote

---

## Page 84

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 84/281
5.2.2AT+CADCReadADC
AT+CADCReadADC
TestCommand
AT+CADC=?Response
+CADC:(listofsupported<status>s),(listofsupported<value>s)
Parameters
<status>1Success
0Fail
<value>Integer0,100-1700
ReadCommand
AT+CADC?Response
+CADC:<status>,<value>
Parameters
SeeTestCommand
ParameterSavingModeNO_SAVE
MaxResponseTime2s
ReferenceNote
5.2.3AT+CFGRIIndicateRIWhenUsingURC
AT+CFGRIIndicateRIWhenUsingURC
TestCommand
AT+CFGRI=?Response
+CFGRI:(0-2)
Parameters
SeeWriteCommand
ReadCommand
AT+CFGRI?Response
+CFGRI:<status>
Parameters
SeeWriteCommand
WriteCommand
AT+CFGRI=<status>Response
ERROR
Parameters

---

## Page 85

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 85/281
<status>0Off
1On(TCPIP,FTPandURCcontrolRIpin)
2On(onlyTCPIPcontrolRIpin)
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
RIpincannotcontrollby"AT+CFGRI"commandwhenmodulehascall
serviceorreceivingSMS.
5.2.4AT+CLTSGetLocalTimestamp
AT+CLTSGetLocalTimestamp
TestCommand
AT+CLTS=?Response
+CLTS:"yy/MM/dd,hh:mm:ss+/-zz"
ReadCommand
AT+CLTS?Response
+CLTS:<mode>
WriteCommand
AT+CLTS=<mode>Response
ERROR
Parameters
<mode>
0Disable
1Enable
UnsolicitedResultCode
When"getlocaltimestamp"functionisenabled,thefollowingURCmaybe
reportedifnetworksendsthemessagetotheMStoprovidetheMSwith
subscriberspecificinformation.
1.Refreshnetworknamebynetwork:
*PSNWID:"<mcc>","<mnc>","<fullnetworkname>",<fullnetwork
nameCI>,"<shortnetworkname>",<shortnetworknameCI>
2.Refreshtimeandtimezonebynetwork:
ThisisUTCtime,thetimequeriedbyAT+CCLKcommandislocaltime.
*PSUTTZ:<year>,<month>,<day>,<hour>,<min>,<sec>,"<time
zone>",<dst>
3.Refreshnetworktimezonebynetwork:

---

## Page 86

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 86/281
+CTZV:"<timezone>"
4.RefreshNetworkDaylightSavingTimebynetwork:
DST:<dst>
Parameters
<mcc>Stringtype;mobilecountrycode
<mnc>Stringtype;mobilenetworkcode
<fullnetworkname>Stringtype;nameofthenetworkinfulllength.
<fullnetworknameCI>Integertype;indicateswhethertoaddCI.
0TheMSwillnotaddtheinitiallettersoftheCountry's
Nametothetextstring.
1TheMSwilladdtheinitiallettersoftheCountry's
Nameandaseparator(e.g.aspace)tothetextstring.
<shortnetworkname>Stringtype;abbreviatednameofthenetwork
<shortnetworknameCI>Integertype;indicateswhethertoaddCI.
0TheMSwillnotaddtheinitiallettersoftheCountry's
Nametothetextstring.
1TheMSwilladdtheinitiallettersoftheCountry's
Nameandaseparator(e.g.aspace)tothetextstring.
<year>4digitsofyear(fromnetwork)
<month>Month(fromnetwork)
<day>Day(fromnetwork)
<hour>Hour(fromnetwork)
<min>Minute(fromnetwork)
<sec>Second(fromnetwork)
<timezone>Stringtype;networktimezone.Ifthenetworktimezonehas
beenadjustedforDaylightSavingTime,thenetworkshallindicatethisby
includingthe<dst>(NetworkDaylightSavingTime)
<dst>NetworkDaylightSavingTime;thecontentofthis
indicatesthevaluethatusedtoadjustthenetworktimezone
0NoadjustmentforDaylightSavingTime
1+1houradjustmentforDaylightSaving
2+2hoursadjustmentforDaylightSavingTime
othersReserved
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
SupportforthisCommandwillbenetworkdependent.
SetAT+CLTS=1,itmeansusercanreceivenetworktimeupdatingand
useAT+CCLKtoshowcurrenttime.
*PSUTTZmayreporttwice.

---

## Page 87

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 87/281
5.2.5AT+CBANDGetandSetMobileOperationBand
AT+CBANDGetandSetMobileOperationBand
TestCommand
AT+CBAND=?Response
+CBAND:(listofsupported<op_band>s)
Parameter
SeeWriteCommand
ReadCommand
AT+CBAND?Response
+CBAND:<op_band>
Parameter
SeeWriteCommand
WriteCommand
AT+CBAND=<op_band
>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameter
<op_band>Astringparameterwhichindicatetheoperationband.
Andthefollowingstringsshouldbeincludedinquotationmarks.
EGSM_MODE
DCS_MODE
ALL_MODE
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
ReferenceNote
Radiosettingsarestoredinnon-volatilememory.
OnlyforGSM
5.2.6AT+CNSMODShowNetworkSystemMode
AT+CNSMODShowNetworkSystemMode
TestCommand
AT+CNSMOD=?Response
+CNSMOD:(listofsupported<n>s)
Parameter
SeeWriteCommand
ReadCommand Response

---

## Page 88

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 88/281
AT+CNSMOD? +CNSMOD:<n>,<stat>
Parameter
SeeWriteCommand
WriteCommand
AT+CNSMOD=<n>Response
ERROR:
Parameter
<n>
0Disableautoreportthenetworksystemmodeinformation
1Autoreportthenetworksystemmodeinformation,command:
+CNSMOD:<stat>
<stat>
0noservice
1GSM
3EGPRS
7LTEM1
9LTENB
ParameterSavingMode-
MaxResponseTime
Reference
5.2.7AT+CSCLKConfigureSlowClock
AT+CSCLKConfigureSlowClock
TestCommand
AT+CSCLK=?Response
+CSCLK:(listofsupported<n>s)
Parameter
SeeWriteCommand
ReadCommand
AT+CSCLK?Response
+CSCLK:<n>
Parameter
SeeWriteCommand
WriteCommand
AT+CSCLK=<n>Response
ERROR

---

## Page 89

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 89/281
Parameter
<n>0Disableslowclock,modulewillnotentersleepmode.
1Enableslowclock,itiscontrolledbyDTR.WhenDTRis
high,modulecanentersleepmode.WhenDTRchangestolow
level,modulecanquitsleepmode.
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
ReferenceNote
5.2.8AT+CCIDShowICCID
AT+CCIDShowICCID
TestCommand
AT+CCID=?Response
ExecutionCommand
AT+CCIDResponse
Cciddata[ex.898600810906F8048812]
ParameterSavingModeNO_SAVE
MaxResponseTime2s
ReferenceNote
5.2.9AT+CDEVICEViewCurrentFlashDeviceType
AT+CDEVICEViewCurrentFlashDeviceType
ReadCommand
AT+CDEVICE?Response
DeviceName:Currentflashdevicetype
RamSize:CurrentRAMsize
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
V.25terNote

---

## Page 90

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 90/281
5.2.10AT+GSVDisplayProductIdentificationInformation
AT+GSVDisplayProductIdentificationInformation
ExecutionCommand
AT+GSVResponse
TAreturnsproductinformationtext
Example:
SIMCOM_Ltd
SIMCOM_SIM7000
Revision:1351B01SIM7000
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
5.2.11AT+SGPIOControltheGPIO
AT+SGPIOControltheGPIO
TestCommand
AT+SGPIO=?Response
+SGPIO:(0-1),(0-4),(0-1),(0-1)
Parameters
SeeWriteCommand
WriteCommand
AT+SGPIO=<operation
>,<GPIO>,<function>,<
level>Response
ERROR
Parameters
<operation>
0SettheGPIOfunctionincludingtheGPIOoutput.
1ReadtheGPIOlevel.Pleasenotethatonlywhenthegpioisset
asinput,usercanuseparameter1toreadtheGPIOlevel,otherwisethe
modulewillreturn"ERROR".
<GPIO>TheGPIOyouwanttobeset.(Ithasrelationswiththehardware,
pleaserefertothehardwaremanual)
<function>Onlywhen<operation>issetto0,thisoptiontakeseffect.
0SettheGPIOtoinput.
1SettheGPIOtooutput

---

## Page 91

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 91/281
<level>0SettheGPIOlowlevel
1SettheGPIOhighlevel
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
5.2.12AT+SLEDSSettheTimerPeriodofNetLight
AT+SLEDSSettheTimerPeriodofNetLight
TestCommand
AT+SLEDS=?Response
+SLEDS:(1-3),(0,40-65535),(0,40-65535)
Parameters
SeeWriteCommand
ReadCommand
AT+SLEDS?Response
+SLEDS:<mode>,<timer_on>,<timer_off>
Parameters
SeeWriteCommand
WriteCommand
AT+SLEDS=<mode>,<t
imer_on>,<timer_off>Response
ERROR
Parameters
<mode>
1SetthetimerperiodofnetlightwhileSIM7000seriesdoesnot
registertothenetwork
2SetthetimerperiodnetlightwhileSIM7000serieshasalready
registeredtothenetwork
3SetthetimerperiodnetlightwhileSIM7000seriesisinthestateof
PPPcommunication
<timer_on>
Timerperiodof"LEDON"indecimalformatwhichrangeis0or
40-65535(ms)
<timer_off>
Timerperiodof"LEDOFF"indecimalformatwhichrangeis0or
40-65535(ms)
ParameterSavingMode-
MaxResponseTime-
Reference Note

---

## Page 92

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 92/281
Thedefaultvalueis:
<mode>,<timer_on>,<timer_off>
1,64,800
2,64,3000
3,64,300
5.2.13AT+CNETLIGHTClosetheNetLightorOpenIttoShining
AT+CNETLIGHTClosetheNetLightorOpenIttoShining
TestCommand
AT+CNETLIGHT=?Response
+CNETLIGHT:(0,1)
Parameters
SeeWriteCommand
ReadCommand
AT+CNETLIGHT?Response
+CNETLIGHT:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CNETLIGHT=<mod
e>Response
ERROR
Parameters
<mode>
0Closethenetlight
1Openthenetlighttoshining
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
Reference Note
5.2.14AT+CSGSNetlightIndicationofGPRSStatus
AT+CSGSNetlightIndicationofGPRSStatus
TestCommand
AT+CSGS=?Response
+CSGS:(0-2)

---

## Page 93

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 93/281
Parameters
SeeWriteCommand
ReadCommand
AT+CSGS?Response
+CSGS:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CSGS=<mode>Response
ERROR
Parameters
<mode>
0Disable
1Enable,thenetlightwillbeforcedtoenterinto64mson/300msoff
blinkingstateinGPRSdatatransmissionservice.Otherwise,the
netlightstateisnotrestricted.
2Enable,thenetlightwillblinkaccordingtoAT+SLEDSinGPRSdata
transmissionservice.
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
5.2.15AT+CGPIOControltheGPIObyPINIndex
AT+CGPIOControltheGPIObyPINIndex
TestCommand
AT+CGPIO=?Response
+CGPIO:(0-1),(listofsupported<pin>s),(0-1),(0-1)
Parameters
SeeWriteCommand
WriteCommand
AT+CGPIO=<operation
>,<pin>,<function>,<le
vel>Response
ERROR
Parameters
<operation>
0SettheGPIOfunctionincludingtheGPIOoutput.
1ReadtheGPIOlevel.Pleasenotethatonlywhenthegpioisset
asinput,usercanuseparameter1toreadtheGPIOlevel,otherwisethe

---

## Page 94

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 94/281
modulewillreturn"ERROR".
<pin>ThePINindexyouwanttobeset.(Ithasrelationswiththe
hardware,pleaserefertothehardwaremanual)
<function>Onlywhen<operation>issetto0,thisoptiontakeseffect.
0SettheGPIOtoinput.
1SettheGPIOtooutput
<level>
0SettheGPIOlowlevel
1SettheGPIOhighlevel
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
5.2.16AT+CBATCHKSetVBATCheckingFeatureON/OFF
AT+CBATCHKSetVBATCheckingFeatureON/OFF
TestCommand
AT+CBATCHK=?Response
+CBATCHK:(0,1)
ReadCommand
AT+CBATCHK?Response
+CBATCHK:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CBATCHK=<mode
>Response
Iffailed:
+CMEERROR:<err>
Parameters
<mode>0ClosethefunctionofVBATchecking
1OpenthefunctionofVBATchecking
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
Reference Note

---

## Page 95

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 95/281
5.2.17AT+CNMPPreferredModeSelection
AT+CNMPPreferredModeSelection
TestCommand
AT+CNMP=?Response
+CNMP:(listofsupported<mode>s)
ReadCommand
AT+CNMP?Response
+CNMP:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CNMP=<mode>Response
Iffailed:
+CMEERROR:<err>
Parameters
<mode>2Automatic
13GSMonly
38LTEonly
51GSMandLTEonly
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
ReferenceNote
Defaultvalueofparameter<mode>isdifferentamongSIM7000series
project.
5.2.18AT+CMNBPreferredSelectionbetweenCAT-MandNB-IoT
AT+CMNBPreferredSelectionbetweenCAT-MandNB-IoT
TestCommand
AT+CMNB=?Response
+CMNB:(listofsupported<mode>s)
ReadCommand
AT+CMNB?Response
+CMNB:<mode>
Parameters
SeeWriteCommand

---

## Page 96

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 96/281
WriteCommand
AT+CMNB=<mode>Response
Iffailed:
+CMEERROR:<err>
Parameters
<mode>1CAT-M
2NB-Iot
3CAT-MandNB-IoT
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
ReferenceNote
Defaultvalueofparameter<mode>isdifferentamongSIM7000series
project.
5.2.19AT+CPSMSPowerSavingModeSetting
AT+CPSMSPowerSavingModeSetting
TestCommand
AT+CPSMS=?Response
+CPSMS:(listofsupported<mode>s),(listofsupported
<Requested_Periodic-RAU>s),(list of supported
<Requested_GPRS-READY-timer>s),(list of supported
<Requested_Periodic-TAU>s),(list of supported
<Requested_Active-Time>s)
ReadCommand
AT+CPSMS?Response
+CPSMS:<mode>,[<Requested_Periodic-RAU>],[<Requested_GPRS-
READY-timer>],[<Requested_Periodic-TAU>],[<Requested_Active-Tim
e>]
Parameters
SeeWriteCommand
WriteCommand
AT+CPSMS=[<mode>[,
<Requested_Periodic-
RAU>[,<Requested_G
PRS-READY-timer>[,<
Requested_Periodic-T
AU>[,<Requested_Acti
ve-Time>]]]]]Response
Iffailed:
+CMEERROR:<err>
Parameters
<mode>
0DisabletheuseofPSM
1EnabletheuseofPSM
<Requested_Periodic-RAU>Notsupported

---

## Page 97

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 97/281
<Requested_GPRS-READY-timer>Notsupported
<Requested_Periodic-TAU>
Stringtype;onebyteinan8bitformat.Requestedextendedperiodic
TAUvalue(T3412)tobeallocatedtotheUEinE-UTRAN.The
requestedextendedperiodicTAUvalueiscodedasonebyte
(octet3)oftheGPRSTimer3informationelementcodedasbit
format(e.g."01000111"equals70hours).Forthecodingandthe
valuerange,seetheGPRSTimer3IEin3GPPTS24.008[8]
Table10.5.163a/3GPPTS24.008.Seealso3GPPTS23.682[149]
and3GPPTS23.401[82].Thedefaultvalue,ifavailable,is
manufacturerspecific.
<Requested_Active-Time>
Stringtype;onebyteinan8bitformat.RequestedActiveTimevalue
(T3324)tobeallocatedtotheUE.TherequestedActiveTimevalue
iscodedasonebyte(octet3)oftheGPRSTimer2information
elementcodedasbitformat(e.g."00100100"equals4minutes).For
thecodingandthevaluerange,seetheGPRSTimer2IEin
3GPPTS24.008[8]Table10.5.163/3GPPTS24.008.Seealso
3GPPTS23.682[149],3GPPTS23.060[47]and
3GPPTS23.401[82].Thedefaultvalue,ifavailable,ismanufacturer
specific.
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
Reference Note
5.2.20AT+CEDRXSExtended-DRXSetting
AT+CEDRXSExtended-DRXSetting
TestCommand
AT+CEDRXS=?Response
+CEDRXS:(listofsupported
<n>s),<AcT-type>,<Requested_eDRX_value>
ReadCommand
AT+CEDRXS?Response
+CEDRXS:<AcT-type>,<Requested_eDRX_value>
Parameters
SeeWriteCommand
WriteCommand
AT+CEDRXS=<n>,<Ac
T-type>,<Requested_eResponse
Iffailed:

---

## Page 98

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 98/281
DRX_value> +CMEERROR:<err>
Parameters
<n>
0DisabletheuseofeDRX
1EnabletheuseofeDRX
2EnabletheuseofeDRXandautoreport
3DisabletheuseofeDRX(Reserved)
<AcT-type>
4CAT-M
5NB-IoT
<Requested_eDRX_value>RequestedeDRXvalue.4bitformat.
"0000"-"1111"
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
ReferenceNote
TheRequested_eDRX_valueisthevalueofcyclelength,separately
means
5.12,10.24,20.48,40.96,61.44,81.92,102.40,122.88,143.36,163.84,327
.68,655.36,1310.72,2621.44,5242.88,10485.76.(seconds)
5.2.21AT+CPSIInquiringUESystemInformation
AT+CPSIInquiringUESystemInformation
TestCommand
AT+CPSI=?Response
ReadCommand
AT+CPSI?Ifcampingonagsmcell:
+CPSI:<SystemMode>,<OperationMode>,<MCC>-<MNC>,<LAC>,<C
ellID>,<AbsoluteRFChNum>,<RxLev>,<TrackLOAdjust>,<C1-C
IfcampingonaCAT-MorNB-IOTcell:
+CPSI:<SystemMode>,<OperationMode>,<MCC>-<MNC>,<TAC>,<S
CellID>,<PCellID>,<FrequencyBand>,<earfcn>,<dlbw>,<ulbw>,<RSR
Q>,<RSRP>,<RSSI>,<RSSNR>
Ifnoservice:
+CPSI:NOSERVICE,Online
Iffailed:

---

## Page 99

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 99/281
+CMEERROR:<err>
Parameters
<SystemMode>Systemmode.
"NOSERVICE"
"GSM"
"LTECAT-M1"
"LTENB-IOT"
<OperationMode>UEoperationmode.
"Online",
"Offline",
"FactoryTestMode",
"Reset",
"LowPowerMode".
<MCC>MobileCountryCode(firstpartofthePLMNcode)
<MNC>MobileNetworkCode(secondpartofthePLMNcode)
<LAC>LocationAreaCode(hexadecimaldigits)
<CellID>Service-cellIdentify
<AbsoluteRFChNum>AFRCNforservice-cell.
<TrackLOAdjust>TrackLOAdjust
<C1>Coefficientforbasestationselection
<C2>CoefficientforCellre-selection
<TAC>TracingAreaCode
<SCellID>ServingCellID
<PCellID>PhysicalCellID
<FrequencyBand>FrequencyBandofactiveset
<earfcn>E-UTRAabsoluteradiofrequencychannelnumberforse
archingCAT-MorNB-IOTcells
<dlbw>Transmissionbandwidthconfigurationoftheservingcello
nthedownlink
<ulbw>Transmissionbandwidthconfigurationoftheservingcell
ontheuplink
<RSRP>Currentreferencesignalreceivedpower.AvailableforCA
T-MorNB-IOT.
<RSRQ>CurrentreferencesignalreceivequalityasmeasuredbyL1.
<RSSI>CurrentReceivedsignalstrengthindicator
<RSSNR>Averagereferencesignalsignal-to-noiseratiooftheservi
ngcellThevalueofSINRcanbecalculatedaccordingto<RSSNR>,t
heformulaisasbelow:
SINR=2*<RSSNR>-20
TherangeofSINRisfrom-20to30
ParameterSavingMode-
MaxResponseTime-
Reference Note

---

## Page 100

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 100/281
5.2.22AT+CGNAPNGetNetworkAPNinCAT-MOrNB-IOT
AT+CGNAPNGetNetworkAPNinCAT-MOrNB-IOT
TestCommand
AT+CGNAPN=?Response
+CGNAPN:(listofsupported<valid>s),<length>
ExecutionCommand
AT+CGNAPNResponse
+CGNAPN:<valid>,<Network_APN>
Iffailed:
+CMEERROR:<err>
Parameters
<valid>
0ThenetworkdidnotsentAPNparametertoUE.Inthe
case,<Network_APN>isNULL.
1ThenetworksentAPNparametertoUE.
<length>
Maxthelengthof<network_APN>.
<Network_APN>
Stringtype.ThenetworksendsAPNparametertoUEwhenUE
registersCAT-MorNB-IOTnetworksuccessfully.In
GSM,<Network_APN>alwaysisNULL.
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
InCAT-MorNB-IOT,afterUEsendingattachrequestmessage,Ifcore
networkrespondsattachacceptmessagethatincludesAPN
parameter,<Netwok_APN>isvalid.
5.2.23AT+CSDPServiceDomainPreference
AT+CSDPServiceDomainPreference
TestCommand
AT+CSDP=?Response
+CSDP:(listofsupported<domain>s)
ReadCommand
AT+CSDP?Response
+CSDP:<domain>

---

## Page 101

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 101/281
Parameters
SeeWriteCommand
WriteCommand
AT+CSDP=<domain>Response
Iffailed:
+CMEERROR:<err>
Parameters
<domain>
0CS(CircuitSwitchedDomain)ONLY
1PS(PacketSwitchedDomain)ONLY
2CS(CircuitSwitchedDomain)+PS(PacketSwitchedDomain)
ParameterSavingModeAUTO_SAVE_REBOOT
MaxResponseTime-
Reference Note
5.2.24AT+MCELLLOCKLockthespecialCAT-Mcell
AT+MCELLLOCKLockthespecialCAT-Mcell
TestCommand
AT+MCELLLOCK=?Response
+MCELLLOCK:(0,1),(0-65535),(0-503)
ReadCommand
AT+MCELLLOCK?Response
+MCELLLOCK:<mode>[,<earfcn>,<pci>]
Parameters
SeeWriteCommand
WriteCommand
AT+MCELLLOCK=<mo
de>[,<earfcn>,<pci>]Response
Iffailed:
+CMEERROR:<err>
Parameter
<mode>0Unlock
1Lock
<earfcn>Anumberintherange0-65535representingtheEARFCN
tosearch
<pci>Anumberintherange0-503representingthePhysicalCellID
tosearch
ParameterSavingModeAUTO_SAVE_REBOOT
MaxResponseTime-
Reference Note

---

## Page 102

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 102/281
5.2.25AT+NCELLLOCKLockthespecialNB-IOTcell
AT+NCELLLOCKLockthespecialNB-IOTcell
TestCommand
AT+NCELLLOCK=?Response
+NCELLLOCK:(0,1),(0-65535),(0-503)
ReadCommand
AT+NCELLLOCK?Response
+NCELLLOCK:<mode>[,<earfcn>,<pci>]
Parameters
SeeWriteCommand
WriteCommand
AT+NCELLLOCK=<mo
de>[,<earfcn>,<pci>]Response
Iffailed:
+CMEERROR:<err>
Parameter
<mode>0Unlock
1Lock
<earfcn>Anumberintherange0-65535representingtheEARFCN
tosearch
<pci>Anumberintherange0-503representingthePhysicalCellID
tosearch
ParameterSavingModeAUTO_SAVE_REBOOT
MaxResponseTime-
Reference Note
5.2.26AT+NBSCConfigureNB-IOTScramblingFeature
AT+NBSCConfigureNB-IOTScramblingFeature
TestCommand
AT+NBSC=?Response
+NBSC:(listofsupported<mode>s)
ReadCommandResponse
+NBSC:<mode>

---

## Page 103

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 103/281
AT+NBSC?
Parameters
SeeWriteCommand
WriteCommand
AT+NBSC=<mode>Response
Iffailed:
+CMEERROR:<err>
Parameters
<mode>
0DisablethescramblingfeatureinNB-IOTnetwork.
1EnablethescramblingfeatureinNB-IOTnetwork.
ParameterSavingModeAUTO_SAVE_REBOOT
MaxResponseTime-
ReferenceNote
PleaseconfigureUEinaccordancewiththebasestation,OtherwiseUE
cannotregisterNB-IOTnetwork.
5.2.27AT+CAPNMODESelecttheModeofApplicationConfigureAPN
AT+CAPNMODESelecttheModeofApplicationConfigureAPN
TestCommand
AT+CAPNMODE=?Response
+CAPNMODE:(listofsupported<mode>s)
ReadCommand
AT+CAPNMODE?Response
+CAPNMODE:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CAPNMODE=<mo
de>Response
Iffailed:
+CMEERROR:<err>
Parameters
<mode>modeofapplicationconfigureAPN.InCAT-MorNB-IOT
network,ifmodulehasregisteredtothenetworksuccessfully,i
twillgetanAPNfrombasestationdelivering.
0Automaticmode.Applications(AT+CSTTandAT+SAPBR)donot
needtoconfigAPN,itwillusetheAPNfrombasestation
delivering.

---

## Page 104

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 104/281
1Manualmode,Applications(AT+CSTT,AT+SAPBR)needtoconfig
APN,theseAPNscangetfromoperators.
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
IfmoduleareusinginGPRSnetwork,youmustconfig<mode>to1
5.2.28AT+CRRCSTATEQueryRRCState
AT+CRRCSTATEQueryRRCState
TestCommand
AT+CRRCSTATE=?Response
+CRRCSTATE:(listofsupported<n>s)
ReadCommand
AT+CRRCSTATE?Response
+CRRCSTATE:<n>,<state>
Parameters
SeeWriteCommand
WriteCommand
AT+CRRCSTATE=<n>Response
Iffailed:
+CMEERROR:<err>
Parameters
<n>Integertype
0Disableunsolicitedresultcode
1Enableunsolicitedresultcode"+CRRCSTATE:<state>"
<state>Integertype,indicatesRRCconnectionstate
0Idle
1Connected
255Other
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
ThecommandisonlyvalidthatmoduleregisteringinCAT-MorNB-IOT
network.
5.2.29AT+CBANDCFGConfigureCAT-MOrNB-IOTBand

---

## Page 105

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 105/281
AT+CBANDCFGConfigureCAT-MOrNB-IOTBand
TestCommand
AT+CBANDCFG=?Response
+CBANDCFG:(CAT-M,NB-IOT),(listofsupported<band>s)
ReadCommand
AT+CBANDCFG?Response
+CBANDCFG:"CAT-M",<band>[,<band>…]
<CR><LF>+CBANDCFG:"NB-IOT",<band>[,<band>…]
Parameters
SeeWriteCommand
WriteCommand
AT+CBANDCFG=<mod
e>,<band>[,<band>…]Response
Iffailed:
+CMEERROR:<err>
Parameters
<mode>stringtype;networksystemmode.
"CAT-M"LTECat.M1(eMTC)
"NB-IOT"NarrowBandInternetofThings
<band>Integertype;Thevalueof<band>mustisinthebandlistof
gettingfromAT+CBANDCFG=?
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
ReferenceNote
Thecommandcantakeeffectimmediately,Itdoesnotneedtoreboot
module.
5.2.30AT+CNACTAPPNetworkActive
AT+CNACTAPPNetworkActive
ReadCommand
AT+CNACT?Response
+CNACT:<status>,<ip_addr>
Parameters
SeeWriteCommand
WriteCommand
AT+CNACT=<mode>[,
<apn>]Response
Iffailed:
+CMEERROR:<err>

---

## Page 106

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 106/281
Parameters
<mode>
0Deactive
1Active
2AutoActive
<apn>
(AccessPointName)Astringparameter(stringshouldbeincludedin
quotationmarks)whichisalogicalnamethatisusedtoselectthe
GGSNortheexternalpacketdatanetwork.Ifthevalueisnullor
omitted,thenthesubscriptionvaluewillberequested.Thedefault
valueisNULL.
<status>
0Deactived
1Actived
2Inoperation
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
"+APPPDP:ACTIVE"willbereportediftheappnetworkactived,and"+APP
PDP:DEACTIVE"willbereportediftheappnetworkdeactived.
AutoActivemeansthewillactiveautomaticallyiftheactivationfailed.
5.2.31AT+CNCFGPDPConfigure
AT+CNCFGPDPConfigure
TestCommand
AT+CNCFG=?Response
+CNCFG: (list of supported
<ip_type>s),<len_APN>,<len_usename>,<len_password>,(listof
supported<authentication>s)
ReadCommand
AT+CNCFG?Response
+CNCFG:
<ip_type>,<APN>,<usename>,<password>,<authentication>
WriteCommand
AT+CNCFG=<ip_type>[,<AP
N>[,<usename>,<password
>[,<authentication>]]]Response
Iffailed:
+CMEERROR:<err>
ParameterSavingMode-
MaxResponseTime -
Reference

---

## Page 107

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 107/281
DefinedValues
<action> 0Deactive
1Active
2AutoActive
<ip_type> PacketDataProtocoltype)AIntegertypeparameterwhichspecifies
thetypeofpacketdataprotocol.
0DualPDNStack
1InternetProtocolVersion4
2InternetProtocolVersion6
<APN> (AccessPointName)Astringparameter(stringshouldbeincludedin
quotationmarks)whichisalogicalnamethatisusedtoselectthe
GGSNortheexternalpacketdatanetwork.Ifthevalueisnullor
omitted,thenthesubscriptionvaluewillberequested.Thedefault
valueisNULL.
<usename> Usernameforauthentication.
<password> Passwordforauthentication.
<authentication> 0NONE
1PAP
2CHAP
3PAPorCHAP
<len_APN> Integertype.Maximumlengthofparameter<APN>.
<len_name> Integertype.Maximumlengthofparameter<usename>.
<len_password> Integertype.Maximumlengthofparameter<password>.
5.2.32AT+CEDUMPSetWhethertheModuleResetWhenTheModuleisCrashed
AT+CEDUMPSetWhethertheModuleResetWhenTheModuleisCrashed
ReadCommand
AT+CEDUMP?Response
+CEDUMP:<mode>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
SeeWriteCommand
WriteCommand
AT+CEDUMP=<mode>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>

---

## Page 108

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 108/281
Parameters
<fun>
0Themodulewillresetwhenthemoduleiscrashed(Default)
1Themodulewillgointodownloadmodewhenthemoduleis
crashed
ParameterSavingMode-
MaxResponseTime
ReferenceNote
5.2.33AT+CNBSConfigureBandScanOptimizationForNB-IOT
AT+CNBSConfigureBandScanOptimizationforNB-IOT
TestCommand
AT+CNBS=?Response
+CNBS:(1-5)
ReadCommand
AT+CNBS?Response
+CNBS:<n>
Parameters
SeeWriteCommand
WriteCommand
AT+CNBS=<n>Response
Iffailed:
+CMEERROR:<err>
Parameters
BandscanisperformedinthefollowinglevelsbasedontheSNR:
level0UsedforgoodSNRlevels(0dbandabove);detectsstrongcells
firstandtakestheshortesttimetoacquirecells.UEscanseach
rasterin30ms.
level1UsedformediumSNRlevels(-9dBandabove),UEscanseach
rasterfor200ms
level2UsedforpoorSNRlevels(-12.6dBandabove),UEscanseach
rasterfor500ms.
<n>
1UEtriesSNRlevel0bandscan
2UEtriesSNRlevel0andlevel1bandscan
3UEtriesSNRlevel0,level1,andlevel2bandscan
4Reserved
5UEtriesSNRlevel2bandscanonly

---

## Page 109

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 109/281
ParameterSavingModeAUTO_SAVE_REBOOT
MaxResponseTime-
ReferenceNote
ThecommandcontrolsthebandscanfordifferentSNRlevels.This
optimizationisapplicableonlyforNB-IOTanditreducesthebandscan
timeandpowerconsumption.
5.2.34AT+CNDSConfigureServiceDomainPreferenceForNB-IOT
AT+CNDSConfigureServiceDomainPreferenceForNB-IOT
TestCommand
AT+CNDS=?Response
+CNDS:(listofsupported<domain>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CNDS?Response
+CNDS:<domain>
Parameters
SeeWriteCommand
WriteCommand
AT+CNDS=<domain>Response
Iffailed:
+CMEERROR:<err>
Parameters
<domain>
1PS(PacketSwitchedDomain)ONLY
2CS(CircuitSwitchedDomain)+PS(PacketSwitchedDomain)
ParameterSavingModeAUTO_SAVE_REBOOT
MaxResponseTime-
ReferenceNote
ThecommandofAT+CSDPisusedtoconfigservicedomain
preferenceforGSMandCAT-M.Ifyouwanttoconfigservicedomain
preferenceforNB-IOT,youcanuseAT+CNDS.
5.2.35AT+CENGSwitchOnorOffEngineeringMode

---

## Page 110

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 110/281
AT+CENGSwitchOnorOffEngineeringMode
TestCommand
AT+CENG=?Response
TAreturnsthelistofsupportedmodes.
+CENG:(listofsupported<mode>s),(listofsupported<Ncell>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CENG?Response
EngineeringModeisdesignedtoallowafieldengineertoviewandtestthe
networkinformationreceivedbyahandset,whenthehandsetiseitherin
idlemodeordedicatedmode(thatis:withacallactive).Ineachmode,the
engineerisabletoviewnetworkinteractionforthe"servingcell"(thecellthe
handsetiscurrentlyregisteredwith)orfortheneighboringcells.
TAreturnsthecurrentengineeringmode.Thenetworkinformationincluding
servingcellandneighboringcellsarereturned.<cell>carrywiththem
correspondingnetworkinteraction.
Ifcampingonagsmcell:
+CENG:<mode>,<Ncell>,<cellnum>,<SystemMode>
[+CENG:<cell>,"<bcch>,<rxl>,<bsic>,<cellid>,<mcc>,<mnc>,<lac>"
<CR><LF>+CENG:
<cell>,"<bcch>,<rxl>,<bsic>,<cellid>,<mcc>,<mnc>,<lac>"…]
IfcampingonaCAT-MorNB-IOTcell:
+CENG:<mode>,<Ncell>,<cellnum>,<SystemMode>
[+CENG:
<cell>,"<earfcn>,<pci>,<rsrp>,<rssi>,<rsrq>,<sinr>,<tac>,<cellid>,<mc
c>,<mnc>,<txpower>"
<CR><LF>+CENG:
<cell>,"<earfcn>,<pci>,<rsrp>,<rssi>,<rsrq>,<sinr>"…]
Parameters
SeeWriteCommand
WriteCommand
AT+CENG=<mode>[,<
Ncell>]Switchonoroffengineeringmode.
Iffailed:
+CMEERROR:<err>
Parameters

---

## Page 111

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 111/281
<mode>0Switchoffengineeringmode
1Switchonengineeringmode
<Ncell>1DisplayneighborcellID
<cellnum>Thenumberofcell,itincludesservingcellandneighborcells.
<SystemMode>Systemmode.
"NOSERVICE"
"GSM"
"LTECAT-M1"
"LTENB-IOT"
<cell>0Theservingcell
1-6Theindexoftheneighboringcell
<bcch>ARFCN(Absoluteradiofrequencychannelnumber)ofBCCH
carrier,indecimalformat
<rxl>Receivelevel,indecimalformat
<mcc>Mobilecountrycode,indecimalformat
<mnc>Mobilenetworkcode,indecimalformat
<bsic>Basestationidentitycode,indecimalformat
<cellid>Cellid,inhexadecimalformat
<lac>Locationareacode,inhexadecimalformat
<earfcn>E-UTRAabsoluteradiofrequencychannelnumberforsea
rchingCAT-MorNB-IOTcells
<pci>PhysicalCellID
<rsrp>Currentreferencesignalreceivedpower.Availablefor
CAT-MorNB-IOT.
<rssi>CurrentReceivedsignalstrengthindicator
<rsrq>Currentreferencesignalreceivequalityasmeasuredby
L1.
<sinr>SignaltoInterferenceplusNoiseRatio,Therangeisfrom
-20to30.
<tac>TracingAreaCode,indecimalformat
<txpower>Txpowervaluein1/10dBm.<txpower>isonlymeaningful
whenthedeviceisintraffic.Whenthereisnotraffic,thevalue
isinvalid.Thevalueof<txpower>is255.
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
5.2.36AT+CNACTCFGConfigureIPProtocolType
AT+CNACTCFGConfigureIPProtocolType
TestCommandResponse
+CNACTCFG:("IPV4","IPV6","IPV4V6")

---

## Page 112

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 112/281
AT+CNACTCFG=?
Parameters
SeeWriteCommand
ReadCommand
AT+CNACTCFG?Response
+CNACTCFG:<IPType>
Parameters
SeeWriteCommand
WriteCommand
AT+CNACTCFG=<IPTy
pe>Response
Iffailed:
+CMEERROR:<err>
Parameters
<IPType>
"IPV4"IPv4protocol
"IPV6"IPv6protocol
"IPV4V6"IPv4andIPv6protocol
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
5.2.37AT+CTLIICControltheSwitchofIIC
AT+CTLIICControltheSwitchofIIC
TestCommand
AT+CTLIIC=?Response
+CTLIIC:(0,1)
Parameters
SeeWriteCommand
ReadCommand
AT+CTLIIC?Response
+CTLIIC:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CTLIIC=<mode>Response

---

## Page 113

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 113/281
ERROR
Parameters
<mode>
0SwitchofftheIIC
1SwitchontheIIC
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
5.2.38AT+CWIICWriteValuestoRegisterofIICDevice
AT+CWIICWriteValuestoRegisterofIICDevice
TestCommand
AT+CWIIC=?Response
WriteCommand
AT+CWIIC=<addr>,<re
g>,<data>,<len>Response
ERROR
Parameters
<addr>Deviceaddress.Inputformatmustbehex,suchas0xFF.
<reg>Registeraddress.Inputformatmustbehex,suchas0xFF.
<len>Readlength.Range:1-4;unit:byte.
<data>Datawritten.Inputformatmustbehex,suchas
0xFF–0xFFFFFFFF
ParameterSavingMode-
MaxResponseTime-
Reference Note
5.2.39AT+CRIICReadValuesfromRegisterofIICDevice
AT+CRIICReadValuesfromRegisterofIICDevice
TestCommand
AT+CRIIC=?Response
WriteCommand
AT+CRIIC=<addr>,<re
g>,<len>Response
+CRIIC:<data>

---

## Page 114

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 114/281
ERROR
Parameters
<addr>Deviceaddress.Inputformatmustbehex,suchas0xFF.
<reg>Registeraddress.Inputformatmustbehex,suchas0xFF.
<len>Readlength.Range:1-4;unit:byte.
<data>Dataread.Inputformatmustbehex,suchas0xFF.
ParameterSavingMode-
MaxResponseTime-
Reference Note
5.2.40AT+CMCFGManageMobileOperatorConfiguration
AT+CMCFGManageMobileOperatorConfiguration
TestCommand
AT+CMCFG=?Response
TAreturnsthelistofsupportedmodes.
+CMCFG:(listofsupported<mode>s),<length>
Parameters
SeeWriteCommand
ReadCommand
AT+CMCFG?Response
+CMCFG:<mode>,<config_num>
[+CMCFG:<index>,<config_name>,<config_version>,<state>…]
Parameters
SeeWriteCommand
WriteCommand
AT+CMCFG=<mode>[,
<config_name>]when<mode>=0,1,2or3andcommandsuccessful:
when<mode>=4andcommandsuccessful:
+CMCFG:4,<flag>,<config_name>
Iffailed:
+CMEERROR:<err>
Parameters
<mode>0Manuallyselectmobileoperatorconfiguration
1Automaticallyselectmobileoperatorconfiguration
accordingtoICCIDinformationinSIMcard
2Activatespecifiedmobileoperatorconfiguration,

---

## Page 115

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 115/281
<config_name>mustbeprovided.
3Deactivationspecifiedmobileoperatorconfiguration,
<config_name>mustbeprovided.
<length> Intergertype,themaximumlengthof<config_name>
<config_num>Integertype,thenumberofmobilenetworkconfiguration
<index> Integertype,theindexofmobilenetworkconfiguration
<config_name>Stringtype,thenameofmobilenetworkconfiguration.
"Default"Defaultnetworkconfiguration
"ATT"ATTnetworkconfiguration,notsupport
VOLTE
"Verizon"Verizonnetworkconfiguration,notsupport
VOLTE
<config_version>Hextype,theversionofmobilenetworkconfiguration
<state> Integertype,thestateofmobilenetworkconfiguration
0Inactive
1Active
<flag> Integertype,itindicateswhethermodulehasactivateda
networkconfiguration.Ifnetworkconfigurationhasbeen
activated,Thethirdparameter<config_name>isthe
nameofactivatingnetworkconfiguration.
0Networkconfigurationhasbeenactivated
1Notanynetworkconfigurationisactivated
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
AftersettingAT+CMCFG=1,modulecanselectmobileoperator
configurationaccordingtoICCIDinformationinSIMcard
automatically,Ifnetworkconfigurationhaschanged,modulewillreboot
andmakeconfigurationeffective
Ifmoduleneedstoselectmobileoperatorconfigurationmanually,you
shoulddoasthefollowingsteps.
1)Settingmanualmode
AT+CMCFG=0
2)Activatespecifiedconfiguration
AT+CMCFG=2,<config_name>
3)Rebootthemodule
AT+CFUN=1,1
5.2.41AT+CSIMLOCKSIMLock
AT+CSIMLOCKSIMLock
TestCommandResponse
TAreturnsthelistofsupportedmodes.

---

## Page 116

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 116/281
AT+CSIMLOCK=?+CSIMLOCK:(listofsupported<facility>s),(listofsupported<mode>s>,
<pwlength>,<pclength>
Parameters
SeeWriteCommand
ReadCommand
AT+CSIMLOCK?Response
Parameters
SeeWriteCommand
WriteCommand
AT+CSIMLOCK=<facili
ty>,<mode>[,<passwor
d>[,<pers_code_list>]]If<mode>≠2andCommandissuccessful
If<mode>=2andCommandissuccessful
+CSIMLOCK:<status>,<pers_code_list>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>Iffailed:
Parameters
<facility>Stringtype,Phonesecuritylockssetbyfactoryorcustomer.
whichcanbe:
"PN"NetworkPersonalisation
<mode>0unlock
1lock
2querystatus
<pwlength>Integertype,maximumlengthof<password>,themaxinum
lengthis16.
<pclength>Integertype,maximumlengthof<pers_code_list>,the
maxinumlengthis160.
<password>Stringtype,passwordisusedtolockorunlocka<facility>.
<pers_code_list>Stringtype,codelistfordevicepersonalization.The
contentsdependontheselected<facility>.
If<facility>is"PN":
<pers_code_list>isintheformat:
"MCC1-MNC1[;MCC2-MNC2[…]]"
ItcontainsalistofpairsofMCCandMNC.MCCandMNC
isseparatedbya‘-‘,everypairofMCCandMNCis
separatedbysemicolon.
Forexample:
"460-00;460-01"
<status>Integertype,thestatusoflock
0lockisinactive
1lockisactive
ParameterSavingMode-
MaxResponseTime-

---

## Page 117

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 117/281
ReferenceNote
Lockdevice
CustomercansendATcommandtolockthedeivcethatcanonlyuse
somespecificSIMcard.
AT+CSIMLOCK="PN",1,"0123456789ABCDEF","460-00;460-01"
Unlockdevice
Ifthedeviceislocking,CustomercansendATcommandtounlockthe
device.
AT+CSIMLOCK="PN",0,"ABCDEFGH12345678"
Querydevicestatus
customermaysendATcommandasfollowtoquerystatusofthe
device
AT+CSIMLOCK="PN",2
5.2.42AT+CRATSRCHConfigureParameterforBetterRATSearch
AT+CRATSRCHConfigureParameterforBetterRATSearch
TestCommand
AT+CRATSRCH=?Response
TAreturnsthelistofsupportedmodes.
+CRATSRCH:(listofsupported<rat_timer>s),(listofsupported
<srch_align>),
Parameters
SeeWriteCommand
ReadCommand
AT+CRATSRCH?Response
+CRATSRCH:<rat_timer>,<srch_align>
Parameters
SeeWriteCommand
WriteCommand
AT+CRATSRCH=<rat_t
imer>,<srch_align>OK
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>Iffailed:
Parameters
<rat_timer>Integertype,<rat_timer>istimeoutforbetterRAT(radio
accesstechnology)search.Thedefaultvalueis60,expressed
inminutes.ForSIM7000seriesmodules,thepriorityofRATis
asfollows:
CAT-M>NB-IOT>GSM
IfUEhasregisteredsuccessfullyGSMnetwork,itwilltryto
searchCAT-MandNB-IOTnetworkafterthetimerexpiring.

---

## Page 118

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 118/281
<srch_align>Integertype,<srch_align>specifiesanintervalbefore
eDRXpagewhenascanshouldbegin.Thedefaultvalueis
20,expressedinminutes.
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
5.2.43AT+SPWMGeneratethePulse-Width-Modulation
AT+SPWMGeneratethePulse-Width-Modulation
TestCommand
AT+SPWM=?Response
+SPWM:(listofsupported<div>s),(listofsupported<level>s)
Parameters
SeeWriteCommand
WriteCommand
AT+SPWM=<div>,<lev
el>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<div>Therangeof<div>is0-31,theoutputfrequencyequalsto
(192KHz)/(period+1).
<level>0-100:tonelevel,whichcanbeconvertedtodutyratio.
ReferenceNote
Theequationoffinalfrequencyand<period>isthis:
frequency=192KHz/(period+1),whendivis0or1,theperiodis1.
Whendivis2,theperiodis1.5.Whendivis3,theperiodis2.When
divis4,theperiodis2.5……..
Theequationof<level>anddutyfactoris:dutyfactor=(level+1).
5.2.44AT+CASRIPShowRemoteIPaddressandPortWhenReceivedData
AT+CASRIPShowRemoteIPAddressandPortWhenReceivedData
ReadCommand
AT+CASRIP?Response
+CASRIP:<mode>

---

## Page 119

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 119/281
Parameters
SeeWriteCommand
WriteCommand
AT+CASRIP=<mode>Response
ERROR
Parameters
<mode>AnumericparameterwhichshowsremoteIPaddressandport.
0Donotshowtheprompt
1Showtheprompt,theformatisasfollows:
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
5.2.45AT+CEDRXConfigureEDRXparameters
AT+CEDRXConfigureEDRXparameters
TestCommand
AT+CEDRX=?Response
+CEDRX:(0-3),(0-1),(0-15),(0-15)
ReadCommand
AT+CEDRX?Response
+CEDRX:<mode>,<enabled>,<ptw>,<cycle_length>
Parameters
SeeWriteCommand
WriteCommand
AT+CEDRX=<mode>,<
enabled>,<ptw>,<cycle
_length>Response
Iffailed:
+CMEERROR:<err>
Parameters
<mode>0GSM
1LTE
2NB-IoT
3CAT-M
<enabled>0Disable
1Enable
<ptw>Pagetimewindow
0-15

---

## Page 120

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 120/281
<cycle_length>0-15
ReferenceNote
Thevalue0-15ofptwseparatelymeans1280,2560,3840,5120,6400,
7680,8960,10240,11520,12800,14080,15360,16640,17920,19200,
20480.(ms)
Thevalue0-15ofcycle_lengthseparatelymeans5.12,10.24,20.48,
40.96,61.44,81.92,102.40,122.88,143.36,163.84,327.68,655.36,1310.
72,2621.44,5242.88,10485.76.(seconds)
Therehasnoeffectif<mode>is0or1.
Theedrxparameterscantakeeffectaftermodulerestarting
5.2.46AT+CPSMRDPReadPSMDynamicParameters
AT+CPSMRDPReadPSMDynamicParameters
TestCommand
AT+CPSMRDP=?Response
+CPSMRDP:(0,1)
ExecutionCommand
AT+CPSMRDPResponse
+CPSMRDP:
<mode>,<Requested_active_Time>,<Requested_Periodic_TAU>,<Net
work_Active_Time>,<Network_T3412_EXT_value>,<Network_T3412_v
alue>
Parameters
<mode>Integertype.DisableorenabletheuseofPSMintheUE.
0DisabletheuseofPSM
1EnabletheuseofPSM
<Requested_active_Time>Integertype.Requestedactivetime
value(T3324)tobeconfigedbyUEinE-UTRANnetwork.Unit:
second.
<Requested_Periodic_TAU>Integertype.Requestedextendedperiodic
TAUvalue(T3412_EXT)tobeconfigedbyUEinE-UTRAN
network.Unit:second.
<Network_Active_Time>Integertype.Networkassignactivetimer
value(T3324)inE-UTRANnetwork.If<network_Active_Time>is
0,itshowsthatnetworkdoesnotsupportPSM
feature.Unit:second.
<Network_T3412_EXT_value>Integertype.Networkassignextended
periodicTAUvalue(T3412_EXT)inE-UTRAN
network.Unit:second.
<Network_T3412_value>Integertype.NetworkassignperiodicTAU

---

## Page 121

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 121/281
value(T3412)inE-UTRANnetwork.Unit:second.
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
If<Network_T3412_EXT_value>isgreaterthan0,UEwillstartTAU
procedureaccordingto<Network_T3412_EXT_value>.
5.2.47AT+CPSMCFGConfigurePSMversionandMinimumThresholdValue
AT+CPSMCFGConfigurePSMversionandMinimumThresholdValue
TestCommand
AT+CPSMCFG=?Response
TAreturnsthelistofsupportedmodes.
+CPSMCFG:(listofsupported<threshold>s),(listofsupported
<psm_version>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CPSMCFG?Response
+CPSMCFG:<threshold>,<psm_version>
Parameters
SeeWriteCommand
WriteCommand
AT+CPSMCFG=<thres
hold>[,<psm_version>
]Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<threshold>Integertype.Minimumthresholdvalue(insecond)toenter
PSM.Therangefrom60to86400.Thedefaultvalueis60seconds.
<psm_version>Integertype.BitmasktoindicatePSMmodes(1-Enable/0-
Disable).Eachbitisconfiguredindependentyly.Therangefrom0to
15.Thedefaultvalueis15.
BIT0PSMwithoutnetworkcoordination
BIT1Rel12PSMwithoutcontextretention
BIT2Rel12PSMwithcontextretention
BIT3PSMinbetweeneDRXcycles
ParameterSavingMode-
MaxResponseTime-
ReferenceNote

---

## Page 122

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 122/281
5.2.48AT+CPSMCFGEXTConfigureModemOptimizationofPSM
AT+CPSMCFGEXTConfigureModemOptimizationofPSM
TestCommand
AT+CPSMCFGEXT=?Response
TAreturnsthelistofsupportedmodes.
+CPSMCFGEXT:(listofsupported<psm_opt_mask>s),(listofsupported
<max_oos_full_scans>s),(list of supported
<psm_duration_due_to_oos>s),(list of supported
<psm_randomization_window>s),(listofsupported<max_oos_time>s),
(listofsupported<early_wake_up_time>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CPSMCFGEXT?Response
+CPSMCFGEXT:
<psm_opt_mask>,<max_oos_full_scans>,<psm_duration_due_to_oos
>,<psm_randomization_window>,<max_oos_time>,<early_wake_up_ti
me>
Parameters
SeeWriteCommand
WriteCommand
AT+CPSMCFGEXT=<p
sm_opt_mask>[,<max
_oos_full_scans>[,<ps
m_duration_due_to_o
os>[,<psm_randomizat
ion_window>[,<max_o
os_time>[,<early_wake
_up_time>]]]]]Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<psm_opt_mask>Integertype.Therangeisfrom0to15.Thedefault
value
is10.
1stbitof<psm_opt_mask>isusedtoenable/disablePSMENTER
requestwithoutsendingPSM_READY_REQtoNAS.ThisisaquickPSM
operation.
2ndbitof<psm_opt_mask>isusedtoenable/disableOutof
Service(OoS)statusindicationfromModemtoAP.
3rdbitof<psm_opt_mask>isusedtoenable/disablelimited
servicestatusindicationfromModemtoAP.
4thbitof<psm_opt_mask>isusedtoenable/disabledeep-sleep
mode.IfPSMdurationislessthanthethresholdvalue.Ifenabled,itputsthe
deviceindeep-sleepmode,ifPSMisnotenteredduetonotmeeting
thresholdvalue.

---

## Page 123

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 123/281
<max_oos_full_scans>Integertype.Maximumnumberoffullscansto
waitbeforemodemdeclaresSYS_PSM_STATUS_OOSto
clients.Therangeisfrom1to100.Thedefaultvalueis2.
<psm_duration_due_to_oos>Integertype.PSMdurationusedbyPSM
daemonuponOOS/LimitedServiceindication,duetoservice
outage.Therangeisfrom120to4294967295.Thedefaultvalueis
120.Theunitissecond.
<psm_randomization_window>Integertype.PSMwakeuprandomization
windowtoavoidnetworkcongestionduetoallthePSMdevices
wakingupatthesametime.TheRangeisfrom1to1000.The
defaultvalueis5.Theunitis5.
<max_oos_time>Integertype.Maximumtimeinsecondstowaitbefore
declaringSYS_PSM_STATUS_OOStoclients.Therangeisfrom1
to65535.Theunitissecond.
<early_wakeup_time>Integertype.Devicewakesupearlytoaccount
forboot-upandacquisitiondelay.WhileprogrammingPMIC,PSM
daemonreducesPSMdurationbythisduration.Therangeisfrom
1to1000.Thedefaultvalueis3.Theunitissecond.
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
5.2.49AT+CPSMSTATUSEnableDeepSleepWakeupIndication
AT+CPSMSTATUSEnableDeepSleepWakeupIndication
TestCommand
AT+CPSMSTATUS=?Response
+CPSMSTATUS:(0-1)
Parameters
SeeWriteCommand
ReadCommand
AT+CPSMSTATUS?Response
+CPSMSTATUS:<enable>
Parameters
SeeWriteCommand
WriteCommand
AT+CPSMSTATUS=<e
nable>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>

---

## Page 124

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 124/281
Parameters
<enable>
0Disableindicationwhenmodemwakesupfromdeepsleep
1Enableindicationwhenmodemwakesupfromdeepsleep
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
5.2.50AT+CEDRXRDPeDRXReadDynamicParameters
AT+CEDRXRDPeDRXReadDynamicParameters
TestCommand
AT+CEDRXRDP=?Response
Parameters
SeeWriteCommand
ExecutionCommand
AT+CEDRXRDPResponse
+CEDRXRDP:
<AcT-type>[,<Requested_eDRX_value>[,<NW-provided_eDRX_value>[
,<Paging_time_window>]]]
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<AcT-type>Integertype,indicatesthetypeofaccesstechnology.This
AT-commandisusedtospecifytherelationshipbetweenthetype
ofaccesstechnologyandtherequestedeDRXvalue
0AccesstechnologyisnotusingEdrx
4E-UTRAN(CAT-M1)
5E-UTRAN(NB-S1mode)
<Requested_Edrx_value>Stringtype;halfabyteina4-bitformat.The
Edrxvaluereferstobit4to1ofoctet3oftheExtendedDRX
parametersinformationelement(seesub-clause10.5.5.32of
3GPPTS24.008).Forthecodingandthevaluerange,see
ExtendedDRXparametersinformationelementin3GPPTS
24.008Table10.5.5.32/3GPPTS24.008.
<NW-provided_eDRX_value>Stringtype;halfabyteina4-bitformat.The
edrxvalueReferstobit4to1ofoctet3oftheExtendedDRX
parametersinformationelement(seesub-clause10.5.5.32of
3GPPTS24.008).Forthecodingandthevaluerange,seethe
ExtendedDRXparametersinformationelementin3GPPTS

---

## Page 125

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 125/281
24.008Table10.5.5.32/3GPPTS24.008.
<Paging_time_window>Stringtype;halfabyteina4-bitformat.The
pagingtimewindowreferstobit8to5octet3oftheExtended
DRX.Parametersinformationelement(seesub-clause10.5.5.32
of3GPPTS24.008).Forthecodingandthevaluerange,seethe
ExtendedDRXparametersinformationelementin3GPPTS
24.008Table10.5.5.32/3GPPTS24.008.
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
5.2.51AT+CRAIConfigureReleaseAssistanceIndicationinNB-IOTnetwork
AT+CRAIConfigureReleaseAssistanceIndicationinNB-IOTnetwork
TestCommand
AT+CRAI=?Response
+CRAI:(listofsupported<rai>s),(listofsupported<valid>s),
Parameters
SeeWriteCommand
ReadCommand
AT+CRAI?Response
+CRAI:<rai>,<valid_time>
Parameters
SeeWriteCommand
WriteCommand
AT+CRAI=<rai>[,<valid
_time>]Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<rai>Integertype.Indicatesthevalueofthereleaseassistance
indication,refer3GPPTS24.301[83]subclause9.9.4.25.V
0Noinformationavailable
1TheMTexpectsthatexchangeofdatawillbecompletedwiththe
transmissionoftheESMDATATRANSPORTmessage.
2TheMTexpectsthatexchangeofdatawillbecompletedwiththe
receiptofanESMDATATRANSPORTmessage.
<valid_time>Integertype.<valid_time>isvalidtimeofreleaseassistance
indication.
0Thevalidtimeis1

---

## Page 126

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 126/281
1unlimitedtime
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
BeforeUEsendsthelastpacketofdata,AT+CRAIshouldbeexecuted
firstly.

---

## Page 127

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 127/281
6ATCommandsforGPRSSupport
6.1Overview
Command Description
AT+CGATT AttachordetachfromGPRSservice
AT+CGDCONT DefinePDPcontext
AT+CGACT PDPcontextactivateordeactivate
AT+CGPADDR ShowPDPaddress
AT+CGREG Networkregistrationstatus
AT+CGSMS SelectserviceforMOSMSmessages
AT+CEREG EPSNetworkRegistrationStatus
6.2DetailedDescriptionsofATCommandsforGPRSSupport
6.2.1AT+CGATTAttachorDetachfromGPRSService
AT+CGATTAttachorDetachfromGPRSService
TestCommand
AT+CGATT=?Response
+CGATT:(listofsupported<state>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CGATT?Response
+CGATT:<state>
Parameters
SeeWriteCommand
WriteCommand
AT+CGATT=<state>Response
IferrorisrelatedtoMEfunctionality:

---

## Page 128

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 128/281
+CMEERROR:<err>
Parameters
<state>IndicatesthestateofGPRSattachment
0Detached
1Attached
OthervaluesarereservedandwillresultinanERRORresponsetothe
WriteCommand.
ParameterSavingModeNO_SAVE
MaxResponseTime75seconds
Reference Note
6.2.2AT+CGDCONTDefinePDPContext
AT+CGDCONTDefinePDPContext
TestCommand
AT+CGDCONT=?Response
+CGDCONT:(rangeofsupported<cid>s),<PDP_type>,,,(listof
supported<d_comp>s),(listofsupported<h_comp>s)(listof
<ipv4_ctrl>s),(listof<emergency_flag>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CGDCONT?Response
+CGDCONT:
[<cid>,<PDP_type>,<APN>,<PDP_addr>,<d_comp>,<h_comp>,<ipv4_c
trl>,<emergency_flag>[<CR><LF>+CGDCONT:
<cid>,<PDP_type>,<APN>,<PDP_addr>,<d_comp>,<h_comp>,<ipv4_ct
rl>,<emergency_flag>[...]]]
Parameters
SeeWriteCommand
WriteCommand
AT+CGDCONT=<cid>[,
<PDP_type>[,<APN>[,<
PDP_addr>[,<d_comp
>[,<h_comp>][,<ipv4_c
trl>[,<emergency_flag
>]]]]]]Response
ERROR
Parameters
<cid> (PDPContextIdentifier)anumericparameterwhich
specifiesaparticularPDPcontextdefinition.Theparameter
islocaltotheTE-MTinterfaceandisusedinotherPDP
context-relatedcommands.Therangeofpermittedvalues

---

## Page 129

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 129/281
(minimumvalue=1)isreturnedbythetestformofthe
command.
1…24
<PDP_type>(PacketDataProtocoltype)Astringparameterwhich
specifiesthetypeofpacketdataprotocol.
IPInternetProtocol(IETFSTD5)
PPPPointtoPointProtocol
IPV6InternetProtocolVersion6
IPV4V6DualPDNStack
<APN>(AccessPointName)Astringparameter(stringshouldbe
includedinquotationmarks)whichisalogicalnamethatis
usedtoselecttheGGSNortheexternalpacketdata
network.Ifthevalueisnulloromitted,thenthesubscription
valuewillberequested.ThedefaultvalueisNULL.
<PDP_addr>AstringparameterthatidentifiestheMTintheaddress
spaceapplicabletothePDP.
Format:"<n>.<n>.<n>.<n>"where<n>=0..255
Ifthevalueisnullorequals0.0.0.0adynamicaddresswill
berequested.Theallocatedaddressmaybereadusingthe
+CGPADDRcommand.
<d_comp>AnumericparameterthatcontrolsPDPdatacompression
0Off(defaultifvalueisomitted)
1On
2V.42bis
<h_comp>AnumericparameterthatcontrolsPDPheadcompression
0Off(defaultifvalueisomitted)
1On
2RFC1144
3RFC2507
4RFC3095
<ipv4_ctrl>ParameterthatcontrolshowtheMT/TArequeststogetthe
IPv4addressinformation:
0AddressAllocationthroughNASSignaling
1on
<emergency_flag>Emergency_flag:
0Off(defaultifvalueisomitted)
1On
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
Reference Note
<cid>values17to24aresupportedfromMPSSJO1.0+onwards.

---

## Page 130

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 130/281
6.2.3AT+CGACTPDPContextActivateorDeactivate
AT+CGACTPDPContextActivateorDeactivate
TestCommand
AT+CGACT=?Response
+CGACT:(listofsupported<state>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CGACT?Response
+CGACT:<cid>,<state>[<CR><LF>+CGACT:<cid>,<state>…]
Parameters
SeeWriteCommand
WriteCommand
AT+CGACT=<state>[,<
cid>[,<cid>[,…]]]Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<state>IndicatesthestateofPDPcontextactivation
0Deactivated
1Activated
OthervaluesarereservedandwillresultinanERRORresponse
totheWriteCommand.
<cid>AnumericparameterwhichspecifiesaparticularPDPcontext
definition(see+CGDCONTCommand).Ifthe<cid>isomitted,it
onlyaffectsthefirstcid.
<cid>values17to24aresupportedfromMPSSJO1.0+
onwards.
1…24
ParameterSavingModeNO_SAVE
MaxResponseTime150seconds
ReferenceNote
ThiscommandisusedtotestPDPswithnetworksimulators.
SuccessfulactivationofPDPonrealnetworkisnotguaranteed.
6.2.4AT+CGPADDRShowPDPAddress
AT+CGPADDRShowPDPAddress
TestCommandResponse
+CGPADDR:(listofdefined<cid>s)

---

## Page 131

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 131/281
AT+CGPADDR=?
Parameters
SeeWriteCommand
WriteCommand
AT+CGPADDR=<cid>[,
<cid>[,…]]Response
+CGPADDR:<cid>,<PDP_addr>
[<CR><LF>+CGPADDR:<cid>,<PDP_addr>[…]]
IfSIMcardsupportsIPV4V6typeandthePDP_typeofthecommand
"AT+CGDCONT"definedisipv4v6:
[+CGPADDR:<cid>,<PDP_addr_IPV4>,<PDP_addr_IPV6>]
+CGPADDR:<cid>,<PDP_addr_IPV4>,<PDP_addr_IPV6>[...]]]
ERROR
Parameters
<cid>AnumericparameterwhichspecifiesaparticularPDPcontext
definition(see+CGDCONTCommand)
1…24
<PDP_addr>Stringtype,IPaddress
Format:<n>.<n>.<n>.<n>where<n>=0..255
<PDP_addr_IPV4>
AstringparameterthatidentifiestheMTintheaddressspace
applicabletothePDP.
<PDP_addr_IPV6>
AstringparameterthatidentifiestheMTintheaddressspace
applicabletothePDPwhenthesim_cardsupportsipv6.
Thepdptypemustbesetto"ipv6"or"ipv4v6"bythe
AT+CGDCONTcommand.
ExecutionCommand
AT+CGPADDRResponse
[+CGPADDR:<cid>,<PDP_addr>]
+CGPADDR:<cid>,<PDP_addr>[...]]]
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
IfSIMcardsupportsIPV4V6typeandthePDP_typeofthecommand
"AT+CGDCONT"definedisipv4v6:
[+CGPADDR:<cid>,<PDP_addr_IPV4>,<PDP_addr_IPV6>]
+CGPADDR:<cid>,<PDP_addr_IPV4>,<PDP_addr_IPV6>[...]]]

---

## Page 132

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 132/281
Parameters
SeeWriteCommand
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
<cid>values17to24aresupportedfromMPSSJO1.0+onwards.
Writecommandreturnsaddressprovidedbythenetworkifa
connectionhasbeenestablished.
6.2.5AT+CGREGNetworkRegistrationStatus
AT+CGREGNetworkRegistrationStatus
TestCommand
AT+CGREG=?Response
+CGREG:(listofsupported<n>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CGREG?Response
+CGREG:
<n>,<stat>[,<lac>,<ci>,<netact>[,[<Active-Time>],[<Periodic-RAU>],[<
GPRS-READY-timer>]]]
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
SeeWriteCommand
WriteCommand
AT+CGREG[=<n>]Response
ERROR
Parameters
<n>0Disablenetworkregistrationunsolicitedresultcode
1Enablenetworkregistrationunsolicitedresultcode+CGREG:
<stat>
2Enablenetworkregistrationandlocationinformation
unsolicitedresultcode+CGREG:<stat>[,<lac>,<ci>,<netact>]
4EnabledisplaygprstimeandperiodicRAU
<stat>
0Notregistered,MTisnotcurrentlysearchingan
operatortoregisterto.TheGPRSserviceisdisabled,theUEis

---

## Page 133

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 133/281
allowedtoattachforGPRSifrequestedbytheuser.
1Registered,homenetwork.
2Notregistered,butMTiscurrentlytryingtoattachor
searchinganoperatortoregisterto.TheGPRSserviceis
enabled,butanallowablePLMNiscurrentlynotavailable.The
UEwillstartaGPRSattachassoonasanallowablePLMNis
available.
3Registrationdenied,TheGPRSserviceisdisabled,theUE
isnotallowedtoattachforGPRSifitisrequestedbytheuser.
4Unknown
5Registered,roaming
<lac>Stringtype(stringshouldbeincludedinquotationmarks);two
bytelocationareacodeinhexadecimalformat(e.g."00C3"
equals195indecimal)
<ci>Stringtype(stringshouldbeincludedinquotationmarks);two
bytescellIDinhexadecimalformat
<netact>0User-specifiedGSMaccesstechnology
1GSMcompact
3GSMEGPRS
7User-specifiedLTEM1AGBaccesstechnology
9User-specifiedLTENBS1accesstechnology
<Active-Time>
Stringtype;onebyteinan8bitformat.RequestedActiveTime
value(T3324)tobeallocatedtotheUE.TherequestedActive
Timevalueiscodedasonebyte(octet3)oftheGPRSTimer2
informationelementcodedasbitformat(e.g."00100100"equals
4minutes).
<Periodic-RAU>
Stringtype;onebyteinan8bitformat.Requestedextended
periodicTAUvalue(T3412)tobeallocatedtotheUEin
E-UTRAN.TherequestedextendedperiodicTAUvalueiscoded
asonebyte(octet3)oftheGPRSTimer3informationelement
codedasbitformat(e.g."01000111"equals70hours).
<GPRS-READY-timer>
Stringtype;onebyteinan8bitformat.RequestedGPRSREADY
timervalue(T3314)tobeallocatedtotheUEinGERAN/UTRAN.
TherequestedGPRSREADYtimervalueiscodedasonebyte
(octet2)oftheGPRSTimerinformationelementcodedasbit
format(e.g."01000011"equals3decihoursor18minutes).
ParameterSavingMode-
MaxResponseTime-
Reference Note

---

## Page 134

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 134/281
6.2.6AT+CGSMSSelectServiceforMOSMSMessages
AT+CGSMSSelectServiceforMOSMSMessages
TestCommand
AT+CGSMS=?Response
+CGSMS:(listofcurrentlyavailable<service>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CGSMS?Response
+CGSMS:<service>
Parameters
SeeWriteCommand
WriteCommand
AT+CGSMS=<service>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<service>Anumericparameterwhichindicatestheserviceorservice
preferencetobeused
0PacketDomain(valueisnotreallysupportedandis
internallymappedto2)
1Circuitswitched(valueisnotreallysupportedandis
internallymappedto3)
2PacketDomainpreferred(usecircuitswitchedif
GPRSnotavailable)
3Circuitswitchedpreferred(usePacketDomainifcircuit
switchednotavailable)
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
ReferenceNote
6.2.7AT+CEREGEPSNetworkRegistrationStatus
AT+CEREGEPSNetworkRegistrationStatus
TestCommand
AT+CEREG=?Response
+CEREG:(listofsupported<n>s)

---

## Page 135

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 135/281
Parameters
SeeWriteCommand
ReadCommand
AT+CEREG?Response
when<n>=0,1,2andcommandsuccessful:
+CEREG:<n>,<stat>[,[<tac>],[<rac>],[<ci>],[<AcT>]]
when<n>=4andcommandsuccessful:
+CEREG:<n>,<stat>[,[<tac>],[<rac>],[<ci>],[<AcT>][,,[,[<Active-Time>]
,[<Periodic-TAU>]]]]
IferrorisrelatedtowrongATsyntaxoroperationnotallowed:
+CMEERROR:<err>
Parameters
SeeWriteCommand
WriteCommand
AT+CEREG[=<n>]Response
ERROR
Parameters
<n>0Disablenetworkregistrationunsolicitedresultcode
1Enablenetworkregistrationunsolicitedresultcode+CEREG:
<stat>
2Enablenetworkregistrationandlocationinformation
unsolicitedresultcode
+CEREG:<stat>[,[<tac>],[<rac>],[<ci>],[<AcT>]]
4ForaUEthatwantstoapplyPSM,enablenetwork
registrationandlocationinformationunsolicitedresultcode
+CEREG:<stat>[,[<tac>],[<rac>],[<ci>],[<AcT>][,,[,[<Active-
Time>],[<Periodic-RAU>]]]]
<stat>
0Notregistered,MTisnotcurrentlysearchinganoperatorto
registerto.TheGPRSserviceisdisabled,theUEisallowedto
attachforGPRSifrequestedbytheuser.
1Registered,homenetwork.
2Notregistered,butMTiscurrentlytryingtoattachor
searchinganoperatortoregisterto.TheGPRSserviceis
enabled,butanallowablePLMNiscurrentlynotavailable.The
UEwillstartaGPRSattachassoonasanallowablePLMNis
available.
3Registrationdenied,TheGPRSserviceisdisabled,theUE
isnotallowedtoattachforGPRSifitisrequestedbytheuser.

---

## Page 136

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 136/281
4Unknown
5Registered,roaming
<tac>Stringtype(stringshouldbeincludedinquotationmarks);two
bytelocationareacodeinhexadecimalformat(e.g."00C3"
equals195indecimal)
<ci>Stringtype(stringshouldbeincludedinquotationmarks);two
bytescellIDinhexadecimalformat
<AcT>0User-specifiedGSMaccesstechnology
7User-specifiedLTEM1AGBaccesstechnology
9User-specifiedLTENBS1accesstechnology
<Active-Time>
Stringtype;onebyteinan8bitformat.RequestedActiveTime
value(T3324)tobeallocatedtotheUE.TherequestedActive
Timevalueiscodedasonebyte(octet3)oftheGPRSTimer2
informationelementcodedasbitformat(e.g."00100100"equals
4minutes).
<Periodic-RAU>
Stringtype;onebyteinan8bitformat.Requestedextended
periodicTAUvalue(T3412)tobeallocatedtotheUEin
E-UTRAN.TherequestedextendedperiodicTAUvalueiscoded
asonebyte(octet3)oftheGPRSTimer3informationelement
codedasbitformat(e.g."01000111"equals70hours).
ParameterSavingMode-
MaxResponseTime-
Reference Note

---

## Page 137

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 137/281
7ATCommandsforIPApplication
7.1Overview
Command Description
AT+SAPBR BearersettingsforapplicationsbasedonIP
7.2DetailedDescriptionsofCommands
7.2.1AT+SAPBRBearerSettingsforApplicationsBasedonIP
AT+SAPBRBearerSettingsforApplicationsBasedonIP
TestCommand
AT+SAPBR=?Response
+SAPBR:(0-4),(1-3),"ConParamTag","ConParamValue"
Parameters
SeeWriteCommand
WriteCommand
AT+SAPBR=<cmd_typ
e>,<cid>[,<ConParamT
ag>,<ConParamValue>
]Response
If<cmd_type>=2
+SAPBR:<cid>,<Status>,<IP_Addr>
If<cmd_type>=4
+SAPBR:
<ConParamTag>,<ConParamValue>
UnsolicitedResultCode
+SAPBR<cid>:DEACT
Parameters
<cmd_type>

---

## Page 138

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 138/281
0Closebearer
1Openbearer
2Querybearer
3Setbearerparameters
4Getbearerparameters
<cid>Bearerprofileidentifier
<Status>
0Bearerisconnecting
1Bearerisconnected
2Bearerisclosing
3Bearerisclosed
<ConParamTag>Bearerparameter
"APN" Accesspointnamestring:maximum64
characters
"USER" Usernamestring:maximum32characters
"PWD" Passwordstring:maximum32characters
<ConParamValue>Bearerparamervalue
<IP_Addr>TheIPaddressofbearer
ParameterSavingModeNO_SAVE
MaxResponseTimeWhen<cmd_type>is1,85seconds
When<cmd_type>is0,65seconds
Reference Note
ThiscommandisappliedtoactivatesomeapplicationssuchasHTTP,FTP.

---

## Page 139

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 139/281
8ATCommandsforTCPIP
ApplicationToolkit
8.1Overview
Command Description
AT+CIPMUX Startupmulti-IPconnection
AT+CIPSTART StartupTCPorUDPconnection
AT+CIPSEND SenddatathroughTCPorUDPconnection
AT+CIPQSEND Selectdatatransmittingmode
AT+CIPACK Querypreviousconnectiondatatransmittingstate
AT+CIPCLOSE CloseTCPorUDPconnection
AT+CIPSHUT DeactivateGPRSPDPcontext
AT+CLPORT Setlocalport
AT+CSTT StarttaskandsetAPN,username,password
AT+CIICR BringupwirelessconnectionwithGPRS
AT+CIFSR GetlocalIPaddress
AT+CIFSREX GetLocalIPAddressextend
AT+CIPSTATUS Querycurrentconnectionstatus
AT+CDNSCFG Configuredomainnameserver
AT+CDNSGIP QuerytheIPaddressofgivendomainname
AT+CIPHEAD AddanIPheadatthebeginningofapackagereceived
AT+CIPATS Setautosendingtimer
AT+CIPSPRT Setpromptof‘>’whenmodulesendsdata
AT+CIPSERVER Configuremoduleasserver
AT+CIPCSGP SetGPRSforconnectionmode
AT+CIPSRIP ShowremoteIPaddressandportwhenreceiveddata
AT+CIPDPDP SetwhethertocheckstateofGPRSnetworktiming
AT+CIPMODE SelectTCPIPapplicationmode
AT+CIPCCFG Configuretransparenttransfermode
AT+CIPSHOWTP DisplaytransferprotocolinIPheadwhenreceiveddata
AT+CIPUDPMODEUDPextendedmode
AT+CIPRXGET Getdatafromnetworkmanually
AT+CIPRDTIMER Setremotedelaytimer
AT+CIPSGTXT SelectGPRSPDPcontext

---

## Page 140

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 140/281
AT+CIPSENDHEXSetCIPSENDDataFormattoHEX
AT+CIPHEXS SetOutput-dataFormatwithsuffix
AT+CIPTKA SetTCPkeepaliveparameters
AT+CIPOPTION EnableorDisableTCPnaglealgorithm
8.2DetailedDescriptionsofCommands
8.2.1AT+CIPMUXStartUpMulti-IPConnection
AT+CIPMUXStartUpMulti-IPConnection
TestCommand
AT+CIPMUX=?Response
+CIPMUX:(0,1)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPMUX?Response
+CIPMUX:<n>
Parameters
SeeWriteCommand
WriteCommand
AT+CIPMUX=<n>Response
Parameters
<n>0SingleIPconnection
1MultiIPconnection
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
OnlyinIPinitialstate,AT+CIPMUX=1iseffective;
OnlywhenmultiIPconnectionandGPRSapplicationarebothshut
down,AT+CIPMUX=0iseffective.
8.2.2AT+CIPSTARTStartUpTCPorUDPConnection

---

## Page 141

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 141/281
AT+CIPSTARTStartUpTCPorUDPConnection
TestCommand
AT+CIPSTART=?Response
1)IfAT+CIPMUX=0
+CIPSTART:(listofsupported<mode>),(<IPaddress>),(<port>)
+CIPSTART:(listofsupported<mode>),(<domainname>),(<port>)
2)IfAT+CIPMUX=1
+CIPSTART:(listofsupported<n>),(listofsupported<mode>),(<IP
address>),(<port>)
+CIPSTART:(listofsupported<n>),(listofsupported<mode>),(<domain
name>),(<port>)
Parameters
SeeWriteCommand
WriteCommand
1)IfsingleIPconnection
(+CIPMUX=0)
AT+CIPSTART=<mode
>,<IPaddress>,<port>
AT+CIPSTART=<mode
>,<domain
name>,<port>
2)Ifmulti-IPconnection
(+CIPMUX=1)
AT+CIPSTART=<n>,<
mode>,<address>,<po
rt>
AT+CIPSTART=<n>,<
mode>,<domain
name>,<port>Response
1)IfsingleIPconnection(+CIPMUX=0)
Ifformatisrightresponse
otherwiseresponse
IferrorisrelatedtoMEfunctionality:
+CMEERROR<err>
Responsewhenconnectionexists
ALREADYCONNECT
Responsewhenconnectionissuccessful
CONNECTOK
Otherwise
STATE:<state>
CONNECTFAIL
2)Ifmulti-IPconnection
(+CIPMUX=1)
Ifformatisright
OK,
otherwiseresponse
IferrorisrelatedtoMEfunctionality:
+CMEERROR<err>
Responsewhenconnectionexists
<n>,ALREADYCONNECT
Ifconnectionissuccessful
<n>,CONNECTOK
Otherwise
<n>,CONNECTFAIL
Parameters

---

## Page 142

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 142/281
<n> 0..7Anumericparameterwhichindicatestheconnection
number
<mode>Astringparameterwhichindicatestheconnectiontype
"TCP"EstablishaTCPconnection
"UDP"EstablishaUDPconnection
<IPaddress>AstringparameterwhichindicatesremoteserverIPaddress
<port> Remoteserverport
<domainname>Astringparameterwhichindicatesremoteserverdomain
name
<state>Astringparameterwhichindicatestheprogressofconnecting
0IPINITIAL
1IPSTART
2IPCONFIG
3IPGPRSACT
4IPSTATUS
5TCPCONNECTING/UDPCONNECTING/
SERVERLISTENING
6CONNECTOK
7TCPCLOSING/UDPCLOSING
8TCPCLOSED/UDPCLOSED
9PDPDEACT
InMulti-IPstate:
0IPINITIAL
1IPSTART
2IPCONFIG
3IPGPRSACT
4IPSTATUS
5IPPROCESSING
9PDPDEACT
ParameterSavingModeNO_SAVE
MaxResponseTimeWhenmodeismulti-IPstate,themaxresponsetime75seconds.
Whenmodeissinglestate,andthestateisIPINITIAL,themaxresponse
timeis160seconds.
ReferenceNote
ThiscommandallowsestablishmentofaTCP/UDPconnectiononly
whenthestateisIPINITIALorIPSTATUSwhenitisinsinglestate.In
multi-IPstate,thestateisinIPSTATUSonly.Soitisnecessaryto
process"AT+CIPSHUT"beforeuserestablishesaTCP/UDP
connectionwiththiscommandwhenthestateisnotIPINITIALorIP
STATUS.
Whenmoduleisinmulti-IPstate,beforethiscommandisexecuted,itis
necessarytoprocess"AT+CSTT,AT+CIICR,AT+CIFSR".

---

## Page 143

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 143/281
8.2.3AT+CIPSENDSendDataThroughTCPorUDPConnection
AT+CIPSENDSendDataThroughTCPorUDPConnection
TestCommand
AT+CIPSEND=?Response
1)ForsingleIPconnection(+CIPMUX=0)
+CIPSEND:<length>
2)FormultiIPconnection(+CIPMUX=1)
+CIPSEND:(0-7),<length>
Parameters
SeeWriteCommand
ReadCommand
AT+CIPSEND?Response
1)ForsingleIPconnection(+CIPMUX=0)
+CIPSEND:<size>
2)FormultiIPconnection(+CIPMUX=1)
+CIPSEND:<n>,<size>
Parameters
<n>Anumericparameterwhichindicatestheconnectionnumber
<size>Anumericparameterwhichindicatesthedatalengthsentatatime
WriteCommand
1)IfsingleIPconnection
(+CIPMUX=0)
AT+CIPSEND=<length
2)IfmultiIPconnection
(+CIPMUX=1)
AT+CIPSEND=<n>[,<le
ngth>]Response
ThisCommandisusedtosendchangeablelengthdata
IfsingleIPisconnected(+CIPMUX=0)
Ifconnectionisnotestablishedormoduleisdisconnected:
IferrorisrelatedtoMEfunctionality:
+CMEERROR<err>
Ifsendingissuccessful:
When+CIPQSEND=0
SENDOK
When+CIPQSEND=1
DATAACCEPT:<length>
Ifsendingfails:
SENDFAIL
IfmultiIPconnectionisestablished(+CIPMUX=1)
Ifconnectionisnotestablishedormoduleisdisconnected:
IferrorisrelatedtoMEfunctionality:
+CMEERROR<err>
Ifsendingissuccessful:
When+CIPQSEND=0

---

## Page 144

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 144/281
<n>,SENDOK
When+CIPQSEND=1
DATAACCEPT:<n>,<length>
Ifsendingfails:
<n>,SENDFAIL
Parameters
<n> Anumericparameterwhichindicatestheconnectionnumber
<length>Anumericparameterwhichindicatesthelengthofsending
data,itmustbelessthan<size>
ExecutionCommand
AT+CIPSEND
Response">",thentype
dataforsend,tap
CTRL+Ztosend,tap
ESCtocancelthe
operationResponse
ThisCommandisusedtosendchangeablelengthdata.
IfsingleIPconnectionisestablished(+CIPMUX=0)
Ifconnectionisnotestablishedormoduleisdisconnected:
IferrorisrelatedtoMEfunctionality:
+CMEERROR<err>
Ifsendingissuccessful:
When+CIPQSEND=0
SENDOK
When+CIPQSEND=1
DATAACCEPT:<length>
Ifsendingfails:
SENDFAIL
Note
ThisCommandcanonlybeusedinsingleIPconnectionmode
(+CIPMUX=0)andtosenddataontheTCPorUDPconnectionthathas
beenestablishedalready.Ctrl-Zisusedasaterminationsymbol.ESCis
usedtocancelsendingdata.Thereareatmost<size>byteswhichcanbe
sentatatime.
ParameterSavingModeNO_SAVE
MaxResponseTimeWhen+CIPQSEND=0andtheremoteservernoresponse,after645
seconds,"CLOSE"willbereported.
ReferenceNote
Thedatalengthwhichcanbesentdependsonnetworkstatus.
SetthetimethatsenddataautomaticallywiththeCommandof
AT+CIPATS.
Onlysenddataatthestatusofestablishedconnection.
8.2.4AT+CIPQSENDSelectDataTransmittingMode
AT+CIPQSENDSelectDataTransmittingMode

---

## Page 145

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 145/281
TestCommand
AT+CIPQSEND=?Response
+CIPQSEND:(0,1)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPQSEND?Response
+CIPQSEND:<n>
Parameter
SeeWriteCommand
WriteCommand
AT+CIPQSEND=<n>Response
Parameters
<n>
0Normalmode–whentheserverreceivesTCPdata,itwillresponse
SENDOK.
1Quicksendmode–whenthedataissenttomodule,itwillresponse
DATAACCEPT:<length>(ForsingleIPconnection(+CIPMUX=0))or
DATAACCEPT:<n>,<length>(FormultiIPconnection(+CIPMUX=1))
whilenotrespondingSENDOK.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
8.2.5AT+CIPACKQueryPreviousConnectionDataTransmittingState
AT+CIPACKQueryPreviousConnectionDataTransmittingState
TestCommand
AT+CIPACK=?Response
WriteCommand
IfmultiIPconnection
(+CIPMUX=1)
AT+CIPACK=<n>Response
+CIPACK:<txlen>,<acklen>,<nacklen>
Parameters
<n>Anumericparameterwhichindicatestheconnectionnumber
<txlen>Thedataamountwhichhasbeensent
<acklen>Thedataamountconfirmedsuccessfullybytheserver
<nacklen>Thedataamountwithoutconfirmationbytheserver
ExecutionCommandResponse

---

## Page 146

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 146/281
IfsingleIPconnection
(+CIPMUX=0)
AT+CIPACK+CIPACK:<txlen>,<acklen>,<nacklen>
Parameters
SeeWriteCommand
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
8.2.6AT+CIPCLOSECloseTCPorUDPConnection
AT+CIPCLOSECloseTCPorUDPConnection
TestCommand
AT+CIPCLOSE=?Response
WriteCommand
1)IfsingleIPconnection
(+CIPMUX=0)
AT+CIPCLOSE=<n>
2)IfmultiIPconnection
(+CIPMUX=1)
AT+CIPCLOSE=<id>,[<
n>]Response:
1)ForsingleIPconnection(+CIPMUX=0)
CLOSEOK
2)FormultiIPconnection(+CIPMUX=1)
<id>,CLOSEOK
Parameters
<n>0Slowclose
1Quickclose
<id>Anumericparameterwhichindicatestheconnectionnumber
ExecutionCommand
AT+CIPCLOSEResponse
Ifcloseissuccessfully:
CLOSEOK
Ifclosefails:
ERROR
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
AT+CIPCLOSEonlyclosesconnectionatcorrespondingstatusofTCP/UDP
stack.ToseethestatususeAT+CIPSTATUScommand.Statusshouldbe:
TCPCONNECTING,UDPCONNECTING,SERVERLISTENINGor
CONNECTOKinsingle-connectionmode(see<state>parameter);
CONNECTINGorCONNECTEDinmulti-connectionmode(see<client
state>);
OPENINGorLISTENINGinmulti-connectionmode(see<serverstate>).
Otherwiseitwillreturn"ERROR".

---

## Page 147

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 147/281
8.2.7AT+CIPSHUTDeactivateGPRSPDPContext
AT+CIPSHUTDeactivateGPRSPDPContext
TestCommand
AT+CIPSHUT=?Response
ExecutionCommand
AT+CIPSHUTResponse
Ifcloseissuccessful:
SHUTOK
Ifclosefails:
ERROR
ParameterSavingModeNO_SAVE
MaxResponseTime65seconds
ReferenceNote
Ifthiscommandisexecutedinmulti-connectionmode,alloftheIP
connectionwillbeshut.
UsercanclosegprspdpcontextbyAT+CIPSHUT.Afteritisclosed,the
statusisIPINITIAL.
If"+PDP:DEACT"urcisreportedwhichmeansthegprsisreleasedby
thenetwork,thenuserstillneedstoexecute"AT+CIPSHUT"command
tomakePDPcontextcomebacktooriginalstate.
8.2.8AT+CLPORTSetLocalPort
AT+CLPORTSetLocalPort
TestCommand
AT+CLPORT=?Response
1)ForsingleIPconnection(+CIPMUX=0)
+CLPORT:("TCP","UDP"),(0-65535)
2)FormultiIPconnection(+CIPMUX=1)
+CLPORT:(0-7),("TCP","UDP"),(0-65535)
Parameters
SeeWriteCommand
ReadCommand
AT+CLPORT?Response
1)ForsingleIPconnection(+CIPMUX=0)
+CLPORT:<TCPport>,<UDPport>
2)FormultiIPconnection(+CIPMUX=1)

---

## Page 148

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 148/281
+CLPORT:0,<TCPport>,<UDPport>
+CLPORT:1,<TCPport>,<UDPport>
+CLPORT:2,<TCPport>,<UDPport>
+CLPORT:3,<TCPport>,<UDPport>
+CLPORT:4,<TCPport>,<UDPport>
+CLPORT:5,<TCPport>,<UDPport>
+CLPORT:6,<TCPport>,<UDPport>
+CLPORT:7,<TCPport>,<UDPport>
Parameters
SeeWriteCommand
WriteCommand
1)ForsingleIP
connection
(+CIPMUX=0)
AT+CLPORT=<mode>,
<port>
2)FormultiIP
connection
(+CIPMUX=1)
AT+CLPORT=<n>,<mo
de>,<port>Response
ERROR
Parameters
<n> 0..7Anumericparameterwhichindicatestheconnection
numberthisusedinmultiIPconnection
<mode>Astringparameterwhichindicatestheconnectiontype
"TCP"TCPlocalport
"UDP"UDPlocalport
<port>0-65535Anumericparameterwhichindicatesthelocalport.
Defaultvalueis0,aportcanbedynamicallyallocatedaport.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
ThiscommandwillbeeffectivewhenmoduleissetasaClient.
8.2.9AT+CSTTStartTaskandSetAPN,USERNAME,PASSWORD
AT+CSTTStartTaskandSetAPN,USERNAME,PASSWORD
TestCommand
AT+CSTT=?Response
+CSTT:"APN","USER","PWD"
Parameters
SeeWriteCommand
ReadCommand
AT+CSTT?Response
+CSTT:<apn>,<username>,<password>

---

## Page 149

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 149/281
Parameters
SeeWriteCommand
WriteCommand
AT+CSTT=<apn>,<use
rname>,<password>Response
ERROR
Parameters
<apn> AstringparameterwhichindicatestheGPRSaccesspoint
name.Themaxlengthis50bytes.Defautlvalueis"CMNET".
<username>AstringparameterwhichindicatestheGPRSusername.
Themaxlengthis50bytes.
<password>AstringparameterwhichindicatestheGPRSpassword.
Themaxlengthis50bytes.
ParameterSavingModeNO_SAVE
MaxResponseTime-
ExecutionCommand
AT+CSTTResponse
ERROR
ReferenceNote
Thewritecommandandexecutioncommandofthiscommandisvalidonly
atthestateofIPINITIAL.Afterthiscommandisexecuted,thestatewillbe
changedtoIPSTART.
8.2.10AT+CIICRBringUpWirelessConnectionwithGPRS
AT+CIICRBringUpWirelessConnectionwithGPRS
TestCommand
AT+CIICR=?Response
ExecutionCommand
AT+CIICRResponse
ERROR
ParameterSavingModeNO_SAVE
MaxResponseTime85seconds
ReferenceNote
AT+CIICRonlyactivatesmovingsceneatthestatusofIPSTART,after
operatingthisCommandisexecuted,thestatewillbechangedtoIP
CONFIG.
Aftermoduleacceptstheactivatedoperation,ifitisactivated
successfully,modulestatewillbechangedtoIPGPRSACT,andit
respondsOK,otherwiseitwillrespondERROR.

---

## Page 150

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 150/281
8.2.11AT+CIFSRGetLocalIPAddress
AT+CIFSRGetLocalIPAddress
TestCommand
AT+CIFSR=?Response
ExecutionCommand
AT+CIFSRResponse
<IPaddress>
ERROR
Parameter
<IPaddress>AstringparameterwhichindicatestheIPaddressassigned
fromGPRS
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
OnlyafterPDPcontextisactivated,localIPaddresscanbeobtainedby
AT+CIFSR,otherwiseitwillrespondERROR.Toseethestatususe
AT+CIPSTATUScommand.Statusshouldbe:
IPGPRSACT,TCPCONNECTING,UDPCONNECTING,SERVER
LISTENING,IPSTATUS,CONNECTOK,TCPCLOSING,UDPCLOSING,
TCPCLOSED,UDPCLOSEDinsingle-connectionmode(see<state>
parameter);
IPSTATUS,IPPROCESSINGinmulti-connectionmode(see<state>
parameter).
8.2.12AT+CIFSREXGetLocalIPAddressextend
AT+CIFSREXGetLocalIPAddressextend
TestCommand
AT+CIFSREX=?Response
ExecutionCommand
AT+CIFSREXResponse
+CIFSREX:<IPaddress>
Parameter
<IPaddress>AstringparameterwhichindicatestheIPaddressassigned
fromGPRS
ParameterSavingModeNO_SAVE

---

## Page 151

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 151/281
MaxResponseTime-
ReferenceNote
OnlyafterPDPcontextisactivated,localIPaddresscanbeobtainedby
AT+CIFSR,otherwiseitwillrespondERROR.Toseethestatususe
AT+CIPSTATUScommand.Statusshouldbe:
IPGPRSACT,TCPCONNECTING,UDPCONNECTING,SERVER
LISTENING,IPSTATUS,CONNECTOK,TCPCLOSING,UDPCLOSING,
TCPCLOSED,UDPCLOSEDinsingle-connectionmode(see<state>
parameter);
IPSTATUS,IPPROCESSINGinmulti-connectionmode(see<state>
parameter).
8.2.13AT+CIPSTATUSQueryCurrentConnectionStatus
AT+CIPSTATUSQueryCurrentConnectionStatus
TestCommand
AT+CIPSTATUS=?Response
WriteCommand
IfmultiIPconnection
mode(+CIPMUX=1)
AT+CIPSTATUS=<n>Response
+CIPSTATUS:<n>,<bearer>,<TCP/UDP>,<IPaddress>,<port>,<client
state>
Parameters
SeeExecutionCommand
ExecutionCommand
AT+CIPSTATUSResponse
1)Ifinsingleconnectionmode(+CIPMUX=0)
STATE:<state>
2)Ifinmulti-connectionmode(+CIPMUX=1)
STATE:<state>
Ifthemoduleissetasserver
S:0,<bearer>,<port>,<serverstate>
C:<n>,<bearer>,<TCP/UDP>,<IPaddress>,<port>,<clientstate>
Parameters
<n> 0-7Anumericparameterwhichindicatestheconnection
number
<bearer> 0-1GPRSbearer,defaultis0
<serverstate>OPENING
LISTENING

---

## Page 152

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 152/281
CLOSING
<clientstate>INITIAL
CONNECTING
CONNECTED
REMOTECLOSING
CLOSING
CLOSED
<state> Astringparameterwhichindicatestheprogressof
connecting
0IPINITIAL
1IPSTART
2IPCONFIG
3IPGPRSACT
4IPSTATUS
5TCPCONNECTING/UDPCONNECTING
/SERVERLISTENING
6CONNECTOK
7TCPCLOSING/UDPCLOSING
8TCPCLOSED/UDPCLOSED
9PDPDEACT
InMulti-IPstate:
0IPINITIAL
1IPSTART
2IPCONFIG
3IPGPRSACT
4IPSTATUS
5IPPROCESSING
9PDPDEACT
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
8.2.14AT+CDNSCFGConfigureDomainNameServer
AT+CDNSCFGConfigureDomainNameServer
TestCommand
AT+CDNSCFG=?Response
+CDNSCFG:("PrimaryDNS"),("SecondaryDNS")
Parameters
SeeWriteCommand

---

## Page 153

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 153/281
ReadCommand
AT+CDNSCFG?Response
PrimaryDns:<pri_dns>
SecondaryDns:<sec_dns>
Parameter
SeeWriteCommand
WriteCommand
AT+CDNSCFG=<pri_d
ns>[,<sec_dns>]Response
ERROR
Parameters
<pri_dns>AstringparameterwhichindicatestheIPaddressofthe
primarydomainnameserver.Defaultvalueis0.0.0.0.
<sec_dns>AstringparameterwhichindicatestheIPaddressofthe
secondarydomainnameserver.Defaultvalueis0.0.0.0.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
8.2.15AT+CDNSGIPQuerytheIPAddressofGivenDomainName
AT+CDNSGIPQuerytheIPAddressofGivenDomainName
TestCommand
AT+CDNSGIP=?Response
WriteCommand
AT+CDNSGIP=<domai
nname>Response
ERROR
Ifsuccessful,return:
+CDNSGIP:1,<domainname>,<IP1>[,<IP2>]
Iffail,return:
+CDNSGIP:0,<dnserrorcode>
Parameters
<domainname>Astringparameterwhichindicatesthedomainname
<IP1>AstringparameterwhichindicatesthefirstIPaddress
correspondingtothedomainname
<IP2>AstringparameterwhichindicatesthesecondIPaddress
correspondingtothedomainname
<dnserrorcode>Anumericparameterwhichindicatestheerrorcode
8DNSCOMMONERROR

---

## Page 154

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 154/281
3NETWORKERROR
Therearesomeothererrorcodesaswell.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
8.2.16AT+CIPHEADAddanIPHeadattheBeginningofaPackageReceived
AT+CIPHEADAddanIPHeadattheBeginningofaPackageReceived
TestCommand
AT+CIPHEAD=?Response
+CIPHEAD:(listofsupported<mode>s)
Parameter
SeeWriteCommand
ReadCommand
AT+CIPHEAD?Response
+CIPHEAD:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CIPHEAD=<mode>Response
ERROR
Parameters
<mode>AnumericparameterwhichindicateswhetheranIPheader
isaddedtothereceiveddataornot.
0NotaddIPheader
1AddIPheader,theformatis:
1)ForsingleIPconnection(+CIPMUX=0)
+IPD,<datalength>:
2)FormultiIPconnection(+CIPMUX=1)
+RECEIVE,<n>,<datalength>:
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note

---

## Page 155

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 155/281
8.2.17AT+CIPATSSetAutoSendingTimer
AT+CIPATSSetAutoSendingTimer
TestCommand
AT+CIPATS=?Response
+CIPATS:(listofsupported<mode>s),(listofsupported<time>)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPATS?Response
+CIPATS:<mode>,<time>
Parameters
SeeWriteCommand
WriteCommand
AT+CIPATS=<mode>[,
<time>]Response
ERROR
Parameters
<mode>Anumericparameterwhichindicateswhethersettimerwhen
moduleissendingdata
0Notsettimerwhenmoduleissendingdata
1Settimerwhenmoduleissendingdata
<time>1..100Anumericparameterwhichindicatestheseconds
afterwhichthedatawillbesent
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
8.2.18AT+CIPSPRTSetPromptof‘>’WhenModuleSendsData
AT+CIPSPRTSetPromptof‘>’WhenModuleSendsData
TestCommand
AT+CIPSPRT=?Response
+CIPSPRT:(listofsupported<sendprompt>s)
Parameters
SeeWriteCommand
ReadCommand Response

---

## Page 156

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 156/281
AT+CIPSPRT? +CIPSPRT:<sendprompt>
Parameters
SeeWriteCommand
WriteCommand
AT+CIPSPRT=<send
prompt>Response
ERROR
Parameters
<sendprompt>Anumericparameterwhichindicateswhethertoecho
prompt‘>’aftermoduleissuesAT+CIPSENDcommand.
0Itshows"sendok"butdoesnotpromptecho‘>’whensendingis
successful.
1Itpromptsecho‘>’andshows"sendok"whensendingis
successful.
2Itneitherpromptsecho‘>’norshows"sendok"whensendingis
successful.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
8.2.19AT+CIPSERVERConfigureModuleasServer
AT+CIPSERVERConfigureModuleasServer
TestCommand
AT+CIPSERVER=?Response
+CIPSERVER:(0-CLOSESERVER,1-OPENSERVER),(1-65535)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPSERVER?Response
+CIPSERVER:<mode>[,<port>,<channelid>,<bearer>]
Parameters
SeeWriteCommand
WriteCommand
AT+CIPSERVER=<mo
de>[,<port>]Response
ERROR

---

## Page 157

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 157/281
Parameters
<mode>0Closeserver
1Openserver
<port>1..65535Listeningport
<channelid>Channelid
<bearer>GPRSbearer
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
ThiscommandisallowedtoestablishaTCPserveronlywhenthestateis
IPINITIALorIPSTATUSwhenitisinsinglestate.Inmulti-IPstate,the
stateisinIPSTATUSonly.
8.2.20AT+CIPCSGPSetGPRSforConnectionMode
AT+CIPCSGPSetGPRSforConnectionMode
TestCommand
AT+CIPCSGP=?Response
+CIPCSGP:1-GPRS,APN,USERNAME,PASSWORD
Parameters
SeeWriteCommand
ReadCommand
AT+CIPCSGP?Response
+CIPCSGP:<mode>,<apn>,<username>,<password>[,<rate>]
Parameters
SeeWriteCommand
WriteCommand
AT+CIPCSGP=<mode>
[,(<apn>,<user
name>,<password>)]Response
ERROR
Parameters
<mode>Anumericparameterwhichindicatesthewirelessconnection
mode
1setGPRSaswirelessconnectionmode
<apn>Astringparameterwhichindicatestheaccesspointname
<username>Astringparameterwhichindicatestheusername
<password>Astringparameterwhichindicatesthepassword
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note

---

## Page 158

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 158/281
8.2.21AT+CIPSRIPShowRemoteIPAddressandPortWhenReceivedData
AT+CIPSRIPShowRemoteIPAddressandPortWhenReceivedData
TestCommand
AT+CIPSRIP=?Response
+CIPSRIP:(listofsupported<mode>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPSRIP?Response
+CIPSRIP:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CIPSRIP=<mode>Response
ERROR
Parameters
<mode>AnumericparameterwhichshowsremoteIPaddressandport.
0Donotshowtheprompt
1Showtheprompt,theformatisasfollows:
1)ForsingleIPconnection(+CIPMUX=0)
RECVFROM:<IPADDRESS>:<PORT>
1)FormultiIPconnection(+CIPMUX=1)
+RECEIVE,<n>,<datalength>,<IPADDRESS>:<PORT>
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
8.2.22AT+CIPDPDPSetWhethertoCheckStateofGPRSNetworkTiming
AT+CIPDPDPSetWhethertoCheckStateofGPRSNetworkTiming
TestCommand
AT+CIPDPDP=?Response
+CIPDPDP:(listofsupported<mode>s,listofsupported<interval>,listof
supported<timer>)

---

## Page 159

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 159/281
Parameters
SeeWriteCommand
ReadCommand
AT+CIPDPDP?Response
+CIPDPDP:<mode>,<interval>,<timer>
Parameters
SeeWriteCommand
WriteCommand
AT+CIPDPDP=<mode>
[,<interval>,<timer>]Response
ERROR
Parameters
<mode>
0NotsetdetectPDP
1SetdetectPDP
<interval>
1<=interval<=180(s),defaultvalueis10.
<timer>
1<=timer<=10,defaultvalueis3.
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
If"+PDP:DEACT"urcisreportedbecauseofmodulenotattachingtogprs
foracertaintimeorotherreasons,userstillneedstoexecute
"AT+CIPSHUT"commandmakesPDPcontextcomebacktooriginalstate.
8.2.23AT+CIPMODESelectTCPIPApplicationMode
AT+CIPMODESelectTCPIPApplicationMode
TestCommand
AT+CIPMODE=?Response
+CIPMODE:(0-NORMALMODE,1-TRANSPARENTMODE)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPMODE?Response
+CIPMODE:<mode>

---

## Page 160

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 160/281
Parameters
SeeWriteCommand
WriteCommand
AT+CIPMODE=<mode
>Response
ERROR
Parameters
<mode>0Normalmode
1Transparentmode
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
8.2.24AT+CIPCCFGConfigureTransparentTransferMode
AT+CIPCCFGConfigureTransparentTransferMode
TestCommand
AT+CIPCCFG=?Response
+CIPCCFG:
(NmRetry:3-8),(WaitTm:1-10),(SendSz:1-1460),(esc:0,1),(Rxmode:0,1),(
RxSize:50-1460),(Rxtimer:20-1000)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPCCFG?Response
+CIPCCFG:
<NmRetry>,<WaitTm>,<SendSz>,<esc>,<Rxmode>,<RxSize>,<Rxtimer
Parameters
SeeWriteCommand
WriteCommand
AT+CIPCCFG=<NmRet
ry>,<WaitTm>,<SendS
z>,<esc>[,<Rxmode>,<
RxSize>,<Rxtimer>]Response
ERROR
Parameters
<NmRetry>NumberofretriestobemadeforanIPpacket.Default
valueis5.
<WaitTm>Numberof100msintervalstowaitforserialinputbefore
sendingthepacket.Defaultvalueis2.

---

## Page 161

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 161/281
<SendSz>Sizeinbytesofdatablocktobereceivedfromserialport
beforesending.Defaultvalueis1024.
<esc> Whetherturnontheescapesequence,defaultisTRUE.
0Turnofftheescapesequence
1Turnontheescapesequence
<Rxmode>Whethertosettimeintervalduringoutputdatafromserial
port.
0outputdatatoserialportwithoutinterval
1outputdatatoserialportwithin<Rxtimer>interval.
<RxSize>Outputdatalengthforeachtime.Defaultvalueis1460.
<Rxtimer>Timeinterval(ms)towaitforserialporttooutputdataagain.
Defaultvalue:50ms
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
Thiscommandwillbeeffectiveonlyinsingleconnectionmode
(+CIPMUX=0)
8.2.25AT+CIPSHOWTPDisplayTransferProtocolinIPHeadWhenReceivedData
AT+CIPSHOWTPDisplayTransferProtocolinIPHeadWhenReceivedData
TestCommand
AT+CIPSHOWTP=?Response
+CIPSHOWTP:(listofsupported<mode>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPSHOWTP?Response
+CIPSHOWTP:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CIPSHOWTP=<mo
de>Response
ERROR
Parameters
<mode>Anumericparameterwhichindicateswhethertodisplay
transferprotocolinIPheadertoreceiveddataornot
0Notdisplaytransferprotocol
1Displaytransferprotocol,theformatis"+IPD,

---

## Page 162

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 162/281
<datasize>,<TCP/UDP>:<data>"
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
Thiscommandwillbeeffectiveonlyinsingleconnectionmode
(+CIPMUX=0).
Onlywhen+CIPHEADissetto1,thesettingofthiscommandwillwork.
8.2.26AT+CIPUDPMODEUDPExtendedMode
AT+CIPUDPMODEUDPExtendedMode
TestCommand
AT+CIPUDPMODE=?Response
1)ForsingleIPconnection(+CIPMUX=0)
+CIPUDPMODE:(0-2),("(0-255).(0-255).(0-255).(0-255)"),(1-65535)
2)FormultiIPconnection(+CIPMUX=1)
+CIPUDPMODE:(0-5),(0-2),("(0-255).(0-255).(0-255).(0-255)"),(1-65535)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPUDPMODE?Response
1)ForsingleIPconnection(+CIPMUX=0)
+CIPUDPMODE:<mode>[,<IPaddress>,<Port>]
2)FormultiIPconnection(+CIPMUX=1)
+CIPUDPMODE:0,<mode>[,<IPaddress>,<Port>]
+CIPUDPMODE:1,<mode>[,<IPaddress>,<Port>]
+CIPUDPMODE:2,<mode>[,<IPaddress>,<Port>]
+CIPUDPMODE:3,<mode>[,<IPaddress>,<Port>]
+CIPUDPMODE:4,<mode>[,<IPaddress>,<Port>]
+CIPUDPMODE:5,<mode>[,<IPaddress>,<Port>]
+CIPUDPMODE:6,<mode>[,<IPaddress>,<Port>]
+CIPUDPMODE:7,<mode>[,<IPaddress>,<Port>]
Parameter
SeeWriteCommand
WriteCommand
1)ForsingleIPResponse

---

## Page 163

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 163/281
connection
(+CIPMUX=0)
AT+CIPUDPMODE=<m
ode>[,<IP
address>,<Port>]
2)FormultiIP
connection
(+CIPMUX=1)
AT+CIPUDPMODE=<n
>,<mode>[,<IP
address>,<Port>]or
ERROR
<n> 0-7Anumericparameterwhichindicatestheconnection
number
<mode>0UDPNormalMode
1UDPExtendedMode
2SetUDPaddresstobesent
<IPaddress>AstringparameterwhichindicatesremoteIPaddress
<port> Remoteport
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
8.2.27AT+CIPRXGETGetDatafromNetworkManually
AT+CIPRXGETGetDatafromNetworkManually
TestCommand
AT+CIPRXGET=?Response
IfsingleIPconnection(+CIPMUX=0)
+CIPRXGET:(listofsupported<mode>s),(listofsupported<reqlength>)
IfmultiIPconnection(+CIPMUX=1)
+CIPRXGET:(listofsupported<mode>s),(listofsupported<id>s),(listof
supported<reqlength>)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPRXGET?Response
+CIPRXGET:<mode>
Parameters
SeeWriteCommand
WriteCommand
1)IfsingleIPconnection
(+CIPMUX=0)
AT+CIPRXGET=<mode
>[,<reqlength>]Response
ERROR
1)ForsingleIPconnection
If"AT+CIPSRIP=1"isset,IPaddressandportarecontained.

---

## Page 164

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 164/281
2)IfmultiIPconnection
(+CIPMUX=1)
AT+CIPRXGET=<mode
>[,<id>,<reqlength>]if<mode>=1
+CIPRXGET:1[,<IPADDRESS>:<PORT>]
if<mode>=2
+CIPRXGET:2,<reqlength>,<cnflength>[,<IPADDRESS>:<PORT>]
1234567890…
if<mode>=3
+CIPRXGET:3,<reqlength>,<cnflength>[,<IPADDRESS>:<PORT>]
5151…
if<mode>=4
+CIPRXGET:4,<cnflength>
2)FormultiIPconnection
If"AT+CIPSRIP=1"isset,IPaddressandportiscontained.
if<mode>=1
+CIPRXGET:1[,<id>,<IPADDRESS>:<PORT>]
if<mode>=2
+CIPRXGET: 2,<id>,<reqlength>,<cnflength>[,<IP
ADDRESS>:<PORT>]
1234567890…
if<mode>=3
+CIPRXGET: 3,<id>,<reqlength>,<cnflength>[,<IP
ADDRESS>:<PORT>]
5151…
if<mode>=4
+CIPRXGET:4,<id>,<cnflength>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<mode>
0Disablegettingdatafromnetworkmanually,themoduleis
settonormalmode,datawillbepushedtoTEdirectly.
1Enablegettingdatafromnetworkmanually.
2Themodulecangetdata,butthelengthofoutputdatacan
notexceed1460bytesatatime.
3Similartomode2,butinHEXmode,whichmeansthe
modulecanget730bytesmaximumatatime.
4QueryhowmanydataarenotreadwithagivenID.
<id>Anumericparameterwhichindicatestheconnectionnumber

---

## Page 165

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 165/281
<reqlength>Requestednumberofdatabytes(1-1460bytes)toberead.
If<mode>=4,therangeof<reqlength>is0-2920bytes.
<cnflength>Confirmednumberofdatabytestoberead,whichmaybeless
than<length>.0indicatesthatnodatacanberead.
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
Toenablethisfunction,parameter<mode>mustbesetto1before
connection.
8.2.28AT+CIPRDTIMERSetRemoteDelayTimer
AT+CIPRDTIMERSetRemoteDelayTimer
TestCommand
AT+CIPRDTIMER=?Response
+CIPRDTIMER:(100-4000),(100-7000)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPRDTIMER?Response
+CIPRDTIMER:<rdsigtimer>,<rdmuxtimer>
Parameters
SeeWriteCommand
WriteCommand
AT+CIPRDTIMER=<rds
igtimer>,<rdmuxtimer>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<rdsigtimer>Remotedelaytimerofsingleconnection.Defaultvalueis
2000.
<rdmuxtimer>Remotedelaytimerofmulti-connections.Defaultvalueis
3500.
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
Thiscommandisusedtoshortenthedisconnecttimelocallywhenthe
remoteserverhasbeendisconnected.

---

## Page 166

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 166/281
8.2.29AT+CIPSGTXTSelectGPRSPDPcontext
AT+CIPSGTXTSelectGPRSPDPcontext
TestCommand
AT+CIPSGTXT=?Response
+CIPSGTXT:(0,1)
Parameters
SeeWriteCommand
WriteCommand
AT+CIPSGTXT=<mode
>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<mode>0SelectfirstPDPcontext
1SelectsecondPDPcontext
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
Thiscommandisusedtoselectpdpcontext,onlyformultiIPconnection
(+CIPMUX=1).
8.2.30AT+CIPSENDHEXSetCIPSENDDataFormattoHex
AT+CIPSENDHEXSetCIPSENDDataFormattoHEX
TestCommand
AT+CIPSENDHEX=?Response
+CIPSENDHEX:(0,1)
Parameters
SeeWriteCommand
WriteCommand
AT+CIPSENDHEX=<m
ode>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<mode>0ThedefaultformatofoutputdatainAT+CIPSEND.
1SettheinputdatainHEXformatwhenusingCIPSEND
commandtosenddata.
ParameterSavingModeNO_SAVE
MaxResponseTime-

---

## Page 167

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 167/281
ReferenceNote
8.2.31AT+CIPHEXSSetOutput-dataFormatwithsuffix
AT+CIPHEXSSetOutput-dataFormatwithsuffix
TestCommand
AT+CIPHEXS=?Response
+CIPHEXS:(listofsupported<mode>s)
Parameters
SeeWriteCommand
WriteCommand
AT+CIPHEXS=<mode>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<mode>0Thedefaultformatofoutputdata
1Settheoutputdatawithsuffix"0d0a"
2SettheoutputdatainHEXformatwithsuffix"0d0a".
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote:
Thiscommandisonlyavailablewhen"AT+CIPHEAD=1".
8.2.32AT+CIPTKASetTCPKeepaliveParameters
AT+CIPTKASetTCPKeepaliveParameters
TestCommand
AT+CIPTKA=?Response
+CIPTKA:(listofsupported<mode>s),(listofsupported
<keepIdle>s),(listofsupported<keepInterval>),(listof
supported<keepCount>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPTKA?Response
+CIPTKA:<mode>,<keepIdle>,<keepInterval>,<keepCount>

---

## Page 168

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 168/281
Parameters
SeeWriteCommand
WriteCommand
AT+CIPTKA=<mode>[,
<keepIdle>[,<keepInter
val>[,<keepCount>]]]Response
IferrorisrelatedtoMEfunctionality:
ERROR
Parameters
<mode>SetTCPkeepaliveoption.
0DisableTCPkeepalivemechanism
1EnableTCPkeepalivemechanism
<keepIdle>Integertype;Idletime(insecond)beforeTCPsendtheinitial
keepaliveprobe.
30-7200
<keepInterval>Intervaltime(insecond)betweenkeepaliveprobes
retransmission.
30-75-600
<keepCount>Integertype;Maximumnumberofkeepaliveprobestobe
sent.
1-9
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
8.2.33AT+CIPOPTIONEnableorDisableTCPnaglealgorithm
AT+CIPOPTIONEnableorDisableTCPnaglealgorithm
TestCommand
AT+CIPOPTION=?Response
+CIPOPTION:(listofsupported<mode>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CIPOPTION?Response
+CIPOPTION:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CIPOPTION=<modResponse

---

## Page 169

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 169/281
e> OK
IferrorisrelatedtoMEfunctionality:
ERROR
Parameters
<mode>ConfigtoenableordisableTCPnaglealgorithm
0EnableTCPnaglealgorithm
1DisableTCPnaglealgorithm
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note

---

## Page 170

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 170/281
9ATCommandsforHTTP(S)
Application
SIM7000serieshasanembeddedTCP/IPstackthatisdrivenbyATcommandsandenablesthehost
applicationtoeasilyaccesstheInternetHTTP(S)service.ThischapterisareferenceguidetoalltheAT
commandsandresponsesdefinedtousewiththeTCP/IPstackinHTTP(S)Service.
9.1Overview
ATCommand Description
AT+SHSSL SelectSSLConfigure
AT+SHCONF SetHTTP(S)Parameter
AT+SHCONN HTTP(S)Connection
AT+SHBOD SetBody
AT+SHBODEXT SetExtensionBody
AT+SHAHEAD AddHead
AT+SHPARA SetHTTP(S)Para
AT+SHCPARA ClearHTTP(S)Para
AT+SHCHEAD ClearHead
AT+SHSTATE QueryHTTP(S)ConnectionStatus
AT+SHREQ SetRequestType
AT+SHREAD ReadResponseValue
AT+SHDISC DisconnectHTTP(S)
AT+HTTPTOFS Downloadfiletoapfilesystem
AT+HTTPTOFSRL Stateofdownloadfiletoapfilesystem
9.2DetailedDescriptionsofCommands

---

## Page 171

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 171/281
9.2.1AT+SHSSLSelectSSLConfigure
AT+SHSSLSelectSSLConfigure
Testcommand
AT+SHSSL=?Response
+SHSSL:(0-5),"calist","certname"
Readcommand
AT+SHSSL?Response
+SHSSL:<index>,<calist>,<certname>
Writecommand
AT+SHSSL=<index>,<ca
list>,<certname>Response
ERROR
Parameters
<index> CSSLCFGsetConfigureindex
<calist> CaCertificatename
<certname>CertCertificatename
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
Reference -
9.2.2AT+SHCONFSetHTTP(S)Parameter
AT+SHCONFSetHTTP(S)Parameter
Testcommand
AT+SHCONF=?Response
+SHCONF:"HTTPParamTag","HTTPParamValue"
Readcommand
AT+SHCONF?Response
+SHCONF:<HTTPParamTag>,<HTTPParamValue>
Writecommand
AT+SHCONF=<HTTPPar
amTag>,<HTTPParamVa
lue>Response
ERROR
Parameters
<HTTPParaTag> <HTTPParamValue>
"URL" ServerURLaddress(maxis64bytes)

---

## Page 172

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 172/281
"serverdomain[:tcpPort]"
"TIMEOUT" Holdoncerequesttime.
Unitissecond.Default60s.range:30-1800
"BODYLEN" Setbodymaxlength(maxis1024bytes)
"HEADERLEN" Setheadmaxlength(maxis350bytes)
"IPVER" SetIPversion
0IPv4
1IPv6
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
ReferenceNote:
MustsetURL,BODYLEN,HEADERLENvalue,TIMEOUTdefaultis60s,
URLformatmust"http://xxx.xx.xx"or"https://xxx.xx.xx"
9.2.3AT+SHCONNHTTP(S)Connection
AT+SHCONNHTTP(S)Connection
Executioncommand
AT+SHCONNResponse
ERROR
ParameterSavingMode-
MaxResponseTime-
Reference -
9.2.4AT+SHBODSetBody
AT+SHBODSetBody
Testcommand
AT+SHBOD=?Response
+SHBOD:"body",<bodylen>
Readcommand
AT+SHBOD?Response
+SHBOD:<body>,<bodylen>
Writecommand
AT+SHBOD=<body>,<b
odylen>Response

---

## Page 173

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 173/281
ERROR
Parameters
<body>Setbodyvalue(maxlengthisSHCONFSetvalue)
<bodylen>Setbodylength(maxlengthisSHCONFSetvalue)
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
ReferenceNote:
Mustbeexecutedaftertheconnection
9.2.5AT+SHBODEXTSetExtensionBody
AT+SHBODEXTSetExetensionBody
TestCommand
AT+SHBODEXT=?Response
+SHBODEXT:(rangeofsupported<bodylen>s),(rangeofsupported
<timeout>s)
ReadCommand
AT+SHBODEXT?Response
+SHBODEXT:<body>,<len_body>
WriteCommand
AT+SHBODEXT=<len_body
>,<timeout>
<CR>textisentered
<ctrl-Z/ESC>
ESCquitswithoutsendingResponse
ERROR
Parameters
<body>Setbodyvalue(maxlengthisSHCONFSetvalue)
<len_body>Lengthof<body>.Maxvalueis<bodylen>.
<bodylen>Max length set by
"AT+SHCONF="BODYLEN",<bodylen>"
<timeout>Timeoutforautomaticallysendingediteddata
(100-10000ms)
ParameterSavingModeAUTO_SAVE
MaxResponseTime -
ReferenceNote:
Mustbeexecutedaftertheconnection
9.2.6AT+SHAHEADAddHead
AT+SHAHEADAddHead

---

## Page 174

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 174/281
Testcommand
AT+SHAHEAD=?Response
+SHAHEAD:"type",”value”
Readcommand
AT+SHAHEAD?Response
+SHAHEAD:<type>,<value>
Writecommand
AT+SHAHEAD=<type>,<
value>Response
ERROR
Parameters
<type>Headtype(maxlengthisSHCONFSetvalue)
<value>Headvalue(maxlengthisSHCONFSetvalue)
Note:Thesumoftypeandvaluemaxlengthis350
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
ReferenceNote:
Mustbeexecutedaftertheconnection
9.2.7AT+SHCHEADClearHead
AT+SHCHEADClearHead
ExecutionCommand
AT+SHCHEADResponse
ERROR
ParameterSavingMode-
MaxResponseTime-
ReferenceNote:
Mustbeexecutedaftertheconnection
9.2.8AT+SHPARASetHTTP(S)Para
AT+SHPARASetHTTP(S)Para
Testcommand
AT+SHPARA=?Response
+SHPARA:"key",”value”

---

## Page 175

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 175/281
Readcommand
AT+SHPARA?Response
+SHPARA:<key>,<value>
Writecommand
AT+SHPARA=<key>,<va
lue>Response
ERROR
Parameters
<key>Setkey(maxis64bytes)
<value>Setvalue(maxis64bytes)
ParameterSavingModeAUTO_SAVE
MaxResponseTime-
ReferenceNote:
Mustbeexecutedaftertheconnection.
9.2.9AT+SHCPARAClearHTTP(S)Para
AT+SHCPARAClearHTTP(S)Para
TestCommand
AT+SHCPARA=?Response
ExecutionCommand
AT+SHCPARAResponse
ERROR
ParameterSavingMode-
MaxResponseTime -
ReferenceNote:
Mustbeexecutedaftertheconnection.
9.2.10AT+SHSTATEQueryHTTP(S)ConnectionStatus
AT+SHSTATEQueryHTTP(S)ConnectionStatus
Readcommand
AT+SHSTATE?Response
+SHSTATE:<status>
Parameters
<status>

---

## Page 176

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 176/281
0ExpressionHTTP(S)disconnectstate；
1ExpressionHTTP(S)connectstate；
ParameterSavingMode-
MaxResponseTime-
Reference -
9.2.11AT+SHREQSetRequestType
AT+SHREQSetRequestType
Testcommand
AT+SHREQ=?Response
+SHREQ:url,(1-5)
Readcommand
AT+SHREQ?Response
+SHREQ:<url>,<type>
Writecommand
AT+SHREQ=<url>,<type
>Response
ERROR
UnsolicitedResultCode
+SHREQ:<typestring>,<StatusCode>,<DataLen>
Parameters
<url>Requestserverdomain(maxis512bytes)
<type>
1GET
2PUT
3POST
4PATCH
5HEAD
<typestring>StringoftypeareGET,PUT,POST,PATCH,HEAD.
<timeout>WaitingforResponsetime(defaultis60sec)
<StatusCode>HTTP(S)StatusCoderespondedbyremoteserver,it
identifierrefertoHTTP1.1(RFC2616)
100Continue
101SwitchingProtocols
200OK
201Created
202Accepted
203Non-AuthoritativeInformation
204NoContent

---

## Page 177

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 177/281
205ResetContent
206PartialContent
300MultipleChoices
301MovedPermanently
302Found
303SeeOther
304NotModified
305UseProxy
307TemporaryRedirect
400BadRequest
401Unauthorized
402PaymentRequired
403Forbidden
404NotFound
405MethodNotAllowed
406NotAcceptable
407ProxyAuthenticationRequired
408RequestTime-out
409Conflict
410Gone
411LengthRequired
412PreconditionFailed
413RequestEntityTooLarge
414Request-URITooLarge
415UnsupportedMediaType
416Requestedrangenotsatisfiable
417ExpectationFailed
500InternalServerError
501NotImplemented
502BadGateway
503ServiceUnavailable
504GatewayTime-out
505HTTP(S)Versionnotsupported
<DataLen>Thelengthofdatagot
ParameterSavingMode-
MaxResponseTime-
ReferenceNote:
Mustbeexecutedaftertheconnection
9.2.12AT+SHREADReadResponseValue
AT+SHREADReadResponseValue

---

## Page 178

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 178/281
Testcommand
AT+SHREAD=?Response
+SHREAD:(0-306176),(1-306176)
Writecommand
AT+SHREAD=<startaddr
ess>,<datalen>Response
+SHREAD:<data_len>
<data>
+SHREAD:<data_len>
<data>
.....
ERROR
If<datalen>isbiggerthanthedatasizereceived,it’serror
If<datalen>isbiggerthan2048,willgotmultiURC+SHREAD
Parameters
<startaddress>Startaddressofdata
<datalen>Setreadvalueslength
<data_len>Returndatalengthmaxis2048bytesonce,
ifmorethan2048bytes,willreturnmanytimeruntilalldataare
readout
<data>Responsedata
ParameterSavingMode-
MaxResponseTime-
ReferenceNote:
Readdataafterrequest
9.2.13AT+SHDISCDisconnectHTTP(S)
AT+SHDISCDisconnectHTTP(S)
ExecutionCommand
AT+SHDISCResponse
ERROR
ParameterSavingMode-
MaxResponseTime-
Reference -

---

## Page 179

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 179/281
9.2.14AT+HTTPTOFSDownloadFiletoAPFileSystem
AT+HTTPTOFSDownloadFiletoAPFileSystem
TestCommand
AT+HTTPTOFS=?Response
+HTTPTOFS:(1-255),(1-127)
ReadCommand
AT+HTTPTOFS?Response
+HTTPTOFS:<status>,<url>,<file_path>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
SeeWriteCommand
WriteCommand
AT+HTTPTOFS=<url>,
<file_path>[,<timeout>
[,<retrycnt>]]Response
+HTTPTOFS:<StatusCode>,<DataLen>
Parameters
<status>
0Idle
1Busy
<url>Theurl
<file_path>
FilepathandnameonAPside,
Forexample:"/customer/test.bin","/custapp/test.bin","/fota/test.bin"
<timeout>TimeoutofHTTPrequest.Unitissecond.
Rangeis10-1000,defaultvalueis50.
<retrycnt>RetrytimesofHTTPrequest.
Rangeis5-100,defaultvalueis5.
<StatusCode>HTTPStatusCoderespondedbyremoteserver,it
identifierrefertoHTTP1.1(RFC2616)
100Continue
200OK
206PartialContent
400BadRequest
404NotFound
408RequestTime-out
500InternalServerError
600NotHTTPPDU
601NetworkError
602Nomemory
603DNSError
604StackBusy

---

## Page 180

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 180/281
620SSLcontinue
65535OtherErrors
<DataLen>
Thelengthofdatadownload
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
9.2.15AT+HTTPTOFSRLStateofDownloadFiletoAPFileSystem
AT+HTTPTOFSRLStateofDownloadFiletoAPFileSystem
TestCommand
AT+HTTPTOFSRL=?Response
ReadCommand
AT+HTTPTOFSRL?Response
+HTTPTOFSRL:<status>,<curlen>,<totallen>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<status>Downloadingstate
0Idle
1Duringdownloading
<curlen>Thelengthofdatahavebeendownloadsuccessfully
<totallen>Thelengthofdatadownload.Iftotallengthdoesnotbeengot,
<totallen>willbe0.
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote

---

## Page 181

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 181/281
10ATCommandsforFTPApplication
SIM7000serieshasanembeddedTCP/IPstackthatisdrivenbyATcommandsandenablesthehost
applicationtoeasilyaccesstheInternetFTPservice.ThischapterisareferenceguidetoalltheAT
commandsandresponsesdefinedforusingwiththeTCP/IPstackinFTPService.
10.1Overview
Command Description
AT+FTPPORTSetFTPcontrolport
AT+FTPMODESetactiveorpassiveFTPmode
AT+FTPTYPESetthetypeofdatatobetransferred
AT+FTPPUTOPTSetFTPputtype
AT+FTPCID SetFTPbearerprofileidentifier
AT+FTPRESTSetresumebrokendownload
AT+FTPSERVSetFTPserveraddress
AT+FTPUN SetFTPusername
AT+FTPPW SetFTPpassword
AT+FTPGETNAMESetdownloadfilename
AT+FTPGETPATHSetdownloadfilepath
AT+FTPPUTNAMESetuploadfilename
AT+FTPPUTPATHSetuploadfilepath
AT+FTPGET Downloadfile
AT+FTPPUT Setuploadfile
AT+FTPDELEDeletespecifiedfileinFTPserver
AT+FTPSIZE GetthesizeofspecifiedfileinFTPserver
AT+FTPSTATEGettheFTPstate
AT+FTPEXTPUTExtenduploadfile
AT+FTPMKD Makedirectoryontheremotemachine
AT+FTPRMD Removedirectoryontheremotemachine
AT+FTPLIST Listcontentsofdirectoryontheremotemachine
AT+FTPEXTGETExtenddownloadfile
AT+FTPETPUTUploadFile
AT+FTPETGETDownloadFile
AT+FTPQUIT QuitcurrentFTPsession
AT+FTPRENAMERenametheSpecifiedFileontheRemoteMachine

---

## Page 182

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 182/281
AT+FTPMDTMGettheLastModificationTimestampofSpecifiedFileontheRemoteMachine
10.2DetailedDescriptionsofCommands
10.2.1AT+FTPPORTSetFTPControlPort
AT+FTPPORTSetFTPControlPort
TestCommand
AT+FTPPORT=?Response
ReadCommand
AT+FTPPORT?Response
+FTPPORT:<value>
Parameters
SeeWriteCommand
WriteCommand
AT+FTPPORT=<value>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<value>ThevalueofFTPControlport,from1to65535.
Defaultvalueis21
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
Numbersabove65535areillegalastheportidentificationfieldsare16bits
longintheTCPheader.
10.2.2AT+FTPMODESetActiveorPassiveFTPMode
AT+FTPMODESetActiveorPassiveFTPMode
TestCommand
AT+FTPMODE=?Response
ReadCommand
AT+FTPMODE?Response
+FTPMODE:<value>

---

## Page 183

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 183/281
Parameters
SeeWriteCommand
WriteCommand
AT+FTPMODE=<value
>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<value>0ActiveFTPmode
1PassiveFTPmode
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
10.2.3AT+FTPTYPESettheTypeofDatatoBeTransferred
AT+FTPTYPESettheTypeofDatatoBeTransferred
TestCommand
AT+FTPTYPE=?Response
ReadCommand
AT+FTPTYPE?Response
+FTPTYPE:<value>
Parameters
SeeWriteCommand
WriteCommand
AT+FTPTYPE=<value>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<value>"A"ForFTPASCIIsessions
"I"ForFTPBinarysessions
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
WhenthisvalueissettoA,allthedatasentbythestacktotheFTPserver
ismadeof7bitscharacters(NVT-ASCII:theMSBissetto0).Asa
consequencebinarydatacontaining8bitscharacterswillbecorrupted
duringthetransferiftheFTPTYPEissettoA.

---

## Page 184

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 184/281
10.2.4AT+FTPPUTOPTSetFTPPutType
AT+FTPPUTOPTSetFTPPutType
TestCommand
AT+FTPPUTOPT=?Response
ReadCommand
AT+FTPPUTOPT?Response
+FTPPUTOPT:<value>
Parameters
SeeWriteCommand
WriteCommand
AT+FTPPUTOPT=<valu
e>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<value>"APPE"Forappendingfile
"STOU"Forstoringuniquefile
"STOR"Forstoringfile
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
10.2.5AT+FTPCIDSetFTPBearerProfileIdentifier
AT+FTPCIDSetFTPBearerProfileIdentifier
TestCommand
AT+FTPCID=?Response
Parameters
SeeWriteCommand
ReadCommand
AT+FTPCID?Response
+FTPCID:<value>
Parameter
SeeWriteCommand
WriteCommand
AT+FTPCID=<value>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>

---

## Page 185

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 185/281
Parameters
<value>BearerprofileidentifierrefertoAT+SAPBR
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
10.2.6AT+FTPRESTSetResumeBrokenDownload
AT+FTPRESTSetResumeBrokenDownload
TestCommand
AT+FTPREST=?Response
ReadCommand
AT+FTPREST?Response
+FTPREST:<value>
Parameters
SeeWriteCommand
WriteCommand
AT+FTPREST=<value>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<value>Brokenpointtoberesumed
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
10.2.7AT+FTPSERVSetFTPServerAddress
AT+FTPSERVSetFTPServerAddress
TestCommand
AT+FTPSERV=?Response
ReadCommand
AT+FTPSERV?Response
+FTPSERV:<value>
Parameters

---

## Page 186

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 186/281
SeeWriteCommand
WriteCommand
AT+FTPSERV=<value>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<value>32-bitnumberindotted-decimalnotation(i.e.xxx.xxx.xxx.xxx)
oralphanumericASCIItextstringupto49charactersifDNSisavailable
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
10.2.8AT+FTPUNSetFTPUserName
AT+FTPUNSetFTPUserName
TestCommand
AT+FTPUN=?Response
Parameters
SeeWriteCommand
ReadCommand
AT+FTPUN?Response
+FTPUN:<value>
Parameters
SeeWriteCommand
WriteCommand
AT+FTPUN=<value>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<value>AlphanumericASCIItextstringupto49characters.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
10.2.9AT+FTPPWSetFTPPassword

---

## Page 187

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 187/281
AT+FTPPWSetFTPPassword
TestCommand
AT+FTPPW=?Response
Parameters
SeeWriteCommand
ReadCommand
AT+FTPPW?Response
+FTPPW:<value>
Parameters
SeeWriteCommand
WriteCommand
AT+FTPPW=<value>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<value>AlphanumericASCIItextstringupto49characters.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
10.2.10AT+FTPGETNAMESetDownloadFileName
AT+FTPGETNAMESetDownloadFileName
TestCommand
AT+FTPGETNAME=?Response
ReadCommand
AT+FTPGETNAME?Response
+FTPGETNAME:<value>
Parameters
SeeWriteCommand
WriteCommand
AT+FTPGETNAME=<v
alue>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<value>AlphanumericASCIItextstringupto99characters
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note

---

## Page 188

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 188/281
10.2.11AT+FTPGETPATHSetDownloadFilePath
AT+FTPGETPATHSetDownloadFilePath
TestCommand
AT+FTPGETPATH=?Response
ReadCommand
AT+FTPGETPATH?Response
+FTPGETPATH:<value>
Parameters
SeeWriteCommand
WriteCommand
AT+FTPGETPATH=<val
ue>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<value>AlphanumericASCIItextstringupto255characters
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
10.2.12AT+FTPPUTNAMESetUploadFileName
AT+FTPPUTNAMESetUploadFileName
TestCommand
AT+FTPPUTNAME=?Response
ReadCommand
AT+FTPPUTNAME?Response
+FTPPUTNAME:<value>
Parameters
SeeWriteCommand
WriteCommand
AT+FTPPUTNAME=<va
lue>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>

---

## Page 189

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 189/281
Parameters
<value>AlphanumericASCIItextstringupto99characters
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
10.2.13AT+FTPPUTPATHSetUploadFilePath
AT+FTPPUTPATHSetUploadFilePath
TestCommand
AT+FTPPUTPATH=?Response
ReadCommand
AT+FTPPUTPATH?Response
+FTPPUTPATH:<value>
Parameters
SeeWriteCommand
WriteCommand
AT+FTPPUTPATH=<val
ue>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<value>AlphanumericASCIItextstringupto255characters
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
10.2.14AT+FTPGETDownloadFile
AT+FTPGETDownloadFile
TestCommand
AT+FTPGET=?Response
WriteCommand
AT+FTPGET=<mode>[,
<reqlength>]Response
Ifmodeis1anditisasuccessfulFTPgetsession:
+FTPGET:1,1

---

## Page 190

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 190/281
Ifdatatransferfinished:
+FTPGET:1,0
Ifmodeis1anditisafailedFTPgetsession:
+FTPGET:1,<error>
Ifmodeis2:
+FTPGET:2,<cnflength>
012345678…
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<mode>1ForopeningFTPgetsession
2ForreadingFTPdownloaddata.
<reqlength>Requestednumberofdatabytes(1-1460)toberead
<cnflength>Confirmednumberofdatabytestoberead,whichmaybeless
than<length>.0indicatesthatnodatacanberead.
<error>61Neterror
62DNSerror
63Connecterror
64Timeout
65Servererror
66Operationnotallow
70Replayerror
71Usererror
72Passworderror
73Typeerror
74Resterror
75Passiveerror
76Activeerror
77Operateerror
78Uploaderror
79Downloaderror
80Manualquit
ParameterSavingModeNO_SAVE
MaxResponseTime75seconds(Incasenoresponseisreceivedfromserver)
ReferenceNote
When"+FTPGET:1,1"isshown,thenuse"AT+FTPGET=2,<reqlength>"
toreaddata.Ifthemodulestillhasunreaddata,"+FTPGET:1,1"willbe
shownagaininacertaintime.

---

## Page 191

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 191/281
10.2.15AT+FTPPUTSetUploadFile
AT+FTPPUTSetUploadFile
TestCommand
AT+FTPPUT=?Response
WriteCommand
AT+FTPPUT=<mode>[,
<reqlength>]Response
Ifmodeis1anditisasuccessfulFTPgetsession:
+FTPPUT:1,1,<maxlength>
Ifmodeis1anditisafailedFTPgetsession:
+FTPPUT:1,<error>
Ifmodeis2and<reqlength>isnot0
+FTPPUT:2,<cnflength>
…… //Inputdata
+FTPPUT:1,1,1360
Ifmodeis2and<reqlength>is0,itwillrespondOK,andFTPsessionwill
beclosed
Ifdatatransferfinished.
+FTPPUT:1,0
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<mode>1ForopeningFTPputsession
2ForwritingFTPuploaddata.
<reqlength>Requestednumberofdatabytes(0-<maxlength>)tobe
transmitted
<cnflength>Confirmednumberofdatabytestobetransmitted
<maxlength>Themaxlengthofdatacanbesentatatime.Itdependson
thenetworkstatus.
<error>See"AT+FTPGET"
ParameterSavingModeNO_SAVE
MaxResponseTime75seconds(Incasenoresponseisreceivedfromserver)

---

## Page 192

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 192/281
ReferenceNote
When"+FTPPUT:1,1,<maxlength>"isshown,thenuse"AT+FTPPUT=2,
<reqlength>"towritedata.
10.2.16AT+FTPDELEDeleteSpecifiedFileinFTPServer
AT+FTPDELEDeleteSpecifiedFileinFTPServer
TestCommand
AT+FTPDELE=?Response
Parameters
SeeExecutionCommand
ExecutionCommand
AT+FTPDELEResponse
Ifsuccessed:
+FTPDELE:1,0
Iffailed:
+FTPDELE:1,<error>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<error>See"AT+FTPGET"
ParameterSavingModeNO_SAVE
MaxResponseTime75seconds(Incasenoresponseisreceivedfromserver)
ReferenceNote
Thefiletobedeletedisspecifiedbythe"AT+FTPGETNAME"and
"AT+FTPGETPATH"commands.
10.2.17AT+FTPSIZEGettheSizeofSpecifiedFileinFTPServer
AT+FTPSIZEGettheSizeofSpecifiedFileinFTPServer
TestCommand
AT+FTPSIZE=?Response
Parameters
SeeExecutionCommand
ExecutionCommandResponse

---

## Page 193

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 193/281
AT+FTPSIZE Ifsuccessed:
+FTPSIZE:1,0,<size>
Iffailed:
+FTPSIZE:1,<error>,0
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<error>See"AT+FTPGET"
<size> Thefilesize.Unit:byte
ParameterSavingModeNO_SAVE
MaxResponseTime75seconds(Incasenoresponseisreceivedfromserver)
ReferenceNote
Thefileisspecifiedbythe"AT+FTPGETNAME"and"AT+FTPGETPATH"
commands.
10.2.18AT+FTPSTATEGettheFTPState
AT+FTPSTATEGettheFTPState
TestCommand
AT+FTPSTATE=?Response
Parameters
SeeExecutionCommand
ExecutionCommand
AT+FTPSTATEResponse
+FTPSTATE:<state>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<state>
0Idle
1IntheFTPsession,includingFTPGET,FTPPUT,FTPDELEand
FTPSIZEoperation.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note

---

## Page 194

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 194/281
10.2.19AT+FTPEXTPUTExtendUploadFile
AT+FTPEXTPUTExtendUploadFile
TestCommand
AT+FTPEXTPUT=?Response
WriteCommand
AT+FTPEXTPUT=<mod
e>[,<pos>,<len>,<time
out>]Response
Ifmodeis0or1
Ifmodeis2
+FTPEXTPUT:<address>,<len>
…… //Inputdata
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<mode>0usedefaultFTPPUTmethod
1useextendFTPPUTmethod
2senddatatoRAMthroughserialport,thenFTPPUTmethod
willgetthedatafromRAM.
<pos>dataoffsetaddress0-300k
<len>datalength0-300k
<timeout>timeoutvalueofserialport.1000ms-1000000ms
<filename>Filenamelengthshouldlessorequal50characters.
<err>See"AT+FTPGET"
ParameterSavingModeNO_SAVE
MaxResponseTime75seconds(Incasenoresponseisreceivedfromserver)
ReferenceNote
WhenextendFTPPUTmodeisactivated,inputdatathenexecute
"AT+FTPPUT=1"totransmit,aftersessioniscomplete,ifsuccessful,it
returns"+FTPPUT:1,0",otherwiseitreturns"+FTPPUT:1,<error>",
<error>see"AT+FTPGET".
10.2.20AT+FTPMKDMakeDirectoryontheRemoteMachine
AT+FTPMKDMakeDirectoryontheRemoteMachine
TestCommand Response

---

## Page 195

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 195/281
AT+FTPMKD=? OK
ExecutionCommand
AT+FTPMKDResponse
Ifsuccess:
+FTPMKD:1,0
Iffailed:
+FTPMKD:1,<error>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<error>See"AT+FTPGET"
ParameterSavingModeNO_SAVE
MaxResponseTime75seconds(Incasenoresponseisreceivedfromserver)
Reference Note
Thecreatedfolderisspecifiedbythe"AT+FTPGETPATH"command.
10.2.21AT+FTPRMDRemoveDirectoryontheRemoteMachine
AT+FTPRMDRemoveDirectoryontheRemoteMachine
TestCommand
AT+FTPRMD=?Response
ExecutionCommand
AT+FTPRMDResponse
Ifsuccess:
+FTPRMD:1,0
Iffailed:
+FTPRMD:1,<error>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<error>See"AT+FTPGET"
ParameterSavingModeNO_SAVE

---

## Page 196

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 196/281
MaxResponseTime75seconds(Incasenoresponseisreceivedfromserver)
Reference Note
Theremovedfolderisspecifiedbythe"AT+FTPGETPATH"command.
10.2.22AT+FTPLISTListContentsofDirectoryontheRemoteMachine
AT+FTPLISTListContentsofDirectoryontheRemoteMachine
TestCommand
AT+FTPLIST=?Response
WriteCommand
AT+FTPLIST=<mode>[,
<reqlength>]Response
Ifmodeis1anditisasuccessfulFTPgetsession:
+FTPLIST:1,1
Ifdatatransferisfinished:
+FTPLIST:1,0
Ifmodeis1anditisafailedFTPgetsession:
+FTPLIST:1,<error>
Ifmodeis2:
+FTPLIST:2,<cnflength>
012345678…
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<mode>
1ForopeningFTPgetfilelistsession
2ForreadingFTPfilelist
<reqlength>Requestednumberofdatabytes(1-1460)toberead
<cnflength>Confirmednumberofdatabytestoberead,whichmaybe
lessthan<reqlength>.0indicatesthatnodatacanberead.
<error>See"AT+FTPGET"
ParameterSavingModeNO_SAVE
MaxResponseTime75seconds(Incasenoresponseisreceivedfromserver)
Reference Note
When"+FTPLIST:1,1"isshown,"AT+FTPLIST=2,<reqlength>"can

---

## Page 197

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 197/281
beusedtoreaddata.Ifthemodulestillhasunreaddata,"+FTPLIST:
1,1"willbeshownagaininacertaintime.
Ifusing"AT+FTPGETPATH"tosetadirectorypath,itwillreturnedthe
filescontentsunderthisdirectory;ifsetafilepath,itwillreturnthe
informationofthefilespecified.
10.2.23AT+FTPEXTGETExtendDownloadFile
AT+FTPEXTGETExtendDownloadFile
TestCommand
AT+FTPEXTGET=?Response
Parameters
SeeWriteCommand
ReadCommand
AT+FTPEXTGET?Response
+FTPEXTGET:<mode>,<length>
Parameters
SeeWriteCommand
WriteCommand
1)ifmodeis0or1
AT+FTPEXTGET=<mo
de>
3)ifmodeis3
AT+FTPEXTGET=<mo
de>,<pos>,<len>Response
Ifmodeis0:
Ifmodeis1andsuccessfullydownloaddata:
+FTPEXTGET:1,0
Ifmodeis1andfailedtodownloaddata:
+FTPEXTGET:1,<error>
Ifmodeis3andsuccessfullydownloaddata:
+FTPEXTGET:3,<length>
0123456…
If<filename>isalreadyexistinflash:
ERROR
Parameters
<mode>0usedefaultFTPGETmethod.
1openextendFTPgetsessionanddownloaddatatoRAM.
3readthedownloadeddatafromRAM,thenoutputittothe
serialport.

---

## Page 198

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 198/281
<filename>Filenamelengthshouldlessthanorequalto50characters.
<pos>dataoffsetshouldlessthan<length>.
<len>datalength0-300k.
<length>Thelengthofthedownloadeddatafromtheremotemachine.
<error>See"AT+FTPGET"
ParameterSavingModeNO_SAVE
MaxResponseTime75seconds(Incasenoresponseisreceivedfromserver)
Reference Note
Thedataitcangetis300katmost.
10.2.24AT+FTPETPUTUploadFile
AT+FTPETPUTUploadFile
TestCommand
AT+FTPETPUT=?Response
Parameters
SeeWriteCommand
WriteCommand
AT+FTPETPUT=<mode
>Response
Ifmodeis1andsuccessfullyopenPUTsession:
+FTPETPUT:1,1
Ifmodeis1andfailedtoopenPUTsession:
+FTPETPUT:1,<error>
Ifmodeis2:
+FTPETPUT:2,1
… //Inputdata
<ETX> //Tonotifythemodulethatalldatahasbeensent,switch
fromdatamodetocommandmode
Ifdatatransferfinished:
+FTPETPUT:1,0
Ifdatatransferfailed:
+FTPETPUT:1,<error>
Parameters

---

## Page 199

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 199/281
<mode>1ForopeningFTPETPUTsession.
2ForwritingFTPuploaddata.
<error>See"AT+FTPEXTGET"
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
TheTCP/IPstackwillonlyinterpretan<ETX>characterastheendof
thefiletobetransferredifit'snotprecededbya<DLE>character.Asa
consequencetheattachedhostmustsend<ETX>characterspreceded
by<DLE>charactersanditmustalsocode<DLE>charactersin
<DLE><DLE>.
10.2.25AT+FTPETGETDownloadFile
AT+FTPETGETDownloadFile
TestCommand
AT+FTPETGET=?Response
Parameters
SeeWriteCommand
WriteCommand
AT+FTPETGET=<mode
>Response
Ifmodeis1andsuccessfullyopenGETsession:
+FTPETGET:1,1
Ifdatatransferfinished:
0123456789…
<ETX> //Tonotifytheuserthatalldatatransferhasbeenfinished,
switchfromdatamodetocommandmode.
+FTPETGET:1,0
Ifmodeis1andfailedtodownloaddata:
+FTPETGET:1,<error>
Parameters
<mode>1OpenFTPETGETsessionanddownloaddata.
<error>See"AT+FTPEXTGET"
ParameterSavingModeNO_SAVE
MaxResponseTime-

---

## Page 200

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 200/281
ReferenceNote
Each<ETX>characterpresentinthepayloaddataoftheFTPflowwill
becodedbytheTCP/IPstackontheserialportas<DLE><ETX>.Each
<DLE>characterwillbecodedas<DLE><DLE>.Theattachedhost
mustthendecodetheFTPflowtoremovetheseescapecharacters.
10.2.26AT+FTPQUITQuitCurrentFTPSession
AT+FTPQUITQuitCurrentFTPSession
TestCommand
AT+FTPQUIT=?Response
ExecutionCommand
AT+FTPQUITResponse
IfthecurrentoperationisGETmethod:
+FTPGET:1,80
IfthecurrentoperationisPUTmethod:
+FTPPUT:1,80
IfFTPisinidlestate:
ERROR
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
10.2.27AT+FTPRENAMERenametheSpecifiedFileontheRemoteMachine
AT+FTPRENAMERenametheSpecifiedFileontheRemoteMachine
TestCommand
AT+FTRENAME=?Response
Parameters
SeeExecutionCommand
ExecutionCommand
AT+FTPRENAMEResponse
Ifsuccess:

---

## Page 201

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 201/281
+FTPRENAME:1,0
Iffailed:
+FTPRENAME:1,<error>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameter
<error>See"AT+FTPGET"
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
Thefileisspecifiedbythe"AT+FTPGETNAME"and
"AT+FTPGETPATH"commands.
Thenewfilenameissetby"AT+FTPPUTNAME"and
"AT+FTPPUTPATH"command.
10.2.28AT+FTPMDTMGettheLastModificationTimestampofSpecifiedFileonthe
RemoteMachine
AT+FTPMDTMGettheLastModificationTimestampofSpecifiedFileonthe
RemoteMachine
TestCommand
AT+FTPMDTM=?Response
Parameters
SeeExecutionCommand
ExecutionCommand
AT+FTPMDTMResponse
Ifsuccess:
+FTPMDTM:1,0,<timestamp>
Iffailed:
+FTPMDTM:1,<error>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameter
<error>See"AT+FTPGET"

---

## Page 202

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 202/281
<timestamp>Thelastmodificationtimestampofthespecifiedfile.
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
Thefileisspecifiedbythe"AT+FTPGETNAME"and"AT+FTPGETPATH"
commands.

---

## Page 203

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 203/281
11ATCommandforNTPfunction
11.1Overview
Command Description
AT+CNTPCID SetGPRSbearerprofile’sID
AT+CNTP Synchronizenetworktime
11.2DetailedDescriptionsofCommands
11.2.1AT+CNTPCIDSetGPRSBearerProfile’sID
AT+CNTPCIDSetGPRSBearerProfile’sID
TestCommand
AT+CNTPCID=?Response
+CNTPCID:(rangeofsupporded<cid>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CNTPCID?Response
+CNTPCID:<cid>
Parameters
SeeWriteCommand
WriteCommand
AT+CNTPCID=<cid>Response
IferrorisrelatedtoMEfunctionality:
ERROR
Parameters
<cid>Bearerprofileidentifier,refertoAT+SAPBR
ParameterSavingMode-
MaxResponseTime-

---

## Page 204

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 204/281
Reference Note
11.2.2AT+CNTPSynchronizeNetworkTime
AT+CNTPSynchronizeNetworkTime
TestCommand
AT+CNTP=?Response
+CNTP:(lengthof<ntpserver>),(rangeof<timezone>),(rangeof<cid>),
(rangeof<mode>)
Parameter
SeeWriteCommand
ReadCommand
AT+CNTP?Response
+CNTP:<ntpsever>,<timezone>,<cid>,<mode>
Parameter
SeeWriteCommand
WriteCommand
AT+CNTP=<ntp
server>[,<time
zone>][,<cid>][,<mode
>]Response
Parameter
<ntpserver>NTPserver’surl
<timezone>Localtimezone,therangeis(-47to48),infact,time
zonerange(-12to12),buttakingintoaccountthatsomecountriesand
regionswillusehalftimezone,orevenfourthtimezone,sotheentire
extendedfourtimezonesX,sothatwhenthetimezoneoftheinputintegers
areused,withouttheneedfordecimal.TimezoneinfrontoftheWestifitis
anegativenumberindicatesthetimezone.
<cid>Bearerprofileidentifier,refertoAT+SAPBR
<mode>printnetworktimeonuartandsettolocaltime
0Justsetnetworktolocaltime
1JustoutputnetworktimetoATport
2SetnetworktolocaltimeandoutputnetworktimetoATport
Executioncommand
AT+CNTPResponse
+CNTP:<code>[,<time>]
Parameter
<code>1Networktimesynchronizationissuccessful
61NetworkError
62DNSresolutionerror
63ConnectionErro
64Serviceresponseerror

---

## Page 205

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 205/281
65ServiceResponseTimeout
<time>Networktime
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
Aftersuccessfulsynchronizationtime,youcanuseAT+CCLKtoquery
localtime.

---

## Page 206

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 206/281
12ATCommandsforOneNet
Application
12.1Overview
Command Description
AT+MIPLCREATE CreateOneNetconfiguration
AT+MIPLDELETE DeleteOneNetconfiguration
AT+MIPLOPEN ConnecttoOneNet
AT+MIPLADDOBJ Addobject
AT+MIPLDELOBJ Deleteobject
AT+MIPLCLOSE DisconnecttoOneNet
AT+MIPLNOTIFY NotifydatatoOneNet
AT+MIPLREADRSP Sendresponseonreadcommand
AT+MIPLWRITERSP Sendresponseonwritecommand
AT+MIPLEXECUTERSPSendresponseonexecutecommand
AT+MIPLOBSERVERSPSendresponseonobservecommand
AT+MIPLDISCOVERRSPSendresponseondiscovercommand
AT+MIPLPARAMETERRSPSendresponseonparametercommand
AT+MIPLUPDATE Updateregistration
AT+MIPLVER VersionofOneNetSDK
AT+MIPLBOOTSTRAPBootstrapmode
+MIPLREAD Readrequesttouser
+MIPLWRITE Writerequesttouser
+MIPLEXECUTE Executerequesttouser
+MIPLOBSERVE Observerequesttouser
+MIPLDISCOVER Discoverrequesttouser
+MIPLPARAMETER Setparameterrequesttouser
+MIPLEVENT Eventindicationtouser

---

## Page 207

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 207/281
12.2DetailedDescriptionsofCommands
12.2.1AT+MIPLCREATECreateOneNetconfiguration
AT+MIPLCREATECreateOneNetconfiguration
TestCommand
AT+MIPLCREATE=?Response
+MIPLCREATE:<size>,<config>,<index>,<totalsize>,<flag>
Parameters
SeeWriteCommand
ExecutionCommand
AT+MIPLCREATEResponse
<ref>
WriteCommand
AT+MIPLCREATE=<siz
e>,<config>,<index>,<t
otalsize>,<flag>Response
<ref>
Parameters
<size>Current<config>size
<config>Configinhexformat
<index>Currentconfigindex
<totalsize>Totalconfigsize
<flag>Indicatetheinputisoverornot
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
12.2.2AT+MIPLDELETEDeleteOneNetconfiguration
AT+MIPLDELETEDeleteOneNetconfiguration
TestCommand
AT+MIPLDELETE=?Response
+MIPLDELETE:<ref>
Parameters
SeeWriteCommand
WriteCommand
AT+MIPLDELETE=<refResponse

---

## Page 208

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 208/281
> Parameters
<ref>Configid
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
12.2.3AT+MIPLOPENConnecttoOneNet
AT+MIPLOPENConnecttoOneNet
TestCommand
AT+MIPLOPEN=?Response
+MIPLOPEN:<ref>,<lifetime>,<param>
Parameters
SeeWriteCommand
WriteCommand
AT+MIPLOPEN=<ref>,<
lifetime>,<param>Response
Parameters
<ref> Configid
<lifetime>Lifetimetoupdateautomatically
<param>Reserved
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
12.2.4AT+MIPLADDOBJAddobject
AT+MIPLADDOBJAddobject
TestCommand
AT+MIPLADDOBJ=?Response
+MIPLADDOBJ:
<ref>,<objectid>,<instancecount>,<instanceBitmap>,<attributeCount>
,<actionCount>
Parameters
SeeWriteCommand
WriteCommand
AT+MIPLADDOBJ=<ref
>,<objectid>,<instanceResponse
Parameters

---

## Page 209

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 209/281
count>,<instanceBitm
ap>,<attributeCount>,<
actionCount><ref> Configid
<objectid> Objectid
<instancecount>Countofinstance
<instanceBitmap>Bitmapofinstance
<attributeCount>Countofattributeresource
<actionCount>Countofactionresource
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
12.2.5AT+MIPLDELOBJDeleteObject
AT+MIPLDELOBJDeleteobject
TestCommand
AT+MIPLDELOBJ=?Response
+MIPLDELOBJ:<ref>,<objectid>
Parameters
SeeWriteCommand
WriteCommand
AT+MIPLDELOBJ=<ref
>,<objectid>Response
Parameters
<ref>Configid
<object>Objectid
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
12.2.6AT+MIPLCLOSEDisconnecttoOneNet
AT+MIPLCLOSEDisconnecttoOneNet
TestCommand
AT+MIPLCLOSE=?Response
+MIPLCLOSE:<ref>
Parameters
SeeWriteCommand
WriteCommand Response

---

## Page 210

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 210/281
AT+MIPLCLOSE=<ref>OK
Parameters
<ref>Configid
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
12.2.7AT+MIPLNOTIFYNotifyDatatoOneNet
AT+MIPLNOTIFYNotifyDatatoOneNet
TestCommand
AT+MIPLNOTIFY=?Response
+MIPLNOTIFY:
<ref>,<msgid>,<objectid>,<instanceid>,<resourceid>,<valuetype>,<le
n>,<value>,<index>,<flag>[,<ackid>]
Parameters
SeeWriteCommand
WriteCommand
AT+MIPLNOTIFY=<ref>
,<msgid>,<objectid>,<i
nstanceid>,<resourcei
d>,<valuetype>,<len>,
<value>,<index>,<flag
>[,<ackid>]Response
Parameters
<ref>Configid
<objectid>Objectid
<instanceid>Instanceid
<resourceid>Resourceid
<valuetype>Typeofvalue
1String
2Opaque
3Integer
4Float
5Bool
<len>Length
<value>Valuestring
<index>Indexofcurrentinput
<flag>Indicatetheinputisoverornot
<ackid>Needackornot
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote

---

## Page 211

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 211/281
12.2.8AT+MIPLREADRSPSendResponseonReadCommand
AT+MIPLREADRSPSendResponseonReadCommand
TestCommand
AT+MIPLREADRSP=?Response
+MIPLREADRSP:
<ref>,<msgid>,<result>,<objectid>,<instanceid>,<resourceid>,<valuet
ype>,<len>,<value>,<index>,<flag>
Parameters
SeeWriteCommand
WriteCommand
AT+MIPLREADRSP=<r
ef>,<msgid>,<result>,<
objectid>,<instanceid>
,<resourceid>,<valuety
pe>,<len>,<value>,<in
dex>,<flag>Response
Parameters
<ref>Configid
<msgid>Messageid
<result>Result
<objectid>Objectid
<instanceid>Instanceid
<resourceid>Resourceid
<valuetype>Typeofvalue
1String
2Opaque
3Integer
4Float
5Bool
<len>Length
<value>Valuestring
<index>Indexofcurrentinput
<flag>Indicatetheinputisoverornot
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
12.2.9AT+MIPLWRITERSPSendResponseonWriteCommand
AT+MIPLWRITERSPSendResponseonWriteCommand
TestCommand
AT+MIPLWRITERSP=?Response
+MIPLWRITERSP:<ref>,<msgid>,<result>

---

## Page 212

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 212/281
Parameters
SeeWriteCommand
WriteCommand
AT+MIPLWRITERSP=<
ref>,<msgid>,<result>Response
Parameters
<ref>Configid
<msgid>Messageid
<result>Result
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
12.2.10AT+MIPLEXECUTERSPSendResponseonExecuteCommand
AT+MIPLEXECUTERSPSendResponseonExecuteCommand
TestCommand
AT+MIPLEXECUTERS
P=?Response
+MIPLEXECUTERSP:<ref>,<msgid>,<result>
Parameters
SeeWriteCommand
WriteCommand
AT+MIPLEXECUTERS
P=<ref>,<msgid>,<res
ult>Response
Parameters
<ref>Configid
<msgid>Messageid
<result>Result
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
12.2.11AT+MIPLOBSERVERSPSendResponseOnObserveCommand
AT+MIPLOBSERVERSPSendResponseonObserveCommand
TestCommand Response

---

## Page 213

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 213/281
AT+MIPLOBSERVERS
P=?+MIPLOBSERVERSP:<ref>,<msgid>,<result>
Parameters
SeeWriteCommand
WriteCommand
AT+MIPLOBSERVERS
P=<ref>,<msgid>,<res
ult>Response
Parameters
<ref>Configid
<msgid>Messageid
<result>Result
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
12.2.12AT+MIPLDISCOVERRSPSendResponseonDiscoverCommand
AT+MIPLDISCOVERRSPSendResponseonDiscoverCommand
TestCommand
AT+MIPLDISCOVERRS
P=?Response
+MIPLDISCOVERRSP:<ref>,<msgid>,<result>,<length>,<valuestring>
Parameters
SeeWriteCommand
WriteCommand
AT+MIPLDISCOVERRS
P=<ref>,<msgid>,<res
ult>,<length>,<valuestr
ing>Response
Parameters
<ref>Configid
<msgid>Messageid
<result>Result
<length>Numberofresourceid
<valuestring>Resourceidstring
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
12.2.13AT+MIPLPARAMETERRSPSendResponseonParameterCommand

---

## Page 214

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 214/281
AT+MIPLPARAMETERRSPSendResponseonParameterCommand
TestCommand
AT+MIPLPARAMETER
RSP=?Response
+MIPLPARAMETERRSP:<ref>,<msgid>,<result>
Parameters
SeeWriteCommand
WriteCommand
AT+MIPLPARAMETER
RSP=<ref>,<msgid>,<r
esult>Response
Parameters
<ref>Configid
<msgid>Messageid
<result>Result
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
12.2.14AT+MIPLUPDATEUpdateRegistration
AT+MIPLUPDATEUpdateRegistration
TestCommand
AT+MIPLUPDATE=?Response
+MIPLUPDATE:<ref>,<lifetime>,<flag>
Parameters
SeeWriteCommand
WriteCommand
AT+MIPLUPDATE=<ref
>,<lifetime>,<flag>Response
Parameters
<ref>Configid
<lifetime>Lifetimetoupdate
<flag>Updatewithobjectupdateornot
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
12.2.15AT+MIPLVERVersionofOneNetSDK

---

## Page 215

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 215/281
AT+MIPLVERVersionofOneNetSDK
ReadCommand
AT+MIPLVER?Response
+MIPLVER:<version>
Parameters
<version>VersionofSDK
ParameterSavingMode-
MaxResponseTime-
ReferenceNote
12.2.16AT+MIPLBOOTSTRAPBootstrapMode
AT+MIPLBOOTSTRAPBootstrapMode
WriteCommand
AT+MIPLBOOTSTRAP
=<mode>Response
Parameters
<mode>Bootstrapmode
0Disable
1Enable
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
12.2.17+MIPLREADReadRequesttoUser
+MIPLREADReadRequesttoUser
Response
+MIPLREAD:<ref>,<msgid>,<objectid>,<instanceid>,<resourceid>
Parameters
<ref>Integer,OneNETinstancereturnedbyAT+MIPLCREATE
<msgid>Integer,messageid
<objectid>Integer,objectid
<instanceid>Integer,instanceid,readallresourcesofallinstancesof
theobjectifinstanceidequals-1
<resourceid>Integer,resourceid,readallresourcesoftheinstanceif
resourceidequals-1

---

## Page 216

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 216/281
12.2.18+MIPLWRITEWriteRequesttoUser
+MIPLWRITEWriteRequesttoUser
Response
+MIPLWRITE:
<ref>,<msgid>,<objectid>,<instanceid>,<resourceid>,<valuetype>,<le
n>,<value>,<flag>,<index>
Parameters
<ref>Integer,OneNETinstancereturnedbyAT+MIPLCREATE
<msgid>Integer,messageid
<objectid>Integer,objectid
<instanceid>Integer,instanceid
<resourceid>Integer,resourceid
<valuetype>Integer,writedatavaluetype
1String
2Opaque
3Integer
0Float
5Bool
<len>Integer,writedatalength.Itcanbeommited,ifvaluetypeisInteger
orFloat,orBool
<value>Integer,writedatavalue
<flag>Integer,messageflag
1Firstmessage;
2Middlemessage;
0Lastmessage
<index>Integer,messageindex,from0to1024
12.2.19+MIPLEXECUTEExecuteRequesttoUser
+MIPLEXECUTEExecuteRequesttoUser
Response
+MIPLEXECUTE:
<ref>,<msgid>,<objectid>,<instanceid>,<resourceid>,<len>,<argumen
ts>
Parameters
<ref>Integer,OneNETinstancereturnedbyAT+MIPLCREATE
<msgid>Integer,messageid
<objectid>Integer,objectid
<instanceid>Integer,instanceid

---

## Page 217

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 217/281
<resourceid>Integer,resourceid
<len>Integer,parameterlength
<arguments>String,parameterstring
12.2.20+MIPLOBSERVEObserveRequesttoUser
+MIPLOBSERVEObserveRequesttoUser
Response
+MIPLOBSERVE:
<ref>,<msgid>,<flag>,<objectid>,<instanceid>,<resourceid>
Parameters
<ref>Integer,OneNETinstancereturnedbyAT+MIPLCREATE
<msgid>Integer,messageid
<flag>Integer,observeflag.
1Indicatesobserve
0Indicatescancelobserve
<objectid>Integer,objectid
<instanceid>Integer,instanceid,observeallresourcesofallinstances
oftheobjectifinstanceidequals-1
<resourceid>Integer,resourceid,observeallresourcesoftheinstanceif
resourceidequals-1
12.2.21+MIPLDISCOVERDiscoverRequesttoUser
+MIPLDISCOVERDiscoverRequesttoUser
Response
+MIPLDISCOVER:<ref>,<msgid>,<objectid>
Parameters
<ref>Integer,OneNETinstancereturnedbyAT+MIPLCREATE
<msgid>Integer,messageid
<objectid>Integer,objectid
12.2.22+MIPLPARAMETERSetParameterRequesttoUser
+MIPLPARAMETERSetParameterRequesttoUser
Response
+MIPLPARAMETER:

---

## Page 218

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 218/281
<ref>,<msgid>,<objectid>,<instanceid>,<resourceid>,<len>,<paramete
Parameters
<ref>Integer,OneNETinstancereturnedbyAT+MIPLCREATE
<msgid>Integer,messageid
<objectid>Integer,objectid
<instanceid>Integer,instanceid,observeallresourcesofallinstances
oftheobjectifinstanceidequals-1
<resourceid>Integer,resourceid,observeallresourcesoftheinstanceif
resourceidequals-1
<len>Integer,parameterlength
<parameter>String,parameterstring,muststartwith"andendwith"
pmin=xxx;pmax=xxx;gt=xxx;lt=xxx;stp=xxx
12.2.23+MIPLEVENTEventIndicationtoUser
+MIPLEVENTEventIndicationtoUser
Response
+MIPLEVENT:<ref>,<evtid>
Parameters
<ref>Integer,OneNETinstancereturnedbyAT+MIPLCREATE
<evtid>Integer,eventid
1BOOTSTRAP_START
2BOOTSTRAP_SUCCESS
3BOOTSTRAP_FAILED
4CONNECT_SUCCESS
5CONNECT_FAILED
6REG_SUCCESS
7REG_FAILED
8REG_TIMEOUT
9LIFETIME_TIMEOUT
10STATUS_HALT
11UPDATE_SUCCESS
12UPDATE_FAILED
13UPDATE_TIMEOUT
14UPDATE_NEED
15UNREG_DONE
20RESPONSE_FAILED
21RESPONSE_SUCCESS
25NOTIFY_FAILED
26NOTIFY_SUCCESS

---

## Page 219

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 219/281
13ATCommandsforTelecomIOT
Application
13.1Overview
Command Description
AT+SIMLCREATE Createconfiguration
AT+SIMLMODE Connectionmode
AT+SIMLOPEN ConnecttoTelecomIOT
AT+SIMLSEND SenddatatoTelecomIOT
AT+SIMLCLOSE DisconnecttoTelecomIOT
13.2DetailedDescriptionsofCommands
13.2.1AT+SIMLCREATECreateConfiguration
AT+SIMLCREATECreateConfiguration
TestCommand
AT+SIMLCREATE=?Response
+SIMLCREATE:<config>
Parameters
SeeWriteCommand
WriteCommand
AT+SIMLCREATE=<co
nfig>Response
Parameters
<config>Configinhexformat
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote

---

## Page 220

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 220/281
13.2.2AT+SIMLMODEConnectionMode
AT+SIMLMODEConnectionMode
TestCommand
AT+SIMLMODE=?Response
+SIMLMODE:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+SIMLMODE=<mod
e>Response
Parameters
<mode>Connectionmode
1Other
2ChinaTelecomIOT
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
13.2.3AT+SIMLOPENConnecttoTelecomIOT
AT+SIMLOPENConnecttoTelecomIOT
TestCommand
AT+SIMLOPEN=?Response
+SIMLOPEN:<lifetime>
Parameters
SeeWriteCommand
WriteCommand
AT+SIMLOPEN=<lifeti
me>Response
Parameters
<lifetime>Reserved
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote

---

## Page 221

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 221/281
13.2.4AT+SIMLSENDSendDatatoTelecomIOT
AT+SIMLSENDSendDatatoTelecomIOT
TestCommand
AT+SIMLSEND=?Response
+SIMLSEND:<data>,<flag>
Parameters
SeeWriteCommand
WriteCommand
AT+SIMLSEND=<data>
,<flag>Response
Parameters
<data>Stringinhexformat
<flag>
0Inputover
1Inputnotover
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
13.2.5AT+SIMLCLOSEDisconnecttoTelecomIOT
AT+SIMLCLOSEDisconnecttoTelecomIOT
ExecutionCommand
AT+SIMLCLOSEResponse
Parameters
ParameterSavingMode-
MaxResponseTime-
ReferenceNote

---

## Page 222

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 222/281
14ATCommandsforGNSS
Application
SIM7000seriesmodulesprovideGNSSATcommandisasfollows:
14.1Overview
Command Description
AT+CGNSPWR GNSSPowerControl
AT+CGNSINF GNSSNavigationInformationParsedFromNMEASentences
AT+CGNSURC GNSSNavigationURCReport
AT+CGNSPORT GNSSNMEAOutPortSet
AT+CGNSCOLD GNSSColdStart
AT+CGNSWARM GNSSWarmStart
AT+CGNSHOT GNSSHotStart
AT+CGNSMOD GNSSWorkModeSet
AT+CGNSCFG GNSSNMEAOutConfigure
AT+CGNSTST GNSSNMEADataOutputtoATPort
AT+CGNSXTRA GNSSXTRAFunctionOpen
AT+CGNSCPY GNSSXTRAFileCopy
AT+CGNSRTMS GNSSNMEAoutfrequencyconfigure
AT+CGNSHOR ConfigurePositioningDesiredAccuracy
AT+CGNSUTIPR ConfigureBaudRateWhenNMEAOutputFromUART3
AT+CGNSNMEA ConfigureNMEAoutputsentences
AT+CGTP IZATGNSSConfigure
AT+CGNSSUPLCFGGNSSSUPLConfigure
AT+CGNSSUPL GNSSSUPLControl
14.2DetailedDescriptionsofCommands
14.2.1AT+CGNSPWRGNSSPowerControl

---

## Page 223

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 223/281
AT+CGNSPWRGNSSPowerControl
TestCommand
AT+CGNSPWR=?Response
+CGNSPWR:(listofsupported<mode>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CGNSPWR?Response
TAreturnsthecurrentstatusofGNSSPowersupply
+CGNSPWR:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CGNSPWR=<mod
e>Response
ERROR
Parameters
<mode>
0TurnoffGNSSpowersupply
1TurnonGNSSpowersupply
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNMEAdatawillnotoutputtousb’sNMEAportwhensetAT+CGNSPWR=1
throughuartportexceptconfigitbyAT+CGNSCFG=1.
14.2.2AT+CGNSINFGNSSNavigationInformationParsedFromNMEASentences
AT+CGNSINFGNSSNavigationInformationParsedFromNMEASentences
TestCommand
AT+CGNSINF=?Response
Parameters
SeeExecutionCommand
ExecutionCommand
AT+CGNSINFResponse
+CGNSINF:<GNSSrunstatus>,<Fixstatus>,<UTCdate&
Time>,<Latitude>,<Longitude>,<MSLAltitude>,<SpeedOver
Ground>,<Course Over Ground>,<Fix
Mode>,<Reserved1>,<HDOP>,<PDOP>,<VDOP>,<Reserved2>,<GNSS
SatellitesinView>,<GNSSSatellitesUsed>,<GLONASSSatellites
Used>,<Reserved3>,<C/N0max>,<HPA>,<VPA>

---

## Page 224

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 224/281
Parameters
<GNSSrunstatus>
0GNSSoff
1GNSSon
<Fixstatus>
0Notfixedposition
1Fixedposition
Seebelowtable15-1.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
Table15-1:AT+CGNSINFreturnParameters
IndexParameter Unit Range Length
1 GNSSrunstatus -- 0-1 1
2 Fixstatus -- 0-1 1
3 UTCdate&TimeyyyyMMddhhmm
ss.sssyyyy:[1980,2039]
MM:[1,12]
dd:[1,31]
hh:[0,23]
mm:[0,59]
ss.sss:[0.000,60.999]18
4 Latitude±dd.dddddd[-90.000000,90.000000]10
5 Longitude±ddd.dddddd[-180.000000,180.000000]11
6 MSLAltitude meters 8
7 SpeedOverGround Km/hour [0,999.99] 6
8 CourseOverGround degrees [0,360.00] 6
9 FixMode -- 0,1,2[1]1
10 Reserved1 0
11 HDOP -- [0,99.9] 4
12 PDOP -- [0,99.9] 4
13 VDOP -- [0,99.9] 4
14 Reserved2 0
15 GNSSSatellitesinView -- [0,99] 2
16 GPSSatellitesUsed -- [0,99] 2
17GLONASSSatellitesused -- [0,99] 2
18 Reserved3 0
19 C/N0max dBHz [0,55] 2
20 HPA[2]meters [0,9999.9] 6
21 VPA[2]meters [0,9999.9] 6

---

## Page 225

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 225/281
Total：(94)chars
Note:
1.Therangeof<FixMode>dependsontheGNSSchipused.
2.Reserved.
14.2.3AT+CGNSURCGNSSNavigationURCReport
AT+CGNSURCGNSSNavigationURCReport
TestCommand
AT+CGNSURC=?Response
+CGNSURC:(0-255)
Parameters
SeeWriteCommand
ReadCommand
AT+CGNSURC?Response
TAreturnsthecurrentURCsetting
+CGNSURC:<Navigationmode>
Parameters
SeeWriteCommand
UnsolicitedResultCode
+UGNSINF:<GNSSrunstatus>,<Fixstatus>,<UTCdate&
Time>,<Latitude>,<Longitude>,<MSLAltitude>,<SpeedOver
Ground>,<Course Over Ground>,<Fix
Mode>,<Reserved1>,<HDOP>,<PDOP>,<VDOP>,<Reserved2>,<GNSS
SatellitesinView>,<GNSSSatellitesUsed>,<GLONASSSatellites
Used>,<Reserved3>,<C/N0max>,<HPA>,<VPA>
WriteCommand
AT+CGNSURC=<Navig
ationmode>Response
ERROR
Parameters
<Navigationmode>:
0TurnoffnavigationdataURCreport
1TurnonnavigationdataURCreport,andreporteveryGNSSFIX
2TurnonnavigationdataURCreport,andreportevery2GNSSFIX
255TurnonnavigationdataURCreport,andreportevery255GNSSFIX
ParameterSavingModeNO_SAVE
MaxResponseTime-

---

## Page 226

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 226/281
ReferenceNote
Factorysettingis"AT+CGNSURC=0".
URC"+UGNSINF:"parametersarethesameas"+CGNSINF:"return.
14.2.4AT+CGNSPORTGNSSNMEAOutPortSet
AT+CGNSPORTGNSSNMEAOutPortSet
TestCommand
AT+CGNSPORT=?Response
+CGNSPORT:(listofsupported<port>)
Parameters
SeeWriteCommand
ReadCommand
AT+CGNSPORT?Response
+CGNSPORT:<port>
WriteCommand
AT+CGNSPORT=<port
>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<port>NumoftheportNMEAout
3NMEAport
4NONE
ParameterSavingModeAUTO_SAVE_REBOOT
MaxResponseTime-
Reference Note
Modulemustreboottomakeiteffectif<port>valueischanged.
14.2.5AT+CGNSCOLDGNSSColdStart
AT+CGNSCOLDGNSSColdStart
Test Command
AT+CGNSCOLD=?Response
ExecutionCommand
AT+CGNSCOLDResponse
IfAT+CGNSXTRA=0
ElseifAT+CGNSXTRA=1

---

## Page 227

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 227/281
+CGNSXTRA:<mod>
Parameters
<mod>
0AidXTRAfilesuccess
1XTRAfileisnotexist
2XTRAfileisnoteffective
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
14.2.6AT+CGNSWARMGNSSWarmStart
AT+CGNSWARMGNSSWarmStart
Test Command
AT+CGNSWARM=?Response
ExecutionCommand
AT+CGNSWARMResponse
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
14.2.7AT+CGNSHOTGNSSHotStart
AT+CGNSHOTGNSSHotStart
Test Command
AT+CGNSHOT=?Response
ExecutionCommand
AT+CGNSHOTResponse
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note

---

## Page 228

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 228/281
14.2.8AT+CGNSMODGNSSWorkModeSet
AT+CGNSMODGNSSWorkModeSet
TestCommand
AT+CGNSMOD=?Response
+CGNSMOD:(listofsupported<gpsmode>),(listofsupported<glo
mode>s),(listofsupported<bdmode>s),(listofsupported<galmode>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CGNSMOD?Response
+CGNSMOD:<gpsmode>,<glomode>,<bdmode>,<galmode>
WriteCommand
AT+CGNSMOD=<gps
mode>,<glo
mode>,<bd
mode>,<galmode>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<GPSmode>GPSworkmode
1StartGPSNMEAout
<glomode>GLONASSworkmode
0StopGLONASSNMEAout
1StartGLONASSNMEAout
<bdmode>BEIDOUworkmode
0StopBEIDOUNMEAout
1StartBEIDOUNMEAout
2BEIDOUoutsideofus
<gamode>GALILEANworkmode
0StopGALILEANNMEAout
1StartGALILEANNMEAout
2GALILEANoutsideofus
ParameterSavingModeAUTO_SAVE_REBOOT
MaxResponseTime-
Reference Note
14.2.9AT+CGNSCFGGNSSNMEAOutConfigure
AT+CGNSCFGGNSSNMEAOutConfigure
TestCommand
AT+CGNSCFG=?Response
+CGNSCFG:(listofsupported<mode>s)

---

## Page 229

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 229/281
Parameters
SeeWriteCommand
ReadCommand
AT+CGNSCFG?Response
TAreturnsthecurrentstatusofconfigure
+CGNSCFG:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CGNSCFG=<mode
>Response
ERROR
Parameters
<mode>
0TurnoffGNSSNMEAdataoutputtoUSB’sNMEAportwhenset
AT+CGNSPWR=1/0throughUART
1TurnonGNSSNMEAdataoutputtoUSB’sNMEAportwhenset
AT+CGNSPWR=1/0throughUART
2TurnonGNSSNMEAdataoutputtoUART3portwhenset
AT+CGNSPWR=1/0
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
ThiscommandonlysupportedinUARTport.
14.2.10AT+CGNSTSTGNSSNMEADataOutputtoATPort
AT+CGNSTSTGNSSNMEADataOutputtoATPort
TestCommand
AT+CGNSTST=?Response
+CGNSTST:(0-1),(1-255)
Parameters
SeeWriteCommand
ReadCommand
AT+CGNSTST?Response
TAreturnsthecurrentstatusofconfigure
+CGNSTST:<TST>

---

## Page 230

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 230/281
Parameters
SeeWriteCommand
WriteCommand
AT+CGNSTST=<TST>[,
<cont>]Response
ERROR
Parameters
<TST>
0TurnoffGNSSNMEAdataoutputtoATport
1TurnonGNSSNMEAdataoutputtoATport
<cont>thenumberofNMEAdatapackage
1-255
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
14.2.11AT+CGNSXTRAGNSSXTRAFunctionOpen
AT+CGNSXTRAGNSSXTRAFunctionOpen
TestCommand
AT+CGNSXTRA=?Response
+CGNSXTRA:(0-1)
Parameters
SeeWriteCommand
ReadCommand
AT+CGNSXTRA?Response
TAreturnsthecurrentstatusofconfigure
+CGNSXTRA:<enable>
Parameters
SeeWriteCommand
WriteCommand
AT+CGNSXTRA=<ena
ble>Response
ERROR
Parameters
<enable>
0DisableXTRAfunction
1EnableXTRAfunction
ExecutionCommand
AT+CGNSXTRAResponse
ThiscommandisusedtoqueryvalidatetimeofXTRAfile.TheXTRAfile

---

## Page 231

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 231/281
existsifthedownloadandcopyaresuccessful.
IfXTRAfileisnotexist
ERROR
ElseifXTRAfileisexist
<validDurationHours>,<InjectgpsOneXTRGPStime>
Parameters
<validDurationHours>ValidatetimeofXTRAfile,UnitisHour.Defaut
valueis168.
<InjectgpsOneXTRGPStime>DownloadtimeofXTRAfile.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
14.2.12AT+CGNSCPYGNSSXTRAFileCopy
AT+CGNSCPYGNSSXTRAFileCopy
TestCommand
AT+CGNSCPY=?Response
Parameters
SeeExecutionCommand
ExecutionCommand
AT+CGNSCPYResponse
+CGNSCPY:<ret>
Parameters
<ret>
1Filenotexist
0Copysuccess
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
14.2.13AT+CGNSRTMSGNSSNMEAOutFrequencyConfigure
AT+CGNSRTMSGNSSNMEAOutFrequencyConfigure
TestCommand
AT+CGNSRTMS=?Response
+CGNSRTMS:(listofsupported<frequency>s)

---

## Page 232

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 232/281
Parameters
SeeReadCommand
ReadCommand
AT+CGNSRTMS?Response
+CGNSRTMS:<frequency>
Parameters
<frequency>GNSSNMEAOutFrequency,rangeis50-1000.
Defaultvalueis1000.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
14.2.14AT+CGNSHORConfigurePositioningDesiredAccuracy
AT+CGNSHORConfigurePositioningDesiredAccuracy
TestCommand
AT+CGNSHOR=?Response
+CGNSHOR:(0-1800000)
Parameters
SeeWriteCommand
ReadCommand
AT+CGNSHOR?Response
TAreturnsthecurrentstatusofconfigure
+CGNSHOR:<acc>
Parameters
SeeWriteCommand
WriteCommand
AT+CGNSHOR=<acc>Response
ERROR
Parameters
<acc>Configurethepositioningdesiredaccuracythresholdinmeters.
Range:0-1800000Defaultvalueis50
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference

---

## Page 233

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 233/281
14.2.15AT+CGNSUTIPRConfigureBaudRateWhenNMEAOutputfromUART3
AT+CGNSUTIPRConfigureBaudRateWhenNMEAOutputfromUART3
TestCommand
AT+CGNSUTIPR=?Response
+CGNSUTIPR:(9600,19200,38400,57600,115200)
Parameters
SeeWriteCommand
ReadCommand
AT+CGNSUTIPR?Response
TAreturnsthecurrentstatusofconfigure
+CGNSUTIPR:<ipr>
Parameters
SeeWriteCommand
WriteCommand
AT+CGNSUTIPR=<ipr>Response
ERROR
Parameters
<ipr>BaudratewhenNMEAoutputfromUART3.
9600
19200
38400
57600
115200
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
WhenGPSisstarted,setAT+CGNSUTIPR=<ipr>first,thenuse
AT+CGNSCFG=2toconfigureUART3output.AfterturningonGPS,you
canusethesetbaudrateoutputinUART3.
14.2.16AT+CGNSNMEAConfigureNMEAOutputSentences
AT+CGNSNMEAConfigureNMEAOutputSentences
TestCommand
AT+CGNSNMEA=?Response
+CGNSNMEA:(rangeofsupported<nmea>s)

---

## Page 234

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 234/281
Parameters
SeeWriteCommand
ReadCommand
AT+CGNSNMEA?Response
+CGNSNMEA:<nmea>
Parameters
SeeWriteCommand
WriteCommand
AT+CGNSNMEA=<nme
a>ThiscommandisusedtoconfigureNMEAoutputsentenceswhichare
generatedbytheGPSOneenginewhenpositiondataisavailable.
Response
ERROR
Parameters
<nmea>Rangeis0-262143.
EachbitenablesanNMEAsentenceoutputasfollows:
Bit0GPGGA(globalpositioningsystemfixdata)
Bit1GPRMC(recommendedminimumspecificGPS/TRANSITdata)
Bit2GPGSV(GPSsatellitesinview)
Bit3GPGSA(GPSDOPandactivesatellites)
Bit4GPVTG(trackmadegoodandgroundspeed)
Bit5PQXFI(GlobalPositioningSystemExtendedFixData.)
Bit6GLGSV(GLONASSsatellitesinviewGLONASSfixesonly)
Bit7GNGSA(1.GPS/2.Glonass/3.GALILEDOPandActive
Satellites.)
Bit8GNGNS(fixdataforGNSSreceivers;outputfor
GPS,GLONASS,GALILEO)
Bit9Reserved
Bit10GAGSV(GALILEOsatellitesinview)
Bit11Reserved
Bit12Reserved
Bit13Reserved
Bit14Reserved
Bit15Reserved,
Bit16BDGSA/PQGSA(BEIDOU/QZSSDOPandactivesatellites)
Bit17BDGSV/PQGSV(BEIDOUQZSSsatellitesinview)
SetthedesiredNMEAsentencebit(s).IfmultipleNMEAsentenceformats
aredesired,"OR"thedesiredbitstogether.
ParameterSavingModeAUTO_SAVE_REBOOT
MaxResponseTime-
Reference Note:
Reserveddefault0,setinvalid.

---

## Page 235

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 235/281
14.2.17AT+CGTPIZATGNSSConfigure
AT+CGTPIZATGNSSConfigure
TestCommand
AT+CGTP=?Response
Parameters
SeeWriteCommand
ReadCommand
AT+CGTP?Response
+CGTP:
<feature_control>,<user_session_control>,<primary_svr_address>,<p
rimary_svr_port>,<secondary_svr_address>,<secondary_svr_port>
Parameters
SeeWriteCommand
WriteCommand
AT+CGTP=<feature_co
ntrol>Response
Ifsuccessfully:
Iffailed:
ERROR
Parameters
<feature_control>
0GTPdisabled
1GTPenabled
IfyouwanttouseIZATfunction,thisvaluemustbe1
<user_session_control>
0ConnectiontotheXTSisneverpermitted
1ConnectiontotheXTSisalwayspermitted
IfyouwanttouseIZATfunction,thisvaluemustbe1
<primary_svr_address>theIPaddressoftheprimaryGTPServer.
IfyouwanttouseIZATfunction,thisvaluemustbegtp1.izatclout.net
<primary_svr_port>theportnumberoftheprimary
IfyouwanttouseIZATfunction,thisvaluemustbe443
<secondary_svr_address>theIPaddressofthesecondaryGTP
Server.
IfyouwanttouseIZATfunction,thisvaluemustbegtp2.izatclout.net
<secondary_svr_port>theportnumberoftheprimary
IfyouwanttouseIZATfunction,thisvaluemustbe443
<latitude>Latitude(specifiedinWGS84datum).
Type:Floatingpoint
Units:Degrees
Range:-90.0to90.0
Positivevaluesindicatenorthernlatitude

---

## Page 236

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 236/281
Negativevaluesindicatesouthernlatitude
<longitude>Longitude(specifiedinWGS84datum).
Type:Floatingpoint
Units:Degrees
Range:-180.0to180.0
Positivevaluesindicateeasternlongitude
Negativevaluesindicatewesternlongitude
<date>Outputformatisyyyy-mm-dd
<time>UTCtimeoutputformatishh:mm:ss
<accuary>Horizontalpositionuncertainty(circular).
Type:Floatingpoint
Units:Meters
ExecutionCommand
AT+CGTPResponse
+GTPCELL:<latitude>,<longitude>,<date>,<time>,<accuary>
Parameters
SeeWriteCommand
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
BeforeallIZATrelatedoperations,weshouldensurenetworkis
registered.
IZATflow
Step1:ConfigureIZATNVparambyAT+CGTP=1.
Step2:QueryIZATNVparambyAT+CGTP?
Step3:StartIZATlocationbyAT+CGTP
ATcommandexample
//QueryIZATNVset
AT+CGTP?
+CGTP:1,1,gtp1.izatcloud.net,443,gtp2.izatcloud.net,443
//Ifqueryresultisnotthis,needsetit
AT+CGTP=1
//StartIZATlocation
AT+CGTP
+GTPCELL:
32.943878,-117.214508,2019-08-23,17:28:03,1330.200928

---

## Page 237

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 237/281
14.2.18AT+CGNSSUPLCFGGNSSSUPLConfigure
AT+CGNSSUPLCFGGNSSSUPLConfigure
TestCommand
AT+CGNSSUPLCFG=?Response
+CGNSSUPLCFG:"APN","SUPLURL",(0-31),(1-4),(0-1)
Parameters
SeeWriteCommand
ReadCommand
AT+CGNSSUPLCFG?Response
+CGNSSUPLCFG:<APN>,<URL>,<SRV>,<PDN>,<SECURITY>
Parameters
SeeWriteCommand
WriteCommand
AT+CGNSSUPLCFG=<
APN>,<SUPLURL>,<S
RV>,<PDN>,<SECURIT
Y>Response
ERROR
Parameters
<APN>APNname
<SUPLURL>Serveraddressurl
<SRV>Servingsystemstype
Bit0CDMA
Bit1HDR
Bit2GSM
Bit3WCDMA
Bit4LTE
<PDN>
1IPV4
2IPV6
3IPV4V6
4PPP
<SECURITY>
0Disablessecurity
1Enablessecurity
ParameterSavingModeAUTO_SAVE_REBOOT
MaxResponseTime-
Reference Note

---

## Page 238

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 238/281
14.2.19AT+CGNSSUPLGNSSSUPLControl
AT+CGNSSUPLGNSSSUPLControl
TestCommand
AT+CGNSSUPL=?Response
+CGNSSUPL:(listofsupported<mode>s)
Parameters
SeeWriteCommand
ReadCommand
AT+CGNSSUPL?Response
+CGNSSUPL:<mode>
Parameters
SeeWriteCommand
WriteCommand
AT+CGNSSUPL=<mod
e>Response
ERROR
Parameters
<mode>
0TurnoffGNSSSUPL
1TurnonGNSSSUPL
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note

---

## Page 239

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 239/281
15ATCommandsforFileSystem
15.1Overview
Command Description
AT+CFSINIT GetFlashDataBuffer
AT+CFSWFILE WriteFiletotheFlashBufferAllocatedbyCFSINIT
AT+CFSRFILE ReadFilefromFlash
AT+CFSDFILE DeletetheFilefromtheFlash
AT+CFSGFIS GetFileSize
AT+CFSREN Renameafile
AT+CFSGFRS Getthesizeoffilesystem
AT+CFSTERM FreetheFlashBufferAllocatedbyCFSINIT
AT+CBAINIT Initializetheapbackupfilesystem
AT+CBALIST Setthefileswhichwanttobackup
AT+CBAPPS StarttobackupapfilesystemallocatedbyCBAINITandCBALIST
AT+CBART Restorethefileintoapfilesystem
15.2DetailedDescriptionsofCommands
15.2.1AT+CFSINITGetFlashDataBuffer
AT+CFSINITGetFlashDataBuffer
ExecutionCommand
AT+CFSINITResponse
ERROR
+CMEERROR:<err>
Parameters
ParameterSavingMode-

---

## Page 240

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 240/281
MaxResponseTime-
Reference Note
15.2.2AT+CFSWFILEWriteFiletotheFlashBufferAllocatedbyCFSINIT
AT+CFSWFILEWriteFiletotheFlashBufferAllocatedbyCFSINIT
TestCommand
AT+CFSWFILE=?Response
+CFSWFILE:(0-3),"fileName",(0-1),(1-10240),(100-10000)
Parameters
SeeWriteCommand
WriteCommand
AT+CFSWFILE=<index
>,<file
name>,<mode>,<file
size>,<inputtime>Response
ERROR
+CMEERROR:<err>
Parameters
<index>
DirectoryofAPfilesystem:
0"/custapp/"
1"/fota/"
2"/datatx/"
3"/customer/"
<filename>
Filenamelengthshouldlessorequal50characters
<mode>
0Ifthefilealreadyexisted,writethedataatthebeginningofthe
file.
1Ifthefilealreadyexisted,addthedataattheendofthefile.
<filesize>
Filesizeshouldbelessthan10240bytes.
<inputtime>Millisecond,shouldsendfileduringthisperiodoryoucan’t
sendfilewhentimeout.Thevalueshouldbelessthan10000ms.
ParameterSavingMode-
MaxResponseTime-
Reference Note

---

## Page 241

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 241/281
15.2.3AT+CFSRFILEReadFilefromFlash
AT+CFSRFILEReadFilefromFlash
TestCommand
AT+CFSRFILE=?Response
+CFSRFILE:(0-3),"fileName",(0-1),(1-10240),(0-filesize)
Parameters
SeeWriteCommand
WriteCommand
AT+CFSRFILE=<index
>,<file
name>,<mode>,<file
size>,<position>Response
ERROR
+CMEERROR:<err>
Parameters
<index>
DirectoryofAPfilesystem:
0"/custapp/"
1"/fota/"
2"/datatx/"
3"/customer/"
<filename>
Filenamelengthshouldbelessthanorequalto50characters,
<mode>
0Readdataatthebeginningofthefile.
1Readdataatthe<position>ofthefile.
<filesize>
Thesizeofthefilethatyouwanttoreadshouldbelessthan10240.
<position>Thestartingpositionthatwillbereadinthefile.
When<writemode>=0,<position>isinvalid.Readdatafromthebeginning
totheendofthefile.
When<writemode>=1,<position>isvalid.Readdatafromthe<position>to
theendofthefile.
ParameterSavingMode-
MaxResponseTime-
Reference Note
15.2.4AT+CFSDFILEDeletetheFilefromtheFlash
AT+CFSDFILEDeletetheFilefromtheFlash

---

## Page 242

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 242/281
TestCommand
AT+CFSDFILE=?Response
+CFSDFILE:(0-3),"fileName"
Parameters
SeeWriteCommand
WriteCommand
AT+CFSDFILE=<index
>,<filename>Response
ERROR
+CMEERROR:<err>
Parameters
<index>
DirectoryofAPfilesystem:
0"/custapp/"
1"/fota/"
2"/datatx/"
3"/customer/"
<filename>
Filenamelengthshouldbelessthanorequalto50characters.
ParameterSavingMode-
MaxResponseTime-
Reference Note
15.2.5AT+CFSGFISGetFileSize
AT+CFSGFISGetFileSize
TestCommand
AT+CFSGFIS=?Response
+CFSGFIS:(0-3),"fileName"
Parameters
SeeWriteCommand
WriteCommand
AT+CFSGFIS=<index>,
<filename>Response
ERROR
+CMEERROR:<err>
+CFSGFIS:<n>

---

## Page 243

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 243/281
Parameters
<filename>
Filenamelengthshouldbelessthanorequalto50characters.
<n>Filesize
<index>
DirectoryofAPfilesystem:
0"/custapp/"
1"/fota/"
2"/datatx/"
3"/customer/"
ParameterSavingMode-
MaxResponseTime-
Reference Note
15.2.6AT+CFSRENRenameaFile
AT+CFSRENRenameaFile
TestCommand
AT+CFSREN=?Response
+CFSREN:(0-3),"old_name","new_name"
Parameters
SeeWriteCommand
WriteCommand
AT+CFSREN=<index>,
<oldfilename>,<new
filename>Response
ERROR
+CMEERROR:<err>
Parameters
<index>
DirectoryofAPfilesystem:
0"/custapp/"
1"/fota/"
2"/datatx/"
3"/customer/"
<oldfilename>
Filenamelengthshouldbelessthanorequalto50characters.
<newfilename>
Filenamelengthshouldbelessthanorequalto50characters.

---

## Page 244

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 244/281
ParameterSavingMode-
MaxResponseTime-
Reference Note
15.2.7AT+CFSGFRSGettheSizeofFileSystem
AT+CFSGFRSGettheSizeoffilesystem
ReadCommand
AT+CFSGFRS?Response
ERROR
+CMEERROR:<err>
+CFSGFRS:<n>
Parameters
<n>thesizeoffilesystem
ParameterSavingMode-
MaxResponseTime-
Reference Note
15.2.8AT+CFSTERMFreetheFlashBufferAllocatedbyCFSINIT
AT+CFSTERMFreetheFlashBufferAllocatedbyCFSINIT
ExecutionCommand
AT+CFSTERMResponse
ERROR
+CMEERROR:<err>
Parameters
ParameterSavingMode-
MaxResponseTime-
Reference Note

---

## Page 245

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 245/281
15.2.9AT+CBAINITInitializetheAPBackupFileSystem
AT+CBAINITInitializetheAPBackupFileSystem
ExecutionCommand
AT+CBAINITResponse
ERROR
+CMEERROR:<err>
ParameterSavingMode-
MaxResponseTime3seconds
Reference Note
15.2.10AT+CBALISTSetthefilesWhichWanttoBackup
AT+CBALISTSettheFilesWhichWanttoBackup
ReadCommand
AT+CBALIST?Response
+CBALIST:<index>,<filename>
Parameters
SeeWriteCommand
WriteCommand
AT+CBALIST=<index>,
<filename>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<index>0-9Thefileindex.
10Disablelog
11Enablelog
<filename>Filenamelengthshouldlessthanorequalto80characters.
ParameterSavingModeNO_SAVE
MaxResponseTime
Reference Note

---

## Page 246

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 246/281
15.2.11AT+CBAPPSStarttoBackupAPFileSystemAllocatedbyCBAINITand
CBALIST
AT+CBAPPSStarttoBackupAPFileSystemAllocatedbyCBAINITandCBALIST
ExecutionCommand
AT+CBAPPSResponse
ERROR
+CMEERROR:<err>
ParameterSavingMode-
MaxResponseTime3seconds
Reference Note
15.2.12AT+CBARTRestoretheFileintoAPFileSystem
AT+CBARTRestoretheFileintoAPFileSystem
ExecutionCommand
AT+CBARTResponse
ERROR
+CMEERROR:<err>
Parameters
ParameterSavingMode-
MaxResponseTime3seconds
Reference Note
Thefilesshouldhavebeenbackupintoapfilesystem.

---

## Page 247

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 247/281
16ATCommandsforSIMApplication
Toolkit
16.1Overview
Command Description
AT+STIN SATindication
AT+STGI GetSATinformation
AT+STGR SATrespond
AT+STK STKswitch
16.2DetailedDescriptionsofCommands
16.2.1AT+STINSATIndication
AT+STINSATIndication
TestCommand
AT+STIN=?Response
Parameters
SeeReadCommand
ReadCommand
AT+STIN?Response
+STIN:<cmd_id>
Ifthecurrentproactivecommandhasbeenchanged:
+STIN:<cmd_id>
Parameters
<cmd_id>Indicatethetypeofproactivecommandissued.
21Displaytext
22Getinkey
23Getinput
24Selectitem

---

## Page 248

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 248/281
25Setupmenu
ParameterSavingMode-
MaxResponseTime-
Reference Notificationthatapplicationwillreturntomainmenuautomaticallyifuser
doesn’tdoanyactionin2minutes.
16.2.2AT+STGIGetSATInformation
AT+STGIGetSATInformation
TestCommand
AT+STGI=?Response
Parameters
SeeWriteCommand
WriteCommand
AT+STGI=<cmd_id>Response
If<cmd_id>=21:
+STGI:21,<prio>,<clear_mode>,<text_len>,<text>
If<cmd_id>=22:
+STGI:22,<rsp_format>,<help>,<text_len>,<text>
If<cmd_id>=23:
+STGI:23,<rsp_format>,<max_len>,<min_len>,<help>,<show><text_le
n>,<text>
If<cmd_id>=24:
+STGI:24,<help>,<softkey>,<present>,<title_len>,<title><item_num>
+STGI:24,<item_id>,<item_len>,<item_data>
[…]
If<cmd_id>=25:
+STGI:25,<help>,<softkey>,<title_len>,<title><item_num>
+STGI:25,<item_id>,<item_len>,<item_data>
[…]

---

## Page 249

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 249/281
ERROR
Parameters
<cmd_id>SeeAT+STIN.
<prio>Priorityofdisplaytext.
0Normalpriority
1Highpriority
<clear_mode>
0Clearafteradelay
1Clearbyuser
<text_len>Lengthoftext
<rsp_format>
0SMSdefaultalphabet
1YESorNO
2Numericalonly
3UCS2
<help>
0Helpunavailable
1Helpavailable
<max_len>Maximumlengthofinput
<min_len>Minimumlengthofinput
<show>
0Hideinputtext
1Displayinputtext
<softkey>
0Nosoftkeypreferred
1Softkeypreferred
<present>Menupresentationformatavailableforselectitem
0Presentationnotspecified
1Datavaluepresentation
2Navigationpresentation
<title_len>Lengthoftitle
<item_num>Numberofitemsinthemenu
<item_id>Identifierofitem
<item_len>Lengthofitem
<title>Titleinucs2format
<item_data>Contentoftheiteminucs2format
<text>Textinucs2format
ParameterSavingMode-
MaxResponseTime-
ReferenceRegularlythiscommandisuseduponreceiptofanURC"+STIN"torequest
theparametersoftheproactivecommand.ThentheTAisexpectedto
acknowledgetheAT+STGIresponsewithAT+STGRtoconfirmthatthe
proactivecommandhasbeenexecuted.

---

## Page 250

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 250/281
16.2.3AT+STGRSATRespond
AT+STGRSATrespond
TestCommand
AT+STGR=?Response
Parameters
SeeWriteCommand
WriteCommand
AT+STGR=<cmd_id>[,
<data>]Response
ERROR
Parameters
<cmd_id>Identifierofproactivecommand.
22Getinkey
23Getinput
24Selectitem
25Setupmenu
83Sessionendbyuser
84Gobackward
<data>
If<cmd_id>=22:
Inputacharacter
If<cmd_id>=23:
Inputastring.
If<rsp_format>isYESorNO,inputofacharacterincaseofANSI
charactersetrequestsonebyte,e.g."Y".
If<rsp_format>isnumericalonly,inputthecharactersindecimal
number,e.g."123".
If<rsp_format>isUCS2,requestsa4bytestring,e.g."0031".
<rsp_format>refertotheresponsebyAT+STGI=23.
If<cmd_id>=24:
Inputtheidentifieroftheitemselectedbyuser.
If<cmd_id>=25:
Inputtheidentifieroftheitemselectedbyuser.
If<cmd_id>=83:
<data>Ignore
Note:Itcouldreturnmainmenuduringproactivecommandidisnot22
or23.
If<cmd_id>=84:
<data>Ignore
ParameterSavingMode-
MaxResponseTime-

---

## Page 251

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 251/281
ReferenceNote
16.2.4AT+STKSTKSwitch
AT+STKSTKSwitch
TestCommand
AT+STK=?Response
Parameters
SeeWriteCommand
ReadCommand
AT+STK?Response
+STK:<value>
Parameters
SeeWriteCommand
WriteCommand
AT+STK=<value>Response
ERROR
Parameters
<value>
0DisableSTK
1EnableSTK
ParameterSavingMode-
MaxResponseTime-
ReferenceNote

---

## Page 252

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 252/281
17ATCommandsforSSLApplication
17.1OverviewofATCommandsforSSLApplication
Command Description
AT+CSSLCFG ConfigureSSLparametersofcontextidentifier
17.2DetailedDescriptionsofATCommandsforSSLApplication
17.2.1AT+CSSLCFGConfigureSSLParametersofContextIdentifier
AT+CSSLCFGConfigureSSLParametersofContextIdentifier
TestCommand
AT+CSSLCFG=?Response
+CSSLCFG:"sslversion",(0-5),(0-5)
+CSSLCFG:
"ciphersuite",(0-5),(0-7),(0x008A,0x008B,0x008C,0x008D,0x00A8,0x00
A9,0x00AE,0x00AF,0x002F,0x0033,0x0035,0x0039,0xC02A,0xC02B,0x
C02C,0xC02D,0xC02E,0xC02F,0xC030,0xC031,0xC032,0xC09C,0xC09
D,0xC09E,0xC09F,0xC0A0,0xC09F,0xC0A1,0xC0A2,0xC0A3,0xCC13,0x
CC14,0xCC15)
+CSSLCFG:"ignorertctime",(0-5),(0-1)
+CSSLCFG:"protocol",(0-5),(1-2)
+CSSLCFG:"sni",(0-5),<servername>
+CSSLCFG:"ctxindex",(0-5)
+CSSLCFG:"convert",(1-3),(<cname>,[<keyname>[,<passkey>]])
Parameters
SeeWriteCommand
ReadCommand
AT+CSSLCFG?Response
Parameters

---

## Page 253

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 253/281
SeeWriteCommand
WriteCommand
AT+CSSLCFG="sslver
sion",<ctxindex>,<sslv
ersion>Response
Iffailed:
+CMEERROR:<err>
Parameters
<ctxindex>(0-5)
<sslversion>
0QAPI_NET_SSL_PROTOCOL_UNKNOWN
1QAPI_NET_SSL_PROTOCOL_TLS_1_0
2QAPI_NET_SSL_PROTOCOL_TLS_1_1
3QAPI_NET_SSL_PROTOCOL_TLS_1_2
4QAPI_NET_SSL_PROTOCOL_DTLS_1_0
5QAPI_NET_SSL_PROTOCOL_DTLS_1_2
AT+CSSLCFG="cipher
suite",<ctxindex>,<cip
her_index>,<ciphersuit
e>Response
Iffailed:
+CMEERROR:<err>
Parameters
<ctxindex>(0-5)
<cipher_index>(0-7)
<ciphersuite>
0x008AQAPI_NET_TLS_PSK_WITH_RC4_128_SHA
0x008BQAPI_NET_TLS_PSK_WITH_3DES_EDE_CBC_SHA
0x008CQAPI_NET_TLS_PSK_WITH_AES_128_CBC_SHA
0x008DQAPI_NET_TLS_PSK_WITH_AES_256_CBC_SHA
0x00A8QAPI_NET_TLS_PSK_WITH_AES_128_GCM_SHA256
0x00A9QAPI_NET_TLS_PSK_WITH_AES_256_GCM_SHA384
0x00AEQAPI_NET_TLS_PSK_WITH_AES_128_CBC_SHA256
0x00AFQAPI_NET_TLS_PSK_WITH_AES_256_CBC_SHA384
0x002FQAPI_NET_TLS_RSA_WITH_AES_128_CBC_SHA
0x0033QAPI_NET_TLS_DHE_RSA_WITH_AES_128_CBC_SHA
0x0035QAPI_NET_TLS_RSA_WITH_AES_256_CBC_SHA
0x0039QAPI_NET_TLS_DHE_RSA_WITH_AES_256_CBC_SHA
0x003CQAPI_NET_TLS_RSA_WITH_AES_128_CBC_SHA256
0x003DQAPI_NET_TLS_RSA_WITH_AES_256_CBC_SHA256
0x0067QAPI_NET_TLS_DHE_RSA_WITH_AES_128_CBC_SHA256
0x006BQAPI_NET_TLS_DHE_RSA_WITH_AES_256_CBC_SHA256
0x009CQAPI_NET_TLS_RSA_WITH_AES_128_GCM_SHA256
0x009DQAPI_NET_TLS_RSA_WITH_AES_256_GCM_SHA384
0x009EQAPI_NET_TLS_DHE_RSA_WITH_AES_128_GCM_SHA256
0x009FQAPI_NET_TLS_DHE_RSA_WITH_AES_256_GCM_SHA384
0xC004QAPI_NET_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA
0xC005QAPI_NET_TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA
0xC009QAPI_NET_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA

---

## Page 254

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 254/281
0xC00AQAPI_NET_TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA
0xC00EQAPI_NET_TLS_ECDH_RSA_WITH_AES_128_CBC_SHA
0xC00FQAPI_NET_TLS_ECDH_RSA_WITH_AES_256_CBC_SHA
0xC013QAPI_NET_TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA
0xC014QAPI_NET_TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA
0xC023
QAPI_NET_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256
0xC024
QAPI_NET_TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384
0xC025QAPI_NET_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256
0xC026QAPI_NET_TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA384
0xC027QAPI_NET_TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256
0xC028QAPI_NET_TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384
0xC029QAPI_NET_TLS_ECDH_RSA_WITH_AES_128_CBC_SHA256
0xC02AQAPI_NET_TLS_ECDH_RSA_WITH_AES_256_CBC_SHA384
0xC02B
QAPI_NET_TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256
0xC02C
QAPI_NET_TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384
0xC02D
QAPI_NET_TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256
0xC02E
QAPI_NET_TLS_ECDH_ECDSA_WITH_AES_256_GCM_SHA384
0xC02FQAPI_NET_TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256
0xC030QAPI_NET_TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384
0xC031QAPI_NET_TLS_ECDH_RSA_WITH_AES_128_GCM_SHA256
0xC032QAPI_NET_TLS_ECDH_RSA_WITH_AES_256_GCM_SHA384
0xC09CQAPI_NET_TLS_RSA_WITH_AES_128_CCM
0xC09DQAPI_NET_TLS_RSA_WITH_AES_256_CCM
0xC09EQAPI_NET_TLS_DHE_RSA_WITH_AES_128_CCM
0xC09FQAPI_NET_TLS_DHE_RSA_WITH_AES_256_CCM
0xC0A0QAPI_NET_TLS_RSA_WITH_AES_128_CCM_8
0xC0A1QAPI_NET_TLS_RSA_WITH_AES_256_CCM_8
0xC0A2QAPI_NET_TLS_DHE_RSA_WITH_AES_128_CCM_8
0xC0A3QAPI_NET_TLS_DHE_RSA_WITH_AES_256_CCM_8
0xCC13
QAPI_NET_TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA25
0xCC14
QAPI_NET_TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA
256
0xCC15
QAPI_NET_TLS_DHE_RSA_WITH_CHACHA20_POLY1305_SHA256
AT+CSSLCFG="ignore
rtctime",<ctxindex>,<i
gnorertctime>Response
Iffailed:

---

## Page 255

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 255/281
+CMEERROR:<err>
Parameters
<ctxindex>(0-5)
<ignorertctime>
0DonotignoretheRTCtime
1IgnoretheRTCtime
AT+CSSLCFG="protoc
ol",<ctxindex>,<protoc
ol>Response
Iffailed:
+CMEERROR:<err>
Parameters
<ctxindex>(0-5)
<protocol>
1QAPI_NET_SSL_TLS_E
2QAPI_NET_SSL_DTLS_E
AT+CSSLCFG="ctxind
ex",<ctxindex>Response
+CSSLCFG:
<ctxindex>,<sslversion>,<ciphersuite>,<ignorertctime>,<protocol>,<s
ni>
Iffailed:
+CMEERROR:<err>
Parameters
Seeothercommands
AT+CSSLCFG="conver
t",<ssltype>,<cname>[,
<keyname>[,<passkey
>]]Response
Iffailed:
+CMEERROR:<err>
Parameters
<ssltype>
1QAPI_NET_SSL_CERTIFICATE_E
2QAPI_NET_SSL_CA_LIST_E
3QAPI_NET_SSL_PSK_TABLE_E
<cname>Stringtype(stringshouldbeincludedinquotationmarks):name
ofcertfile
<keyname>Stringtype(stringshouldbeincludedinquotation
marks):nameofkeyfile
<passkey>Stringtype(stringshouldbeincludedinquotation
marks):valueofpasskey
AT+CSSLCFG="sni",<
ctxindex>,<servernam
e>Response
Iffailed:
+CMEERROR:<err>
Parameters

---

## Page 256

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 256/281
<ctxindex>(0-5)
<servername>Stringtype.ServerNameIndication.SNIaddressesthis
issuebyhavingtheclientsendthenameofthevirtualdomainaspartofthe
TLSnegotiation.
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note

---

## Page 257

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 257/281
18ATCommandsforTCP/UDP
Application
18.1Overview
Command Description
AT+CACID SetTCP/UDPidentifier
AT+CASSLCFG SetSSLcertificateandtimeoutparameters
AT+CAOPEN OpenaTCP/UDPconnection
AT+CASERVER OpenaTCP/UDPServer
AT+CASEND Senddataviaanestablishedconnection
AT+CARECV Receivedataviaanestablishedconnection
AT+CAACK QuerySendDataInformation
AT+CASTATE QueryTCP/UDPConnectionState
AT+CACLOSE CloseaTCP/UDPconnection
AT+CACFG Configuretransparenttransmissionparameters
AT+CASWITCH Switchtotransparenttransportmode
18.2DetailedDescriptionsofCommands
18.2.1AT+CACIDSetTCP/UDPIdentifier
AT+CACIDSetTCP/UDPIdentifier
TestCommand
AT+CACID=?Response
+CACID:(rangeofsupported<cid>s)
Parameters
SeeWriteCommand
ReadCommand Response

---

## Page 258

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 258/281
AT+CACID? [+CACID:<cid>]
Parameters
SeeWriteCommand
WriteCommand
AT+CACID=<cid>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<cid>TCP/UDPidentifier
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
18.2.2AT+CASSLCFGSetSSLCertificateandTimeoutParameters
AT+CASSLCFGSetSSLCertificateandTimeoutParameters
TestCommand
AT+CASSLCFG=?Response
+CASSLCFG:(rangeofsupported<cid>s),"cacert",<caname>
+CASSLCFG:(rangeofsupported<cid>s),"clientcert",<certname>
+CASSLCFG:(rangeofsupported<cid>s),"psktable",<pskname>
+CASSLCFG:(rangeofsupported<cid>s),"timeout",(0-65535)
+CASSLCFG:(rangeofsupported<cid>s),"ssl",(0,1)
+CASSLCFG:(rangeofsupported<cid>s),"crindex",(0,5)
+CASSLCFG:(rangeofsupported<cid>s),"localport",(0-65536)
+CASSLCFG:(rangeofsupported<cid>s),"protocol",(0,1)
Parameters
SeeWriteCommand
ReadCommand
AT+CASSLCFG?Response
If<cid>hasbeensetbyAT+CACID:
+CASSLCFG:<cid>
cacert:<caname>
clientcert:<certname>
psktable:<pskname>
timeout:<timeout>
ssl:<ssl>
crindex:<crindex>
localport:<localport>

---

## Page 259

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 259/281
protocol:<protocol>
Ifno<cid>hasbeensetbyAT+CACID:
Parameter
SeeWriteCommand
WriteCommand
AT+CASSLCFG=<cid>,
"cacert",<caname>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<cid>TCP/UDPidentifier,seeAT+CACID
<caname>AlphanumericASCIItextstringupto64characters.Root
certificatenamethathasbeenconfiguredbyAT+CSSLCFG.
Note:Iftherootcertificateisempty,modulewilltrustallcertificatesas
default.
AT+CASSLCFG=<cid>,
"clientcert",<certname
>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<cid>seeAT+CACID
<certname>AlphanumericASCIItextstringupto64characters.Client
certificatenamethathasbeenconfiguredbyAT+CSSLCFG.
AT+CASSLCFG=<cid>,
"psktable",<pskname>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<cid>seeAT+CACID
<pskname>AlphanumericASCIItextstringupto64characters.PSK
tablenamethathasbeenconfiguredbyAT+CSSLCFG.
Filecontentformatis<identity>:<hexstring>.
AT+CASSLCFG=<cid>,
"ssl",<sslFlag>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<cid>seeAT+CACID
<sslFlag>Interger
0NotsupportSSL
1SupportSSL
AT+CASSLCFG=<cid>,
"crindex",<crindex>Response

---

## Page 260

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 260/281
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<cid>seeAT+CACID
<ctxindex>TheidentifierofSSLconfigurations,seeAT+CSSLCFG.
AT+CASSLCFG=<cid>,
"protocol",<crindex>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<cid>seeAT+CACID
<protocol>Interger
0TCP
1UDP
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
18.2.3AT+CAOPENOpenaTCP/UDPConnection
AT+CAOPENOpenaTCP/UDPConnection
TestCommand
AT+CAOPEN=?Response
+CAOPEN:(rangeofsupported<cid>s),<server>,(1-65535)
Parameters
SeeWriteCommand
ReadCommand
AT+CAOPEN?Response
If<cid>hasbeensetbyAT+CACID:
+CAOPEN:<cid>,<conn_type>,<server>,<port>
Ifno<cid>hasbeensetbyAT+CACID:
Parameter
SeeWriteCommand
WriteCommand
AT+CAOPEN=<cid>[,<
conn_type>],<server>,
<port>Response
If<asyncOpen_enable>notsetorset0.
+CAOPEN:<cid>,<result>

---

## Page 261

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 261/281
Otherwise
+CAOPEN:<cid>,<result>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<cid>seeAT+CACID
<conn_type>Stringtype.Transfertype.IPV4orIPV6addresscanbe
automaticallyidentifiedontheclient.
"TCP"
"UDP"
<server>AlphanumericASCIItextstringupto64characters.ServerIP
addressorhostname.
<port>Interger.Serverport.
<result>
0Success
1Socketerror
2Nomemory
3Connectionlimit
4Parameterinvalid
6InvalidIPaddress
7Notsupportthefunction
12Can’tbindtheport
13Can’tlistentheport
20Can’tresolvthehost
21Networknotactive
23Remoterefuse
24Certificate’stimeexpired
25Certificate’scommonnamedoesnotmatch
26Certificate’scommonnamedoesnotmatchandtimeexpired
27Connectfailed
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
Afteropenaconnectionsuccessfully,ifmodulereceivesdata,itwillreport
"+CADATAIND:<cid>"toremindusertoreaddata.
18.2.4AT+CASERVEROpenaTCP/UDPServer
AT+CASERVEROpenaTCP/UDPServer
TestCommand
AT+CASERVER=?Response
+CASERVER:(rangeofsupported<cid>s),(listofsupported

---

## Page 262

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 262/281
<conn_type>s),(rangeofsupported<port>s)
ReadCommand
AT+CASERVER?Response
[+CASERVER:<cid>,<conn_type>,<port>
WriteCommand
AT+CASERVER<cid>,<
conn_type>,<port>Response
+CASERVER:<cid>,<result>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference
DefinedValues
<cid> TCP/UDPidentifier
<conn_type> Transfertype
"TCP"
"TCP6"
"UDP"
"UDP6"
<port> Integer.Serverport.
<result> 0Success
1Socketerror
2Nomemory
3Connectionlimit
4Parameterinvalid
6InvalidIPaddress
7Notsupportthefunction
12Can’tbindtheport
13Can’tlistentheport
20Can’tresolvthehost
21Networknotactive
23Remoterefuse
24Certificate’stimeexpired
25Certificate’scommonnamedoesnotmatch
26Certificate’scommonnamedoesnotmatchandtimeexpired
27Connectfailederror
NOTE

---

## Page 263

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 263/281
Afteraclientaccess,itwillreportthat.
+CANEW:<server_cid>,<client_cid>,<client_ip>,<client_port>
18.2.5AT+CASENDSendDataviaanEstablishedConnection
AT+CASENDSendDataviaanEstablishedConnection
TestCommand
AT+CASEND=?Response
+CASEND:(rangeofsupported<cid>s),(rangeofsupported
<datalen>),(rangeofsupported<inputtime>)
Parameters
SeeWriteCommand
WriteCommand
AT+CASEND=<cid>Response
+CASEND:<leftsize>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
WriteCommand
AT+CASEND=<cid>,<d
atalen>[,inputtime]Response
+CASEND:<cid>,<datalen>
……..//Inputdata
+CASEND:<cid>,<result>,<sendlen>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<cid>seeAT+CACID
<datalen>Requestednumberofdatabytestobetransmitted
<inputtime>Millisecond,shouldinputdataduringthisperiodoryoucan’t
inputdatawhentimeout.
<sendlen>Databytesthathasbeensentsuccessfully
<result>seeAT+CAOPEN
ParameterSavingModeNO_SAVE
MaxResponseTime-
ReferenceNote
Settheinputtimethatinputdataduringthisperiodoryoucan’tinputdata
whentimeout.Thedefaultinputtimeis5000ms.

---

## Page 264

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 264/281
18.2.6AT+CARECVReceiveDataviaanEstablishedConnection
AT+CARECVReceiveDataviaanEstablishedConnection
TestCommand
AT+CARECV=?Response
+CARECV:(rangeofsupported<cid>s),(rangeofsupported<readlen>)
Parameters
SeeWriteCommand
WriteCommand
AT+CARECV=<cid>,<r
eadlen>Response
+CARECV:<cid>,<recvlen>
…….//outputdata
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
Parameters
<cid>seeAT+CACID
<readlen>Requestednumberofdatabytestoberead
<recvlen>Databytesthathasbeenactuallyreceived
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
18.2.7AT+CAACKQuerySendDataInformation
AT+CAACKQuerySendDataInformations
TestCommand
AT+CAACK=?Response
+CAACK:(rangeofsupported<cid>s)
WriteCommand
AT+CAACK=<cid>Response
+CAACK:<totalsize>,<unacksize>
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference -
DefinedValues

---

## Page 265

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 265/281
<cid> TCP/UDPidentifier
<totalsize> Totalsizeofsentdata.
<unacksize> Thesizeofunackdata
18.2.8AT+CASTATEQueryTCP/UDPConnectionState
AT+CASTATEQueryTCP/UDPConnectionState
ReadCommand
AT+CASTATE?Response
[+CASTATE:<cid>,<state>
UnsolicitedResultCodeIftheremoteconnectionisdisconnected。
+CASTATE:<cid>,<state>
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference -
DefinedValues
<cid> TCP/UDPidentifier
<state> 0Closedbyremoteserverorinternalerror
1Connectedtoremoteserver
2Listening(servermode)
18.2.9AT+CACLOSECloseaTCP/UDPConnection
AT+CACLOSECloseaTCP/UDPConnection
TestCommand
AT+CACLOSE=?Response
+CACLOSE:(rangeofsupported<cid>s)
Parameters
SeeWriteCommand
WriteCommand
AT+CACLOSE=<cid>Response
IferrorisrelatedtoMEfunctionality:
+CMEERROR:<err>

---

## Page 266

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 266/281
Parameters
<cid>seeAT+CACID
UnsolicitedResultCodeIf<autoClose_s>=1,thisreportwillbereportedwhentheremoteconnection
isdisconnected.
+CACLOSE:(rangeofsupported<cid>s)
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
18.2.10AT+CACFGConfigureTransparentTransmissionParameters
AT+CACFGConfigureTransparentTransmissionParameters
TestCommand
AT+CACFG=?Response
+CACFG:"TRANSWAITTM",(rangeofsupported<wait_timeout>s)
+CACFG:"TRANSPKTSIZE",(rangeofsupported<size>s)
+CACFG:"SACK",(listofsupported<sack_enable>s)
+CACFG:"MSS",(rangeofsupported<mss_value>s)
+CACFG:"ACKDELAY",(rangeofsupported<ackDelay_ms>s)
+CACFG:"TCPIRT",(rangeofsupported<tcpIRT_ms>s)
+CACFG:"MAXRXT",(rangeofsupported<tcpMaxRXT_cnt>s)
+CACFG:"TCPOT",(rangeofsupported<tcpOT_ms>s)
+CACFG:"KEEPALIVE",(listofsupported<keepalive_enable>s)[,(range
ofsupported<keepalive_idle>s),(rangeofsupported
<keepalive_intval>s),(rangeofsupported<keepalive_cnt>s)]
+CACFG:"TCP_NODELAY",(listofsupported<tcpNodelay_enable>s)
+CACFG:"LINGER",(listofsupported<linger_enable>s)[,(rangeof
supported<linger_ms>s)]
+CACFG:"SNDBUF",(rangeofsupported<sndBuf_size>)
+CACFG:"RCVBUF",(rangeofsupported<rcvBuf_size>)
+CACFG:"ATOCLOSE",(listofsupported<autoClose_enable>s)[,(range
ofsupported<autoClose_s>s]
+CACFG:"ACCEPTNUM",(rangeofsupported<acceptMax_num>s)
+CACFG:"ASYNCOPEN",(listofsupported<asyncOpen_enable>s)
+CACFG:"TIMEOUT",(rangeofsupported<cid>s),(rangeofsupported
<timeout>s)
+CACFG:"LOCALPORT",(rangeofsupported<cid>s),(rangeof
supported<localport>s)
+CACFG:"REMOTEADDR",(rangeofsupported<cid>s),(rangeof
supported<ipaddress>s),(rangeofsupported<port>s)

---

## Page 267

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 267/281
ReadCommand
AT+CACFG?Response
+CACFG:
+TRANSWAITTM:<wait_timeout>
+TRANSPKTSIZE:<size>
+CACFG:"SACK",<sack_enable>
+CACFG:"MSS",<mss_value>
+CACFG:"ACKDELAY",<ackDelay_ms>
+CACFG:"TCPIRT",<tcpIRT_ms>
+CACFG:"MAXRXT",<tcpMaxRXT_cnt>s)
+CACFG:"TCPOT",<tcpOT_ms>
+CACFG:
"KEEPALIVE",<keepalive_enable>[<keepalive_idle>,<keepalive_intval
>,<keepalive_cnt>]
+CACFG:"TCP_NODELAY",<tcpNodelay_enable>
+CACFG:"LINGER",<linger_enable>[,<linger_ms>]
+CACFG:"SNDBUF",<sndBuf_size>
+CACFG:"RCVBUF",<rcvBuf_size>
+CACFG:"ATOCLOSE",<autoClose_enable>[,<autoClose_s>]
+CACFG:"ACCEPTNUM",<acceptMax_num>
+CACFG:"ASYNCOPEN",<asyncOpen_enable>
+TIMEOUT:<cidx>,<timeoutx>...
+LOCALPORT:<cidx>,<localportx>...
[+REMOTEADDR,<cidx>,<ipadressx>,<portx>...
WriteCommand
AT+CACFG="TRANSW
AITTM",<wait_timeout
>Response
ERROR
WriteCommand
AT+CACFG="TRANSP
KTSIZE",<size>Response
ERROR
WriteCommand
AT+CACFG="SACK",<
sack_enable>Response
ERROR
WriteCommand
AT+CACFG="MSS",<m
ss_value>Response
ERROR
WriteCommand
AT+CACFG="Response

---

## Page 268

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 268/281
ACKDELAY",<ackDela
y_ms>or
ERROR
WriteCommand
AT+CACFG="TCPIRT",
<tcpIRT_ms>Response
ERROR
WriteCommand
AT+CACFG="TCPOT",
<tcpOT_ms>Response
ERROR
WriteCommand
AT+CACFG="KEEPALI
VE",<keepalive_enable
>[<keepalive_idle>,<ke
epalive_intval>,<keepa
live_cnt>]Response
ERROR
WriteCommand
AT+CACFG="TCP_NO
DELAY",<tcpNodelay_
enable>Response
ERROR
WriteCommand
AT+CACFG="LINGER"
,<linger_enable>[,<ling
er_ms>]Response
ERROR
WriteCommand
AT+CACFG="SNDBUF
",<sndBuf_size>Response
ERROR
WriteCommand
AT+CACFG="RCVBUF
",<rcvBuf_size>Response
ERROR
WriteCommand
AT+CACFG="ATOCLO
SE",<autoClose_enabl
e>[,<autoClose_s>]Response
ERROR
WriteCommand
AT+CACFG="ACCEPT
NUM",<acceptMax_nu
m>Response
ERROR
WriteCommand
AT+CACFG="ASYNCO
PEN",(0-1)Response
ERROR
WriteCommand Response

---

## Page 269

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 269/281
AT+CACFG="TIMEOUT
",<cid>,<timeoutx>OK
ERROR
WriteCommand
AT+CACFG="LOCALP
ORT",<cid>,<localport
>Response
ERROR
WriteCommand
AT+CACFG="REMOTE
ADDR",<cid>,<ipaddre
ss>,<localport>Response
ERROR
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note
18.2.11AT+CASWITCHSwitchtoTransparentTransportMode
AT+CASWITCHSwitchtoTransparentTransportMode
TestCommand
AT+CASWITCH=?Response
+CASWITCH:(0-1),(0,1)
ReadCommand
AT+CASWITCH?Response
+CASWITCH:0,0
WriteCommand
AT+CASWITCH=<cid>,
<transmode>Response
CONNECT
ERROR
Parameters
<cid>seeAT+CACID
<transmode>
0Nontransparenttransmissionmode

---

## Page 270

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 270/281
1Transparenttransmissionmode
ParameterSavingModeNO_SAVE
MaxResponseTime-
Reference Note

---

## Page 271

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 271/281
19ATCommandsforPING
19.1Overview
Command Description
AT+SNPING4 SendsanIPv4ping
AT+SNPING6 SendsanIPv6ping
19.2DetailedDescriptionsofCommands
19.2.1AT+SNPING4SendsanIPv4ping
AT+SNPING4SendsanIPv4ping
Testcommand
AT+SNPING4=?Response
+SNPING4:"URL",(1-500),(1-1400),(0-60000)
Writecommand
AT+SNPING4=<URL>,<
count>,<size>,<timeou
t>Response
+SNPING4:<replyId>,<IPaddress>,<replyTime>
ERROR
Parameters
<URL>Stringtype:Addressoftheremotehost
<count>ThenumberofPingEchoRequsettosend,range:1~500
<size>Numberofdatabytestosend,range:1~1400
<timeout>Pingrequesttimeoutvalue(inms),range:0-60000
<replyId>EchoReplynumber
<IPAddress>IPAddressoftheremotehost
<replyTime>Time,inms,requiredtoreceivetheresponse
ParameterSavingMode-
MaxResponseTime-

---

## Page 272

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 272/281
ReferenceNote:
BeforesendingPINGRequesttheGPRScontextmustbeactivated
19.2.2AT+SNPING6SendsanIPv6ping
AT+SNPING6SendsanIPv6ping
Testcommand
AT+SNPING6=?Response
+SNPING6:"URL",(1-500),(1-1400),(0-60000)
Writecommand
AT+SNPING6=<URL>,<
count>,<size>,<timeou
t>Response
+SNPING6:<replyId>,<IPaddress>,<replyTime>
ERROR
Parameters
<URL>Stringtype:Addressoftheremotehost
<count>ThenumberofPingEchoRequsettosend,range:1~500
<size>Numberofdatabytestosend,range:1~1400
<timeout>Pingrequesttimeoutvalue(inms),range:0-60000
<replyId>EchoReplynumber
<IPAddress>IPAddressoftheremotehost
<replyTime>Time,inms,requiredtoreceivetheresponse
ParameterSavingMode-
MaxResponseTime-
ReferenceNote:
BeforesendingPINGRequesttheGPRScontextmustbeactivated.

---

## Page 273

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 273/281
20SupportedErrorCodesand
UnsolicitedResultCodes
20.1SummaryofCMEERRORCodes
Finalresultcode+CMEERROR:<err>indicatesanerrorrelatedtomobileequipmentornetwork.The
operationissimilartoERRORresultcode.NoneofthefollowingcommandsinthesameCommandlineis
executed.NeitherERRORnorOKresultcodeshallbereturned.
<err>valuesusedbycommonmessagingcommands:
Codeof<err>Meaning
0 phonefailure
1 noconnectiontophone
2 phone-adaptorlinkreserved
3 operationnotallowed
4 operationnotsupported
5 PH-SIMPINrequired
6 PH-FSIMPINrequired
7 PH-FSIMPUKrequired
10 SIMnotinserted
11 SIMPINrequired
12 SIMPUKrequired
13 SIMfailure
14 SIMbusy
15 SIMwrong
16 incorrectpassword
17 SIMPIN2required
18 SIMPUK2required
20 memoryfull
21 invalidindex
22 notfound
23 memoryfailure
24 textstringtoolong
25 invalidcharactersintextstring
26 dialstringtoolong

---

## Page 274

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 274/281
27 invalidcharactersindialstring
30 nonetworkservice
31 networktimeout
32 networknotallowed-emergencycallonly
40 networkpersonalizationPINrequired
41 networkpersonalizationPUKrequired
42 networksubsetpersonalizationPINrequired
43 networksubsetpersonalizationPUKrequired
44 serviceproviderpersonalizationPINrequired
45 serviceproviderpersonalizationPUKrequired
46 corporatepersonalizationPINrequired
47 corporatepersonalizationPUKrequired
99 resourcelimitation
100 unknown
103 IllegalMS
106 IllegalME
107 GPRSservicesnotallowed
111 PLMNnotallowed
112 Locationareanotallowed
113 Roamingnotallowedinthislocationarea
132 serviceoptionnotsupported
133 requestedserviceoptionnotsubscribed
134 serviceoptiontemporarilyoutoforder
148 unspecifiedGPRSerror
149 PDPauthenticationfailure
150 invalidmobileclass
160 DNSresolvefailed
161 Socketopenfailed
171 MMStaskisbusynow
172 TheMMSdataisoversize
173 Theoperationisovertime
174 ThereisnoMMSreceiver
175 Thestorageforaddressisfull
176 Notfindtheaddress
177 Theconnectiontonetworkisfailed
178 Failedtoreadpushmessage
179 Thisisnotapushmessage
180 gprsisnotattached
181 tcpipstackisbusy
182 TheMMSstorageisfull
183 Theboxisempty

---

## Page 275

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 275/281
184 failedtosaveMMS
185 Itisineditmode
186 Itisnotineditmode
187 Nocontentinthebuffer
188 Notfindthefile
189 FailedtoreceiveMMS
190 FailedtoreadMMS
191 NotM-Notification.ind
192 TheMMSenclosureisfull
193 Unknown
600 NoError
601 UnrecognizedCommand
602 ReturnValueError
603 SyntaxError
604 UnspecifiedError
605 DataTransferAlready
606 ActionAlready
607 NotAtCmd
608 MultiCmdtoolong
609 AbortCops
610 NoCallDisc
611 BTSAPUndefined
612 BTSAPNotAccessible
613 BTSAPCardRemoved
614 ATNotAllowedByCustomer
753 missingrequiredcmdparameter
754 invalidSIMcommand
755 invalidFileId
756 missingrequiredP1/2/3parameter
757 invalidP1/2/3parameter
758 missingrequiredcommanddata
759 invalidcharactersincommanddata
765 Invalidinputvalue
766 Unsupportedmode
767 Operationfailed
768 Muxalreadyrunning
769 Unabletogetcontrol
770 SIMnetworkreject
771 Callsetupinprogress
772 SIMpowereddown
773 SIMfilenotpresent

---

## Page 276

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 276/281
791 Paramcountnotenough
792 Paramcountbeyond
793 Paramvaluerangebeyond
794 Paramtypenotmatch
795 Paramformatinvalid
796 Getanullparam
797 CFUNstateis0or4
20.2SummaryofCMSERRORCodes
Finalresultcode+CMSERROR:<err>indicatesanerrorrelatedtomessageserviceornetwork.The
operationissimilartoERRORresultcode.NoneofthefollowingcommandsinthesameCommandlineis
executed.NeitherERRORnorOKresultcodeshallbereturned.
<err>valuesusedbycommonmessagingcommands:
Codeof<err>Meaning
1 Unassigned(unallocated)number
3 Noroutetodestination
6 Channelunacceptable
8 Operatordeterminedbarring
10 Callbarred
11 Reserved
16 Normalcallclearing
17 Userbusy
18 Nouserresponding
19 Useralerting,noanswer
21 Shortmessagetransferrejected
22 Numberchanged
25 Pre-emption
26 Non-selecteduserclearing
27 Destinationoutofservice
28 Invalidnumberformat(incompletenumber)
29 Facilityrejected
30 ResponsetoSTATUSENQUIRY
32 Normal,unspecified
34 Nocircuit/channelavailable
38 Networkoutoforder
41 Temporaryfailure

---

## Page 277

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 277/281
42 SwitchingequipmentCongestion
43 Accessinformationdiscarded
44 Requestedcircuit/channelnotavailable
47 Resourcesunavailable,unspecified
49 Qualityofserviceunavailable
50 Requestedfacilitynotsubscribed
55 Requestedfacilitynotsubscribed
57 Bearercapabilitynotauthorized
58 Bearercapabilitynotpresentlyavailable
63 Serviceoroptionnotavailable,unspecified
65 Bearerservicenotimplemented
68 ACMequalorgreaterthanACMmaximum
69 Requestedfacilitynotimplemented
70 Onlyrestricteddigitalinformationbearercapabilityisavailable
79 Serviceoroptionnotimplemented,unspecified
81 Invalidtransactionidentifiervalue
87 UsernotmemberofCUG
88 Incompatibledestination
91 Invalidtransitnetworkselection
95 Semanticallyincorrectmessage
96 Invalidmandatoryinformation
97 Messagetypenon-existentornotimplemented
98 Messagetypenotcompatiblewithprotocolstate
99 Informationelementnon-existentornotimplemented
100 Conditionalinformationelementerror
101 Messagenotcompatiblewithprotocol
102 Recoveryontimerexpiry
111 Protocolerror,unspecified
127 Interworking,unspecified
128 Telematicinterworkingnotsupported
129 ShortmessageType0notsupported
130 Cannotreplaceshortmessage
143 UnspecifiedTP-PIDerror
144 Datacodingscheme(alphabet)notsupported
145 Messageclassnotsupported
159 UnspecifiedTP-DCSerror
160 Commandcannotbeacted
161 Commandunsupported
175 UnspecifiedTP-Commanderror
176 TPDUnotsupported
192 SCbusy

---

## Page 278

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 278/281
193 NoSCsubscription
194 SCsystemfailure
195 InvalidSMEaddress
196 DestinationSMEbarred
197 SMRejected-DuplicateSM
198 TP-VPFnotsupported
199 TP-VPnotsupported
208 SIMSMSstoragefull
209 NoSMSstoragecapabilityinSIM
210 ErrorinMS
211 MemoryCapacityExceeded
212 SIMApplicationToolkitBusy
213 SIMdatadownloaderror
224 CPretryexceed
225 RPtrimtimeout
226 SMSconnectionbroken
255 Unspecifiederrorcause
300 MEfailure
301 SMSreserved
302 operationnotallowed
303 operationnotsupported
304 invalidPDUmode
305 invalidtextmode
310 SIMnotinserted
311 SIMpinnecessary
312 PHSIMpinnecessary
313 SIMfailure
314 SIMbusy
315 SIMwrong
316 SIMPUKrequired
317 SIMPIN2required
318 SIMPUK2required
320 memoryfailure
321 invalidmemoryindex
322 memoryfull
323 invalidinputparameter
324 invalidinputformat
325 invalidinputvalue
330 SMSCaddressunknown
331 nonetwork
332 networktimeout

---

## Page 279

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 279/281
340 nocnmaack
500 Unknown
512 SMSnoerror
513 Messagelengthexceedsmaximumlength
514 Invalidrequestparameters
515 MEstoragefailure
516 Invalidbearerservice
517 Invalidservicemode
518 Invalidstoragetype
519 Invalidmessageformat
520 ToomanyMOconcatenatedmessages
521 SMSALnotready
522 SMSALnomoreservice
523 NotsupportTP-Status-Report&TP-Commandinstorage
524 ReservedMTI
525 NofreeentityinRLlayer
526 Theportnumberisalreadyregisterred
527 Thereisnofreeentityforportnumber
528 MoreMessagetoSendstateerror
529 MOSMSisnotallow
530 GPRSissuspended
531 MEstoragefull
532 DoingSIMrefresh
20.3SummaryofUnsolicitedResultCodes
URC Description ATCommand
+CRING:<type>IndicatesincomingcalltotheTEifextended
formatisenabled.AT+CRC=1
+CREG:
<stat>[,<lac>,<ci>,<netact>]ThereisachangeintheMTnetwork
registrationstatusorachangeofthe
networkcell.AT+CREG=<n>
+CMTI:<mem3>,<index>Indicatesthatnewmessagehasbeen
received.AT+CNMI
<mt>=1
+CMTI:
<mem3>,<index>,"MMS
PUSH"IndicatesthatnewMMSmessagehasbeen
received.AT+CNMI
<mt>=1
+CMT:
<length><CR><LF><pdu>Indicatesthatnewmessagehasbeen
received.AT+CNMI
<mt>=2(PDUmode)

---

## Page 280

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 280/281
+CMT:
<oa>,<scts>[,<tooa>,<fo>,<pid
>,<dcs>,<sca>,<tosca>,
<length>]<CR><LF><data>Indicatesthatnewmessagehasbeen
received.AT+CNMI
<mt>=2(textmode)
+CBM:
<length><CR><LF><pdu>Indicatesthatnewcellbroadcastmessage
hasbeenreceived.AT+CNMI
<bm>=2(PDUmode
enabled):
+CBM:
<sn>,<mid>,<dcs>,<page>,<pa
ges><CR><LF><data>Indicatesthatnewcellbroadcastmessage
hasbeenreceived.AT+CNMI
<bm>=2(textmode
enabled):
+CDS:
<length><CR><LF><pdu>IndicatesthatnewSMSstatusreporthas
beenreceived.AT+CNMI
<ds>=1(PDUmode
enabled):
+CDS:
<fo>,<mr>[,<ra>][,<tora>],<sct
s>,<dt>,<st>IndicatesthatnewSMSstatusreporthas
beenreceived.AT+CNMI
<ds>=1(textmode
enabled):
*PSNWID:"<mcc>","<mnc>",
"<fullnetworkname>",<full
networknameCI>,"<short
networkname>",<short
networknameCI>Refreshnetworknamebynetwork.
AT+CLTS=1*PSUTTZ:
<year>,<month>,<day>,<hour>
,<min>,<sec>,"<time
zone>",<dst>Refreshtimeandtimezonebynetwork.
+CTZV:"<timezone>" Refreshnetworktimezonebynetwork.
DST:<dst>RefreshNetworkDaylightSavingTimeby
network.
+CPIN:<code>Indicateswhethersomepasswordis
requiredornot.
AT+CPIN+CPIN:NOTREADY SIMCardisnotready.
+CPIN:NOTINSERTED SIMCardisnotinserted.
+CUSD:
<n>[,<str_urc>[,<dcs>]]IndicatesanUSSDresponsefromthe
network,ornetworkinitiatedoperation.AT+CUSD=1
NORMALPOWERDOWNSIM7000ispowereddownbythePWRKEY
pinorATcommand"AT+CPOWD=1".
UNDER-VOLTAGEPOWER
DOWNUnder-voltageautomaticpowerdown.
UNDER-VOLTAGEWARNNINGunder-voltagewarning
OVER-VOLTAGEPOWER
DOWNOver-voltageautomaticpowerdown.
OVER-VOLTAGEWARNNINGover-voltagewarning
RDYPoweronprocedureiscompleted,andthe
moduleisreadytooperateatfixedbaud
rate.(ThisURCdoesnotappearwhen
auto-baudingfunctionisactive).AT+IPR=<rate>
<rate>isnot0
+CFUN:<fun> Phonefunctionalityindication(ThisURCAT+IPR=<rate>

---

## Page 281

SIM7000Series_ATCommandManual_V1.06
www.simcom.com 281/281
doesnotappearwhenauto-bauding
functionisactive).<rate>isnot0
[<n>,]CONNECTOK TCP/UDPconnectionissuccessful AT+CIPSTART
CONNECTTCP/UDPconnectioninchannelmodeis
successful
[<n>,]CONNECTFAIL TCP/UDPconnectionfails AT+CIPSTART
[<n>,]ALREADYCONNECTTCP/UDPconnectionexists AT+CIPSTART
[<n>,]SENDOK Datasendingissuccessful
[<n>,]CLOSED TCP/UDPconnectionisclosed
RECVFROM:<IPADDRESS>:
<PORT>showsremoteIPaddressandport
(onlyinsingleconnectionmode)AT+CIPSRIP=1
+IPD,<data
size>,<TCP/UDP>:<data>displaytransferprotocolinIPheaderto
receiveddataornot(onlyinsingle
connectionmode)AT+CIPHEAD
AT+CIPSHOWTP
+RECEIVE,<n>,<length>Receiveddatafromremoteclient(onlyin
multipleconnectionmode)
REMOTEIP:<IPADDRESS>Remoteclientconnectedin
+CDNSGIP:1,<domain
name>,<IP>[,<IP2>]DNSsuccessful AT+CDNSGIP
+CDNSGIP:0,<dnserrorcode>DNSfailed
+PDP:DEACT GPRSisdisconnectedbynetwork
+APPPDP:ACTIVE Activethenetworkofappside AT+CNACT=1
+APPPDP:DEACTIVE Deactivethenetworkofappside AT+CNACT=0

---

