//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: smooth_simu.h
//
// Code generated for Simulink model 'smooth_simu'.
//
// Model version                  : 1.18
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Tue Nov 19 17:01:24 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: NXP->Cortex-M4
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef smooth_simu_h_
#define smooth_simu_h_
#include <cmath>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "smooth_simu_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model smooth_simu
class smooth_simu final
{
  // public data and function members
 public:
  // External inputs (root inport signals with default storage)
  struct ExtU_smooth_simu_T {
    real32_T u[100];                   // '<Root>/u'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_smooth_simu_T {
    real_T Out1;                       // '<Root>/Out1'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_smooth_simu_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  smooth_simu(smooth_simu const&) = delete;

  // Assignment Operator
  smooth_simu& operator= (smooth_simu const&) & = delete;

  // Move Constructor
  smooth_simu(smooth_simu &&) = delete;

  // Move Assignment Operator
  smooth_simu& operator= (smooth_simu &&) = delete;

  // Real-Time Model get method
  smooth_simu::RT_MODEL_smooth_simu_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_smooth_simu_T *pExtU_smooth_simu_T)
  {
    smooth_simu_U = *pExtU_smooth_simu_T;
  }

  // Root outports get method
  const ExtY_smooth_simu_T &getExternalOutputs() const
  {
    return smooth_simu_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  smooth_simu();

  // Destructor
  ~smooth_simu();

  // private data and function members
 private:
  // External inputs
  ExtU_smooth_simu_T smooth_simu_U;

  // External outputs
  ExtY_smooth_simu_T smooth_simu_Y;

  // private member function(s) for subsystem '<Root>'
  void FFTImplementationCallback_doHal(const real32_T x[100], int32_T xoffInit,
    creal32_T y[100], const creal32_T wwc[99], const real32_T costabinv[129],
    const real32_T sintabinv[129]);
  void smooth_simu_merge(int32_T idx[51], real32_T x[51], int32_T offset,
    int32_T np, int32_T nq, int32_T iwork[51], real32_T xwork[51]);
  void smooth_simu_sort(real32_T x[51], int32_T idx[51]);

  // Real-Time Model
  RT_MODEL_smooth_simu_T smooth_simu_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'smooth_simu'
//  '<S1>'   : 'smooth_simu/MATLAB Function'

#endif                                 // smooth_simu_h_

//
// File trailer for generated code.
//
// [EOF]
//
