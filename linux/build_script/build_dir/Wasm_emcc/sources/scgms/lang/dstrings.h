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

#pragma once

//UI strings used by the entire application

extern const wchar_t* dsGPredict3_App_Name;
extern const wchar_t* dsGPredict3_App_Domain;

extern const wchar_t* dsNaN;
extern const wchar_t* dsCommon;

extern const wchar_t* dsmmol_per_L;
extern const wchar_t* dsU;
extern const wchar_t* dsU_per_Hr;
extern const wchar_t* dsA;
extern const wchar_t* dsS;
extern const wchar_t* dsm_per_s2;

extern const char* dsSCGMS_Not_Loaded;

extern const char* dsFile;
extern const char* dsNew_Experimental_Setup;
extern const char* dsOpen_Experimental_Setup;
extern const char* dsOpen_Recent_Experimental_Setup;
extern const char* dsSave_Experimental_Setup;
extern const char* dsSave_Experimental_Setup_As;
extern const char* dsExperimental_Setup_File_Mask;
extern const char* dsUnsaved_Experimental_Setup;
extern const char* dsQuit;
extern const char* dsTools;
extern const char* dsFilters;
extern const char* dsSimulation;
extern const char* dsOptimize_Parameters;

extern const char* dsNo_Recent_Files;

extern const char* dsLog_Tab;
extern const char* dsErrors_Tab;

extern const char* dsClose_Tab;
extern const char* dsSave_Tab_State;
extern const char* dsSaved_State_Tab_Suffix;
extern const char* dsBest_Metric_Label;
extern const char* dsBest_Metric_NotAvailable;

extern const char* dsSolver_Status_Disabled;
extern const char* dsSolver_Status_Idle;
extern const char* dsSolver_Status_In_Progress;
extern const char* dsSolver_Status_Completed_Improved;
extern const char* dsSolver_Status_Completed_Not_Improved;
extern const char* dsSolver_Status_Failed;
extern const char* dsSolver_Status_Stopped;

extern const char* dsClose;
extern const char* dsClose_All;

extern const char* dsTile_Vertically;
extern const char* dsTile_Horizontally;
extern const char* dsCascade;
extern const char* dsNext;
extern const char* dsPrevious;

extern const char* dsWindow;
extern const char* dsHelp;
extern const char* dsAbout;
extern const char* dsAbout_Amp;
extern const char* dsGlucose_Prediction;
extern const char* dsWarning;

extern const char* dsSave_Experimental_Setup_Failed;
extern const char* dsErrors_Warnings_Hints;

extern const char* dsAdd;
extern const char* dsDelete;
extern const char* dsRemove;
extern const char* dsConfigure;
extern const char* dsMove_Up;
extern const char* dsMove_Down;

extern const char* dsStart;
extern const char* dsStop;
extern const char* dsSolve;
extern const char* dsSolve_Reset;
extern const char* dsSuspend;
extern const char* dsResume;
extern const char* dsStepUnit;
extern const char* dsStep;

extern const char* dsFilters_Window;
extern const char* dsApplied_Filters;
extern const char* dsAvailable_Filters;
extern const char* dsSimulation_Window;
extern const char* dsExport_To_CSV;
extern const char* dsExport_CSV_Default_File_Name;
extern const char* dsExport_CSV_Ext_Spec;
extern const char* dsExport_CSV_Dialog_Title;

extern const char* dsParameters_Optimization_Use;

extern const wchar_t *dsDb_Reader;
extern const wchar_t *dsDb_Writer;
extern const wchar_t* dsDb_Reader_Legacy;
extern const wchar_t* dsDb_Writer_Legacy;
extern const wchar_t *dsSinCos_Generator;
extern const wchar_t *dsDummy_Generator;

extern const wchar_t* dsRecent_Files_Filename;

extern const wchar_t *dsDb_Host;
extern const wchar_t *dsDb_Port;
extern const wchar_t *dsDb_Provider;
extern const wchar_t *dsDb_Name;
extern const wchar_t *dsDb_User_Name;
extern const wchar_t *dsDb_Password;
extern const wchar_t *dsTime_Segment_ID;
extern const wchar_t *dsShutdown_After_Last;

extern const wchar_t *dsError_Could_Not_Connect_To_Db;
extern const wchar_t* dsNo_Time_Segments_Specified;

extern const wchar_t *dsGenerate_Primary_Keys;
extern const wchar_t *dsStore_Data;
extern const wchar_t *dsStore_Parameters;
extern const wchar_t *dsSubject_Id;

extern const wchar_t *dsGen_IG_Offset;
extern const wchar_t *dsGen_IG_Amplitude;
extern const wchar_t *dsGen_IG_Sin_Period;
extern const wchar_t *dsGen_IG_Sampling_Period;
extern const wchar_t *dsGen_BG_Offset;
extern const wchar_t *dsGen_BG_Amplitude;
extern const wchar_t *dsGen_BG_Cos_Period;
extern const wchar_t *dsGen_BG_Sampling_Period;
extern const wchar_t *dsGen_Total_Time;

extern const wchar_t *dsSolver_Filter;

extern const wchar_t *dsSelected_Model;
extern const wchar_t *dsSelected_Metric;
extern const wchar_t *dsSelected_Solver;
extern const wchar_t *dsSelected_Signal;
extern const wchar_t *dsSelected_Model_Bounds;

extern const wchar_t *dsUse_Relative_Error;
extern const wchar_t *dsUse_Squared_Diff;
extern const wchar_t *dsUse_Prefer_More_Levels;
extern const wchar_t *dsMetric_Threshold;
extern const wchar_t *dsMetric_Levels_Required;
extern const wchar_t *dsUse_Measured_Levels;
extern const wchar_t* dsEmit_metric_as_signal;
extern const wchar_t* dsEmit_last_value_only;
extern const wchar_t* dsDiscard_Repeating_Level;
extern const wchar_t* dsSignal_Nor_Metric_ID_Cannot_Be_Null;
extern const wchar_t* dsSignal_ID_Cannot_Be_Null;

extern const wchar_t *dsRecalculate_On_Levels_Count;
extern const wchar_t *dsRecalculate_On_Segment_End;
extern const wchar_t *dsRecalculate_On_Calibration;

extern const wchar_t *dsFile_Reader;
extern const wchar_t *dsAdditional_Rules;
extern const wchar_t *dsInput_Values_File;
extern const wchar_t *dsMaximum_IG_Interval;
extern const wchar_t *dsMinimum_Required_IGs;
extern const wchar_t *dsRequire_BG;
extern const wchar_t* dsFailed_To_Send_Event;

extern const wchar_t *dsHold_Values_Delay;

extern const wchar_t *dsSignal_Source_Id;
extern const wchar_t *dsSignal_Destination_Id;
extern const wchar_t* dsRemove_From_Source;
extern const wchar_t* dsCondition;
extern const wchar_t* dsExpression_Parse_Error;
extern const char* dsInvalid_expression_character;
extern const wchar_t* dsCollect_Statistics;
extern const wchar_t* dsOutput_to_file_enabled_but_no_filename_given;
extern const wchar_t* dsInvalid_Argument_Value_per_Parameter;
extern const wchar_t* dsCannot_Open_File;
extern const wchar_t* dsCannot_Read_File;
extern const wchar_t* dsCannot_Write_File;

extern const wchar_t *dsSignal_Masked_Id;
extern const wchar_t *dsSignal_Value_Bitmask;

extern const wchar_t *dsHold_Filter;
extern const wchar_t *dsDrawing_Filter;
extern const wchar_t *dsMapping_Filter;
extern const wchar_t* dsMasking_Filter;
extern const wchar_t* dsUnmasking_Filter;
extern const wchar_t* dsCalculated_Signal_Filter;
extern const wchar_t* dsDecoupling_Filter;

extern const wchar_t *dsDrawing_Filter_Period;
extern const wchar_t *dsDiagnosis_Is_Type2;
extern const wchar_t *dsDrawing_Filter_Canvas_Width;
extern const wchar_t *dsDrawing_Filter_Canvas_Height;
extern const wchar_t *dsDrawing_Filter_Filename_Graph;
extern const wchar_t *dsDrawing_Filter_Filename_Day;
extern const wchar_t *dsDrawing_Filter_Filename_AGP;
extern const wchar_t *dsDrawing_Filter_Filename_Parkes;
extern const wchar_t *dsDrawing_Filter_Filename_Clark;
extern const wchar_t *dsDrawing_Filter_Filename_ECDF;

extern const wchar_t *dsInterop_Export_Filter;

extern const wchar_t *dsLog_Filter;
extern const wchar_t *dsLog_Output_File;
extern const wchar_t* dsLog_Segments_Individually;
extern const wchar_t* dsReduced_Log;
extern const wchar_t* dsSecond_Threshold;
extern const wchar_t* dsLog_Input_File_Or_Dir;
extern const wchar_t *dsEmit_Shutdown_Msg;
extern const wchar_t *dsLog_Header;
extern const wchar_t *dsLog_Filter_Replay;
extern const wchar_t* dsInterpret_Filename_As_Segment_Id;
extern const wchar_t* dsReset_Segment_Id;
extern const wchar_t* dsEmit_All_Events_Before_Shutdown;
extern const wchar_t* dsProcessing_File;
extern const wchar_t* dsFile_Has_Not_Expected_Header;
extern const wchar_t* dsUnexpected_Error_While_Parsing;
extern const wchar_t* dsUnknown_Date_Time_Format;
extern const wchar_t* dsLine_No;
extern const wchar_t* dsError_In_Number_Format;
extern const wchar_t* dsInvalid_GUID;

extern const wchar_t *dsDevice_Feedback_Filter;
extern const wchar_t *dsDevice_Filter;

extern const wchar_t *dsGUI_Filter;

extern const char* dsSave_Image_To_File;
extern const char* dsSave_Image_Ext_Spec;
extern const char* dsSave_Viewport_To_File;
extern const char* dsSave_Viewport_Ext_Spec;
extern const char* dsDefault_Viewport_File_Name;
extern const char* dsReset_Zoom;

extern const char* dsDiagnosis_T1D;
extern const char* dsDiagnosis_T2D;
extern const char* dsDiagnosis_Gestational;

extern const char* dsSave_Image_Default_Filename_Graph;
extern const char* dsSave_Image_Default_Filename_Day;
extern const char* dsSave_Image_Default_Filename_Parkes;
extern const char* dsSave_Image_Default_Filename_Clark;
extern const char* dsSave_Image_Default_Filename_AGP;
extern const char* dsSave_Image_Default_Filename_ECDF;
extern const char* dsSave_Image_Default_Filename_Profile_Glucose;
extern const char* dsSave_Image_Default_Filename_Profile_Insulin;
extern const char* dsSave_Image_Default_Filename_Profile_Carbs;

//extern const wchar_t *dsCalculate_Past_New_Params;
//extern const wchar_t *dsRecalculate_With_Every_Params;
extern const wchar_t* dsRecalculate_Past_On_Params;
//extern const wchar_t* dsRecalculate_Past_On_Segment_Stop;
extern const wchar_t *dsUse_Just_Opened_Segments;

extern const wchar_t *dsCalculated_Signal;
extern const wchar_t* dsPrediction_Window;
extern const wchar_t* dsSolving_Parameters_Separator;
extern const wchar_t* dsSolve_Parameters;
extern const wchar_t* dsSolve_Using_All_Segments;
extern const wchar_t* dsMetric_Separator;
extern const wchar_t* dsMetric_Levels_Required_Hint;
extern const wchar_t* dsSolve_On_Level_Count;
extern const wchar_t* dsSolve_On_Calibration;
extern const wchar_t* dsSolve_On_Time_Segment_End;

extern const char *dsConfiguration;
extern const char *dsSelect_Just_One_Item;
extern const char *dsSimulation_Is_In_Progress;

extern const char *dsInformation;
extern const char *dsMain_Parameters;
extern const char *dsFilter_Executor_Failed_Review_Config_Errors;

extern const char* dsOK;
extern const char* dsCancel;
extern const char* dsApply;
extern const char* dsCommit;

extern const char* dsSubject;
extern const char* dsSegment;
extern const char* dsValue_Count;

extern const wchar_t* dsAvg_Abs;
extern const wchar_t* dsMax_Abs;
extern const wchar_t* dsPerc_Abs;
extern const wchar_t* dsThresh_Abs;
extern const wchar_t* dsLeal_2010;
extern const wchar_t* dsAIC;
extern const wchar_t* dsBessel_Std_Dev;
extern const wchar_t* dsBessel_Variance;
extern const wchar_t* dsCrosswalk;
extern const wchar_t* dsIntegral_CDF;
extern const wchar_t* dsAvg_Plus_Bessel_Std_Dev;
extern const wchar_t* dsRMSE;
extern const wchar_t* dsExpWtDiffPolar;
extern const wchar_t* dsAvg_Pow_StdDev_Metric;

extern const wchar_t* dsBlood;
extern const wchar_t* dsInterstitial;

extern const wchar_t* dsConstant_Signal;

extern const wchar_t* dsDiffusion_Model_v2;
extern const wchar_t* dsSteil_Rebrin;
extern const wchar_t* dsSteil_Rebrin_Diffusion_Prediction;
extern const wchar_t* dsDiffusion_Prediction;
extern const wchar_t* dsOref0_Basal_Insulin;
extern const wchar_t* dsOref0_Basal_Insulin_Orig;
extern const wchar_t* dsOref0_IOB_Model;
extern const wchar_t* dsOref0_COB_Model;
extern const wchar_t* dsOref0_Insulin_Activity_Bilinear;
extern const wchar_t* dsOref0_Insulin_Activity_Exponential;
extern const wchar_t* dsOref0_IOB_Bilinear;
extern const wchar_t* dsOref0_IOB_Exponential;
extern const wchar_t* dsOref0_COB_Bilinear;
extern const wchar_t* dsOref0_BG_Prediction;
extern const wchar_t* dsOref0_BG_IOB_Prediction;
extern const wchar_t* dsOref0_BG_COB_Prediction;
extern const wchar_t* dsOref0_BG_UAM_Prediction;
extern const wchar_t* dsOref0_BG_ZT_Prediction;
extern const wchar_t* dsOref0_BG_Prediction_Signal;
extern const wchar_t* dsConstant_Model;
extern const wchar_t* dsUVa_Padova_S2013;
extern const wchar_t* dsUVa_Padova_S2017;
extern const wchar_t* dsUVa_Padova_IG;
extern const wchar_t* dsUVa_Padova_BG;
extern const wchar_t* dsUVa_Padova_Delivered_Insulin;
extern const wchar_t* dsUVa_Padova_S2017_IG;
extern const wchar_t* dsUVa_Padova_S2017_BG;
extern const wchar_t* dsUVa_Padova_S2017_Delivered_Insulin;
extern const wchar_t* dsUVa_Padova_S2017_IOB;
extern const wchar_t* dsUVa_Padova_S2017_COB;

extern const wchar_t* dsGCT_Model_v1;
extern const wchar_t* dsGCT_Model_v1_IG;
extern const wchar_t* dsGCT_Model_v1_BG;
extern const wchar_t* dsGCT_Model_v1_Delivered_Insulin;
extern const wchar_t* dsGCT_Model_v1_IOB;
extern const wchar_t* dsGCT_Model_v1_COB;

extern const wchar_t* dsGCT_Model_v2;
extern const wchar_t* dsGCT_Model_v2_IG;
extern const wchar_t* dsGCT_Model_v2_BG;
extern const wchar_t* dsGCT_Model_v2_Delivered_Insulin;
extern const wchar_t* dsGCT_Model_v2_IOB;
extern const wchar_t* dsGCT_Model_v2_COB;

extern const wchar_t* dsPhysical_Activity_Detection_Model;
extern const wchar_t* dsPhysical_Activity_Detected_Signal;
extern const wchar_t* dsHeart_Rate_Resting;

extern const wchar_t* dsOref0_Solver;

extern const wchar_t* dsIOB_Model;
extern const wchar_t* dsCOB_Model;
extern const wchar_t* dsInsulin_Activity_Bilinear;
extern const wchar_t* dsInsulin_Activity_Exponential;
extern const wchar_t* dsIOB_Bilinear;
extern const wchar_t* dsIOB_Exponential;
extern const wchar_t* dsCOB_Bilinear;

extern const wchar_t* dsP;
extern const wchar_t* dsCg;
extern const wchar_t* dsC;
extern const wchar_t* dsDt;
extern const wchar_t* dsK;
extern const wchar_t* dsH;

extern const wchar_t* dsTau;
extern const wchar_t* dsAlpha;
extern const wchar_t* dsBeta;
extern const wchar_t* dsGamma;

extern const wchar_t* dsInv_G;

extern const wchar_t* dsConstantParam;

extern const wchar_t* dsRetrospectiveP;
extern const wchar_t* dsRetrospectiveCg;
extern const wchar_t* dsRetrospectiveC;
extern const wchar_t* dsRetrospectiveDt;

extern const wchar_t* dsPredictiveP;
extern const wchar_t* dsPredictiveCg;
extern const wchar_t* dsPredictiveC;
extern const wchar_t* dsPredictiveDt;

extern const wchar_t* dsInsulin_TwoTerm_Regulation;
extern const wchar_t* dsInsulin_PID_Regulation;
extern const wchar_t* dsBetaPID;
extern const wchar_t* dsBetaPID3;
extern const wchar_t* dsInsulin_TwoTerm_OnOff_Rate;
extern const wchar_t* dsInsulin_TwoTerm_OnNeturalOff_Rate;
extern const wchar_t* dsInsulin_TwoTerm_OnOff_Hysteresis_Rate;
extern const wchar_t* dsInsulin_PID_Regulation_Rate;
extern const wchar_t* dsInsulin_BetaPID_Rate;
extern const wchar_t* dsInsulin_BetaPID2_Rate;
extern const wchar_t* dsInsulin_BetaPID3_Rate;
extern const wchar_t* dsKp;
extern const wchar_t* dsKi;
extern const wchar_t* dsKd;
extern const wchar_t* dsBasal_Insulin_Rate;
extern const wchar_t* dsBolus_Calculator;

extern const wchar_t* dsCalculated_Bolus_Insulin;
extern const wchar_t* dsBolus_Calculator;
extern const wchar_t* dsConst_Basal_Insulin;
extern const wchar_t* dsConst_Basal_Low_Suspend_Insulin;

extern const wchar_t* dsISF;
extern const wchar_t* dsCSR;
extern const wchar_t* dsInsulinPeak;
extern const wchar_t* dsDIA;
extern const wchar_t* dsCarbPeak;
extern const wchar_t* dsCarbDA;

extern const wchar_t* dsNewUOA;
extern const wchar_t* dsMetaDE;
extern const wchar_t* dsMT_MetaDE;
extern const wchar_t* dsHalton_MetaDE;
extern const wchar_t* dsRnd_MetaDE;
extern const wchar_t* dsBOBYQA;
extern const wchar_t* dsPathfinder_Spiral;
extern const wchar_t* dsPathfinder_Landscape;

extern const wchar_t* dsPathfinder_Fast;
extern const wchar_t* dsSequential_Brute_Force_Scan;
extern const wchar_t* dsSequential_Convex_Scan;
extern const wchar_t* dsPSO_Halton;
extern const wchar_t* dsPSO;
extern const wchar_t* dsSADE;
extern const wchar_t* dsDE1220;
extern const wchar_t* dsABC;
extern const wchar_t* dsCMAES;
extern const wchar_t* dsXNES;
extern const wchar_t* dsGPSO;
extern const wchar_t* dsIHS;
extern const wchar_t* dsSimplex;
extern const wchar_t* dsSubplex;
extern const wchar_t* dsPraxis;

extern const char* dsMax_Generations;
extern const char* dsPopulation_Size;


extern const wchar_t *dsLine_Approx;
extern const wchar_t *dsAkima;
extern const wchar_t* dsAvgExp;

extern const char *dsDrawing_Tab_Graph;
extern const char *dsDrawing_Tab_Day;
extern const char *dsDrawing_Tab_Clark;
extern const char *dsDrawing_Tab_Parkes;
extern const char *dsDrawing_Tab_AGP;
extern const char *dsDrawing_Tab_ECDF;
extern const char *dsDrawing_Tab_Profile_Glucose;
extern const char *dsDrawing_Tab_Profile_Carbs;
extern const char *dsDrawing_Tab_Profile_Insulin;

extern const char *dsLower_Bounds;
extern const char *dsDefault_Parameters;
extern const char *dsUpper_Bounds;

extern const char *dsReset_Bounds;

extern const char *dsLog_Table_View;
extern const char *dsLog_Raw_View;
extern const char* dsConfig_Errors;

extern const wchar_t *dsSignal_Measured_BG;
extern const wchar_t *dsSignal_Measured_IG;
extern const wchar_t *dsSignal_Measured_ISIG;
extern const wchar_t *dsSignal_Measured_Calibration;
extern const wchar_t *dsSignal_Delivered_Insulin_Bolus;
extern const wchar_t *dsSignal_Delivered_Insulin_Total;
extern const wchar_t* dsSignal_Requested_Insulin_Bolus;
extern const wchar_t *dsSignal_Delivered_Insulin_Basal_Rate;
extern const wchar_t *dsSignal_Requested_Insulin_Basal_Rate;
extern const wchar_t *dsSignal_Delivered_Insulin_Intradermal_Rate;
extern const wchar_t *dsSignal_Requested_Insulin_Intradermal_Rate;
extern const wchar_t *dsSignal_Delivered_Insulin_Inhaled;
extern const wchar_t *dsSignal_Measured_Insulin_Activity;
extern const wchar_t *dsSignal_Measured_IOB;
extern const wchar_t *dsSignal_Measured_COB;
extern const wchar_t *dsSignal_Measured_Carb_Intake;
extern const wchar_t *dsSignal_Measured_Health_Physical_Activity;
extern const wchar_t* dsSignal_Measured_Insulin_Sensitivity;
extern const wchar_t* dsSignal_Measured_Carb_Ratio;
extern const wchar_t *dsSignal_Suffix_Measured;
extern const wchar_t *dsSignal_Suffix_Calculated;
extern const wchar_t *dsSignal_Unknown;
extern const wchar_t *dsSignal_Prefix_Virtual;
extern const wchar_t* dsSignal_Null;
extern const wchar_t* dsInvalid_ID;

extern const wchar_t* dsSignal_GUI_Name_All;
extern const wchar_t* dsSignal_GUI_Name_BG;
extern const wchar_t* dsSignal_GUI_Name_IG;
extern const wchar_t* dsSignal_GUI_Name_ISIG;
extern const wchar_t* dsSignal_GUI_Name_Calibration;
extern const wchar_t* dsSignal_GUI_Name_Delivered_Insulin_Bolus;
extern const wchar_t* dsSignal_GUI_Name_Delivered_Insulin_Basal;
extern const wchar_t* dsSignal_GUI_Name_Requested_Basal_Insulin_Rate;
extern const wchar_t* dsSignal_GUI_Name_Insulin_Activity;
extern const wchar_t* dsSignal_GUI_Name_Basal_Insulin;
extern const wchar_t* dsSignal_GUI_Name_IOB;
extern const wchar_t* dsSignal_GUI_Name_COB;
extern const wchar_t* dsSignal_GUI_Name_Carbs;
extern const wchar_t* dsSignal_GUI_Name_Carb_Rescue;
extern const wchar_t* dsSignal_GUI_Name_Physical_Activity;

extern const wchar_t* dsSignal_GUI_Name_Skin_Temperature;
extern const wchar_t* dsSignal_GUI_Name_Air_Temperature;
extern const wchar_t* dsSignal_GUI_Name_Heartbeat;
extern const wchar_t* dsSignal_GUI_Name_Electrodermal_Activity;
extern const wchar_t* dsSignal_GUI_Name_Steps;
extern const wchar_t* dsSignal_GUI_Name_Sleep_Quality;
extern const wchar_t* dsSignal_GUI_Name_Acceleration;
extern const wchar_t* dsSignal_GUI_Name_Movement_Speed;
extern const wchar_t* dsSignal_GUI_Name_Error_Metric;
extern const wchar_t *dsSignal_GUI_Name_Insulin_Sensitivity;
extern const wchar_t *dsSignal_GUI_Name_Carb_Ratio;

extern const wchar_t *dsSignal_GUI_Name_Unknown;

extern const wchar_t *dsSolver_Progress_Box_Title;

extern const wchar_t *dsCould_Not_Init_Network;
extern const wchar_t *dsInvalid_Network_Port;
extern const wchar_t *dsInvalid_Model_GUID;
extern const wchar_t *dsCould_Not_Allocate_Network_Pool_Slot;

extern const wchar_t* dsInvalid_Metric_GUID;

extern const wchar_t *dsError_Column_Average;
extern const wchar_t *dsError_Column_StdDev;
extern const wchar_t* dsError_Column_ExcKurtosis;
extern const wchar_t* dsError_Column_Skewness;
extern const wchar_t *dsError_Column_Count;
extern const wchar_t *dsError_Column_Sum;
extern const wchar_t *dsError_Column_Minimum;
extern const wchar_t *dsError_Column_First_Quantile;
extern const wchar_t *dsError_Column_Median;
extern const wchar_t *dsError_Column_Third_Quantile;
extern const wchar_t *dsError_Column_95_Quantile;
extern const wchar_t *dsError_Column_99_Quantile;
extern const wchar_t *dsError_Column_Maximum;
extern const wchar_t *dsError_Column_Range_5pct;
extern const wchar_t *dsError_Column_Range_10pct;
extern const wchar_t *dsError_Column_Range_25pct;
extern const wchar_t *dsError_Column_Range_50pct;

extern const wchar_t* rsInsert_New_Measured_Value;

extern const wchar_t* rsInsert_Params_Base;
extern const wchar_t* rsInsert_Params_Segmentid_Column;
extern const wchar_t* rsInsert_Params_Values_Stmt;

extern const wchar_t* rsInsert_Params;

extern const wchar_t* rsCreated_Segment_Identifier_Base;
extern const wchar_t* rsInsert_New_Time_Segment;
extern const wchar_t* rsSelect_Time_Segment_Id_By_Name;
extern const wchar_t* rsRename_Time_Segment;
extern const wchar_t* rsDelete_Parameters_Of_Segment_Base;
extern const wchar_t* rsDelete_Parameters_Of_Segment_Stmt;

extern const wchar_t* rsLegacy_Db_Insert_Params_Base;
extern const wchar_t* rsLegacy_Db_Insert_Params_Segmentid_Column;
extern const wchar_t* rsLegacy_Db_Insert_Params_Values_Stmt;
extern const wchar_t* rsLegacy_Db_Select_Params_Base;
extern const wchar_t* rsLegacy_Db_Select_Params_From;
extern const wchar_t* rsLegacy_Db_Select_Params_Condition;
extern const wchar_t* rsLegacy_Db_Insert_New_Measured_Value;
extern const wchar_t* rsLegacy_Db_Insert_New_Time_Segment;
extern const wchar_t* rsLegacy_Db_Select_Time_Segment_Id_By_Name;
extern const wchar_t* rsLegacy_Db_Rename_Time_Segment;
extern const wchar_t* rsLegacy_Db_Delete_Parameters_Of_Segment_Stmt;
extern const wchar_t* rsLegacy_Db_Select_Subjects_And_Segments_For_Db_Reader_Filter;
extern const wchar_t* rsLegacy_Db_Select_Timesegment_Values_Filter;
extern const wchar_t* rsLegacy_Db_Found_New_Segment;
extern const wchar_t* rsLegacy_Db_Select_Founded_Segment;
extern const wchar_t* rsLegacy_Db_Update_Founded_Segment;
extern const wchar_t* rsLegacy_Db_Found_New_Subject;
extern const wchar_t* rsLegacy_Db_Update_Founded_Subject;

extern const wchar_t* rsT1DMS_Receiver_Filter;
extern const wchar_t* rsT1DMS_Sender_Filter;

extern const wchar_t* rsInsulin_Regulation;
extern const wchar_t* rsInsulin_PID_Regulation;
extern const wchar_t* rsBetaPID;
extern const wchar_t* rsBetaPID3;
extern const wchar_t* rsKp;
extern const wchar_t* rsKi;
extern const wchar_t* rsKd;
extern const wchar_t* rsBasal_Insulin_Rate;

extern const wchar_t* rsBolus_Calculator;
extern const wchar_t* rsConst_Basal_Insulin;

extern const wchar_t* dsLGS_Basal_Insulin_Model;
extern const wchar_t* dsSuspend_Threshold;
extern const wchar_t* dsLGS_Suspend_Duration;
extern const wchar_t* dsInsulin_LGS_Rate;

extern const wchar_t* dsConst_ISF;
extern const wchar_t* dsConst_ISF_Model;
extern const wchar_t* dsConst_CR;
extern const wchar_t* dsConst_CR_Model;

extern const wchar_t* dsPattern_Prediction_Model;
extern const wchar_t* dsPattern_Prediction_Signal;
extern const wchar_t* dsParameters_File;
extern const wchar_t* dsDo_Not_Update_Parameters_File;
extern const wchar_t* dsDo_Not_Learn;
extern const wchar_t* dsUse_Config_parameters;
extern const wchar_t* dsSanitize_Unused_Patterns;
extern const wchar_t* dsSliding_Window_Length;
extern const wchar_t* dsLearned_Data_Filename_Prefix;
extern const wchar_t* dsExperimental;

extern const wchar_t* dsWeighted_Moving_Average;
extern const wchar_t* dsWeight_0;
extern const wchar_t* dsWeight_5;
extern const wchar_t* dsWeight_10;
extern const wchar_t* dsWeight_15;
extern const wchar_t* dsWeight_20;
extern const wchar_t* dsWeight_25;
extern const wchar_t* dsWeight_30;
extern const wchar_t* dsWeight_35;
extern const wchar_t* dsWeight_40;
extern const wchar_t* dsWeight_45;
extern const wchar_t* dsWeight_50;
extern const wchar_t* dsWeight_55;

extern const wchar_t* dsExtModel_Unknown_Opcode;
extern const wchar_t* dsExtModel_Invalid_Opcode_Direction;
extern const wchar_t* dsExtModel_Invalid_State_Handshake_Reply;
extern const wchar_t* dsExtModel_Remote_Fatal_Error;
extern const wchar_t* dsExtModel_Protocol_Version_Mismatch;
extern const wchar_t* dsExtModel_Unknown_Handshake_Error;
extern const wchar_t* dsExtModel_Unknown_Model_Requested;
extern const wchar_t* dsExtModel_Invalid_State_Data;
extern const wchar_t* dsExtModel_Invalid_State_Teardown_Request;
extern const wchar_t* dsExtModel_Invalid_State_Teardown_Reply;
extern const wchar_t* dsExtModel_Could_Not_Connect;
extern const wchar_t* dsExtModel_Invalid_Remote_Protocol_Magic;
extern const wchar_t* dsExtModel_Invalid_Remote_Protocol_Packet_Length;
extern const wchar_t* dsExtModel_Invalid_Packet_State;
extern const wchar_t* dsExtModel_Local_Network_Subsystem_Error;

// ---- drawing-related constants

extern const wchar_t* dsDrawingLocaleTitle;
extern const wchar_t* dsDrawingLocaleTitleAgp;
extern const wchar_t* dsDrawingLocaleTitleClark;
extern const wchar_t* dsDrawingLocaleTitleParkes;
extern const wchar_t* dsDrawingLocaleTitleECDF;
extern const wchar_t* dsDrawingLocaleTitleProfileGlucose;
extern const wchar_t* dsDrawingLocaleTitleDay;
extern const wchar_t* dsDrawingLocaleSubtitle;
extern const wchar_t* dsDrawingLocaleDiabetes1;
extern const wchar_t* dsDrawingLocaleDiabetes2;
extern const wchar_t* dsDrawingLocaleTime;
extern const wchar_t* dsDrawingLocaleTimeDay;
extern const wchar_t* dsDrawingLocaleConcentration;
extern const wchar_t* dsDrawingLocaleHypoglycemy;
extern const wchar_t* dsDrawingLocaleHyperglycemy;
extern const wchar_t* dsDrawingLocaleBlood;
extern const wchar_t* dsDrawingLocaleBloodCalibration;
extern const wchar_t* dsDrawingLocaleIst;
extern const wchar_t* dsDrawingLocaleResults;
extern const wchar_t* dsDrawingLocaleDiff2;
extern const wchar_t* dsDrawingLocaleDiff3;
extern const wchar_t* dsDrawingLocaleQuantile;
extern const wchar_t* dsDrawingLocaleRelative;
extern const wchar_t* dsDrawingLocaleAbsolute;
extern const wchar_t* dsDrawingLocaleAverage;
extern const wchar_t* dsDrawingLocaleType;
extern const wchar_t* dsDrawingLocaleError;
extern const wchar_t* dsDrawingLocaleDescription;
extern const wchar_t* dsDrawingLocaleColor;
extern const wchar_t* dsDrawingLocaleCounted;
extern const wchar_t* dsDrawingLocaleMeasured;
extern const wchar_t* dsDrawingLocaleAxisX;
extern const wchar_t* dsDrawingLocaleAxisY;
extern const wchar_t* dsDrawingLocaleSvgDatetimeTitle;
extern const wchar_t* dsDrawingLocaleSvgIstTitle;
extern const wchar_t* dsDrawingLocaleSvgBloodTitle;
extern const wchar_t* dsDrawingLocaleSvgBloodCalibrationTitle;
extern const wchar_t* dsDrawingLocaleSvgInsulinTitle;
extern const wchar_t* dsDrawingLocaleSvgCarbohydratesTitle;
extern const wchar_t* dsDrawingLocaleSvgISIGTitle;
extern const wchar_t* dsDrawingLocaleSvgDiff2Title;
extern const wchar_t* dsDrawingLocaleSvgDiff3Title;
extern const wchar_t* dsDrawingLocaleRelativeError;
extern const wchar_t* dsDrawingLocaleCummulativeProbability;
extern const wchar_t* dsDrawingLocaleElevatedGlucose;

//xxxxxxxxxxxxxxxx

extern const wchar_t *dsRecalculate_With_Every_Params;
extern const wchar_t *dsUse_Just_Opened_Segments;
extern const wchar_t *dsHold_During_Solve;
extern const wchar_t *dsHold_During_Solve_Tooltip;

extern const char *dsTime_Segments_Panel_Title;
extern const char *dsSignals_Panel_Title;
extern const char *dsRedraw_Button_Title;
extern const char *dsTime_Segments_Panel_Segment_Name;
extern const char *dsSelect_All_Segments;
extern const char *dsSelect_No_Segments;

extern const char *dsAnonymous_Subject;
extern const char *dsCreate_New_Subject;
extern const char *dsExisting_Subject;

// filter configuration tooltips

extern const wchar_t *dsDb_Host_Tooltip;
extern const wchar_t *dsDb_Port_Tooltip;
extern const wchar_t *dsDb_Provider_Tooltip;
extern const wchar_t *dsDb_Name_Tooltip;
extern const wchar_t *dsDb_Username_Tooltip;
extern const wchar_t *dsDb_Password_Tooltip;
extern const wchar_t *dsShutdown_After_Last_Tooltip;
extern const wchar_t *dsGenerate_Primary_Keys_Tooltip;
extern const wchar_t *dsStore_Data_Tooltip;
extern const wchar_t *dsStore_Parameters_Tooltip;
extern const wchar_t *dsInput_Values_File_Tooltip;
extern const wchar_t *dsInput_Segment_Spacing_Tooltip;
extern const wchar_t *dsHold_Values_Delay_Tooltip;
extern const wchar_t *dsMinimum_Segment_Levels_Tooltip;
extern const wchar_t *dsRequire_IG_BG_Tooltip;

extern const wchar_t *dsCanvas_Width_Tooltip;
extern const wchar_t *dsCanvas_Height_Tooltip;
extern const wchar_t *dsFilename_Graph_Tooltip;
extern const wchar_t *dsFilename_Day_Tooltip;
extern const wchar_t *dsFilename_AGP_Tooltip;
extern const wchar_t *dsFilename_Parkes_Tooltip;
extern const wchar_t *dsFilename_Clark_Tooltip;
extern const wchar_t *dsFilename_ECDF_Tooltip;

extern const wchar_t *dsLog_File_Output_Tooltip;
extern const wchar_t *dsLog_File_Input_Tooltip;

extern const wchar_t *dsSelected_Model_Tooltip;
extern const wchar_t *dsSelected_Signal_Tooltip;
extern const wchar_t *dsPrediction_Window_Tooltip;
extern const wchar_t *dsMapping_Source_Signal_Tooltip;
extern const wchar_t *dsMapping_Destination_Signal_Tooltip;
extern const wchar_t* dsDestination_Signal_Cannot_Be_Invalid;
extern const wchar_t *dsMasked_Signal_Tooltip;
extern const wchar_t *dsSignal_Values_Mask_Tooltip;

extern const wchar_t *dsSelected_Metric_Tooltip;
extern const wchar_t *dsSelected_Solver_Tooltip;
extern const wchar_t *dsUse_Relative_Error_Tooltip;
extern const wchar_t *dsUse_Squared_Diff_Tooltip;
extern const wchar_t *dsUse_Prefer_More_Levels_Tooltip;
extern const wchar_t *dsMetric_Threshold_Tooltip;
extern const wchar_t *dsUse_Measured_Levels_Tooltip;
extern const wchar_t *dsRecalculate_On_Levels_Count_Tooltip;
extern const wchar_t *dsRecalculate_On_Segment_End_Tooltip;
extern const wchar_t *dsRecalculate_On_Calibration_Tooltip;
extern const wchar_t *dsRecalculate_On_Parameters_Tooltip;
extern const wchar_t *dsUse_Opened_Segments_Only_Tooltip;

extern const wchar_t *dsParameter_Configuration_Failed_RC;

extern const wchar_t* dsSignal_Error;
extern const wchar_t* dsFast_Signal_Error;
extern const wchar_t* dsReference_Signal;
extern const wchar_t* dsError_Signal;
extern const wchar_t* dsError;
extern const wchar_t* dsDescription;
extern const wchar_t* dsAbsolute;
extern const wchar_t* dsRelative;
extern const wchar_t* dsUnsupported_Metric_Configuration;

extern const wchar_t* dsDiabetes_Grid_Filter;
extern const wchar_t* dsClarke_Error_Grid;
extern const wchar_t* dsParkes_Error_Grid_Type_1;
extern const wchar_t* dsParkes_Error_Grid_Type_2;


extern const wchar_t* dsBergman_Minimal_Model;
extern const wchar_t* dsBergman_p1;
extern const wchar_t* dsBergman_p2;
extern const wchar_t* dsBergman_p3;
extern const wchar_t* dsBergman_p4;
extern const wchar_t* dsBergman_k12;
extern const wchar_t* dsBergman_k21;
extern const wchar_t* dsBergman_Vi;
extern const wchar_t* dsBergman_BW;
extern const wchar_t* dsBergman_VgDist;
extern const wchar_t* dsBergman_d1rate;
extern const wchar_t* dsBergman_d2rate;
extern const wchar_t* dsBergman_irate;
extern const wchar_t* dsBergman_Qb;
extern const wchar_t* dsBergman_Ib;
extern const wchar_t* dsBergman_Q10;
extern const wchar_t* dsBergman_Q20;
extern const wchar_t* dsBergman_X0;
extern const wchar_t* dsBergman_I0;
extern const wchar_t* dsBergman_D10;
extern const wchar_t* dsBergman_D20;
extern const wchar_t* dsBergman_Isc0;
extern const wchar_t* dsBergman_Gsc0;
extern const wchar_t* dsBergman_BasalRate0;
extern const wchar_t* dsBergman_diff2_p;
extern const wchar_t* dsBergman_diff2_cg;
extern const wchar_t* dsBergman_diff2_c; 
extern const wchar_t* dsBergman_diff2_dt;
extern const wchar_t* dsBergman_diff2_k;
extern const wchar_t* dsBergman_diff2_h;
extern const wchar_t* dsBergman_Ag;

extern const wchar_t *dsBergman_Signal_BG;
extern const wchar_t *dsBergman_Signal_IG;
extern const wchar_t *dsBergman_Signal_IOB;
extern const wchar_t *dsBergman_Signal_COB;
extern const wchar_t *dsBergman_Signal_Basal_Insulin;
extern const wchar_t *dsBergman_Signal_Insulin_Activity;

extern const wchar_t* dsSignal_Generator;
extern const wchar_t* dsSignal_Generator_Network;
extern const wchar_t* dsParameters;
extern const wchar_t* dsFeedback_Name;
extern const wchar_t* dsSynchronize_to_Signal;
extern const wchar_t* dsSynchronization_Signal;
extern const wchar_t* dsStepping;
extern const wchar_t* dsMaximum_Time;
extern const wchar_t* dsEcho_Default_Parameters_As_Event;
extern const wchar_t* dsIndividualize_Segment_Specific_Parameters;
extern const wchar_t* dsAsync_Stepping_Not_Positive;
extern const wchar_t* dsCannot_Get_Model_Descriptor_By_Signal_Id;
extern const wchar_t* dsCannot_Get_Model_Descriptor;
extern const wchar_t* dsError_Initializing_Discrete_Model;
extern const wchar_t* dsAsync_Sig_Gen_Req_Seg_Id;
extern const wchar_t* dsFailed_To_Configure_Model;

extern const wchar_t* dsImpulse_Response_Filter;
extern const wchar_t* dsSignal_Id;
extern const wchar_t* dsResponse_Window;

extern const wchar_t* dsRemote_Host;
extern const wchar_t* dsRemote_Port;
extern const wchar_t* dsRemote_Model_Id;
extern const wchar_t* dsRemote_Subject_Name;

extern const wchar_t* dsParam_K;
extern const wchar_t* dsKp;
extern const wchar_t* dsKi;
extern const wchar_t* dsKd;
extern const wchar_t* dsBasal_Insulin_Rate;
extern const wchar_t* dsKiDecay;

extern const wchar_t* dsSignal_Feedback;
extern const wchar_t* dsRemove_From_Source;

extern const wchar_t* dsSignal_Stats;
extern const wchar_t* dsOutput_CSV_File;
extern const wchar_t* dsLevel;
extern const wchar_t* dsPeriod;

extern const wchar_t* dsInvalid_Section_Name;
extern const wchar_t* dsCannot_Resolve_Filter_Descriptor;
extern const wchar_t* dsMalformed_Filter_Parameter_Value;
extern const wchar_t* dsVar_Not_Set_Filter_Parameter_Value;
extern const wchar_t* dsFilter_Parameter_Not_Configured;

extern const wchar_t* dsParameters_to_optimize_not_found;
extern const wchar_t* dsParameters_to_optimize_could_not_be_read_bounds_including;
extern const wchar_t* dsFailed_to_clone_configuration;
extern const wchar_t* dsSolver_Failed;
extern const wchar_t* dsFailed_to_write_parameters;
extern const wchar_t* dsFailed_to_execute_first_filters;
extern const wchar_t* dsCannot_read_configuration;
extern const wchar_t* dsCannot_read_filter_id;
extern const wchar_t* dsFailed_to_configure_filter;
extern const wchar_t* dsLast_RC;
extern const wchar_t* dsFeedback_sender_not_connected;
extern const wchar_t* dsFilter_configuration_param_value_error;
extern const wchar_t* dsStored_Parameters_Corrupted_Not_Loaded;

extern const wchar_t* dsDefault_Filters_Path;
extern const wchar_t* dsLoaded_Filters;
extern const wchar_t* dsNone;

extern const wchar_t* dsIcarus_v1_AI_Boluses;
extern const wchar_t* dsBolus_Offset;
extern const wchar_t* dsBolus_Amount;

extern const wchar_t* dsIcarus_Basal_And_Bolus;
extern const wchar_t* dsCarb_To_Insulin_Ratio;

extern const wchar_t* dsBasal_2_Bolus;
extern const wchar_t* dsMinimum_Volume;
extern const wchar_t* dsPPeriod;


//--------------------------------- do not translate any of the rs-prefixed texts --

extern const char* rsAbout_Text;

extern const wchar_t *rsDb_Reader;
extern const wchar_t *rsDb_Host;
extern const wchar_t *rsDb_Port;
extern const wchar_t *rsDb_Provider;
extern const wchar_t *rsDb_Name;
extern const wchar_t *rsDb_User_Name;
extern const wchar_t *rsDb_Password;
extern const wchar_t *rsTime_Segment_ID;

extern const wchar_t *rsDiffusion_v2_Table;
extern const wchar_t *rsDiffusion_v3_Table;
extern const wchar_t *rsSteil_Rebrin_Table;
extern const wchar_t *rsSteil_Rebrin_Diffusion_Prediction_Table;
extern const wchar_t* rsDiffusion_Prediction_Table;
extern const wchar_t* rsOref0_Basal_Insulin;
extern const wchar_t* rsOref0_IOB;
extern const wchar_t* rsOref0_COB;
extern const wchar_t* rsOref0_BG_Prediction;
extern const wchar_t* rsOref0_BG_IOB_Prediction;
extern const wchar_t* rsOref0_BG_COB_Prediction;
extern const wchar_t* rsOref0_BG_UAM_Prediction;
extern const wchar_t* rsOref0_BG_ZT_Prediction;
extern const wchar_t* rsConstant_Model;

extern const wchar_t* rsPhysical_Activity_Detection_Model;
extern const wchar_t* rsHeart_Rate_Resting;

extern const wchar_t* rsP_Column;
extern const wchar_t* rsCg_Column;
extern const wchar_t* rsC_Column;
extern const wchar_t* rsDt_Column;
extern const wchar_t* rsK_Column;
extern const wchar_t* rsH_Column;

extern const wchar_t* rsTau_Column;
extern const wchar_t* rsAlpha_Column;
extern const wchar_t* rsBeta_Column;
extern const wchar_t* rsGamma_Column;

extern const wchar_t* rsInv_G_Column;

extern const wchar_t* rsRetrospectiveP;
extern const wchar_t* rsRetrospectiveCg;
extern const wchar_t* rsRetrospectiveC;
extern const wchar_t* rsRetrospectiveDt;

extern const wchar_t* rsPredictiveP;
extern const wchar_t* rsPredictiveCg;
extern const wchar_t* rsPredictiveC;
extern const wchar_t* rsPredictiveDt;

extern const wchar_t* rsISF;
extern const wchar_t* rsCSR;
extern const wchar_t* rsInsulinPeak;
extern const wchar_t* rsDIA;
extern const wchar_t* rsCarbPeak;
extern const wchar_t* rsCarbDA;

extern const wchar_t *rsNet_Host;
extern const wchar_t *rsNet_Port;
extern const wchar_t *rsNet_RecvSide;

extern const wchar_t *rsAdditional_Rules;
extern const wchar_t *rsInput_Values_File;
extern const wchar_t *rsMaximum_IG_Interval;

extern const wchar_t *rsHold_Values_Delay;

extern const wchar_t *rsSignal_Source_Id;
extern const wchar_t *rsSignal_Destination_Id;
extern const wchar_t* rsRemove_From_Source;
extern const wchar_t* rsCondition;
extern const wchar_t* rsCollect_Statistics;

extern const wchar_t* rsSignal_Id;
extern const wchar_t* rsResponse_Window;

extern const wchar_t *rsSignal_Masked_Id;
extern const wchar_t *rsSignal_Value_Bitmask;

extern const wchar_t *rsGen_IG_Offset;
extern const wchar_t *rsGen_IG_Amplitude;
extern const wchar_t *rsGen_IG_Sin_Period;
extern const wchar_t *rsGen_IG_Sampling_Period;
extern const wchar_t *rsGen_BG_Level_Offset;
extern const wchar_t *rsGen_BG_Amplitude;
extern const wchar_t *rsGen_BG_Cos_Period;
extern const wchar_t *rsGen_BG_Sampling_Period;
extern const wchar_t *rsGen_Total_Time;

extern const wchar_t *rsParameters_Reset;
extern const wchar_t *rsParameters_Reset_Request;
extern const wchar_t *rsSegment_Recalculate_Complete;

extern const wchar_t *rsSelected_Model;
extern const wchar_t *rsSelected_Metric;
extern const wchar_t *rsSelected_Solver;
extern const wchar_t *rsSelected_Signal;
extern const wchar_t *rsSelected_Model_Bounds;
extern const wchar_t *rsUse_Relative_Error;
extern const wchar_t *rsUse_Squared_Diff;
extern const wchar_t *rsUse_Prefer_More_Levels;
extern const wchar_t *rsMetric_Threshold;
extern const wchar_t *rsMetric_Levels_Required;
extern const wchar_t *rsUse_Measured_Levels;
extern const wchar_t* rsEmit_metric_as_signal;
extern const wchar_t* rsEmit_last_value_only;
extern const wchar_t* rsDiscard_Repeating_Level;

extern const wchar_t *rsRecalculate_On_Levels_Count;
extern const wchar_t *rsRecalculate_On_Segment_End;
extern const wchar_t *rsRecalculate_On_Calibration;

extern const wchar_t *rsLog_Output_File;
extern const wchar_t* rsLog_Segments_Individually;
extern const wchar_t* rsReduced_Log;
extern const wchar_t* rsSecond_Threshold;
extern const wchar_t *rsEmit_Shutdown_Msg;
extern const wchar_t* rsInterpret_Filename_As_Segment_Id;
extern const wchar_t* rsReset_Segment_Id;
extern const wchar_t* rsEmit_All_Events_Before_Shutdown;

extern const wchar_t *rsDrawing_Filter_Period;
extern const wchar_t *rsDiagnosis_Is_Type2;
extern const wchar_t *rsDrawing_Filter_Canvas_Width;
extern const wchar_t *rsDrawing_Filter_Canvas_Height;
extern const wchar_t *rsDrawing_Filter_Filename_Graph;
extern const wchar_t *rsDrawing_Filter_Filename_Day;
extern const wchar_t *rsDrawing_Filter_Filename_AGP;
extern const wchar_t *rsDrawing_Filter_Filename_Parkes;
extern const wchar_t *rsDrawing_Filter_Filename_Clark;
extern const wchar_t *rsDrawing_Filter_Filename_ECDF;

extern const wchar_t* rsFile_Path;

extern const wchar_t *rsCallback_Log_Message;
extern const wchar_t *rsCallback_Drawing_Graph;
extern const wchar_t *rsCallback_Drawing_Day;
extern const wchar_t *rsCallback_Drawing_Clark;
extern const wchar_t *rsCallback_Drawing_Parkes;
extern const wchar_t *rsCallback_Drawing_Parkes_Type2;
extern const wchar_t *rsCallback_Drawing_AGP;

extern const wchar_t *rsInfo_Redraw_Complete;
extern const wchar_t *rsInfo_Solver_Progress;
extern const wchar_t *rsInfo_Solver_Failed;
extern const wchar_t *rsInfo_Solver_Completed_But_No_Improvement;
extern const wchar_t *rsInfo_Error_Metrics_Ready;
extern const wchar_t *rsInfo_Shut_Down_Marker;

extern const wchar_t *rsConfig_File_Name;
extern const wchar_t *rsFilter_Section_Prefix;
extern const wchar_t rsFilter_Section_Separator;
extern const wchar_t *rsIni_Comment_Prefix;

extern const wchar_t* rsSolversDir;

extern const char* rsFilter_Get_SVG_AGP;
extern const char* rsFilter_Get_SVG_Clark;
extern const char* rsFilter_Get_SVG_Day;
extern const char* rsFilter_Get_SVG_Graph;
extern const char* rsFilter_Get_SVG_Parkes;
extern const char* rsFilter_Get_SVG_Parkes_Type2;

extern const char* rsFilter_Get_Errors;

extern const wchar_t* rsSelect_Subjects_And_Segments_For_Db_Reader_Filter;
extern const wchar_t* rsSelect_Subjects;
extern const wchar_t* rsSelect_Timesegment_Values_Filter;
extern const wchar_t* rsSelect_Params_Filter;


// ---- drawing-related constants

extern const wchar_t* rsDrawingLocaleTitle;
extern const wchar_t* rsDrawingLocaleTitleDay;
extern const wchar_t* rsDrawingLocaleSubtitle;
extern const wchar_t* rsDrawingLocaleDiabetes1;
extern const wchar_t* rsDrawingLocaleDiabetes2;
extern const wchar_t* rsDrawingLocaleTime;
extern const wchar_t* rsDrawingLocaleTimeDay;
extern const wchar_t* rsDrawingLocaleConcentration;
extern const wchar_t* rsDrawingLocaleHypoglycemy;
extern const wchar_t* rsDrawingLocaleHyperglycemy;
extern const wchar_t* rsDrawingLocaleBlood;
extern const wchar_t* rsDrawingLocaleBloodCalibration;
extern const wchar_t* rsDrawingLocaleIst;
extern const wchar_t* rsDrawingLocaleResults;
extern const wchar_t* rsDrawingLocaleDiff2;
extern const wchar_t* rsDrawingLocaleDiff3;
extern const wchar_t* rsDrawingLocaleQuantile;
extern const wchar_t* rsDrawingLocaleRelative;
extern const wchar_t* rsDrawingLocaleAbsolute;
extern const wchar_t* rsDrawingLocaleAverage;
extern const wchar_t* rsDrawingLocaleType;
extern const wchar_t* rsDrawingLocaleError;
extern const wchar_t* rsDrawingLocaleDescription;
extern const wchar_t* rsDrawingLocaleColor;
extern const wchar_t* rsDrawingLocaleCounted;
extern const wchar_t* rsDrawingLocaleMeasured;
extern const wchar_t* rsDrawingLocaleAxisX;
extern const wchar_t* rsDrawingLocaleAxisY;
extern const wchar_t* rsDrawingLocaleSvgDatetimeTitle;
extern const wchar_t* rsDrawingLocaleSvgIstTitle;
extern const wchar_t* rsDrawingLocaleSvgBloodTitle;
extern const wchar_t* rsDrawingLocaleSvgBloodCalibrationTitle;
extern const wchar_t* rsDrawingLocaleSvgInsulinTitle;
extern const wchar_t* rsDrawingLocaleSvgCarbohydratesTitle;
extern const wchar_t* rsDrawingLocaleSvgISIGTitle;
extern const wchar_t* rsDrawingLocaleSvgDiff2Title;
extern const wchar_t* rsDrawingLocaleSvgDiff3Title;
extern const wchar_t* rsDrawingLocaleRelativeError;
extern const wchar_t* rsDrawingLocaleCummulativeProbability;
extern const wchar_t* rsDrawingLocaleElevatedGlucose;

extern const wchar_t* rsCannot_Get_Parameters;
extern const wchar_t* rsLog_Date_Time_Format;

extern const wchar_t* rsLog_CSV_Separator;

extern const wchar_t* rsConstantParam;

extern const char* rsRattime_Edit_Mask;
extern const wchar_t *rsShutdown_After_Last;
extern const wchar_t *rsMinimum_Required_IGs;
extern const wchar_t *rsRequire_BG;

extern const wchar_t *rsGenerate_Primary_Keys;
extern const wchar_t *rsStore_Data;
extern const wchar_t *rsStore_Parameters;
extern const wchar_t *rsSubject_Id;

extern const wchar_t* rsReserved_Segment_Name;
extern const wchar_t* rsFound_New_Segment;
extern const wchar_t* rsSelect_Founded_Segment;
extern const wchar_t* rsUpdate_Founded_Segment;

extern const wchar_t* rsReserved_Subject_Name;
extern const wchar_t* rsFound_New_Subject;
extern const wchar_t* rsSelect_Founded_Subject;
extern const wchar_t* rsUpdate_Founded_Subject;

extern const wchar_t* rsPrediction_Window;
extern const wchar_t* rsSolve_Parameters;
extern const wchar_t* rsSolve_Using_All_Segments;
extern const wchar_t* rsSolve_On_Level_Count;
extern const wchar_t* rsSolve_On_Calibration;
extern const wchar_t* rsSolve_On_Time_Segment_End;

extern const wchar_t* rsMatlab_Manifest_File;
extern const wchar_t* rsMatlab_Manifest_Session_Name_Path;
extern const wchar_t* rsMatlab_Manifest_Workdir_Path;
extern const wchar_t* rsMatlab_Manifest_Models_Path;
extern const wchar_t* rsMatlab_Manifest_Solvers_Path;
extern const wchar_t* rsMatlab_Manifest_Model_Tag;
extern const wchar_t* rsMatlab_Manifest_Solver_Tag;
extern const wchar_t* rsMatlab_Manifest_Id_Parameter;
extern const wchar_t* rsMatlab_Manifest_Description_Parameter;
extern const wchar_t* rsMatlab_Manifest_Name_Parameter;
extern const wchar_t* rsMatlab_Manifest_DB_Table_Parameter;
extern const wchar_t* rsMatlab_Manifest_Parameters_Tag;
extern const wchar_t* rsMatlab_Manifest_Parameter_Tag;
extern const wchar_t* rsMatlab_Manifest_DB_Column_Parameter;
extern const wchar_t* rsMatlab_Manifest_Default_Parameter;
extern const wchar_t* rsMatlab_Manifest_Param_Lowbound;
extern const wchar_t* rsMatlab_Manifest_Param_Upbound;
extern const wchar_t* rsMatlab_Manifest_Signals_Tag;
extern const wchar_t* rsMatlab_Manifest_Signal_Tag;
extern const wchar_t* rsMatlab_Manifest_Reference_Signal_Id_Param;
extern const wchar_t* rsMatlab_Manifest_Script_Name;
extern const wchar_t* rsMatlab_Manifest_Models_Tag;

extern const char16_t* rsMatlab_Variable_Model_Parameters;
extern const char16_t* rsMatlab_Variable_Model_Times;
extern const char16_t* rsMatlab_Variable_Model_Derivation;
extern const char16_t* rsMatlab_Variable_Model_Output;
extern const char16_t* rsMatlab_Variable_Solver_Times;
extern const char16_t* rsMatlab_Variable_Solver_Values;
extern const char16_t* rsMatlab_Variable_Solver_Hints;
extern const char16_t* rsMatlab_Variable_Solver_Lowbounds;
extern const char16_t* rsMatlab_Variable_Solver_Upbounds;
extern const char16_t* rsMatlab_Variable_Solver_Output;

extern const wchar_t* rsT1DMS_Feedback_Request;
extern const wchar_t* rsBergman_Feedback_Request;

extern const wchar_t* rsOref0_Manifest_File;
extern const wchar_t* rsOref0_Manifest_Workdir_Path;
extern const wchar_t* rsOref0_Manifest_Runner_Script_Path;
extern const wchar_t* rsOref0_Manifest_Node_Command_Path;
extern const wchar_t* rsOref0_Manifest_Socket_Timeout_Path;
extern const wchar_t* rsOref0_Manifest_Socket_Port_Path;
extern const wchar_t* rsOref0_Manifest_Default_Runner_Script;
extern const wchar_t* rsOref0_Manifest_Default_Node_Command;

extern const wchar_t* rsParameters;
extern const wchar_t* rsFeedback_Name;
extern const wchar_t* rsSynchronize_to_Signal;
extern const wchar_t* rsSynchronization_Signal;

//*******
extern const wchar_t *rsCalculate_Past_New_Params;
extern const wchar_t *rsRecalculate_With_Every_Params;
extern const wchar_t *rsUse_Just_Opened_Segments;
extern const wchar_t *rsHold_During_Solve;
extern const wchar_t* rsStepping;
extern const wchar_t* rsMaximum_Time;
extern const wchar_t* rsEcho_Default_Parameters_As_Event;
extern const wchar_t* rsIndividualize_Segment_Specific_Parameters;

extern const wchar_t* rsRemote_Host;
extern const wchar_t* rsRemote_Port;
extern const wchar_t* rsRemote_Model_Id;
extern const wchar_t* rsRemote_Subject_Name;

extern const wchar_t* rsReference_Signal;
extern const wchar_t* rsError_Signal;
extern const wchar_t* rsDescription;

extern const wchar_t* rsIOB_Model;
extern const wchar_t* rsCOB_Model;

extern const wchar_t* rsParam_K;
extern const wchar_t* rsKp;
extern const wchar_t* rsKi;
extern const wchar_t* rsKd;
extern const wchar_t* rsBasal_Insulin_Rate;
extern const wchar_t* rsKiDecay;

extern const wchar_t* rsLGS_Basal_Insulin_Model;
extern const wchar_t* rsSuspend_Threshold;
extern const wchar_t* rsLGS_Suspend_Duration;

extern const wchar_t* rsConst_ISF;
extern const wchar_t* rsConst_CR;

extern const wchar_t* rsOutput_CSV_File;
extern const wchar_t* rsSignal_Stats_Header;
extern const wchar_t* rsDecoupling_Stats_Header;
extern const wchar_t* rsDiabetes_Grid_Header;

extern const wchar_t* rsPattern_Prediction_Model;
extern const wchar_t* rsParameters_File;
extern const wchar_t* rsDo_Not_Update_Parameters_File;
extern const wchar_t* rsDo_Not_Learn;
extern const wchar_t* rsUse_Config_parameters;
extern const wchar_t* rsSanitize_Unused_Patterns;
extern const wchar_t* rsSliding_Window_Length;
extern const wchar_t* rsLearned_Data_Filename_Prefix;

extern const wchar_t* rsIcarus_v1_AI_Boluses;
extern const wchar_t* rsBolus_Offset;
extern const wchar_t* rsBolus_Amount;

extern const wchar_t* rsIcarus_Basal_And_Bolus;
extern const wchar_t* rsCarb_To_Insulin_Ratio;

extern const wchar_t* rsWeighted_Moving_Average;
extern const wchar_t* rsWeight_0;
extern const wchar_t* rsWeight_5;
extern const wchar_t* rsWeight_10;
extern const wchar_t* rsWeight_15;
extern const wchar_t* rsWeight_20;
extern const wchar_t* rsWeight_25;
extern const wchar_t* rsWeight_30;
extern const wchar_t* rsWeight_35;
extern const wchar_t* rsWeight_40;
extern const wchar_t* rsWeight_45;
extern const wchar_t* rsWeight_50;
extern const wchar_t* rsWeight_55;

extern const wchar_t* rsSignal_Id;
extern const wchar_t* rsResponse_Window;

extern const wchar_t* rsFailed_to_allocate_memory;

extern const wchar_t* rsUnused_Variable_Name;

extern const wchar_t* rsMinimum;
extern const wchar_t* rsPeriod;