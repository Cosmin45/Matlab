/*
 * AlarmSystem.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "AlarmSystem".
 *
 * Model version              : 1.4
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Dec 14 18:28:37 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AlarmSystem.h"
#include "rtwtypes.h"
#include <string.h>
#include "AlarmSystem_private.h"
#include "rt_nonfinite.h"

/* Named constants for Chart: '<Root>/AlarmSystem' */
#define AlarmSystem_IN_ALARM           ((uint8_T)1U)
#define AlarmSystem_IN_IDLE            ((uint8_T)2U)
#define AlarmSystem_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define AlarmSystem_IN_WAIT            ((uint8_T)3U)

/* Block states (default storage) */
DW_AlarmSystem_T AlarmSystem_DW;

/* External inputs (root inport signals with default storage) */
ExtU_AlarmSystem_T AlarmSystem_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_AlarmSystem_T AlarmSystem_Y;

/* Real-time model */
static RT_MODEL_AlarmSystem_T AlarmSystem_M_;
RT_MODEL_AlarmSystem_T *const AlarmSystem_M = &AlarmSystem_M_;

/* Model step function */
void AlarmSystem_step(void)
{
  /* Chart: '<Root>/AlarmSystem' incorporates:
   *  Inport: '<Root>/CodeOK'
   *  Inport: '<Root>/DoorOpen'
   */
  if (AlarmSystem_DW.temporalCounter_i1 < 2047U) {
    AlarmSystem_DW.temporalCounter_i1++;
  }

  if (AlarmSystem_DW.is_active_c3_AlarmSystem == 0U) {
    AlarmSystem_DW.is_active_c3_AlarmSystem = 1U;
    AlarmSystem_DW.is_c3_AlarmSystem = AlarmSystem_IN_IDLE;

    /* Outport: '<Root>/AlarmON' */
    AlarmSystem_Y.AlarmON = false;
  } else {
    switch (AlarmSystem_DW.is_c3_AlarmSystem) {
     case AlarmSystem_IN_ALARM:
      /* Outport: '<Root>/AlarmON' */
      AlarmSystem_Y.AlarmON = true;
      if (AlarmSystem_U.CodeOK == 1.0) {
        AlarmSystem_DW.is_c3_AlarmSystem = AlarmSystem_IN_IDLE;

        /* Outport: '<Root>/AlarmON' */
        AlarmSystem_Y.AlarmON = false;
      }
      break;

     case AlarmSystem_IN_IDLE:
      /* Outport: '<Root>/AlarmON' */
      AlarmSystem_Y.AlarmON = false;
      if (AlarmSystem_U.DoorOpen == 1.0) {
        AlarmSystem_DW.temporalCounter_i1 = 0U;
        AlarmSystem_DW.is_c3_AlarmSystem = AlarmSystem_IN_WAIT;
      }
      break;

     default:
      /* case IN_WAIT: */
      if (AlarmSystem_U.CodeOK == 1.0) {
        AlarmSystem_DW.is_c3_AlarmSystem = AlarmSystem_IN_IDLE;

        /* Outport: '<Root>/AlarmON' */
        AlarmSystem_Y.AlarmON = false;
      } else if (AlarmSystem_DW.temporalCounter_i1 >= 1500U) {
        AlarmSystem_DW.is_c3_AlarmSystem = AlarmSystem_IN_ALARM;

        /* Outport: '<Root>/AlarmON' */
        AlarmSystem_Y.AlarmON = true;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/AlarmSystem' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(AlarmSystem_M->rtwLogInfo,
                      (&AlarmSystem_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(AlarmSystem_M)!=-1) &&
        !((rtmGetTFinal(AlarmSystem_M)-AlarmSystem_M->Timing.taskTime0) >
          AlarmSystem_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(AlarmSystem_M, "Simulation finished");
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
  if (!(++AlarmSystem_M->Timing.clockTick0)) {
    ++AlarmSystem_M->Timing.clockTickH0;
  }

  AlarmSystem_M->Timing.taskTime0 = AlarmSystem_M->Timing.clockTick0 *
    AlarmSystem_M->Timing.stepSize0 + AlarmSystem_M->Timing.clockTickH0 *
    AlarmSystem_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void AlarmSystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)AlarmSystem_M, 0,
                sizeof(RT_MODEL_AlarmSystem_T));
  rtmSetTFinal(AlarmSystem_M, 30.0);
  AlarmSystem_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    AlarmSystem_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(AlarmSystem_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(AlarmSystem_M->rtwLogInfo, (NULL));
    rtliSetLogT(AlarmSystem_M->rtwLogInfo, "tout");
    rtliSetLogX(AlarmSystem_M->rtwLogInfo, "");
    rtliSetLogXFinal(AlarmSystem_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(AlarmSystem_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(AlarmSystem_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(AlarmSystem_M->rtwLogInfo, 0);
    rtliSetLogDecimation(AlarmSystem_M->rtwLogInfo, 1);
    rtliSetLogY(AlarmSystem_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(AlarmSystem_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(AlarmSystem_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&AlarmSystem_DW, 0,
                sizeof(DW_AlarmSystem_T));

  /* external inputs */
  (void)memset(&AlarmSystem_U, 0, sizeof(ExtU_AlarmSystem_T));

  /* external outputs */
  AlarmSystem_Y.AlarmON = false;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(AlarmSystem_M->rtwLogInfo, 0.0, rtmGetTFinal
    (AlarmSystem_M), AlarmSystem_M->Timing.stepSize0, (&rtmGetErrorStatus
    (AlarmSystem_M)));

  /* SystemInitialize for Chart: '<Root>/AlarmSystem' */
  AlarmSystem_DW.temporalCounter_i1 = 0U;
  AlarmSystem_DW.is_active_c3_AlarmSystem = 0U;
  AlarmSystem_DW.is_c3_AlarmSystem = AlarmSystem_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Outport: '<Root>/AlarmON' incorporates:
   *  Chart: '<Root>/AlarmSystem'
   */
  AlarmSystem_Y.AlarmON = false;
}

/* Model terminate function */
void AlarmSystem_terminate(void)
{
  /* (no terminate code required) */
}
