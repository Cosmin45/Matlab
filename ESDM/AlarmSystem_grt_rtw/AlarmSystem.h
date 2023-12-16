/*
 * AlarmSystem.h
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

#ifndef RTW_HEADER_AlarmSystem_h_
#define RTW_HEADER_AlarmSystem_h_
#ifndef AlarmSystem_COMMON_INCLUDES_
#define AlarmSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* AlarmSystem_COMMON_INCLUDES_ */

#include "AlarmSystem_types.h"
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
  uint8_T is_active_c3_AlarmSystem;    /* '<Root>/AlarmSystem' */
  uint8_T is_c3_AlarmSystem;           /* '<Root>/AlarmSystem' */
} DW_AlarmSystem_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T CodeOK;                       /* '<Root>/CodeOK' */
  real_T DoorOpen;                     /* '<Root>/DoorOpen' */
} ExtU_AlarmSystem_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T AlarmON;                   /* '<Root>/AlarmON' */
} ExtY_AlarmSystem_T;

/* Real-time Model Data Structure */
struct tag_RTM_AlarmSystem_T {
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
extern DW_AlarmSystem_T AlarmSystem_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_AlarmSystem_T AlarmSystem_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_AlarmSystem_T AlarmSystem_Y;

/* Model entry point functions */
extern void AlarmSystem_initialize(void);
extern void AlarmSystem_step(void);
extern void AlarmSystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AlarmSystem_T *const AlarmSystem_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Test_Model/AlarmSystem')    - opens subsystem Test_Model/AlarmSystem
 * hilite_system('Test_Model/AlarmSystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Test_Model'
 * '<S1>'   : 'Test_Model/AlarmSystem'
 */
#endif                                 /* RTW_HEADER_AlarmSystem_h_ */
