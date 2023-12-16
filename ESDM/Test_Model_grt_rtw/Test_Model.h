/*
 * Test_Model.h
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

#ifndef RTW_HEADER_Test_Model_h_
#define RTW_HEADER_Test_Model_h_
#ifndef Test_Model_COMMON_INCLUDES_
#define Test_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Test_Model_COMMON_INCLUDES_ */

#include "Test_Model_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
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

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<Root>/AlarmSystem' */
  uint8_T is_active_c3_Test_Model;     /* '<Root>/AlarmSystem' */
  uint8_T is_c3_Test_Model;            /* '<Root>/AlarmSystem' */
} DW_Test_Model_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T CodeOK;                       /* '<Root>/CodeOK' */
  real_T DoorOpen;                     /* '<Root>/DoorOpen' */
} ExtU_Test_Model_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T AlarmON;                   /* '<Root>/AlarmON' */
} ExtY_Test_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_Test_Model_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block states (default storage) */
extern DW_Test_Model_T Test_Model_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Test_Model_T Test_Model_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Test_Model_T Test_Model_Y;

/* Model entry point functions */
extern void Test_Model_initialize(void);
extern void Test_Model_step(void);
extern void Test_Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Test_Model_T *const Test_Model_M;

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
 * '<Root>' : 'Test_Model'
 * '<S1>'   : 'Test_Model/AlarmSystem'
 */
#endif                                 /* RTW_HEADER_Test_Model_h_ */
