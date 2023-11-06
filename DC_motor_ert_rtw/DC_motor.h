/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DC_motor.h
 *
 * Code generated for Simulink model 'DC_motor'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Nov  3 09:14:50 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DC_motor_h_
#define RTW_HEADER_DC_motor_h_
#ifndef DC_motor_COMMON_INCLUDES_
#define DC_motor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduinoextint.h"
#include "MW_AnalogIn.h"
#include "dht_arduino.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "MW_Ultrasonic.h"
#endif                                 /* DC_motor_COMMON_INCLUDES_ */

#include "DC_motor_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Multiply1;                    /* '<Root>/Multiply1' */
  uint8_T DataTypeConversion;          /* '<Root>/Data Type Conversion' */
  uint8_T DataTypeConversion2;         /* '<Root>/Data Type Conversion2' */
  uint8_T DataTypeConversion1;         /* '<Root>/Data Type Conversion1' */
  uint8_T Merge;                       /* '<Root>/Merge' */
  uint8_T output;                      /* '<Root>/Chart' */
  boolean_T RateTransition1;           /* '<Root>/Rate Transition1' */
  boolean_T AND1;                      /* '<Root>/AND1' */
  boolean_T AND;                       /* '<Root>/AND' */
  boolean_T RateTransition;            /* '<Root>/Rate Transition' */
} B_DC_motor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  read_dht_DC_motor_T obj;             /* '<S2>/MATLAB System' */
  codertarget_arduinobase_inter_T obj_h;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_d;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_block_T obj_dh;/* '<Root>/Digital Output2' */
  codertarget_arduinobase_block_T obj_p;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_b;/* '<Root>/Digital Output' */
  codertarget_arduinobase_int_n_T obj_l;/* '<Root>/PWM1' */
  codertarget_arduinobase_int_n_T obj_h5;/* '<Root>/PWM' */
  codertarget_arduinobase_in_nw_T obj_pe;/* '<Root>/Ultrasonic Sensor' */
  uint32_T is_c3_DC_motor;             /* '<Root>/Chart' */
  uint8_T UnitDelay_DSTATE;            /* '<Root>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S4>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_h;        /* '<S3>/Unit Delay' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<Root>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<Root>/If Action Subsystem' */
  int8_T FunctionCallSubsystem1_SubsysRa;/* '<Root>/Function-Call Subsystem1' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  uint8_T acc_speed;                   /* '<Root>/Chart' */
  uint8_T is_active_c3_DC_motor;       /* '<Root>/Chart' */
} DW_DC_motor_T;

/* Parameters (default storage) */
struct P_DC_motor_T_ {
  real_T DHT_F;                        /* Mask Parameter: DHT_F
                                        * Referenced by: '<S2>/MATLAB System'
                                        */
  real_T DHT_Pin;                      /* Mask Parameter: DHT_Pin
                                        * Referenced by: '<S2>/MATLAB System'
                                        */
  real_T DHT_Tp;                       /* Mask Parameter: DHT_Tp
                                        * Referenced by: '<S2>/MATLAB System'
                                        */
  real_T DHT_Ts;                       /* Mask Parameter: DHT_Ts
                                        * Referenced by: '<S2>/MATLAB System'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Multiply1_Gain;               /* Expression: 100
                                        * Referenced by: '<Root>/Multiply1'
                                        */
  real_T Constant3_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value_j;             /* Expression: 50
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant4_Value;              /* Expression: 95
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 95
                                        * Referenced by: '<Root>/Constant5'
                                        */
  uint16_T Multiply_Gain;              /* Computed Parameter: Multiply_Gain
                                        * Referenced by: '<Root>/Multiply'
                                        */
  boolean_T Out1_Y0;                   /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S3>/Out1'
                                        */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S3>/Unit Delay'
                                */
  boolean_T Out1_Y0_h;                 /* Computed Parameter: Out1_Y0_h
                                        * Referenced by: '<S4>/Out1'
                                        */
  boolean_T UnitDelay_InitialCondition_o;
                             /* Computed Parameter: UnitDelay_InitialCondition_o
                              * Referenced by: '<S4>/Unit Delay'
                              */
  uint8_T Multiply2_Gain;              /* Computed Parameter: Multiply2_Gain
                                        * Referenced by: '<Root>/Multiply2'
                                        */
  uint8_T Multiply_Gain_l;             /* Computed Parameter: Multiply_Gain_l
                                        * Referenced by: '<S5>/Multiply'
                                        */
  uint8_T UnitDelay_InitialCondition_g;
                             /* Computed Parameter: UnitDelay_InitialCondition_g
                              * Referenced by: '<Root>/Unit Delay'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_DC_motor_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint8_T rtmDbBufReadBuf2;
    uint8_T rtmDbBufWriteBuf2;
    boolean_T rtmDbBufLastBufWr2;
    uint32_T rtmDbBufClockTick2[2];
    uint32_T clockTick3;
    uint8_T rtmDbBufReadBuf3;
    uint8_T rtmDbBufWriteBuf3;
    boolean_T rtmDbBufLastBufWr3;
    uint32_T rtmDbBufClockTick3[2];
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_DC_motor_T DC_motor_P;

/* Block signals (default storage) */
extern B_DC_motor_T DC_motor_B;

/* Block states (default storage) */
extern DW_DC_motor_T DC_motor_DW;

/* External function called from main */
extern void DC_motor_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void DC_motor_initialize(void);
extern void DC_motor_step0(void);
extern void DC_motor_step1(void);
extern void DC_motor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DC_motor_T *const DC_motor_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DC_motor'
 * '<S1>'   : 'DC_motor/Chart'
 * '<S2>'   : 'DC_motor/DHT'
 * '<S3>'   : 'DC_motor/Function-Call Subsystem'
 * '<S4>'   : 'DC_motor/Function-Call Subsystem1'
 * '<S5>'   : 'DC_motor/If Action Subsystem'
 * '<S6>'   : 'DC_motor/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_DC_motor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
