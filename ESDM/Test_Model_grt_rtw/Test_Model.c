/*
 * Test_Model.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Test_Model".
 *
 * Model version              : 1.4
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Dec 14 18:57:16 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Test_Model.h"
#include "rtwtypes.h"
#include <string.h>
#include "Test_Model_private.h"
#include "rt_nonfinite.h"

/* Named constants for Chart: '<Root>/AlarmSystem' */
#define Test_Model_IN_ALARM            ((uint8_T)1U)
#define Test_Model_IN_IDLE             ((uint8_T)2U)
#define Test_Model_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define Test_Model_IN_WAIT             ((uint8_T)3U)

/* Block states (default storage) */
DW_Test_Model_T Test_Model_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Test_Model_T Test_Model_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Test_Model_T Test_Model_Y;

/* Real-time model */
static RT_MODEL_Test_Model_T Test_Model_M_;
RT_MODEL_Test_Model_T *const Test_Model_M = &Test_Model_M_;

/* Model step function */
void Test_Model_step(void)
{
  /* Chart: '<Root>/AlarmSystem' incorporates:
   *  Inport: '<Root>/CodeOK'
   *  Inport: '<Root>/DoorOpen'
   */
  if (Test_Model_DW.temporalCounter_i1 < 2047U) {
    Test_Model_DW.temporalCounter_i1++;
  }

  if (Test_Model_DW.is_active_c3_Test_Model == 0U) {
    Test_Model_DW.is_active_c3_Test_Model = 1U;
    Test_Model_DW.is_c3_Test_Model = Test_Model_IN_IDLE;

    /* Outport: '<Root>/AlarmON' */
    Test_Model_Y.AlarmON = false;
  } else {
    switch (Test_Model_DW.is_c3_Test_Model) {
     case Test_Model_IN_ALARM:
      /* Outport: '<Root>/AlarmON' */
      Test_Model_Y.AlarmON = true;
      if (Test_Model_U.CodeOK == 1.0) {
        Test_Model_DW.is_c3_Test_Model = Test_Model_IN_IDLE;

        /* Outport: '<Root>/AlarmON' */
        Test_Model_Y.AlarmON = false;
      }
      break;

     case Test_Model_IN_IDLE:
      /* Outport: '<Root>/AlarmON' */
      Test_Model_Y.AlarmON = false;
      if (Test_Model_U.DoorOpen == 1.0) {
        Test_Model_DW.temporalCounter_i1 = 0U;
        Test_Model_DW.is_c3_Test_Model = Test_Model_IN_WAIT;
      }
      break;

     default:
      /* case IN_WAIT: */
      if (Test_Model_U.CodeOK == 1.0) {
        Test_Model_DW.is_c3_Test_Model = Test_Model_IN_IDLE;

        /* Outport: '<Root>/AlarmON' */
        Test_Model_Y.AlarmON = false;
      } else if (Test_Model_DW.temporalCounter_i1 >= 1500U) {
        Test_Model_DW.is_c3_Test_Model = Test_Model_IN_ALARM;

        /* Outport: '<Root>/AlarmON' */
        Test_Model_Y.AlarmON = true;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/AlarmSystem' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(Test_Model_M->rtwLogInfo, (&Test_Model_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(Test_Model_M)!=-1) &&
        !((rtmGetTFinal(Test_Model_M)-Test_Model_M->Timing.taskTime0) >
          Test_Model_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Test_Model_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Test_Model_M->Timing.clockTick0)) {
    ++Test_Model_M->Timing.clockTickH0;
  }

  Test_Model_M->Timing.taskTime0 = Test_Model_M->Timing.clockTick0 *
    Test_Model_M->Timing.stepSize0 + Test_Model_M->Timing.clockTickH0 *
    Test_Model_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Test_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Test_Model_M, 0,
                sizeof(RT_MODEL_Test_Model_T));
  rtmSetTFinal(Test_Model_M, 30.0);
  Test_Model_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Test_Model_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Test_Model_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Test_Model_M->rtwLogInfo, (NULL));
    rtliSetLogT(Test_Model_M->rtwLogInfo, "tout");
    rtliSetLogX(Test_Model_M->rtwLogInfo, "");
    rtliSetLogXFinal(Test_Model_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Test_Model_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Test_Model_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Test_Model_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Test_Model_M->rtwLogInfo, 1);
    rtliSetLogY(Test_Model_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Test_Model_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Test_Model_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&Test_Model_DW, 0,
                sizeof(DW_Test_Model_T));

  /* external inputs */
  (void)memset(&Test_Model_U, 0, sizeof(ExtU_Test_Model_T));

  /* external outputs */
  Test_Model_Y.AlarmON = false;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Test_Model_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Test_Model_M), Test_Model_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Test_Model_M)));

  /* SystemInitialize for Chart: '<Root>/AlarmSystem' */
  Test_Model_DW.temporalCounter_i1 = 0U;
  Test_Model_DW.is_active_c3_Test_Model = 0U;
  Test_Model_DW.is_c3_Test_Model = Test_Model_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Outport: '<Root>/AlarmON' incorporates:
   *  Chart: '<Root>/AlarmSystem'
   */
  Test_Model_Y.AlarmON = false;
}

/* Model terminate function */
void Test_Model_terminate(void)
{
  /* (no terminate code required) */
}
