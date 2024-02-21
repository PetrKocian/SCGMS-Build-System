/**
 * SmartCGMS - continuous glucose monitoring and controlling framework
 * https://diabetes.zcu.cz/
 *
 * Copyright (c) since 2018 University of West Bohemia.
 *
 * Contact:
 * diabetes@mail.kiv.zcu.cz
 * Medical Informatics, Department of Computer Science and Engineering
 * Faculty of Applied Sciences, University of West Bohemia
 * Univerzitni 8, 301 00 Pilsen
 * Czech Republic
 * 
 * 
 * Purpose of this software:
 * This software is intended to demonstrate work of the diabetes.zcu.cz research
 * group to other scientists, to complement our published papers. It is strictly
 * prohibited to use this software for diagnosis or treatment of any medical condition,
 * without obtaining all required approvals from respective regulatory bodies.
 *
 * Especially, a diabetic patient is warned that unauthorized use of this software
 * may result into severe injure, including death.
 *
 *
 * Licensing terms:
 * Unless required by applicable law or agreed to in writing, software
 * distributed under these license terms is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *
 * a) This file is available under the Apache License, Version 2.0.
 * b) When publishing any derivative work or results obtained using this software, you agree to cite the following paper:
 *    Tomas Koutny and Martin Ubl, "SmartCGMS as a Testbed for a Blood-Glucose Level Prediction and/or 
 *    Control Challenge with (an FDA-Accepted) Diabetic Patient Simulation", Procedia Computer Science,  
 *    Volume 177, pp. 354-362, 2020
 */

#include "dstrings.h"

const wchar_t* dsGPredict3_App_Name = L"gpredict3-desktop";
const wchar_t* dsGPredict3_App_Domain = L"diabetes.zcu.cz";

const wchar_t* dsNaN = L"NaN";
const wchar_t* dsCommon = L"Common";

const wchar_t* dsmmol_per_L = L"mmol/L";
const wchar_t* dsU = L"U";
const wchar_t* dsU_per_Hr = L"U/Hr";
const wchar_t* dsA = L"A";
const wchar_t* dsS = L"S";
const wchar_t* dsm_per_s2 = L"m/s2";

const char* dsSCGMS_Not_Loaded = "SmartCGMS library is not loaded!";

const char* dsFile = "&File";
const char* dsNew_Experimental_Setup = "New";
const char* dsOpen_Experimental_Setup = "Open";
const char* dsOpen_Recent_Experimental_Setup = "Open &recent";
const char* dsSave_Experimental_Setup = "Save";
const char* dsSave_Experimental_Setup_As = "Save As...";
const char* dsExperimental_Setup_File_Mask = "Experimental Setup (*.ini)";
const char* dsUnsaved_Experimental_Setup = "Unsaved experimental setup";
const char* dsQuit = "Quit";
const char* dsTools = "Tools";
const char* dsFilters = "Filters";
const char* dsSimulation = "Simulation";
const char* dsOptimize_Parameters = "Optimize Parameters";

const char* dsNo_Recent_Files = "No recent files";

const char* dsLog_Tab = "Log";
const char* dsErrors_Tab = "Errors";

const char* dsClose_Tab = "Close";
const char* dsSave_Tab_State = "Save state";
const char* dsSaved_State_Tab_Suffix = " (saved)";
const char* dsBest_Metric_Label = "Best metric: %1";
const char* dsBest_Metric_NotAvailable = "N/A";

const char* dsSolver_Status_Disabled = "Disabled";
const char* dsSolver_Status_Idle = "Idle";
const char* dsSolver_Status_In_Progress = "In progress";
const char* dsSolver_Status_Completed_Improved = "Completed and improved";
const char* dsSolver_Status_Completed_Not_Improved = "Completed, but not improved";
const char* dsSolver_Status_Failed = "Failed";
const char* dsSolver_Status_Stopped = "Stopped";

const char* dsClose = "Close";
const char* dsClose_All = "Close All";

const char* dsTile_Vertically = "&Tile Vertically";
const char* dsTile_Horizontally = "&Tile Horizontally";
const char* dsCascade = "&Cascade";
const char* dsNext = "Ne&xt";
const char* dsPrevious = "Pre&vious";

const char* dsWindow = "Window";
const char* dsHelp = "&Help";
const char* dsAbout = "About";
const char* dsAbout_Amp = "&About";
const char* dsGlucose_Prediction = "GPredict3 (SmartCGMS) - %1";
const char* dsWarning = "Warning";

const char* dsSave_Experimental_Setup_Failed = "There are warnings/errrors related this experimental setup.\n\nError code: ";
const char* dsErrors_Warnings_Hints = "Errors, Warnings, Hints:";

const char* dsAdd = "Add";
const char* dsDelete = "Delete";
const char* dsRemove = "Remove";
const char* dsConfigure = "Configure";
const char* dsMove_Up = "Move up";
const char* dsMove_Down = "Move down";

const char* dsStart = "Start";
const char* dsStop = "Stop";
const char* dsSolve = "Solve";
const char* dsSolve_Reset = "Reset and recalculate";
const char* dsSuspend = "Suspend solvers";
const char* dsResume = "Resume solvers";
const char* dsStepUnit = "levels";
const char* dsStep = "Step";

const char* dsFilters_Window = "Filters window";
const char* dsApplied_Filters = "Applied filters";
const char* dsAvailable_Filters = "Available filters";
const char* dsSimulation_Window = "Simulation window";
const char* dsExport_To_CSV = "Export to CSV";
const char* dsExport_CSV_Default_File_Name = "export.csv";
const char* dsExport_CSV_Ext_Spec = "CSV file (*.csv)";
const char* dsExport_CSV_Dialog_Title = "Export to CSV";

const char* dsParameters_Optimization_Use = "To enable parameters' optimization, the filter chain must contain:\n"
											"  a) at least one filter with configured and saved parameters (configure, commit and save)\n"
											"  b) at least one (maximum %1), configured Signal Error filter(s) (higher priority first)\n"
											"  c) exactly one filter must emit Shutdown, and any feedback receiver cannot precede this filter\n"
											"Parameters with improved fitness are applied automatically.";

const wchar_t* dsDb_Reader = L"Db Reader";
const wchar_t* dsDb_Writer = L"Db Writer";
const wchar_t* dsDb_Reader_Legacy = L"Db Reader (legacy)";
const wchar_t* dsDb_Writer_Legacy = L"Db Writer (legacy)";
const wchar_t *dsSinCos_Generator = L"Sin/Cos IG/BG generator";
const wchar_t *dsDummy_Generator = L"Dummy IG/BG generator";

const wchar_t* dsRecent_Files_Filename = L"recent_files";

const wchar_t *dsDb_Host = L"Host";
const wchar_t *dsDb_Port = L"Port";
const wchar_t *dsDb_Provider = L"Provider";
const wchar_t *dsDb_Name = L"Name";
const wchar_t *dsDb_User_Name = L"User name";
const wchar_t *dsDb_Password = L"Password";
const wchar_t *dsTime_Segment_ID = L"Segment Id";
const wchar_t *dsShutdown_After_Last = L"Shutdown after last value";

const wchar_t *dsError_Could_Not_Connect_To_Db = L"Could not connect to database!";
const wchar_t* dsNo_Time_Segments_Specified = L"No time segment specified.";

const wchar_t *dsGenerate_Primary_Keys = L"Generate new primary keys";
const wchar_t *dsStore_Data = L"Store data";
const wchar_t *dsStore_Parameters = L"Store parameters";
const wchar_t *dsSubject_Id = L"Subject";

const wchar_t *dsGen_IG_Offset = L"IG level offset";
const wchar_t *dsGen_IG_Amplitude = L"IG amplitude";
const wchar_t *dsGen_IG_Sin_Period = L"IG sinus period";
const wchar_t *dsGen_IG_Sampling_Period = L"IG sampling period";
const wchar_t *dsGen_BG_Offset = L"BG level offset";
const wchar_t *dsGen_BG_Amplitude = L"BG amplitude";
const wchar_t *dsGen_BG_Cos_Period = L"BG cosinus period";
const wchar_t *dsGen_BG_Sampling_Period = L"BG sampling period";
const wchar_t *dsGen_Total_Time = L"Total generated time interval";

const wchar_t *dsSolver_Filter = L"Solver";

const wchar_t *dsSelected_Model = L"Model";
const wchar_t *dsSelected_Metric = L"Metric";
const wchar_t *dsSelected_Solver = L"Solver";
const wchar_t *dsSelected_Signal = L"Signal";
const wchar_t *dsSelected_Model_Bounds = L"Model bounds";
const wchar_t *dsUse_Relative_Error = L"Use relative error";
const wchar_t *dsUse_Squared_Diff = L"Use squared differences";
const wchar_t *dsUse_Prefer_More_Levels = L"Prefer more levels";
const wchar_t *dsMetric_Threshold = L"Metric threshold";
const wchar_t *dsMetric_Levels_Required = L"Levels required";
const wchar_t *dsUse_Measured_Levels = L"Use measured levels";
const wchar_t* dsEmit_metric_as_signal = L"Emit metric as a signal";
const wchar_t* dsEmit_last_value_only = L"Emit last value only";
const wchar_t* dsDiscard_Repeating_Level = L"Discard repeating level";
const wchar_t* dsSignal_Nor_Metric_ID_Cannot_Be_Null = L"Signal nor metric id cannot be null.";
const wchar_t* dsSignal_ID_Cannot_Be_Null = L"Signal ID cannot be null.";

const wchar_t *dsRecalculate_On_Levels_Count = L"Recalculate on reference level count (0 = off)";
const wchar_t *dsRecalculate_On_Segment_End = L"Recalculate on segment end";
const wchar_t *dsRecalculate_On_Calibration = L"Recalculate on calibration";

const wchar_t *dsFile_Reader = L"File Reader";
const wchar_t *dsAdditional_Rules = L"Additional rules";
const wchar_t *dsInput_Values_File = L"Input file";
const wchar_t *dsMaximum_IG_Interval = L"Maximum IG interval";
const wchar_t *dsMinimum_Required_IGs = L"Minimum IG levels";
const wchar_t *dsRequire_BG = L"Require BG levels";
const wchar_t* dsFailed_To_Send_Event = L" failed to send event. Return code: ";

const wchar_t *dsHold_Values_Delay = L"Hold delay [ms] (0 for real-time)";

const wchar_t *dsSignal_Source_Id = L"Source ID";
const wchar_t *dsSignal_Destination_Id = L"Map to ID";
const wchar_t* dsClone_From_Source = L"Clone from source";
const wchar_t* dsCondition = L"Condition";
const wchar_t* dsExpression_Parse_Error = L"Error parsing the expression: ";
const char* dsInvalid_expression_character = "Invalid character in the expression: ";
const wchar_t* dsCollect_Statistics = L"Collect statistics";
const wchar_t* dsOutput_to_file_enabled_but_no_filename_given = L"Ouput to file enabled, but no filename given.";
const wchar_t* dsInvalid_Argument_Value_per_Parameter = L"Invalid argument value, parameter name: ";
const wchar_t* dsCannot_Open_File = L"Cannot open file: ";
const wchar_t* dsCannot_Read_File = L"Cannot read file: ";
const wchar_t* dsCannot_Write_File = L"Cannot write to file: ";


const wchar_t *rsSignal_Masked_Id = L"Signal";
const wchar_t *rsSignal_Value_Bitmask = L"Bitmask";

const wchar_t *dsSignal_Masked_Id = L"Signal ID";
const wchar_t *dsSignal_Value_Bitmask = L"(bit)Mask<br>(8-64 bit, reads left-to-right)";

const wchar_t *dsHold_Filter = L"Hold";
const wchar_t *dsDrawing_Filter = L"Drawing";
const wchar_t *dsMapping_Filter = L"Signal mapping";
const wchar_t *dsMasking_Filter = L"Signal value masking";
const wchar_t *dsUnmasking_Filter = L"Signal value unmasking";
const wchar_t *dsCalculated_Signal_Filter = L"Calculated signal";
const wchar_t *dsDecoupling_Filter = L"Signal decoupling";

const wchar_t *dsDrawing_Filter_Period = L"Redraw period [ms]";
const wchar_t *dsDiagnosis_Is_Type2 = L"Diabetes type 2? (1 = off)";
const wchar_t *dsDrawing_Filter_Canvas_Width = L"Canvas width";
const wchar_t *dsDrawing_Filter_Canvas_Height = L"Canvas height";
const wchar_t *dsDrawing_Filter_Filename_Graph = L"Single plot file path";
const wchar_t *dsDrawing_Filter_Filename_Day = L"Daily plot file path";
const wchar_t *dsDrawing_Filter_Filename_AGP = L"AGP file path";
const wchar_t *dsDrawing_Filter_Filename_Parkes = L"Parkes grid file path";
const wchar_t *dsDrawing_Filter_Filename_Clark = L"Clark grid file path";
const wchar_t *dsDrawing_Filter_Filename_ECDF = L"ECDF file path";

const wchar_t *dsLog_Filter = L"Log";
const wchar_t *dsLog_Output_File = L"Save log to CSV file";
const wchar_t* dsLog_Segments_Individually = L"Save each segment to a dedicated file";
const wchar_t* dsReduced_Log = L"Saved reduced log";
const wchar_t* dsSecond_Threshold = L"Second threshold";
const wchar_t* dsLog_Input_File_Or_Dir = L"Log file or dir with log files";
const wchar_t *dsEmit_Shutdown_Msg = L"Emit the shutdown message";
const wchar_t *dsLog_Header = L"Logical Clock; Device Time; Event Code; Signal; Info; Segment Id; Event Code Id; Device Id; Signal Id";
const wchar_t *dsLog_Filter_Replay = L"CSV File Log Replay";
const wchar_t* dsInterpret_Filename_As_Segment_Id = L"Interpret filename as segment id";
const wchar_t* dsReset_Segment_Id = L"Reset segment id";
const wchar_t* dsEmit_All_Events_Before_Shutdown = L"Emit all events before shutdown";
const wchar_t* dsProcessing_File = L"Processing file: ";
const wchar_t* dsFile_Has_Not_Expected_Header = L"Expected header not found, will assume standard one. Filename: ";
const wchar_t* dsUnexpected_Error_While_Parsing = L"Unexpected error while parsing file: ";
const wchar_t* dsUnknown_Date_Time_Format = L"Unknown date time format: ";
const wchar_t* dsLine_No = L", line no.: ";
const wchar_t* dsError_In_Number_Format = L"Error in number format: ";
const wchar_t* dsInvalid_GUID = L"Invalid GUID";

const wchar_t *dsDevice_Feedback_Filter = L"Device feedback";
const wchar_t *dsDevice_Filter = L"Device";

const wchar_t *dsGUI_Filter = L"Visualization";

const char* dsSave_Image_To_File = "Save to file";
const char* dsSave_Image_Ext_Spec = "SVG Image (*.svg)";
const char* dsSave_Viewport_To_File = "Save viewport to file";
const char* dsSave_Viewport_Ext_Spec = "Portable Network Graphics (*.png)";
const char* dsDefault_Viewport_File_Name = "image.png";
const char* dsReset_Zoom = "Reset zoom";

const char* dsDiagnosis_T1D = "Type 1";
const char* dsDiagnosis_T2D = "Type 2";
const char* dsDiagnosis_Gestational = "Gestational";

const char* dsSave_Image_Default_Filename_Graph = "graph.svg";
const char* dsSave_Image_Default_Filename_Day = "day.svg";
const char* dsSave_Image_Default_Filename_Parkes = "parkes.svg";
const char* dsSave_Image_Default_Filename_Clark = "clark.svg";
const char* dsSave_Image_Default_Filename_AGP = "agp.svg";
const char* dsSave_Image_Default_Filename_ECDF = "ecdf.svg";
const char* dsSave_Image_Default_Filename_Profile_Glucose = "mobile_glucose.svg";
const char* dsSave_Image_Default_Filename_Profile_Insulin = "mobile_insulin.svg";
const char* dsSave_Image_Default_Filename_Profile_Carbs = "mobile_carbs.svg";


const wchar_t *dsCalculated_Signal = L"Calculated Signal";
const wchar_t* dsPrediction_Window = L"Prediction window";
const wchar_t* dsSolving_Parameters_Separator = L"Solving";
const wchar_t* dsSolve_Parameters = L"Solve parameters";
const wchar_t* dsSolve_Using_All_Segments = L"Solve using all segments";
const wchar_t* dsMetric_Separator = L"Metric";
const wchar_t* dsMetric_Levels_Required_Hint = L"Enter negative number as complement to current number of all reference levels";
const wchar_t* dsSolve_On_Level_Count = L"Solve on level count (0=off)";
const wchar_t* dsSolve_On_Calibration = L"Solve on calibration";
const wchar_t* dsSolve_On_Time_Segment_End = L"Solve on time-segment end";

const wchar_t *dsUse_Just_Opened_Segments = L"Determine parameters using all known segments";

const char *dsConfiguration = "Configuration";
const char *dsSelect_Just_One_Item = "Select just one item.";
const char *dsSimulation_Is_In_Progress = "Simulation is in progress.";

const char *dsInformation = "Information";
const char *dsMain_Parameters = "Main parameters";
const char *dsFilter_Executor_Failed_Review_Config_Errors = "Failed to execute the filters. Please, review the Log|Configuration errors tab.";

const char* dsOK = "OK";
const char* dsCancel = "Cancel";
const char* dsApply = "Apply";
const char* dsCommit = "Commit";

const char* dsSubject = "Subject";
const char* dsSegment = "Segment";
const char* dsValue_Count = "Measured value count";

const wchar_t* dsAvg_Abs = L"average error";
const wchar_t* dsMax_Abs = L"maximum error";
const wchar_t* dsPerc_Abs = L"error at percentil";
const wchar_t* dsThresh_Abs = L"number of errors above threshold";
const wchar_t* dsLeal_2010 = L"Leal 2010";
const wchar_t* dsAIC = L"Akaike Information Criterion";
const wchar_t* dsBessel_Std_Dev = L"standard deviation, with Bessel correction, within threshold to 1-threshold percentiles";
const wchar_t* dsBessel_Variance = L"variance, with Bessel correction, within threshold to 1-threshold percentiles";
const wchar_t* dsCrosswalk = L"Crosswalk";
const wchar_t* dsIntegral_CDF = L"area under ECDF";
const wchar_t* dsAvg_Plus_Bessel_Std_Dev = L"average plus standard deviation with Bessel's correction, within threshold to 1-threshold percentiles";
const wchar_t* dsRMSE = L"RMSE";
const wchar_t* dsExpWtDiffPolar = L"weighted average error preferring positive differences";
const wchar_t* dsAvg_Pow_StdDev_Metric = L"avg^sd";

const wchar_t* dsBlood = L"blood";
const wchar_t* dsInterstitial = L"interstitial fluid";

const wchar_t* dsConstant_Signal = L"Constant signal";

const wchar_t* dsDiffusion_Model_v2 = L"Diffusion model v2";
const wchar_t* dsSteil_Rebrin = L"Steil-Rebrin";
const wchar_t* dsSteil_Rebrin_Diffusion_Prediction = L"Steil-Rebrin Diffusion Prediction";
const wchar_t* dsDiffusion_Prediction = L"Diffusion Prediction";
const wchar_t* dsOref0_Basal_Insulin = L"oref0 basal insulin";
const wchar_t* dsOref0_Basal_Insulin_Orig = L"oref0 basal insulin (orig)";
const wchar_t* dsOref0_IOB_Model = L"oref0 IOB";
const wchar_t* dsOref0_COB_Model = L"oref0 COB";
const wchar_t* dsOref0_Insulin_Activity_Bilinear = L"oref0 insulin activity bilinear";
const wchar_t* dsOref0_Insulin_Activity_Exponential = L"oref0 insulin activity exponential";
const wchar_t* dsOref0_IOB_Bilinear = L"oref0 IOB bilinear";
const wchar_t* dsOref0_IOB_Exponential = L"oref0 IOB exponential";
const wchar_t* dsOref0_COB_Bilinear = L"oref0 COB bilinear";
const wchar_t* dsOref0_BG_Prediction = L"oref0 BG Prediction";
const wchar_t* dsOref0_BG_IOB_Prediction = L"oref0 IOB-based BG Prediction";
const wchar_t* dsOref0_BG_COB_Prediction = L"oref0 COB-based BG Prediction";
const wchar_t* dsOref0_BG_UAM_Prediction = L"oref0 UAM-based BG Prediction";
const wchar_t* dsOref0_BG_ZT_Prediction = L"oref0 ZT-based BG Prediction";
const wchar_t* dsOref0_BG_Prediction_Signal = L"oref0 aggregated BG Prediction";
const wchar_t* dsConstant_Model = L"Constant model";
const wchar_t* dsUVa_Padova_S2013 = L"UVA/Padova S2013";
const wchar_t* dsUVa_Padova_S2017 = L"UVA/Padova S2017";

const wchar_t* dsUVa_Padova_IG = L"UVa/Padova S2013 - Interstitial glucose";
const wchar_t* dsUVa_Padova_BG = L"UVa/Padova S2013 - Blood glucose";
const wchar_t* dsUVa_Padova_Delivered_Insulin = L"UVa/Padova S2013 - Delivered insulin";
const wchar_t* dsUVa_Padova_S2017_IG = L"UVa/Padova S2017 - Interstitial glucose";
const wchar_t* dsUVa_Padova_S2017_BG = L"UVa/Padova S2017 - Blood glucose";
const wchar_t* dsUVa_Padova_S2017_Delivered_Insulin = L"UVa/Padova S2017 - Delivered insulin";
const wchar_t* dsUVa_Padova_S2017_IOB = L"UVa/Padova S2017 - IOB";
const wchar_t* dsUVa_Padova_S2017_COB = L"UVa/Padova S2017 - COB";

const wchar_t* dsGCT_Model_v1 = L"GCT model v1";
const wchar_t* dsGCT_Model_v1_IG = L"GCT model v1 - Interstitial glucose";
const wchar_t* dsGCT_Model_v1_BG = L"GCT model v1 - Blood glucose";
const wchar_t* dsGCT_Model_v1_Delivered_Insulin = L"GCT model v1 - Delivered insulin";
const wchar_t* dsGCT_Model_v1_IOB = L"GCT model v1 - IOB";
const wchar_t* dsGCT_Model_v1_COB = L"GCT model v1 - COB";

const wchar_t* dsGCT_Model_v2 = L"GCT model v2";
const wchar_t* dsGCT_Model_v2_IG = L"GCT model v2 - Interstitial glucose";
const wchar_t* dsGCT_Model_v2_BG = L"GCT model v2 - Blood glucose";
const wchar_t* dsGCT_Model_v2_Delivered_Insulin = L"GCT model v2 - Delivered insulin";
const wchar_t* dsGCT_Model_v2_IOB = L"GCT model v2 - IOB";
const wchar_t* dsGCT_Model_v2_COB = L"GCT model v2 - COB";

const wchar_t* dsPhysical_Activity_Detection_Model = L"Physical activity detection";
const wchar_t* dsPhysical_Activity_Detected_Signal = L"Detected physical activity";
const wchar_t* dsHeart_Rate_Resting = L"HeartRate_resting";

const wchar_t* dsOref0_Solver = L"oref0 solver";

const wchar_t* dsIOB_Model = L"IOB";
const wchar_t* dsCOB_Model = L"COB";
const wchar_t* dsInsulin_Activity_Bilinear = L"Insulin activity bilinear";
const wchar_t* dsInsulin_Activity_Exponential = L"Insulin activity exponential";
const wchar_t* dsIOB_Bilinear = L"IOB bilinear";
const wchar_t* dsIOB_Exponential = L"IOB exponential";
const wchar_t* dsCOB_Bilinear = L"COB bilinear";

const wchar_t* dsP = L"p";
const wchar_t* dsCg = L"cg";
const wchar_t* dsC = L"c";
const wchar_t* dsDt = L"dt";
const wchar_t* dsK = L"k";
const wchar_t* dsH = L"h";

const wchar_t* dsTau = L"tau";
const wchar_t* dsAlpha = L"alpha";
const wchar_t* dsBeta = L"beta";
const wchar_t* dsGamma = L"gamma";

const wchar_t* dsInv_G = L"1/g";

const wchar_t* dsConstantParam = L"c";

const wchar_t* dsRetrospectiveP = L"pr";
const wchar_t* dsRetrospectiveCg = L"cgr";
const wchar_t* dsRetrospectiveC = L"cr";
const wchar_t* dsRetrospectiveDt = L"dtr";

const wchar_t* dsPredictiveP = L"pp";
const wchar_t* dsPredictiveCg = L"cgp";
const wchar_t* dsPredictiveC = L"cp";
const wchar_t* dsPredictiveDt = L"dtp";

const wchar_t* dsInsulin_TwoTerm_Regulation = L"Insulin two-term regulation";
const wchar_t* dsInsulin_PID_Regulation = L"Insulin PID regulation";
const wchar_t* dsBetaPID = L"BetaPID";
const wchar_t* dsBetaPID3 = L"BetaPID3";
const wchar_t* dsInsulin_TwoTerm_OnOff_Rate = L"Two-term on-off regulator insulin rate";
const wchar_t* dsInsulin_TwoTerm_OnNeturalOff_Rate = L"Two-term on-neutral-off regulator insulin rate";
const wchar_t* dsInsulin_TwoTerm_OnOff_Hysteresis_Rate = L"Two-term on-off regulator with hysteresis insulin rate";
const wchar_t* dsInsulin_PID_Regulation_Rate = L"PID regulator insulin rate";
const wchar_t* dsInsulin_BetaPID_Rate = L"BetaPID regulator insulin rate";
const wchar_t* dsInsulin_BetaPID2_Rate = L"BetaPID2 regulator insulin rate";
const wchar_t* dsInsulin_BetaPID3_Rate = L"BetaPID3 regulator insulin rate";
const wchar_t* dsParam_K = L"K";
const wchar_t* dsKp = L"Kp";
const wchar_t* dsKi = L"Ki";
const wchar_t* dsKd = L"Kd";
const wchar_t* dsBasal_Insulin_Rate = L"Basal insulin rate";
const wchar_t* dsKiDecay = L"KiDecay";

const wchar_t* dsLGS_Basal_Insulin_Model = L"Low-Glucose Suspend";
const wchar_t* dsBolus_Calculator = L"Bolus calculator";
const wchar_t* dsCalculated_Bolus_Insulin = L"Calculated bolus insulin";
const wchar_t* dsConst_Basal_Insulin = L"Constant basal insulin rate";
const wchar_t* dsConst_Basal_Low_Suspend_Insulin = L"Constant basal insulin rate with low glucose suspend";

const wchar_t* dsSuspend_Threshold = L"Suspend threshold";
const wchar_t* dsLGS_Suspend_Duration = L"Suspend duration";

const wchar_t* dsISF = L"ISF";
const wchar_t* dsCSR = L"CSR";
const wchar_t* dsInsulinPeak = L"Insulin activity peak";
const wchar_t* dsDIA = L"DIA";

const wchar_t* dsCarbPeak = L"Carbohydrates activity peak";
const wchar_t* dsCarbDA = L"DCA?";

const wchar_t* dsNewUOA = L"NewUOA";
const wchar_t* dsMT_MetaDE = L"MT MetaDE";
const wchar_t* dsHalton_MetaDE = L"Halton MetaDE";
const wchar_t* dsRnd_MetaDE = L"RND MetaDE";
const wchar_t* dsMetaDE = L"MetaDE";
const wchar_t* dsBOBYQA = L"BOBYQA";

const wchar_t* dsPathfinder_Fast = L"Pathfinder, fast";
const wchar_t* dsPathfinder_Spiral = L"Pathfinder, spiral";
const wchar_t* dsPathfinder_Landscape = L"Pathfinder, landscape";
const wchar_t* dsSequential_Brute_Force_Scan = L"Sequential Brute Force Scan";
const wchar_t* dsSequential_Convex_Scan = L"Sequential Convex Scan";
const wchar_t* dsPSO_Halton = L"Halton PSO";
const wchar_t* dsPSO = L"PSO";
const wchar_t* dsSADE = L"SADE";
const wchar_t* dsDE1220 = L"DE1220";
const wchar_t* dsABC = L"Artificial Bee Colony";
const wchar_t* dsCMAES = L"Cov. Matrix Adapt. Evo.";
const wchar_t* dsXNES = L"Exp. Evo. Strat.";
const wchar_t* dsGPSO = L"PSO Generational";
const wchar_t* dsIHS = L"Improved Harmony Search";
const wchar_t* dsSimplex = L"Simplex";
const wchar_t* dsSubplex = L"Subplex";
const wchar_t* dsPraxis = L"Praxis";

const char* dsMax_Generations = "Maximum generations";
const char* dsPopulation_Size = "Population size";


const wchar_t *dsLine_Approx = L"Line";
const wchar_t *dsAkima = L"Akima";
const wchar_t* dsAvgExp = L"AvgExp";

const char *dsDrawing_Tab_Graph = "Single plot";
const char *dsDrawing_Tab_Day = "Daily plot";
const char *dsDrawing_Tab_Clark = "Clarke's Grid";
const char *dsDrawing_Tab_Parkes = "Parkes' Grid";
const char *dsDrawing_Tab_AGP = "AGP";
const char *dsDrawing_Tab_ECDF = "ECDF";
const char *dsDrawing_Tab_Profile_Glucose = "Mobile - Glucose";
const char *dsDrawing_Tab_Profile_Carbs = "Mobile - Carbohydrates";
const char *dsDrawing_Tab_Profile_Insulin = "Mobile - Insulin";

const char *dsLower_Bounds = "Lower bounds";
const char *dsDefault_Parameters = "Default parameters";
const char *dsUpper_Bounds = "Upper bounds";

const char *dsReset_Bounds = "Reset";

const char *dsLog_Table_View = "Table";
const char *dsLog_Raw_View = "Raw";
const char* dsConfig_Errors = "Configuration errors";

const wchar_t *dsSignal_Measured_BG = L"blood glucose";
const wchar_t *dsSignal_Measured_IG = L"interstitial fluid glucose";
const wchar_t *dsSignal_Measured_ISIG = L"ISIG";
const wchar_t *dsSignal_Measured_Calibration = L"blood glucose calibration";
const wchar_t *dsSignal_Delivered_Insulin_Bolus = L"delivered insulin bolus";
const wchar_t *dsSignal_Delivered_Insulin_Total = L"delivered insulin total";
const wchar_t* dsSignal_Requested_Insulin_Bolus = L"requested insulin bolus";
const wchar_t *dsSignal_Delivered_Insulin_Basal_Rate = L"delivered insulin basal rate";
const wchar_t *dsSignal_Requested_Insulin_Basal_Rate = L"requested insulin basal rate";
const wchar_t *dsSignal_Delivered_Insulin_Intradermal_Rate = L"delivered insulin intradermal rate";
const wchar_t *dsSignal_Requested_Insulin_Intradermal_Rate = L"requested insulin intradermal rate";
const wchar_t *dsSignal_Delivered_Insulin_Inhaled = L"delivered inhaled insulin";
const wchar_t *dsSignal_Measured_Insulin_Activity = L"insulin activity";
const wchar_t *dsSignal_Measured_IOB = L"insulin on board (IOB)";
const wchar_t *dsSignal_Measured_COB = L"carbohydrates on board (COB)";
const wchar_t *dsSignal_Measured_Carb_Intake = L"carbohydrate intake";
const wchar_t *dsSignal_Measured_Health_Physical_Activity = L"physical activity";
const wchar_t* dsSignal_Measured_Insulin_Sensitivity = L"insulin sensitivity factor";
const wchar_t* dsSignal_Measured_Carb_Ratio = L"carb-to-insulin ratio";
const wchar_t *dsSignal_Suffix_Measured = L"measured";
const wchar_t *dsSignal_Suffix_Calculated = L"calculated";
const wchar_t *dsSignal_Unknown = L"Unknown";
const wchar_t *dsSignal_Prefix_Virtual = L"virtual";
const wchar_t* dsSignal_Null = L"Null (discards the events)";
const wchar_t* dsInvalid_ID = L"Invalid ID";

const wchar_t *dsSignal_GUI_Name_All = L"All signals";
const wchar_t *dsSignal_GUI_Name_BG = L"Blood glucose";
const wchar_t *dsSignal_GUI_Name_IG = L"Interstitial glucose";
const wchar_t *dsSignal_GUI_Name_ISIG = L"ISIG";
const wchar_t *dsSignal_GUI_Name_Calibration = L"Calibration";
const wchar_t *dsSignal_GUI_Name_Delivered_Insulin_Bolus = L"Bolus Insulin intake";
const wchar_t *dsSignal_GUI_Name_Delivered_Insulin_Basal = L"Basal Insulin intake";
const wchar_t *dsSignal_GUI_Name_Requested_Basal_Insulin_Rate = L"Basal Insulin rate";
const wchar_t *dsSignal_GUI_Name_Insulin_Activity = L"Insulin activity";
const wchar_t* dsSignal_GUI_Name_Basal_Insulin = L"basal insulin";
const wchar_t *dsSignal_GUI_Name_IOB = L"IOB";
const wchar_t *dsSignal_GUI_Name_COB = L"COB";
const wchar_t *dsSignal_GUI_Name_Carbs = L"Carbohydrate intake";
const wchar_t* dsSignal_GUI_Name_Carb_Rescue = L"Carbohydrate rescue";
const wchar_t *dsSignal_GUI_Name_Physical_Activity = L"Physical activity";
const wchar_t* dsSignal_GUI_Name_Skin_Temperature = L"Skin temperature";
const wchar_t* dsSignal_GUI_Name_Air_Temperature = L"Air temperature";
const wchar_t* dsSignal_GUI_Name_Heartbeat = L"Heartbeat";
const wchar_t* dsSignal_GUI_Name_Electrodermal_Activity = L"Electrodermal activity";
const wchar_t* dsSignal_GUI_Name_Steps = L"Steps";
const wchar_t* dsSignal_GUI_Name_Sleep_Quality = L"Sleep quality";
const wchar_t* dsSignal_GUI_Name_Acceleration = L"Acceleration";
const wchar_t* dsSignal_GUI_Name_Movement_Speed = L"Movement speed";
const wchar_t* dsSignal_GUI_Name_Error_Metric = L"error metric";
const wchar_t *dsSignal_GUI_Name_Insulin_Sensitivity = L"Insulin sensitivity factor";
const wchar_t *dsSignal_GUI_Name_Carb_Ratio = L"CHO-to-insulin ratio";

const wchar_t *dsSignal_GUI_Name_Unknown = L"Unknown signal";

const wchar_t *dsSolver_Progress_Box_Title = L"Solver progress";

const wchar_t *dsCould_Not_Init_Network = L"Could not initialize network subsystem";
const wchar_t *dsInvalid_Network_Port = L"Invalid network port specified";
const wchar_t *dsInvalid_Model_GUID = L"Invalid network model ID specified";
const wchar_t *dsCould_Not_Allocate_Network_Pool_Slot = L"Could not allocate network pool slot due to fatal error";

const wchar_t* dsInvalid_Metric_GUID = L"Invalid metric ID specified: ";

const wchar_t *dsError_Column_Average = L"Average";
const wchar_t *dsError_Column_StdDev = L"Std.Dev (Bessel)";
const wchar_t* dsError_Column_ExcKurtosis = L"Exc.Kurt. (Bessel)";
const wchar_t* dsError_Column_Skewness = L"Skewness (Bessel)";
const wchar_t *dsError_Column_Count = L"Count";
const wchar_t *dsError_Column_Sum = L"Sum";
const wchar_t *dsError_Column_Minimum = L"Minimum";
const wchar_t *dsError_Column_First_Quantile = L"1. Quartile";
const wchar_t *dsError_Column_Median = L"Median";
const wchar_t *dsError_Column_Third_Quantile = L"3. Quartile";
const wchar_t *dsError_Column_95_Quantile = L"95% Quantile";
const wchar_t *dsError_Column_99_Quantile = L"99% Quantile";
const wchar_t *dsError_Column_Maximum = L"Maximum";
const wchar_t *dsError_Column_Range_5pct = L"<=5% prob.";
const wchar_t *dsError_Column_Range_10pct = L"<=10% prob.";
const wchar_t *dsError_Column_Range_25pct = L"<=25% prob.";
const wchar_t *dsError_Column_Range_50pct = L"<=50% prob.";

const wchar_t* rsInsert_New_Measured_Value = L"INSERT INTO measured_value (measured_at, time_segment_id, signal_id, value) VALUES (?, ?, ?, ?)";

const wchar_t* rsInsert_Params_Base = L"INSERT INTO ";
const wchar_t* rsInsert_Params_Segmentid_Column = L"segmentid";
const wchar_t* rsInsert_Params_Values_Stmt = L"VALUES";

const wchar_t* rsInsert_Params = L"INSERT INTO model_parameters (time_segment_id, model_id, signal_id, recorded_at, parameters) VALUES (?, ?, ?, ?, ?)";

const wchar_t* rsCreated_Segment_Identifier_Base = L"New_Segment_Marker_";
const wchar_t* rsInsert_New_Time_Segment = L"INSERT INTO time_segment (name, comment, subject_id) VALUES (?, ?, ?)";
const wchar_t* rsSelect_Time_Segment_Id_By_Name = L"SELECT id FROM time_segment WHERE name = ?";
const wchar_t* rsRename_Time_Segment = L"UPDATE time_segment SET name = ? WHERE id = ?";
const wchar_t* rsDelete_Parameters_Of_Segment_Base = L"DELETE FROM ";
const wchar_t* rsDelete_Parameters_Of_Segment_Stmt = L" WHERE time_segment_id = ?";

const wchar_t* rsLegacy_Db_Insert_New_Measured_Value = L"INSERT INTO measuredvalue (measuredat, blood, ist, isig, insulin_bolus, insulin_basal_rate, carbohydrates, calibration, heartrate, steps, movement_speed, segmentid) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
const wchar_t* rsLegacy_Db_Insert_Params_Base = L"INSERT INTO ";
const wchar_t* rsLegacy_Db_Insert_Params_Segmentid_Column = L"segmentid";
const wchar_t* rsLegacy_Db_Insert_Params_Values_Stmt = L"VALUES";
const wchar_t* rsLegacy_Db_Insert_New_Time_Segment = L"INSERT INTO timesegment (name, comment, deleted, subjectid, parallel_id) VALUES (?, ?, ?, ?, ?)";
const wchar_t* rsLegacy_Db_Select_Time_Segment_Id_By_Name = L"SELECT id FROM timesegment WHERE name = ?";
const wchar_t* rsLegacy_Db_Rename_Time_Segment = L"UPDATE timesegment SET name = ? WHERE id = ?";
const wchar_t* rsLegacy_Db_Delete_Parameters_Of_Segment_Stmt = L" WHERE segmentid = ?";
const wchar_t* rsLegacy_Db_Select_Subjects_And_Segments_For_Db_Reader_Filter = L"select timesegment.id, subject.name, timesegment.name, count(measuredvalue.id) from subject, timesegment, measuredvalue where subject.id = timesegment.subjectid and timesegment.id = measuredvalue.segmentid group by timesegment.id, subject.name order by subject.name, timesegment.name asc";
const wchar_t* rsLegacy_Db_Select_Timesegment_Values_Filter = L"select measuredat, blood, ist, isig, insulin_bolus, insulin_basal_rate, carbohydrates, calibration, heartrate, steps, movement_speed from measuredvalue where segmentid = ? order by measuredat asc";
const wchar_t* rsLegacy_Db_Select_Params_Base = L"select ";
const wchar_t* rsLegacy_Db_Select_Params_From = L" from ";
const wchar_t* rsLegacy_Db_Select_Params_Condition = L" where segmentid = ?";
const wchar_t* rsLegacy_Db_Found_New_Segment = L"insert into timesegment (name, comment, deleted) values (?, ?, ?)";
const wchar_t* rsLegacy_Db_Select_Founded_Segment = L"select id from timesegment where name = ?";
const wchar_t* rsLegacy_Db_Update_Founded_Segment = L"update timesegment set name = ?, comment = ?, deleted=?, subjectid=?, parallel_id=? where id=?";
const wchar_t* rsLegacy_Db_Found_New_Subject = L"insert into subject (name, comments, sex, weight) values (?, ?, ?, ?)";
const wchar_t* rsLegacy_Db_Update_Founded_Subject = L"update subject set name = ?, comments = ?, sex = ?, weight = ? where id=?";

const wchar_t* rsInsulin_Regulation = L"insulin-regulation";
const wchar_t* rsInsulin_PID_Regulation = L"insulin-pid-regulation";
const wchar_t* rsBetaPID = L"betapid";
const wchar_t* rsBetaPID3 = L"betapid3";
const wchar_t* rsKp = L"kp";
const wchar_t* rsKi = L"ki";
const wchar_t* rsKd = L"kd";
const wchar_t* rsBasal_Insulin_Rate = L"Basal_insulin_rate";

const wchar_t* rsBolus_Calculator = L"boluscalc";
const wchar_t* rsConst_Basal_Insulin = L"const-basal";

// ---- drawing-related constants

const wchar_t* dsDrawingLocaleTitle = L"Calculated Blood Glucose Level";
const wchar_t* dsDrawingLocaleTitleAgp = L"Ambulatory Glucose Profile";
const wchar_t* dsDrawingLocaleTitleClark = L"Clarke's error grid";
const wchar_t* dsDrawingLocaleTitleParkes = L"Parkes' error grid";
const wchar_t* dsDrawingLocaleTitleECDF = L"ECDF";
const wchar_t* dsDrawingLocaleTitleProfileGlucose = L"Profile - glucose";
const wchar_t* dsDrawingLocaleTitleDay = L"Day";
const wchar_t* dsDrawingLocaleSubtitle = L"Blood glucose level that was calculated from CMGS-measured subcutanoues tissue glucose levels and sporadically measured blood glucose levels";
const wchar_t* dsDrawingLocaleDiabetes1 = L"Diabetes 1";
const wchar_t* dsDrawingLocaleDiabetes2 = L"Diabetes 2";
const wchar_t* dsDrawingLocaleTime = L"Time [day. month. year hour:minute]";
const wchar_t* dsDrawingLocaleTimeDay = L"Time [Hours]";
const wchar_t* dsDrawingLocaleConcentration = L"Glucose Level";
const wchar_t* dsDrawingLocaleHypoglycemy = L"Hypoglycemia";
const wchar_t* dsDrawingLocaleHyperglycemy = L"Hyperglycemia";
const wchar_t* dsDrawingLocaleBlood = L"Measured Blood Glucose Level";
const wchar_t* dsDrawingLocaleBloodCalibration = L"Calibration";
const wchar_t* dsDrawingLocaleIst = L"Subc. Tissue Glucose Level";
const wchar_t* dsDrawingLocaleResults = L"Calculated Blood Glucose Level";
const wchar_t* dsDrawingLocaleDiff2 = L"Diffusion 2 method";
const wchar_t* dsDrawingLocaleDiff3 = L"Diffusion 3 method";
const wchar_t* dsDrawingLocaleQuantile = L"Error Quantiles";
const wchar_t* dsDrawingLocaleRelative = L"Relative";
const wchar_t* dsDrawingLocaleAbsolute = L"Absolute";
const wchar_t* dsDrawingLocaleAverage = L"Average";
const wchar_t* dsDrawingLocaleType = L"Error type";
const wchar_t* dsDrawingLocaleError = L"Error";
const wchar_t* dsDrawingLocaleDescription = L"Description";
const wchar_t* dsDrawingLocaleColor = L"Color";
const wchar_t* dsDrawingLocaleCounted = L"Calculated concentration";
const wchar_t* dsDrawingLocaleMeasured = L"Measured concentration";
const wchar_t* dsDrawingLocaleAxisX = L"Time [Hours]";
const wchar_t* dsDrawingLocaleAxisY = L"Glucose";
const wchar_t* dsDrawingLocaleSvgDatetimeTitle = L"Measured at";
const wchar_t* dsDrawingLocaleSvgIstTitle = L"IST";
const wchar_t* dsDrawingLocaleSvgBloodTitle = L"Blood";
const wchar_t* dsDrawingLocaleSvgBloodCalibrationTitle = L"Blood (calibration)";
const wchar_t* dsDrawingLocaleSvgInsulinTitle = L"Insulin";
const wchar_t* dsDrawingLocaleSvgCarbohydratesTitle = L"Carbohydrates";
const wchar_t* dsDrawingLocaleSvgISIGTitle = L"ISIG";
const wchar_t* dsDrawingLocaleSvgDiff2Title = L"Diffusion 2";
const wchar_t* dsDrawingLocaleSvgDiff3Title = L"Diffusion 3";
const wchar_t* dsDrawingLocaleRelativeError = L"Relative error [%]";
const wchar_t* dsDrawingLocaleCummulativeProbability = L"Cummulative probability [%]";
const wchar_t* dsDrawingLocaleElevatedGlucose = L"Elevated glucose";


const wchar_t *dsCalculate_Past_New_Params = L"Calculate past with first parameter set";
const wchar_t *dsRecalculate_With_Every_Params = L"New parameters recalculate entire segment";
const wchar_t *dsHold_During_Solve = L"Hold during solve";

const wchar_t *dsHold_During_Solve_Tooltip = L"Hold all incoming messages while solver is in progress";

const char *dsTime_Segments_Panel_Title = "Time segments";
const char *dsSignals_Panel_Title = "Signals";
const char *dsRedraw_Button_Title = "Apply visibility";
const char *dsTime_Segments_Panel_Segment_Name = "Segment %1";
const char *dsSelect_All_Segments = "All";
const char *dsSelect_No_Segments = "None";

const char *dsAnonymous_Subject = "Anonymous subject";
const char *dsCreate_New_Subject = "Create new subject";
const char *dsExisting_Subject = "Select existing subject:";

// filter configuration tooltips

// data filter group
const wchar_t *dsDb_Host_Tooltip = L"Database host (hostname or IP address)";
const wchar_t *dsDb_Port_Tooltip = L"Database port (0-65535)";
const wchar_t *dsDb_Provider_Tooltip = L"Database driver provider; for Qt drivers, use QPSQL, QMYSQL, QSQLITE, etc.";
const wchar_t *dsDb_Name_Tooltip = L"Database or schema name relevant to chosen database driver";
const wchar_t *dsDb_Username_Tooltip = L"Username to be used when connecting to database";
const wchar_t *dsDb_Password_Tooltip = L"Password to be used when connecting to database";
const wchar_t *dsShutdown_After_Last_Tooltip = L"Should the filter chain terminate after last value? This is typically used for headless simulations";
const wchar_t *dsGenerate_Primary_Keys_Tooltip = L"Generate new time segment when storing data?";
const wchar_t *dsStore_Data_Tooltip = L"Should all incoming data (measured values) be stored to database?";
const wchar_t *dsStore_Parameters_Tooltip = L"Should all incoming parameters (of all known models) be stored to database? Existing set of parameters would be overwritten";
const wchar_t *dsInput_Values_File_Tooltip = L"File to be extracted and its contents to be sent to simulation";
const wchar_t *dsInput_Segment_Spacing_Tooltip = L"Minimal spacing between values (in seconds) to end currently running segment and start a new one";
const wchar_t *dsHold_Values_Delay_Tooltip = L"Input values will be held for this amount of milliseconds. For slowing down simulation to real-time, use 0";
const wchar_t *dsMinimum_Segment_Levels_Tooltip = L"How many values does the segment need to have to be accepted?";
const wchar_t *dsRequire_IG_BG_Tooltip = L"To accept a segment, it must contain both IG and BG values";

// drawing filter group
const wchar_t *dsCanvas_Width_Tooltip = L"Desired canvas width for output images. Also reflects GUI widget width";
const wchar_t *dsCanvas_Height_Tooltip = L"Desired canvas height for output images. Also reflects GUI widget height";
const wchar_t *dsFilename_Graph_Tooltip = L"Where to store 'Single plot' drawing at the end of simulation";
const wchar_t *dsFilename_Day_Tooltip = L"Where to store 'Daily plot' drawing at the end of simulation";
const wchar_t *dsFilename_AGP_Tooltip = L"Where to store 'AGP' drawing at the end of simulation";
const wchar_t *dsFilename_Parkes_Tooltip = L"Where to store 'Parkes grid' drawing at the end of simulation";
const wchar_t *dsFilename_Clark_Tooltip = L"Where to store 'Clarke grid' drawing at the end of simulation";
const wchar_t *dsFilename_ECDF_Tooltip = L"Where to store 'ECDF' drawing at the end of simulation";

// log filter group
const wchar_t *dsLog_File_Output_Tooltip = L"Log file output. Any existing file with such name will be overwritten";
const wchar_t *dsLog_File_Input_Tooltip = L"Log file to be parsed and its contents to be sent to simulation";

// signals filter group
const wchar_t *dsSelected_Model_Tooltip = L"Model to be used. Make sure you also select valid signal from signal box below";
const wchar_t *dsSelected_Signal_Tooltip = L"Model signal to be used";
const wchar_t *dsPrediction_Window_Tooltip = L"Size of prediction window to be requested from signal calculator regardless of accuracy";
const wchar_t *dsMapping_Source_Signal_Tooltip = L"Incoming signal to be mapped";
const wchar_t *dsMapping_Destination_Signal_Tooltip = L"The incoming signal will be mapped to this signal identifier";
const wchar_t* dsDestination_Signal_Cannot_Be_Invalid = L"Destination signal cannot have invalid id.";
const wchar_t *dsMasked_Signal_Tooltip = L"Signal to be masked";
const wchar_t *dsSignal_Values_Mask_Tooltip = L"Recurring pattern (bitmask) to be applied when masking given signal, up to 64 bits are supported, use 1 to mask value, 0 to leave as-is, insert spaces as you wish";

// solver filter group
const wchar_t *dsSelected_Metric_Tooltip = L"Metric to be used for solution evaluation";
const wchar_t *dsSelected_Solver_Tooltip = L"Solver implementation to be used";
const wchar_t *dsUse_Relative_Error_Tooltip = L"Use relative errors when calculating metric values";
const wchar_t *dsUse_Squared_Diff_Tooltip = L"Use squared differences when calculating metric values";
const wchar_t *dsUse_Prefer_More_Levels_Tooltip = L"Prefer solutions with more levels?";
const wchar_t *dsMetric_Threshold_Tooltip = L"Metric value threshold";
const wchar_t *dsUse_Measured_Levels_Tooltip = L"Use measured signal instead of its approximation?";
const wchar_t *dsRecalculate_On_Levels_Count_Tooltip = L"Run solver after given amount of reference levels";
const wchar_t *dsRecalculate_On_Segment_End_Tooltip = L"Run solver after each segment end marker";
const wchar_t *dsRecalculate_On_Calibration_Tooltip = L"Run solver on every calibration (blood-glucose calibration signal)";
const wchar_t *dsRecalculate_On_Parameters_Tooltip = L"Request signal recalculation on every parameter set";
const wchar_t *dsUse_Opened_Segments_Only_Tooltip = L"Use currently opened segments only";

const wchar_t *dsParameter_Configuration_Failed_RC = L"Parameter (%1) configuration failed with HRESULT == %2";

const wchar_t* dsBergman_Minimal_Model = L"Bergman extended minimal model";
const wchar_t* dsBergman_p1 = L"p1";
const wchar_t* dsBergman_p2 = L"p2";
const wchar_t* dsBergman_p3 = L"p3";
const wchar_t* dsBergman_p4 = L"p4";
const wchar_t* dsBergman_k12 = L"k12";
const wchar_t* dsBergman_k21 = L"k21";
const wchar_t* dsBergman_Vi = L"Vi";
const wchar_t* dsBergman_BW = L"body weight";
const wchar_t* dsBergman_VgDist = L"VgDist";
const wchar_t* dsBergman_d1rate = L"d1rate";
const wchar_t* dsBergman_d2rate = L"d2rate";
const wchar_t* dsBergman_irate = L"irate";
const wchar_t* dsBergman_Qb = L"Qb";
const wchar_t* dsBergman_Ib = L"Ib";
const wchar_t* dsBergman_Q10 = L"Q10";
const wchar_t* dsBergman_Q20 = L"Q20";
const wchar_t* dsBergman_X0 = L"X0";
const wchar_t* dsBergman_I0 = L"I0";
const wchar_t* dsBergman_D10 = L"D10";
const wchar_t* dsBergman_D20 = L"D20";
const wchar_t* dsBergman_Isc0 = L"Isc0";
const wchar_t* dsBergman_Gsc0 = L"Gsc0";
const wchar_t* dsBergman_BasalRate0 = L"BasalRate0";
const wchar_t* dsBergman_diff2_p = L"p";
const wchar_t* dsBergman_diff2_cg = L"cg";
const wchar_t* dsBergman_diff2_c = L"c";
const wchar_t* dsBergman_diff2_dt = L"dt";
const wchar_t* dsBergman_diff2_k = L"k";
const wchar_t* dsBergman_diff2_h = L"h";
const wchar_t* dsBergman_Ag = L"Ag";

const wchar_t *dsBergman_Signal_BG = L"Bergman - blood glucose";
const wchar_t *dsBergman_Signal_IG = L"Bergman - interst. glucose";
const wchar_t *dsBergman_Signal_IOB = L"Bergman - insulin on board";
const wchar_t *dsBergman_Signal_COB = L"Bergman - CHO on board";
const wchar_t *dsBergman_Signal_Basal_Insulin = L"Bergman - dosed basal insulin";
const wchar_t *dsBergman_Signal_Insulin_Activity = L"Bergman - insulin activity";

const wchar_t* dsSignal_Generator = L"Signal generator";
const wchar_t* dsSignal_Generator_Network = L"Signal generator (network)";
const wchar_t* dsParameters = L"Parameters";
const wchar_t* dsFeedback_Name = L"Feedback name";
const wchar_t* dsSynchronize_to_Signal = L"Synchronize to signal";
const wchar_t* dsSynchronization_Signal = L"Synchronization signal";
const wchar_t* dsStepping = L"Stepping";
const wchar_t* dsMaximum_Time = L"Maximum time";
const wchar_t* dsEcho_Default_Parameters_As_Event = L"Echo default parameters as event";
const wchar_t* dsIndividualize_Segment_Specific_Parameters = L"Individualize segment-specific parameters";
const wchar_t* dsAsync_Stepping_Not_Positive = L"Asynchronous stepping must be positive. Affected model: ";
const wchar_t* dsCannot_Get_Model_Descriptor_By_Signal_Id = L"Cannot get model descriptor. Signal id: ";
const wchar_t* dsCannot_Get_Model_Descriptor = L"Cannot get model descriptor.";
const wchar_t* dsError_Initializing_Discrete_Model = L"Cannot initialize discrete model.";
const wchar_t* dsAsync_Sig_Gen_Req_Seg_Id = L"Asynchronously configured model requires a valid segment-id configuration!";
const wchar_t* dsFailed_To_Configure_Model = L"Failed to configure the model.";

const wchar_t* dsImpulse_Response_Filter = L"Impulse response filter";
const wchar_t* dsSignal_Id = L"Signal ID";
const wchar_t* dsResponse_Window = L"Response window (0 = infinite)";

const wchar_t* dsRemote_Host = L"Host";
const wchar_t* dsRemote_Port = L"Port";
const wchar_t* dsRemote_Model_Id = L"Remote model";
const wchar_t* dsRemote_Subject_Name = L"Remote subject name";

const wchar_t* dsSignal_Error = L"Signal error";
const wchar_t* dsFast_Signal_Error = L"Fast signal error";
const wchar_t* dsReference_Signal = L"Reference signal";
const wchar_t* dsError_Signal = L"Error signal";
const wchar_t* dsError = L"Error";
const wchar_t* dsDescription = L"Description";
const wchar_t* dsAbsolute = L"Absolute [mmol/l]";
const wchar_t* dsRelative = L"Relative [%]";
const wchar_t* dsUnsupported_Metric_Configuration = L"Unsupported metric configuration.";

const wchar_t* dsDiabetes_Grid_Filter = L"Diabetes Error Grids";
const wchar_t* dsClarke_Error_Grid = L"Clarke Error Grid";
const wchar_t* dsParkes_Error_Grid_Type_1 = L"Parkes' Error Grid, Type 1";
const wchar_t* dsParkes_Error_Grid_Type_2 = L"Parkes' Error Grid, Type 2";


const wchar_t* dsInsulin_LGS_Rate = L"LGS Basal Insulin Rate";

const wchar_t* dsConst_ISF = L"insulin sensitivity factor";
const wchar_t* dsConst_ISF_Model = L"Constant insulin sensitivity factor";
const wchar_t* dsConst_CR = L"carb-to-insulin ratio";
const wchar_t* dsConst_CR_Model = L"Constant carb-to-insulin ratio";

const wchar_t* dsPattern_Prediction_Model = L"Pattern ist. prediction";
const wchar_t* dsPattern_Prediction_Signal = L"Pattern ist. prediction";
const wchar_t* dsParameters_File = L"Parameters file";
const wchar_t* dsDo_Not_Update_Parameters_File = L"Do not update the parameters file";
const wchar_t* dsDo_Not_Learn = L"Do not learn";
const wchar_t* dsUse_Config_parameters = L"Use config parameters";
const wchar_t* dsSanitize_Unused_Patterns = L"Sanitize unused patterns";
const wchar_t* dsSliding_Window_Length = L"Sliding Window Length";
const wchar_t* dsLearned_Data_Filename_Prefix = L"Learned Data Filename Prefix";
const wchar_t* dsExperimental = L"Experimental";

const wchar_t* dsWeighted_Moving_Average = L"Weighted Moving Average";
const wchar_t* dsWeight_0 = L"Weight t-00";
const wchar_t* dsWeight_5 = L"Weight t-05";
const wchar_t* dsWeight_10 = L"Weight t-10";
const wchar_t* dsWeight_15 = L"Weight t-15";
const wchar_t* dsWeight_20 = L"Weight t-20";
const wchar_t* dsWeight_25 = L"Weight t-25";
const wchar_t* dsWeight_30 = L"Weight t-30";
const wchar_t* dsWeight_35 = L"Weight t-35";
const wchar_t* dsWeight_40 = L"Weight t-40";
const wchar_t* dsWeight_45 = L"Weight t-45";
const wchar_t* dsWeight_50 = L"Weight t-50";
const wchar_t* dsWeight_55 = L"Weight t-55";

const wchar_t* dsExtModel_Unknown_Opcode = L"Unknown opcode received";
const wchar_t* dsExtModel_Invalid_Opcode_Direction = L"Received an opcode in unexpected direction";
const wchar_t* dsExtModel_Invalid_State_Handshake_Reply = L"Handshake reply received in invalid state";
const wchar_t* dsExtModel_Remote_Fatal_Error = L"Fatal error occurred on the remote side, unable to restore state";
const wchar_t* dsExtModel_Protocol_Version_Mismatch = L"Protocol version mismatch";
const wchar_t* dsExtModel_Unknown_Handshake_Error = L"An unknown error occurred during handshake";
const wchar_t* dsExtModel_Unknown_Model_Requested = L"Unknown model requested";
const wchar_t* dsExtModel_Invalid_State_Data = L"Data packet received in invalid state";
const wchar_t* dsExtModel_Invalid_State_Teardown_Request = L"Tear down request received in invalid state";
const wchar_t* dsExtModel_Invalid_State_Teardown_Reply = L"Tear down reply received in invalid state";
const wchar_t* dsExtModel_Could_Not_Connect = L"Could not connect to the remote end";
const wchar_t* dsExtModel_Invalid_Remote_Protocol_Magic = L"Invalid protocol magic reported by remote end";
const wchar_t* dsExtModel_Invalid_Remote_Protocol_Packet_Length = L"Invalid length received in packet header";
const wchar_t* dsExtModel_Invalid_Packet_State = L"Packet received in invalid state";
const wchar_t* dsExtModel_Local_Network_Subsystem_Error = L"Local network subsystem error";

const wchar_t* dsSignal_Feedback = L"Signal feedback";
const wchar_t* dsRemove_From_Source = L"Remove from source";

const wchar_t* dsSignal_Stats = L"Signal statistics";
const wchar_t* dsOutput_CSV_File = L"Output CSV file";
const wchar_t* dsLevel = L"level";
const wchar_t* dsPeriod = L"period";

const wchar_t* dsInvalid_Section_Name = L"Configuration, invalid section name: ";
const wchar_t* dsCannot_Resolve_Filter_Descriptor = L"Cannot resolve filter descriptor by id: ";
const wchar_t* dsMalformed_Filter_Parameter_Value = L"Malformed filter(1)-parameter(2)'s value(3): (1)";
const wchar_t* dsVar_Not_Set_Filter_Parameter_Value = L"Variable filter(1)-parameter(2)'s value(3) not set: (1)";
const wchar_t* dsFilter_Parameter_Not_Configured = L"Filter(1)-parameter(2) is not configured, default value will be used.\nEither set it to $([[maybe_unused]]), or configure it, and save the configuration to remove whis warning.\n(1)";

const wchar_t* dsParameters_to_optimize_not_found = L"Parameters to optimize were not found.";
const wchar_t* dsParameters_to_optimize_could_not_be_read_bounds_including = L"Parameters to optimize could not be read, bounds including.";
const wchar_t* dsFailed_to_clone_configuration = L"Failed to clone configuration";
const wchar_t* dsSolver_Failed = L"Solver failed";
const wchar_t* dsFailed_to_write_parameters = L"Failed to write parameters";
const wchar_t* dsFailed_to_execute_first_filters = L"Failed to execute first filters.";
const wchar_t* dsCannot_read_configuration = L"Cannot read configuration";
const wchar_t* dsCannot_read_filter_id = L"Cannot read filter id.";
const wchar_t* dsFailed_to_configure_filter = L"Failed to configure filter with id: ";
const wchar_t* dsLast_RC = L"Error code: ";
const wchar_t* dsFeedback_sender_not_connected = L"Feedback-sender not connected, sender's name: ";
const wchar_t* dsFilter_configuration_param_value_error = L"Filter(1)-parameter(2) value(3) error: (1)";
const wchar_t* dsStored_Parameters_Corrupted_Not_Loaded = L"Stored parameters are corruped and were not loaded.";

const wchar_t* dsDefault_Filters_Path = L"Default filters directory: ";
const wchar_t* dsLoaded_Filters = L"Loaded filters: ";
const wchar_t* dsNone = L"None";

const wchar_t* dsIcarus_v1_AI_Boluses = L"Icarus v1 AI Boluses";
const wchar_t* dsBolus_Offset = L"Bolus Offset ";
const wchar_t* dsBolus_Amount = L"Bolus Amount ";

const wchar_t* dsIcarus_Basal_And_Bolus = L"Icarus Fixed Basal and Boluses";
const wchar_t* dsCarb_To_Insulin_Ratio = L"Carb to Insulin Ratio";


const wchar_t* dsBasal_2_Bolus = L"Basal to bolus";
const wchar_t* dsMinimum_Volume = L"Minimum volume";
const wchar_t* dsPPeriod = L"Period";	//PPeriod is not a typo, we already have dsPeriod with small P


//--------------------------------- do not translate any of the rs-prefixed texts --

const char* rsAbout_Text = R"CLC(
<b>SmartCGMS</b> - continuous glucose monitoring and controlling framework<br>
<a href="https://diabetes.zcu.cz/smartcgms">https://diabetes.zcu.cz/</a><br>
&nbsp;<br>
Copyright&copy; since 2018 University of West Bohemia.<br>
Release date: June 12, 2020<br>
&nbsp;<br>
<i>Contact:</i><br>
<a href="mailto:diabetes@mail.kiv.zcu.cz?Subject=SmartCGMS">diabetes@mail.kiv.zcu.cz</a><br>
Medical Informatics, Department of Computer Science and Engineering<br>
Faculty of Applied Sciences, University of West Bohemia<br>
Univerzitni 8<br>
301 00, Pilsen<br>
Czech Republic<br>
&nbsp;<br>
&nbsp;<br>
<i>Purpose of this software:</i><br>
 This software is intended to demonstrate work of the diabetes.zcu.cz research
 group to other scientists, to complement our published papers. It is strictly
 prohibited to use this software for diagnosis or treatment of any medical condition,
 without obtaining all required approvals from respective regulatory bodies.<br>
&nbsp;<br>
Especially, a diabetic patient is warned that unauthorized use of this software
may result into severe injure, including death.<br>
&nbsp;<br>
&nbsp;<br>
 <i>Licensing terms:</i><br>
 Unless required by applicable law or agreed to in writing, software
 distributed under these license terms is distributed on an "AS IS" BASIS, WITHOUT
 WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.<br>
 
<ol type="a"> 
<li>For non-profit, academic research, this software is available under the <a href="https://www.gnu.org/licenses/gpl-3.0.html">GPLv3 license</a>.</li>
<li>For any other use, especially commercial use, you must contact us and obtain specific terms and conditions for the use of the software.<li>
<li>When publishing work with results obtained using this software, you agree to cite the following paper:<br>
Tomas Koutny and Martin Ubl, <i>"Parallel software architecture for the next generation of glucose monitoring"</i>, 
Procedia Computer Science, Volume 141C, pp. 279-286, 2018</li>
 </ol>
)CLC";

const wchar_t *rsDb_Host = L"Host";
const wchar_t *rsDb_Port = L"Port";
const wchar_t *rsDb_Provider = L"Provider";
const wchar_t *rsDb_Name = L"Name";
const wchar_t *rsDb_User_Name = L"User_Name";
const wchar_t *rsDb_Password = L"Password";
const wchar_t *rsTime_Segment_ID = L"Time_Segment_Id";

const wchar_t *rsDiffusion_v2_Table = L"difuse2params";
const wchar_t *rsDiffusion_v3_Table = L"difuse3params";
const wchar_t *rsSteil_Rebrin_Table = L"steilrebrinparams";
const wchar_t* rsSteil_Rebrin_Diffusion_Prediction_Table = L"steil_rebrin_diffusion_prediction";
const wchar_t* rsDiffusion_Prediction_Table = L"diffusion_prediction";
const wchar_t* rsOref0_Basal_Insulin = L"oref0_basal_insulin";
const wchar_t* rsOref0_IOB = L"oref0_iob";
const wchar_t* rsOref0_COB = L"oref0_cob";
const wchar_t* rsOref0_BG_Prediction = L"oref0_bg_prediction";
const wchar_t* rsOref0_BG_IOB_Prediction = L"oref0_bg_iob_prediction";
const wchar_t* rsOref0_BG_COB_Prediction = L"oref0_bg_cob_prediction";
const wchar_t* rsOref0_BG_UAM_Prediction = L"oref0_bg_uam_prediction";
const wchar_t* rsOref0_BG_ZT_Prediction = L"oref0_bg_zt_prediction";
const wchar_t* rsConstant_Model = L"constant_model";

const wchar_t* rsPhysical_Activity_Detection_Model = L"Physical_activity_detection";
const wchar_t* rsHeart_Rate_Resting = L"heartrate_Resting";

const wchar_t* rsP_Column = L"p";
const wchar_t* rsCg_Column = L"cg";
const wchar_t* rsC_Column = L"c";
const wchar_t* rsDt_Column = L"dt";
const wchar_t* rsK_Column = L"k";
const wchar_t* rsH_Column = L"h";

const wchar_t* rsInv_G_Column = L"inv_g";

const wchar_t* rsRetrospectiveP = L"p_retro";
const wchar_t* rsRetrospectiveCg = L"cg_retro";
const wchar_t* rsRetrospectiveC = L"c_retro";
const wchar_t* rsRetrospectiveDt = L"dt_retro";

const wchar_t* rsPredictiveP = L"p_pred";
const wchar_t* rsPredictiveCg = L"cg_pred";
const wchar_t* rsPredictiveC = L"c_pred";
const wchar_t* rsPredictiveDt = L"dt_pred";

const wchar_t* rsTau_Column = L"t";
const wchar_t* rsAlpha_Column = L"alpha";
const wchar_t* rsBeta_Column = L"beta";
const wchar_t* rsGamma_Column = L"gamma";

const wchar_t* rsISF = L"isf";
const wchar_t* rsCSR = L"csr";
const wchar_t* rsInsulinPeak = L"ia_peak";
const wchar_t* rsDIA = L"dia";
const wchar_t* rsCarbPeak = L"ca_peak";
const wchar_t* rsCarbDA = L"carbda";

const wchar_t *rsNet_Host = L"Host";
const wchar_t *rsNet_Port = L"Port";
const wchar_t *rsNet_RecvSide = L"Is_Recv";

const wchar_t *rsAdditional_Rules = L"Additional_Rules";

const wchar_t *rsInput_Values_File = L"Input_File";
const wchar_t *rsMaximum_IG_Interval = L"Maximum_IG_Interval";

const wchar_t *rsHold_Values_Delay = L"Hold_Delay";

const wchar_t *rsSignal_Source_Id = L"Signal_Src_Id";
const wchar_t *rsSignal_Destination_Id = L"Signal_Dst_Id";
const wchar_t* rsRemove_From_Source = L"Remove_from_source";
const wchar_t* rsCondition = L"Condition";
const wchar_t* rsCollect_Statistics = L"Collect_statistics";

const wchar_t *rsRecalculate_Past_On_Params = L"Recalculate_Past_On_Params";

const wchar_t *rsGen_IG_Offset = L"IG_Level_Offset";
const wchar_t *rsGen_IG_Amplitude = L"IG_Amplitude";
const wchar_t *rsGen_IG_Sin_Period = L"IG_Sinus_Period";
const wchar_t *rsGen_IG_Sampling_Period = L"IG_Sampling_Period";
const wchar_t *rsGen_BG_Level_Offset = L"BG_Level_Offset";
const wchar_t *rsGen_BG_Amplitude = L"BG_Amplitude";
const wchar_t *rsGen_BG_Cos_Period = L"BG_Cosinus_Period";
const wchar_t *rsGen_BG_Sampling_Period = L"BG_Sampling_Period";
const wchar_t *rsGen_Total_Time = L"Total_Time";

const wchar_t *rsParameters_Reset = L"Model_Signal_Params_Reset";
const wchar_t *rsParameters_Reset_Request = L"Model_Signal_Params_Reset_Request";
const wchar_t *rsSegment_Recalculate_Complete = L"Segment_Recalculate_Complete";

const wchar_t *rsSelected_Model = L"Model";
const wchar_t *rsSelected_Metric = L"Metric";
const wchar_t *rsSelected_Solver = L"Solver";
const wchar_t *rsSelected_Signal = L"Signal";
const wchar_t *rsSelected_Model_Bounds = L"Model_Bounds";
const wchar_t *rsUse_Relative_Error = L"Relative_Error";
const wchar_t *rsUse_Squared_Diff = L"Squared_Diff";
const wchar_t *rsUse_Prefer_More_Levels = L"Prefer_More_Levels";
const wchar_t *rsMetric_Threshold = L"Metric_Threshold";
const wchar_t *rsMetric_Levels_Required = L"Levels_Required";
const wchar_t *rsUse_Measured_Levels = L"Measured_Levels";
const wchar_t* rsEmit_metric_as_signal = L"Emit_Metric_As_Signal";
const wchar_t* rsEmit_last_value_only = L"Emit_Last_Value_Only";
const wchar_t* rsDiscard_Repeating_Level = L"Discard_Repeating_Level";

const wchar_t *rsRecalculate_On_Levels_Count = L"Recalculate_Levels_Count";
const wchar_t *rsRecalculate_On_Segment_End = L"Recalculate_At_Segment_End";
const wchar_t *rsRecalculate_On_Calibration = L"Recalculate_On_Calibration";

const wchar_t *rsLog_Output_File = L"Log_File";
const wchar_t *rsLog_Segments_Individually = L"Log_Segments_Individually";
const wchar_t *rsReduced_Log = L"Reduce_Log";
const wchar_t *rsSecond_Threshold = L"Second_Threshold";
const wchar_t *rsEmit_Shutdown_Msg = L"Emit_Shutdown";
const wchar_t *rsInterpret_Filename_As_Segment_Id = L"Filename_as_segment_id";
const wchar_t* rsReset_Segment_Id = L"Reset_segment_id";
const wchar_t *rsEmit_All_Events_Before_Shutdown = L"Emit_All_Events_Before_Shutdown";

const wchar_t *rsDrawing_Filter_Period = L"Redraw_Period";
const wchar_t *rsDiagnosis_Is_Type2 = L"Diabetes_Type_2";
const wchar_t *rsDrawing_Filter_Canvas_Width = L"Canvas_Width";
const wchar_t *rsDrawing_Filter_Canvas_Height = L"Canvas_Height";
const wchar_t *rsDrawing_Filter_Filename_Graph = L"Graph_File_Path";
const wchar_t *rsDrawing_Filter_Filename_Day = L"Day_File_Path";
const wchar_t *rsDrawing_Filter_Filename_AGP = L"AGP_File_Path";
const wchar_t *rsDrawing_Filter_Filename_Parkes = L"Parkes_File_Path";
const wchar_t *rsDrawing_Filter_Filename_Clark = L"Clark_File_Path";
const wchar_t *rsDrawing_Filter_Filename_ECDF = L"ECDF_File_Path";

const wchar_t* rsFile_Path = L"File_Path";

const wchar_t *rsCallback_Log_Message = L"CallbackLog_Message";
const wchar_t *rsCallback_Drawing_Graph = L"CallbackDrawing_Graph";
const wchar_t *rsCallback_Drawing_Day = L"CallbackDrawing_Day";
const wchar_t *rsCallback_Drawing_Clark = L"CallbackDrawing_Clark";
const wchar_t *rsCallback_Drawing_Parkes = L"CallbackDrawing_Parkes";
const wchar_t *rsCallback_Drawing_Parkes_Type2 = L"CallbackDrawing_Parkes_Type2";
const wchar_t *rsCallback_Drawing_AGP = L"CallbackDrawing_AGP";

const wchar_t *rsInfo_Redraw_Complete = L"RedrawComplete";
const wchar_t *rsInfo_Solver_Progress = L"SolverProgress";
const wchar_t *rsInfo_Solver_Failed = L"SolverFailed";
const wchar_t *rsInfo_Solver_Completed_But_No_Improvement = L"Solver_Completed_But_No_Improvement";
const wchar_t *rsInfo_Error_Metrics_Ready = L"ErrorMetricsReady";
const wchar_t *rsInfo_Shut_Down_Marker = L"Shut_Down_Marker";

const wchar_t *rsConfig_File_Name = L"config.ini";
const wchar_t *rsFilter_Section_Prefix = L"Filter";
const wchar_t rsFilter_Section_Separator = L'_';
const wchar_t *rsIni_Comment_Prefix = L"; ";

const wchar_t* rsSolversDir = L"filters";

const char* rsFilter_Get_SVG_AGP = "get_svg_agp";
const char* rsFilter_Get_SVG_Clark = "get_svg_clark";
const char* rsFilter_Get_SVG_Day = "get_svg_day";
const char* rsFilter_Get_SVG_Graph = "get_svg_graph";
const char* rsFilter_Get_SVG_Parkes = "get_svg_parkes";
const char* rsFilter_Get_SVG_Parkes_Type2 = "get_svg_parkes_type2";

const char* rsFilter_Get_Errors = "get_error_metrics";

const wchar_t* rsSelect_Subjects_And_Segments_For_Db_Reader_Filter = L"select time_segment.id, subject.name, time_segment.name, count(measured_value.id) from subject, time_segment, measured_value where subject.id = time_segment.subject_id and time_segment.id = measured_value.time_segment_id group by time_segment.id, subject.name order by subject.name, time_segment.name asc";
const wchar_t* rsSelect_Subjects = L"select id, name from subject";
const wchar_t* rsSelect_Timesegment_Values_Filter = L"select measured_at, signal_id, value from measured_value where time_segment_id = ? order by measured_at asc";
const wchar_t* rsSelect_Params_Filter = L"select recorded_at, model_id, signal_id, parameters from model_parameters where time_segment_id = ? order by recorded_at asc";

// ---- drawing-related constants

const wchar_t* rsDrawingLocaleTitle = L"title";
const wchar_t* rsDrawingLocaleTitleDay = L"titleDay";
const wchar_t* rsDrawingLocaleSubtitle = L"subtitle";
const wchar_t* rsDrawingLocaleDiabetes1 = L"diabetes_type_1";
const wchar_t* rsDrawingLocaleDiabetes2 = L"diabetes_type_2";
const wchar_t* rsDrawingLocaleTime = L"time";
const wchar_t* rsDrawingLocaleTimeDay = L"timeDay";
const wchar_t* rsDrawingLocaleConcentration = L"concentration";
const wchar_t* rsDrawingLocaleHypoglycemy = L"hypoglycemia";
const wchar_t* rsDrawingLocaleHyperglycemy = L"hyperglycemia";
const wchar_t* rsDrawingLocaleBlood = L"blood";
const wchar_t* rsDrawingLocaleBloodCalibration = L"bloodCalibration";
const wchar_t* rsDrawingLocaleIst = L"ist";
const wchar_t* rsDrawingLocaleResults = L"results";
const wchar_t* rsDrawingLocaleDiff2 = L"diff2";
const wchar_t* rsDrawingLocaleDiff3 = L"diff3";
const wchar_t* rsDrawingLocaleQuantile = L"quantil";
const wchar_t* rsDrawingLocaleRelative = L"relative";
const wchar_t* rsDrawingLocaleAbsolute = L"absolute";
const wchar_t* rsDrawingLocaleAverage = L"average";
const wchar_t* rsDrawingLocaleType = L"type";
const wchar_t* rsDrawingLocaleError = L"error";
const wchar_t* rsDrawingLocaleDescription = L"description";
const wchar_t* rsDrawingLocaleColor = L"color";
const wchar_t* rsDrawingLocaleCounted = L"counted";
const wchar_t* rsDrawingLocaleMeasured = L"measured";
const wchar_t* rsDrawingLocaleAxisX = L"axis_x";
const wchar_t* rsDrawingLocaleAxisY = L"axis_y";
const wchar_t* rsDrawingLocaleSvgDatetimeTitle = L"title_datetime";
const wchar_t* rsDrawingLocaleSvgIstTitle = L"title_ist";
const wchar_t* rsDrawingLocaleSvgBloodTitle = L"title_blood";
const wchar_t* rsDrawingLocaleSvgBloodCalibrationTitle = L"title_blood_calibration";
const wchar_t* rsDrawingLocaleSvgInsulinTitle = L"title_insulin";
const wchar_t* rsDrawingLocaleSvgCarbohydratesTitle = L"title_carbohydrates";
const wchar_t* rsDrawingLocaleSvgISIGTitle = L"title_isig";
const wchar_t* rsDrawingLocaleSvgDiff2Title = L"title_diff2";
const wchar_t* rsDrawingLocaleSvgDiff3Title = L"title_diff3";
const wchar_t* rsDrawingLocaleRelativeError = L"rel_error";
const wchar_t* rsDrawingLocaleCummulativeProbability = L"cummulative_probability";
const wchar_t* rsDrawingLocaleElevatedGlucose = L"elevatedglucose";

const wchar_t* rsCannot_Get_Parameters = L"Cannot get parameters!";
const wchar_t* rsLog_Date_Time_Format = L"%Y-%m-%d %H:%M:%S";

const wchar_t* rsLog_CSV_Separator = L"; ";
const char* rsRattime_Edit_Mask = "h:mm:ss.zzz";
const wchar_t *rsShutdown_After_Last = L"Shutdown_After_Last";
const wchar_t *rsMinimum_Required_IGs = L"Minimum_Required_IGs";
const wchar_t *rsRequire_BG = L"Require_BG";

const wchar_t* rsConstantParam = L"c";

const wchar_t *rsGenerate_Primary_Keys = L"Generate_Primary_Keys";
const wchar_t *rsStore_Data = L"Store_Data";
const wchar_t *rsStore_Parameters = L"Store_Parameters";
const wchar_t *rsSubject_Id = L"Subject_Id";

const wchar_t* rsReserved_Segment_Name = L"RESERVED_SEGMENT_NAME";
const wchar_t* rsFound_New_Segment = L"insert into time_segment (name) values (?)";
const wchar_t* rsSelect_Founded_Segment = L"select id from time_segment where name = ?";
const wchar_t* rsUpdate_Founded_Segment = L"update time_segment set name = ?, subject_id = ? where id = ?";

const wchar_t* rsReserved_Subject_Name = L"RESERVED_SUBJECT_NAME";
const wchar_t* rsFound_New_Subject = L"insert into subject (name, comment) values (?, ?)";
const wchar_t* rsSelect_Founded_Subject = L"select id from subject where name = ?";
const wchar_t* rsUpdate_Founded_Subject = L"update subject set name = ?, comment = ? where id = ?";

const wchar_t* rsPrediction_Window = L"Prediction_Window";
const wchar_t* rsSolve_Parameters = L"Solve_Parameters";
const wchar_t* rsSolve_Using_All_Segments = L"Solve_Using_All_Segments";
const wchar_t* rsSolve_On_Level_Count = L"Solve_On_Level_Count";
const wchar_t* rsSolve_On_Calibration = L"Solve_On_Calibration";
const wchar_t* rsSolve_On_Time_Segment_End = L"Solve_On_Time_Segment_End";

const wchar_t* rsMatlab_Manifest_File = L"matlab_manifest.xml";
const wchar_t* rsMatlab_Manifest_Session_Name_Path = L"manifest.session:name";
const wchar_t* rsMatlab_Manifest_Workdir_Path = L"manifest.directory:path";
const wchar_t* rsMatlab_Manifest_Models_Path = L"manifest.models";
const wchar_t* rsMatlab_Manifest_Solvers_Path = L"manifest.solvers";
const wchar_t* rsMatlab_Manifest_Model_Tag = L"model";
const wchar_t* rsMatlab_Manifest_Solver_Tag = L"solver";
const wchar_t* rsMatlab_Manifest_Id_Parameter = L"id";
const wchar_t* rsMatlab_Manifest_Description_Parameter = L"description";
const wchar_t* rsMatlab_Manifest_Name_Parameter = L"name";
const wchar_t* rsMatlab_Manifest_DB_Table_Parameter = L"dbtable";
const wchar_t* rsMatlab_Manifest_Parameters_Tag = L"parameters";
const wchar_t* rsMatlab_Manifest_Parameter_Tag = L"param";
const wchar_t* rsMatlab_Manifest_DB_Column_Parameter = L"dbname";
const wchar_t* rsMatlab_Manifest_Default_Parameter = L"default";
const wchar_t* rsMatlab_Manifest_Param_Lowbound = L"lowerbound";
const wchar_t* rsMatlab_Manifest_Param_Upbound = L"upperbound";
const wchar_t* rsMatlab_Manifest_Signals_Tag = L"signals";
const wchar_t* rsMatlab_Manifest_Signal_Tag = L"signal";
const wchar_t* rsMatlab_Manifest_Reference_Signal_Id_Param = L"reference";
const wchar_t* rsMatlab_Manifest_Script_Name = L"scriptname";
const wchar_t* rsMatlab_Manifest_Models_Tag = L"models";

const char16_t* rsMatlab_Variable_Model_Parameters = u"model_parameters";
const char16_t* rsMatlab_Variable_Model_Times = u"model_times";
const char16_t* rsMatlab_Variable_Model_Derivation = u"model_derivation";
const char16_t* rsMatlab_Variable_Model_Output = u"model_output";
const char16_t* rsMatlab_Variable_Solver_Times = u"solver_times";
const char16_t* rsMatlab_Variable_Solver_Values = u"solver_values";
const char16_t* rsMatlab_Variable_Solver_Hints = u"solver_hints";
const char16_t* rsMatlab_Variable_Solver_Lowbounds = u"solver_lowerbounds";
const char16_t* rsMatlab_Variable_Solver_Upbounds = u"solver_upperbounds";
const char16_t* rsMatlab_Variable_Solver_Output = u"solver_output";

const wchar_t* rsOref0_Manifest_File = L"oref0_manifest.xml";
const wchar_t* rsOref0_Manifest_Workdir_Path = L"manifest.workdir:path";
const wchar_t* rsOref0_Manifest_Runner_Script_Path = L"manifest.runner:path";
const wchar_t* rsOref0_Manifest_Node_Command_Path = L"manifest.node:command";
const wchar_t* rsOref0_Manifest_Socket_Timeout_Path = L"manifest.socket:timeout";
const wchar_t* rsOref0_Manifest_Socket_Port_Path = L"manifest.socket:port";
const wchar_t* rsOref0_Manifest_Default_Runner_Script = L"runner.js";
const wchar_t* rsOref0_Manifest_Default_Node_Command = L"node";

//**************
const wchar_t *rsCalculate_Past_New_Params = L"Calc_Past_First_Params";
const wchar_t *rsRecalculate_With_Every_Params = L"Recalc_Every_Params";
const wchar_t *rsUse_Just_Opened_Segments = L"Use_Just_Opened_Segments";
const wchar_t *rsHold_During_Solve = L"Hold_During_Solve";


const wchar_t* rsParameters = L"Parameters";
const wchar_t* rsFeedback_Name = L"Feedback_Name";
const wchar_t* rsSynchronize_to_Signal = L"Synchronize_To_Signal";
const wchar_t* rsSynchronization_Signal = L"Synchronization_Signal";
const wchar_t* rsStepping = L"Stepping";
const wchar_t* rsMaximum_Time = L"Maximum_Time";
const wchar_t* rsEcho_Default_Parameters_As_Event = L"Echo_Default_Parameters_As_Event";
const wchar_t* rsIndividualize_Segment_Specific_Parameters = L"Individualize_Segment_Specific_Parameters";

const wchar_t* rsRemote_Host = L"Host";
const wchar_t* rsRemote_Port = L"Port";
const wchar_t* rsRemote_Model_Id = L"Remote_Model";
const wchar_t* rsRemote_Subject_Name = L"Remote_Subject";

const wchar_t* rsReference_Signal = L"Reference_Signal";
const wchar_t* rsError_Signal = L"Error_Signal";
const wchar_t* rsDescription = L"Description";

const wchar_t* rsIOB_Model = L"iob";
const wchar_t* rsCOB_Model = L"cob";


const wchar_t* rsParam_K = L"k";
const wchar_t* rsKiDecay = L"kidecay";

const wchar_t* rsLGS_Basal_Insulin_Model = L"Low_Glucose_Suspend";
const wchar_t* rsSuspend_Threshold = L"Suspend_Threshold";
const wchar_t* rsLGS_Suspend_Duration = L"Suspend_Duration";

const wchar_t* rsConst_ISF = L"const_insulin_sensitivity_factor";
const wchar_t* rsConst_CR = L"const_carb_to_insulin_ratio";


const wchar_t* rsOutput_CSV_File = L"Output_CSV_file";
const wchar_t* rsSignal_Stats_Header = L"Segment id; marker;; avg; stddev;exc.kurt;skew;count;; min; 25th; median; 75; 95; 99; max";
const wchar_t* rsDecoupling_Stats_Header = L"Segment id; marker;; avg; stddev;exc.kurt;skew;count;; min; 25th; median; 75; max;; matched_events; total_events; matched_levels; total_levels";

const wchar_t* rsDiabetes_Grid_Header = L"Segment id;; A; B; A+B; C; D; E";


const wchar_t* rsPattern_Prediction_Model = L"Pattern_IG_Prediction";
const wchar_t* rsParameters_File = L"Parameters_File";
const wchar_t* rsDo_Not_Update_Parameters_File = L"Do_Not_Update_Parameters_File";
const wchar_t* rsDo_Not_Learn = L"Do_Not_Learn";
const wchar_t* rsUse_Config_parameters = L"Use_Config_Parameters";
const wchar_t* rsSanitize_Unused_Patterns = L"Sanitize_Unused_Patterns";
const wchar_t* rsSliding_Window_Length = L"Sliding_Window_Length";
const wchar_t* rsLearned_Data_Filename_Prefix = L"Learned_Data_Filename_Prefix";

const wchar_t* rsIcarus_v1_AI_Boluses = L"Icarus_v1_AI_Boluses";
const wchar_t* rsBolus_Offset = L"Bolus_Offset_";
const wchar_t* rsBolus_Amount = L"Bolus_Amount_";

const wchar_t* rsIcarus_Basal_And_Bolus = L"Icarus_Fixed_Basal_And_Bolus";
const wchar_t* rsCarb_To_Insulin_Ratio = L"Carb_To_Insulin_Ratio";


const wchar_t* rsWeighted_Moving_Average = L"Weighted_Moving_Average";
const wchar_t* rsWeight_0 = L"Weight_0";
const wchar_t* rsWeight_5 = L"Weight_5";
const wchar_t* rsWeight_10 = L"Weight_10";
const wchar_t* rsWeight_15 = L"Weight_15";
const wchar_t* rsWeight_20 = L"Weight_20";
const wchar_t* rsWeight_25 = L"Weight_25";
const wchar_t* rsWeight_30 = L"Weight_30";
const wchar_t* rsWeight_35 = L"Weight_35";
const wchar_t* rsWeight_40 = L"Weight_40";
const wchar_t* rsWeight_45 = L"Weight_45";
const wchar_t* rsWeight_50 = L"Weight_50";
const wchar_t* rsWeight_55 = L"Weight_55";

const wchar_t* rsSignal_Id = L"Signal_ID";
const wchar_t* rsResponse_Window = L"Response_Window";

const wchar_t* rsFailed_to_allocate_memory = L"Failed to allocate memory!";

const wchar_t* rsUnused_Variable_Name = L"$([[maybe_unused]])";

const wchar_t* rsMinimum = L"Minimum";
const wchar_t* rsPeriod = L"Period";
