/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ultrasonic_sensor.c
 *
 * Code generated for Simulink model 'ultrasonic_sensor'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Nov  2 12:41:33 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ultrasonic_sensor.h"
#include "rtwtypes.h"
#include "ultrasonic_sensor_private.h"

/* Block signals (default storage) */
B_ultrasonic_sensor_T ultrasonic_sensor_B;

/* Block states (default storage) */
DW_ultrasonic_sensor_T ultrasonic_sensor_DW;

/* Real-time model */
static RT_MODEL_ultrasonic_sensor_T ultrasonic_sensor_M_;
RT_MODEL_ultrasonic_sensor_T *const ultrasonic_sensor_M = &ultrasonic_sensor_M_;

/* Model step function */
void ultrasonic_sensor_step(void)
{
  uint32_T duration;

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  if (ultrasonic_sensor_DW.obj.TunablePropsChanged) {
    ultrasonic_sensor_DW.obj.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 50, 51, 10);

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  ultrasonic_sensor_B.UltrasonicSensor = (real_T)duration * 0.000343 / 2.0;

  {                                    /* Sample time: [0.1s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ultrasonic_sensor_M->Timing.taskTime0 =
    ((time_T)(++ultrasonic_sensor_M->Timing.clockTick0)) *
    ultrasonic_sensor_M->Timing.stepSize0;
}

/* Model initialize function */
void ultrasonic_sensor_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(ultrasonic_sensor_M, -1);
  ultrasonic_sensor_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  ultrasonic_sensor_M->Sizes.checksums[0] = (3360380242U);
  ultrasonic_sensor_M->Sizes.checksums[1] = (1240003306U);
  ultrasonic_sensor_M->Sizes.checksums[2] = (251855837U);
  ultrasonic_sensor_M->Sizes.checksums[3] = (1269915446U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    ultrasonic_sensor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ultrasonic_sensor_M->extModeInfo,
      &ultrasonic_sensor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ultrasonic_sensor_M->extModeInfo,
                        ultrasonic_sensor_M->Sizes.checksums);
    rteiSetTPtr(ultrasonic_sensor_M->extModeInfo, rtmGetTPtr(ultrasonic_sensor_M));
  }

  /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
  ultrasonic_sensor_DW.obj.isInitialized = 1L;
  MW_UltrasonicSetup(50, 51);
  ultrasonic_sensor_DW.obj.TunablePropsChanged = false;
}

/* Model terminate function */
void ultrasonic_sensor_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
