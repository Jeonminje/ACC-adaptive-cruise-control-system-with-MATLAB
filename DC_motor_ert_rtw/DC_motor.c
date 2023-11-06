/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DC_motor.c
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

#include "DC_motor.h"
#include "DC_motor_types.h"
#include "rtwtypes.h"
#include "DC_motor_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<Root>/Chart' */
#define DC_motor_IN_acc_off            (1UL)
#define DC_motor_IN_follow             (2UL)
#define DC_motor_IN_follow_1           (3UL)
#define DC_motor_IN_follow_2           (4UL)
#define DC_motor_IN_follow_3           (5UL)
#define DC_motor_IN_follow_4           (6UL)
#define DC_motor_IN_return             (7UL)
#define DC_motor_IN_speed_control      (8UL)

/* Block signals (default storage) */
B_DC_motor_T DC_motor_B;

/* Block states (default storage) */
DW_DC_motor_T DC_motor_DW;

/* Real-time model */
static RT_MODEL_DC_motor_T DC_motor_M_;
RT_MODEL_DC_motor_T *const DC_motor_M = &DC_motor_M_;

/* Forward declaration for local functions */
static void DC_motor_SystemCore_release(codertarget_arduinobase_int_n_T *obj);
static void rate_monotonic_scheduler(void);

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt' */
void MW_ISR_2(void)
{
  /* Call the system: <Root>/Function-Call Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(DC_motor_DW.FunctionCallSubsystem_SubsysRan);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (DC_motor_M->Timing.rtmDbBufWriteBuf2) {
     case 0:
      DC_motor_M->Timing.rtmDbBufReadBuf2 = 1;
      break;

     case 1:
      DC_motor_M->Timing.rtmDbBufReadBuf2 = 0;
      break;

     default:
      DC_motor_M->Timing.rtmDbBufReadBuf2 =
        DC_motor_M->Timing.rtmDbBufLastBufWr2;
      break;
    }

    DC_motor_M->Timing.clockTick2 = DC_motor_M->
      Timing.rtmDbBufClockTick2[DC_motor_M->Timing.rtmDbBufReadBuf2];
    DC_motor_M->Timing.rtmDbBufReadBuf2 = 0xFF;

    /* Logic: '<S3>/XOR' incorporates:
     *  Constant: '<S3>/Constant'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    DC_motor_DW.UnitDelay_DSTATE_h = (DC_motor_P.Constant_Value != 0.0) ^
      DC_motor_DW.UnitDelay_DSTATE_h;
    DC_motor_DW.FunctionCallSubsystem_SubsysRan = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
  }
}

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt1' */
void MW_ISR_3(void)
{
  /* Call the system: <Root>/Function-Call Subsystem1 */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(DC_motor_DW.FunctionCallSubsystem1_SubsysRa);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt1' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem1' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (DC_motor_M->Timing.rtmDbBufWriteBuf3) {
     case 0:
      DC_motor_M->Timing.rtmDbBufReadBuf3 = 1;
      break;

     case 1:
      DC_motor_M->Timing.rtmDbBufReadBuf3 = 0;
      break;

     default:
      DC_motor_M->Timing.rtmDbBufReadBuf3 =
        DC_motor_M->Timing.rtmDbBufLastBufWr3;
      break;
    }

    DC_motor_M->Timing.clockTick3 = DC_motor_M->
      Timing.rtmDbBufClockTick3[DC_motor_M->Timing.rtmDbBufReadBuf3];
    DC_motor_M->Timing.rtmDbBufReadBuf3 = 0xFF;

    /* Logic: '<S4>/XOR' incorporates:
     *  Constant: '<S4>/Constant'
     *  UnitDelay: '<S4>/Unit Delay'
     */
    DC_motor_DW.UnitDelay_DSTATE_e = (DC_motor_P.Constant_Value_f != 0.0) ^
      DC_motor_DW.UnitDelay_DSTATE_e;
    DC_motor_DW.FunctionCallSubsystem1_SubsysRa = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt1' */
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void DC_motor_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(DC_motor_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (DC_motor_M->Timing.TaskCounters.TID[1])++;
  if ((DC_motor_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.5s, 0.0s] */
    DC_motor_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void DC_motor_SystemCore_release(codertarget_arduinobase_int_n_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
    MW_PWM_SetDutyCycle(obj->PWMDriverObj.MW_PWM_HANDLE, -0.0);
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
    MW_PWM_Close(obj->PWMDriverObj.MW_PWM_HANDLE);
  }
}

/* Model step function for TID0 */
void DC_motor_step0(void)              /* Sample time: [0.1s, 0.0s] */
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  codertarget_arduinobase_int_n_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  uint32_T duration;
  uint16_T b_varargout_1;
  boolean_T rtb_LessThan1;

  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  if (DC_motor_DW.obj_pe.TunablePropsChanged) {
    DC_motor_DW.obj_pe.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 50, 51, 10);

  /* Gain: '<Root>/Multiply1' incorporates:
   *  MATLABSystem: '<Root>/Ultrasonic Sensor'
   */
  DC_motor_B.Multiply1 = (real_T)duration * 0.000343 / 2.0 *
    DC_motor_P.Multiply1_Gain;

  /* RelationalOperator: '<Root>/Less Than1' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtb_LessThan1 = (DC_motor_B.Multiply1 < DC_motor_P.Constant3_Value);

  /* RateTransition: '<Root>/Rate Transition1' incorporates:
   *  UnitDelay: '<S4>/Unit Delay'
   */
  DC_motor_B.RateTransition1 = DC_motor_DW.UnitDelay_DSTATE_e;

  /* Logic: '<Root>/AND1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  RelationalOperator: '<Root>/NotEqual1'
   */
  DC_motor_B.AND1 = (rtb_LessThan1 && (DC_motor_B.RateTransition1 !=
    DC_motor_P.Constant2_Value));

  /* MATLABSystem: '<Root>/Digital Output1' */
  writeDigitalPin(8, (uint8_T)DC_motor_B.AND1);

  /* Logic: '<Root>/AND' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  RelationalOperator: '<Root>/Less Than'
   *  RelationalOperator: '<Root>/NotEqual'
   */
  DC_motor_B.AND = ((DC_motor_B.Multiply1 < DC_motor_P.Constant_Value_j) &&
                    (DC_motor_B.RateTransition1 != DC_motor_P.Constant1_Value));

  /* MATLABSystem: '<Root>/Digital Output2' */
  writeDigitalPin(12, (uint8_T)DC_motor_B.AND);

  /* MATLABSystem: '<Root>/Analog Input' */
  if (DC_motor_DW.obj_h.SampleTime != DC_motor_P.AnalogInput_SampleTime) {
    DC_motor_DW.obj_h.SampleTime = DC_motor_P.AnalogInput_SampleTime;
  }

  obj = &DC_motor_DW.obj_h;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (DC_motor_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     datatype_id);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Gain: '<Root>/Multiply'
   *  MATLABSystem: '<Root>/Analog Input'
   */
  DC_motor_B.DataTypeConversion = (uint8_T)(((uint32_T)DC_motor_P.Multiply_Gain *
    b_varargout_1) >> 17);

  /* MATLABSystem: '<Root>/PWM1' incorporates:
   *  Gain: '<Root>/Multiply2'
   */
  obj_0 = &DC_motor_DW.obj_l;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
  MW_PWM_SetDutyCycle(DC_motor_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, -((real_T)
    (DC_motor_B.AND1 ? (int16_T)DC_motor_P.Multiply2_Gain : 0) * 0.03125 *
    12857.0 / 255.0));

  /* Chart: '<Root>/Chart' */
  if (DC_motor_DW.is_active_c3_DC_motor == 0U) {
    DC_motor_DW.is_active_c3_DC_motor = 1U;
    DC_motor_DW.is_c3_DC_motor = DC_motor_IN_acc_off;
    DC_motor_B.output = DC_motor_B.DataTypeConversion;
    DC_motor_DW.acc_speed = DC_motor_B.DataTypeConversion1;
  } else {
    switch (DC_motor_DW.is_c3_DC_motor) {
     case DC_motor_IN_acc_off:
      if (DC_motor_B.RateTransition1) {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_speed_control;
        DC_motor_B.output = DC_motor_DW.acc_speed;
      } else {
        DC_motor_B.output = DC_motor_B.DataTypeConversion;
        DC_motor_DW.acc_speed = DC_motor_B.DataTypeConversion1;
      }
      break;

     case DC_motor_IN_follow:
      if ((DC_motor_DW.acc_speed < 60) && (DC_motor_B.Multiply1 > 50.0)) {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_return;
        DC_motor_DW.acc_speed = 60U;
      } else if ((DC_motor_B.Multiply1 <= 40.0) && (DC_motor_B.Multiply1 > 30.0))
      {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_follow_1;
        DC_motor_B.output = (uint8_T)rt_roundd_snf((real_T)DC_motor_DW.acc_speed
          * 0.8);
      } else if ((DC_motor_DW.acc_speed > 60) && (DC_motor_B.Multiply1 > 50.0))
      {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_speed_control;
        DC_motor_B.output = DC_motor_DW.acc_speed;
      } else {
        DC_motor_B.output = (uint8_T)rt_roundd_snf((real_T)DC_motor_DW.acc_speed
          * 0.9);
      }
      break;

     case DC_motor_IN_follow_1:
      if ((DC_motor_B.Multiply1 <= 30.0) && (DC_motor_B.Multiply1 > 20.0)) {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_follow_2;
        DC_motor_B.output = (uint8_T)rt_roundd_snf((real_T)DC_motor_DW.acc_speed
          * 0.7);
      } else if (DC_motor_B.Multiply1 > 40.0) {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_follow;
        DC_motor_B.output = (uint8_T)rt_roundd_snf((real_T)DC_motor_DW.acc_speed
          * 0.9);
      } else {
        DC_motor_B.output = (uint8_T)rt_roundd_snf((real_T)DC_motor_DW.acc_speed
          * 0.8);
      }
      break;

     case DC_motor_IN_follow_2:
      if ((DC_motor_B.Multiply1 <= 20.0) && (DC_motor_B.Multiply1 >= 10.0)) {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_follow_3;
        DC_motor_B.output = (uint8_T)rt_roundd_snf((real_T)DC_motor_DW.acc_speed
          * 0.6);
      } else if (DC_motor_B.Multiply1 > 30.0) {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_follow_1;
        DC_motor_B.output = (uint8_T)rt_roundd_snf((real_T)DC_motor_DW.acc_speed
          * 0.8);
      } else {
        DC_motor_B.output = (uint8_T)rt_roundd_snf((real_T)DC_motor_DW.acc_speed
          * 0.7);
      }
      break;

     case DC_motor_IN_follow_3:
      if (DC_motor_B.Multiply1 > 20.0) {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_follow_2;
        DC_motor_B.output = (uint8_T)rt_roundd_snf((real_T)DC_motor_DW.acc_speed
          * 0.7);
      } else if (DC_motor_B.Multiply1 < 10.0) {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_follow_4;
        DC_motor_B.output = 0U;
      } else {
        DC_motor_B.output = (uint8_T)rt_roundd_snf((real_T)DC_motor_DW.acc_speed
          * 0.6);
      }
      break;

     case DC_motor_IN_follow_4:
      if (DC_motor_B.Multiply1 >= 10.0) {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_follow_3;
        DC_motor_B.output = (uint8_T)rt_roundd_snf((real_T)DC_motor_DW.acc_speed
          * 0.6);
      } else {
        DC_motor_B.output = 0U;
      }
      break;

     case DC_motor_IN_return:
      DC_motor_DW.is_c3_DC_motor = DC_motor_IN_speed_control;
      DC_motor_B.output = DC_motor_DW.acc_speed;
      break;

     default:
      /* case IN_speed_control: */
      if (!DC_motor_B.RateTransition1) {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_acc_off;
        DC_motor_B.output = DC_motor_B.DataTypeConversion;
        DC_motor_DW.acc_speed = DC_motor_B.DataTypeConversion1;
      } else if (DC_motor_B.Multiply1 <= 50.0) {
        DC_motor_DW.is_c3_DC_motor = DC_motor_IN_follow;
        DC_motor_B.output = (uint8_T)rt_roundd_snf((real_T)DC_motor_DW.acc_speed
          * 0.9);
      } else {
        DC_motor_B.output = DC_motor_DW.acc_speed;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  DC_motor_B.RateTransition = DC_motor_DW.UnitDelay_DSTATE_h;

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(13, (uint8_T)DC_motor_B.RateTransition);

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  DC_motor_M->Timing.taskTime0 =
    ((time_T)(++DC_motor_M->Timing.clockTick0)) * DC_motor_M->Timing.stepSize0;
  switch (DC_motor_M->Timing.rtmDbBufReadBuf2) {
   case 0:
    DC_motor_M->Timing.rtmDbBufWriteBuf2 = 1;
    break;

   case 1:
    DC_motor_M->Timing.rtmDbBufWriteBuf2 = 0;
    break;

   default:
    DC_motor_M->Timing.rtmDbBufWriteBuf2 =
      !DC_motor_M->Timing.rtmDbBufLastBufWr2;
    break;
  }

  DC_motor_M->Timing.rtmDbBufClockTick2[DC_motor_M->Timing.rtmDbBufWriteBuf2] =
    DC_motor_M->Timing.clockTick0;
  DC_motor_M->Timing.rtmDbBufLastBufWr2 = DC_motor_M->Timing.rtmDbBufWriteBuf2;
  DC_motor_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
  switch (DC_motor_M->Timing.rtmDbBufReadBuf3) {
   case 0:
    DC_motor_M->Timing.rtmDbBufWriteBuf3 = 1;
    break;

   case 1:
    DC_motor_M->Timing.rtmDbBufWriteBuf3 = 0;
    break;

   default:
    DC_motor_M->Timing.rtmDbBufWriteBuf3 =
      !DC_motor_M->Timing.rtmDbBufLastBufWr3;
    break;
  }

  DC_motor_M->Timing.rtmDbBufClockTick3[DC_motor_M->Timing.rtmDbBufWriteBuf3] =
    DC_motor_M->Timing.clockTick0;
  DC_motor_M->Timing.rtmDbBufLastBufWr3 = DC_motor_M->Timing.rtmDbBufWriteBuf3;
  DC_motor_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
}

/* Model step function for TID1 */
void DC_motor_step1(void)              /* Sample time: [0.5s, 0.0s] */
{
  codertarget_arduinobase_int_n_T *obj;
  real32_T b_varargout_1;
  real32_T b_varargout_2;

  /* Reset subsysRan breadcrumbs */
  srClearBC(DC_motor_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DC_motor_DW.IfActionSubsystem1_SubsysRanBC);

  /* MATLABSystem: '<S2>/MATLAB System' */
  if (DC_motor_DW.obj.Pin != DC_motor_P.DHT_Pin) {
    DC_motor_DW.obj.Pin = DC_motor_P.DHT_Pin;
  }

  if (DC_motor_DW.obj.Sensor != DC_motor_P.DHT_Tp) {
    DC_motor_DW.obj.Sensor = DC_motor_P.DHT_Tp;
  }

  if (DC_motor_DW.obj.F != DC_motor_P.DHT_F) {
    DC_motor_DW.obj.F = DC_motor_P.DHT_F;
  }

  if (DC_motor_DW.obj.SampleTime != DC_motor_P.DHT_Ts) {
    DC_motor_DW.obj.SampleTime = DC_motor_P.DHT_Ts;
  }

  /*         %% Define output properties */
  /*  Call C-function implementing device output */
  b_varargout_1 = readHumidity();
  if (DC_motor_DW.obj.F != 0.0) {
    /*  if in Fahrenheit */
    b_varargout_2 = readTempF();
    computeHeatIndexF(b_varargout_2, b_varargout_1);
  } else {
    /*  if in Celsius */
    b_varargout_2 = readTemp();
    computeHeatIndex(b_varargout_2, b_varargout_1);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  MATLABSystem: '<S2>/MATLAB System'
   */
  b_varargout_1 = (real32_T)floor(b_varargout_1);
  if (rtIsNaNF(b_varargout_1) || rtIsInfF(b_varargout_1)) {
    b_varargout_1 = 0.0F;
  } else {
    b_varargout_1 = (real32_T)fmod(b_varargout_1, 256.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  DC_motor_B.DataTypeConversion2 = (uint8_T)(b_varargout_1 < 0.0F ? (int16_T)
    (uint8_T)-(int8_T)(uint8_T)-b_varargout_1 : (int16_T)(uint8_T)b_varargout_1);

  /* MATLABSystem: '<Root>/Digital Output3' incorporates:
   *  Constant: '<Root>/Constant4'
   *  RelationalOperator: '<Root>/Relational Operator'
   */
  writeDigitalPin(10, (uint8_T)(DC_motor_P.Constant4_Value <=
    DC_motor_B.DataTypeConversion2));

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  DC_motor_B.DataTypeConversion1 = DC_motor_DW.UnitDelay_DSTATE;

  /* If: '<Root>/If' incorporates:
   *  Constant: '<Root>/Constant5'
   *  RelationalOperator: '<Root>/Relational Operator1'
   */
  if (DC_motor_P.Constant5_Value <= DC_motor_B.DataTypeConversion2) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion'
     *  Gain: '<S5>/Multiply'
     */
    DC_motor_B.Merge = (uint8_T)(((uint16_T)DC_motor_P.Multiply_Gain_l *
      DC_motor_B.output) >> 8);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(DC_motor_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  SignalConversion generated from: '<S6>/output'
     */
    DC_motor_B.Merge = DC_motor_B.output;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(DC_motor_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem1' */
  }

  /* End of If: '<Root>/If' */

  /* MATLABSystem: '<Root>/PWM' */
  obj = &DC_motor_DW.obj_h5;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
  MW_PWM_SetDutyCycle(DC_motor_DW.obj_h5.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                      DC_motor_B.Merge);

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  DC_motor_DW.UnitDelay_DSTATE = DC_motor_B.Merge;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.5, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  DC_motor_M->Timing.clockTick1++;
}

/* Model initialize function */
void DC_motor_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(DC_motor_M, -1);
  DC_motor_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  DC_motor_M->Sizes.checksums[0] = (422032543U);
  DC_motor_M->Sizes.checksums[1] = (848361615U);
  DC_motor_M->Sizes.checksums[2] = (1891626663U);
  DC_motor_M->Sizes.checksums[3] = (2428594689U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    DC_motor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)&DC_motor_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[9] = (sysRanDType *)&DC_motor_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[10] = (sysRanDType *)&DC_motor_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&DC_motor_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DC_motor_M->extModeInfo,
      &DC_motor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DC_motor_M->extModeInfo, DC_motor_M->Sizes.checksums);
    rteiSetTPtr(DC_motor_M->extModeInfo, rtmGetTPtr(DC_motor_M));
  }

  {
    codertarget_arduinobase_int_n_T *obj_0;
    codertarget_arduinobase_inter_T *obj;
    real_T sampleTime;
    real_T tmp;
    uint8_T tmp_0;
    uint8_T tmp_1;
    DC_motor_M->Timing.rtmDbBufReadBuf2 = 0xFF;
    DC_motor_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
    DC_motor_M->Timing.rtmDbBufLastBufWr2 = 0;
    DC_motor_M->Timing.rtmDbBufReadBuf3 = 0xFF;
    DC_motor_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
    DC_motor_M->Timing.rtmDbBufLastBufWr3 = 0;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    DC_motor_DW.UnitDelay_DSTATE = DC_motor_P.UnitDelay_InitialCondition_g;

    /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt1' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem1'
     */
    /* System initialize for function-call system: '<Root>/Function-Call Subsystem1' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (DC_motor_M->Timing.rtmDbBufWriteBuf3) {
     case 0:
      DC_motor_M->Timing.rtmDbBufReadBuf3 = 1;
      break;

     case 1:
      DC_motor_M->Timing.rtmDbBufReadBuf3 = 0;
      break;

     default:
      DC_motor_M->Timing.rtmDbBufReadBuf3 =
        DC_motor_M->Timing.rtmDbBufLastBufWr3;
      break;
    }

    DC_motor_M->Timing.clockTick3 = DC_motor_M->
      Timing.rtmDbBufClockTick3[DC_motor_M->Timing.rtmDbBufReadBuf3];
    DC_motor_M->Timing.rtmDbBufReadBuf3 = 0xFF;

    /* SystemInitialize for Outport: '<S4>/Out1' incorporates:
     *  Logic: '<S4>/XOR'
     *  UnitDelay: '<S4>/Unit Delay'
     */
    DC_motor_DW.UnitDelay_DSTATE_e = DC_motor_P.Out1_Y0_h;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(3), &MW_ISR_3, FALLING);

    /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (DC_motor_M->Timing.rtmDbBufWriteBuf2) {
     case 0:
      DC_motor_M->Timing.rtmDbBufReadBuf2 = 1;
      break;

     case 1:
      DC_motor_M->Timing.rtmDbBufReadBuf2 = 0;
      break;

     default:
      DC_motor_M->Timing.rtmDbBufReadBuf2 =
        DC_motor_M->Timing.rtmDbBufLastBufWr2;
      break;
    }

    DC_motor_M->Timing.clockTick2 = DC_motor_M->
      Timing.rtmDbBufClockTick2[DC_motor_M->Timing.rtmDbBufReadBuf2];
    DC_motor_M->Timing.rtmDbBufReadBuf2 = 0xFF;

    /* SystemInitialize for Outport: '<S3>/Out1' incorporates:
     *  Logic: '<S3>/XOR'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    DC_motor_DW.UnitDelay_DSTATE_h = DC_motor_P.Out1_Y0;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, FALLING);

    /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
    DC_motor_DW.obj_pe.isInitialized = 1L;
    MW_UltrasonicSetup(50, 51);
    DC_motor_DW.obj_pe.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    DC_motor_DW.obj_p.matlabCodegenIsDeleted = false;
    DC_motor_DW.obj_p.isInitialized = 1L;
    digitalIOSetup(8, 1);
    DC_motor_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output2' */
    DC_motor_DW.obj_dh.matlabCodegenIsDeleted = false;
    DC_motor_DW.obj_dh.isInitialized = 1L;
    digitalIOSetup(12, 1);
    DC_motor_DW.obj_dh.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    DC_motor_DW.obj_h.matlabCodegenIsDeleted = false;
    DC_motor_DW.obj_h.SampleTime = DC_motor_P.AnalogInput_SampleTime;
    obj = &DC_motor_DW.obj_h;
    DC_motor_DW.obj_h.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(54UL);
    DC_motor_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM1' */
    DC_motor_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &DC_motor_DW.obj_l;
    DC_motor_DW.obj_l.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 1.0, 12857.0);
    DC_motor_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    DC_motor_DW.obj_b.matlabCodegenIsDeleted = false;
    DC_motor_DW.obj_b.isInitialized = 1L;
    digitalIOSetup(13, 1);
    DC_motor_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/MATLAB System' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    DC_motor_DW.obj.matlabCodegenIsDeleted = false;
    DC_motor_DW.obj.Pin = DC_motor_P.DHT_Pin;
    DC_motor_DW.obj.Sensor = DC_motor_P.DHT_Tp;
    DC_motor_DW.obj.F = DC_motor_P.DHT_F;
    if (((!rtIsInf(DC_motor_P.DHT_Ts)) && (!rtIsNaN(DC_motor_P.DHT_Ts))) ||
        rtIsInf(DC_motor_P.DHT_Ts)) {
      sampleTime = DC_motor_P.DHT_Ts;
    }

    DC_motor_DW.obj.SampleTime = sampleTime;
    DC_motor_DW.obj.isInitialized = 1L;

    /*         %% Define output properties */
    /*  Call C-function implementing device initialization */
    sampleTime = rt_roundd_snf(DC_motor_DW.obj.Pin);
    tmp = rt_roundd_snf(DC_motor_DW.obj.Sensor);
    if (sampleTime < 256.0) {
      if (sampleTime >= 0.0) {
        tmp_0 = (uint8_T)sampleTime;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_1 = (uint8_T)tmp;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    setDHT(tmp_0, tmp_1);
    DC_motor_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/MATLAB System' */

    /* Start for MATLABSystem: '<Root>/Digital Output3' */
    DC_motor_DW.obj_d.matlabCodegenIsDeleted = false;
    DC_motor_DW.obj_d.isInitialized = 1L;
    digitalIOSetup(10, 1);
    DC_motor_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    DC_motor_DW.obj_h5.matlabCodegenIsDeleted = false;
    obj_0 = &DC_motor_DW.obj_h5;
    DC_motor_DW.obj_h5.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    DC_motor_DW.obj_h5.isSetupComplete = true;
  }
}

/* Model terminate function */
void DC_motor_terminate(void)
{
  codertarget_arduinobase_int_n_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!DC_motor_DW.obj_p.matlabCodegenIsDeleted) {
    DC_motor_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!DC_motor_DW.obj_dh.matlabCodegenIsDeleted) {
    DC_motor_DW.obj_dh.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &DC_motor_DW.obj_h;
  if (!DC_motor_DW.obj_h.matlabCodegenIsDeleted) {
    DC_motor_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((DC_motor_DW.obj_h.isInitialized == 1L) &&
        DC_motor_DW.obj_h.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close(DC_motor_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  if (!DC_motor_DW.obj_l.matlabCodegenIsDeleted) {
    DC_motor_DW.obj_l.matlabCodegenIsDeleted = true;
    DC_motor_SystemCore_release(&DC_motor_DW.obj_l);
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!DC_motor_DW.obj_b.matlabCodegenIsDeleted) {
    DC_motor_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
  /* Terminate for MATLABSystem: '<S2>/MATLAB System' */
  if (!DC_motor_DW.obj.matlabCodegenIsDeleted) {
    DC_motor_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/MATLAB System' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!DC_motor_DW.obj_d.matlabCodegenIsDeleted) {
    DC_motor_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj_0 = &DC_motor_DW.obj_h5;
  if (!DC_motor_DW.obj_h5.matlabCodegenIsDeleted) {
    DC_motor_DW.obj_h5.matlabCodegenIsDeleted = true;
    if ((DC_motor_DW.obj_h5.isInitialized == 1L) &&
        DC_motor_DW.obj_h5.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(DC_motor_DW.obj_h5.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(DC_motor_DW.obj_h5.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
