/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DC_motor_data.c
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

/* Block parameters (default storage) */
P_DC_motor_T DC_motor_P = {
  /* Mask Parameter: DHT_F
   * Referenced by: '<S2>/MATLAB System'
   */
  0.0,

  /* Mask Parameter: DHT_Pin
   * Referenced by: '<S2>/MATLAB System'
   */
  4.0,

  /* Mask Parameter: DHT_Tp
   * Referenced by: '<S2>/MATLAB System'
   */
  11.0,

  /* Mask Parameter: DHT_Ts
   * Referenced by: '<S2>/MATLAB System'
   */
  0.5,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Constant'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<Root>/Multiply1'
   */
  100.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant3'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 95
   * Referenced by: '<Root>/Constant4'
   */
  95.0,

  /* Expression: 95
   * Referenced by: '<Root>/Constant5'
   */
  95.0,

  /* Computed Parameter: Multiply_Gain
   * Referenced by: '<Root>/Multiply'
   */
  32768U,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S3>/Out1'
   */
  false,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S3>/Unit Delay'
   */
  false,

  /* Computed Parameter: Out1_Y0_h
   * Referenced by: '<S4>/Out1'
   */
  false,

  /* Computed Parameter: UnitDelay_InitialCondition_o
   * Referenced by: '<S4>/Unit Delay'
   */
  false,

  /* Computed Parameter: Multiply2_Gain
   * Referenced by: '<Root>/Multiply2'
   */
  160U,

  /* Computed Parameter: Multiply_Gain_l
   * Referenced by: '<S5>/Multiply'
   */
  230U,

  /* Computed Parameter: UnitDelay_InitialCondition_g
   * Referenced by: '<Root>/Unit Delay'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
