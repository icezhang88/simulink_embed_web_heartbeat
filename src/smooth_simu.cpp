//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: smooth_simu.cpp
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
#include "smooth_simu.h"
#include "rtwtypes.h"
#include <cmath>
#include <cstring>
#include "smooth_simu_private.h"
#include "cmath"

// Function for MATLAB Function: '<Root>/MATLAB Function'
void smooth_simu::FFTImplementationCallback_doHal(const real32_T x[100], int32_T
  xoffInit, creal32_T y[100], const creal32_T wwc[99], const real32_T costabinv
  [129], const real32_T sintabinv[129])
{
  creal32_T fv[128];
  creal32_T fy[128];
  creal32_T ytmp[50];
  int32_T b_k;
  int32_T c_ihi;
  int32_T c_istart;
  int32_T i;
  int32_T iheight;
  int32_T iy;
  int32_T j_i;
  int32_T ju;
  real32_T hcostab[64];
  real32_T hcostabinv[64];
  real32_T hsintab[64];
  real32_T hsintabinv[64];
  real32_T temp_im;
  real32_T temp_re;
  real32_T twid_im;
  real32_T twid_re;
  real32_T ytmp_re_tmp;
  boolean_T tst;
  static const real32_T b[129]{ 1.0F, 0.999698818F, 0.99879545F, 0.997290432F,
    0.99518472F, 0.992479563F, 0.989176512F, 0.985277653F, 0.980785251F,
    0.975702107F, 0.970031261F, 0.963776052F, 0.956940353F, 0.949528158F,
    0.941544056F, 0.932992816F, 0.923879504F, 0.914209723F, 0.903989315F,
    0.893224299F, 0.881921232F, 0.870086968F, 0.857728601F, 0.84485358F,
    0.831469595F, 0.817584813F, 0.803207517F, 0.78834641F, 0.773010433F,
    0.757208824F, 0.740951121F, 0.724247098F, 0.707106769F, 0.689540565F,
    0.671559F, 0.653172851F, 0.634393334F, 0.615231633F, 0.59569931F,
    0.575808227F, 0.555570245F, 0.534997642F, 0.514102757F, 0.492898226F,
    0.471396744F, 0.449611336F, 0.427555084F, 0.40524134F, 0.382683456F,
    0.359895051F, 0.336889863F, 0.313681751F, 0.290284663F, 0.266712785F,
    0.242980197F, 0.219101235F, 0.195090324F, 0.170961902F, 0.146730468F,
    0.122410677F, 0.0980171412F, 0.0735645667F, 0.0490676761F, 0.024541229F,
    0.0F, -0.024541229F, -0.0490676761F, -0.0735645667F, -0.0980171412F,
    -0.122410677F, -0.146730468F, -0.170961902F, -0.195090324F, -0.219101235F,
    -0.242980197F, -0.266712785F, -0.290284663F, -0.313681751F, -0.336889863F,
    -0.359895051F, -0.382683456F, -0.40524134F, -0.427555084F, -0.449611336F,
    -0.471396744F, -0.492898226F, -0.514102757F, -0.534997642F, -0.555570245F,
    -0.575808227F, -0.59569931F, -0.615231633F, -0.634393334F, -0.653172851F,
    -0.671559F, -0.689540565F, -0.707106769F, -0.724247098F, -0.740951121F,
    -0.757208824F, -0.773010433F, -0.78834641F, -0.803207517F, -0.817584813F,
    -0.831469595F, -0.84485358F, -0.857728601F, -0.870086968F, -0.881921232F,
    -0.893224299F, -0.903989315F, -0.914209723F, -0.923879504F, -0.932992816F,
    -0.941544056F, -0.949528158F, -0.956940353F, -0.963776052F, -0.970031261F,
    -0.975702107F, -0.980785251F, -0.985277653F, -0.989176512F, -0.992479563F,
    -0.99518472F, -0.997290432F, -0.99879545F, -0.999698818F, -1.0F };

  static const real32_T c[129]{ 0.0F, -0.024541229F, -0.0490676761F,
    -0.0735645667F, -0.0980171412F, -0.122410677F, -0.146730468F, -0.170961902F,
    -0.195090324F, -0.219101235F, -0.242980197F, -0.266712785F, -0.290284663F,
    -0.313681751F, -0.336889863F, -0.359895051F, -0.382683456F, -0.40524134F,
    -0.427555084F, -0.449611336F, -0.471396744F, -0.492898226F, -0.514102757F,
    -0.534997642F, -0.555570245F, -0.575808227F, -0.59569931F, -0.615231633F,
    -0.634393334F, -0.653172851F, -0.671559F, -0.689540565F, -0.707106769F,
    -0.724247098F, -0.740951121F, -0.757208824F, -0.773010433F, -0.78834641F,
    -0.803207517F, -0.817584813F, -0.831469595F, -0.84485358F, -0.857728601F,
    -0.870086968F, -0.881921232F, -0.893224299F, -0.903989315F, -0.914209723F,
    -0.923879504F, -0.932992816F, -0.941544056F, -0.949528158F, -0.956940353F,
    -0.963776052F, -0.970031261F, -0.975702107F, -0.980785251F, -0.985277653F,
    -0.989176512F, -0.992479563F, -0.99518472F, -0.997290432F, -0.99879545F,
    -0.999698818F, -1.0F, -0.999698818F, -0.99879545F, -0.997290432F,
    -0.99518472F, -0.992479563F, -0.989176512F, -0.985277653F, -0.980785251F,
    -0.975702107F, -0.970031261F, -0.963776052F, -0.956940353F, -0.949528158F,
    -0.941544056F, -0.932992816F, -0.923879504F, -0.914209723F, -0.903989315F,
    -0.893224299F, -0.881921232F, -0.870086968F, -0.857728601F, -0.84485358F,
    -0.831469595F, -0.817584813F, -0.803207517F, -0.78834641F, -0.773010433F,
    -0.757208824F, -0.740951121F, -0.724247098F, -0.707106769F, -0.689540565F,
    -0.671559F, -0.653172851F, -0.634393334F, -0.615231633F, -0.59569931F,
    -0.575808227F, -0.555570245F, -0.534997642F, -0.514102757F, -0.492898226F,
    -0.471396744F, -0.449611336F, -0.427555084F, -0.40524134F, -0.382683456F,
    -0.359895051F, -0.336889863F, -0.313681751F, -0.290284663F, -0.266712785F,
    -0.242980197F, -0.219101235F, -0.195090324F, -0.170961902F, -0.146730468F,
    -0.122410677F, -0.0980171412F, -0.0735645667F, -0.0490676761F, -0.024541229F,
    -0.0F };

  static const creal32_T reconVar1[50]{ { 1.0F,// re
      -1.0F                            // im
    }, { 0.937209487F,                 // re
      -0.998026729F                    // im
    }, { 0.87466675F,                  // re
      -0.992114723F                    // im
    }, { 0.812618673F,                 // re
      -0.982287228F                    // im
    }, { 0.75131011F,                  // re
      -0.968583167F                    // im
    }, { 0.690983F,                    // re
      -0.95105654F                     // im
    }, { 0.631875396F,                 // re
      -0.92977649F                     // im
    }, { 0.574220657F,                 // re
      -0.904827058F                    // im
    }, { 0.518246293F,                 // re
      -0.876306653F                    // im
    }, { 0.464173138F,                 // re
      -0.844327867F                    // im
    }, { 0.412214756F,                 // re
      -0.809017F                       // im
    }, { 0.362576F,                    // re
      -0.770513237F                    // im
    }, { 0.315452814F,                 // re
      -0.728968561F                    // im
    }, { 0.271031439F,                 // re
      -0.684547186F                    // im
    }, { 0.229486763F,                 // re
      -0.637424F                       // im
    }, { 0.190983F,                    // re
      -0.587785244F                    // im
    }, { 0.155672133F,                 // re
      -0.535826862F                    // im
    }, { 0.123693347F,                 // re
      -0.481753707F                    // im
    }, { 0.0951729417F,                // re
      -0.425779313F                    // im
    }, { 0.0702235103F,                // re
      -0.368124574F                    // im
    }, { 0.04894346F,                  // re
      -0.309017F                       // im
    }, { 0.0314168334F,                // re
      -0.248689905F                    // im
    }, { 0.0177127719F,                // re
      -0.187381327F                    // im
    }, { 0.00788527727F,               // re
      -0.125333235F                    // im
    }, { 0.00197327137F,               // re
      -0.0627905205F                   // im
    }, { 0.0F,                         // re
      -0.0F                            // im
    }, { 0.00197327137F,               // re
      0.0627905205F                    // im
    }, { 0.00788527727F,               // re
      0.125333235F                     // im
    }, { 0.0177127719F,                // re
      0.187381327F                     // im
    }, { 0.0314168334F,                // re
      0.248689905F                     // im
    }, { 0.04894346F,                  // re
      0.309017F                        // im
    }, { 0.0702235103F,                // re
      0.368124574F                     // im
    }, { 0.0951729417F,                // re
      0.425779313F                     // im
    }, { 0.123693347F,                 // re
      0.481753707F                     // im
    }, { 0.155672133F,                 // re
      0.535826862F                     // im
    }, { 0.190983F,                    // re
      0.587785244F                     // im
    }, { 0.229486763F,                 // re
      0.637424F                        // im
    }, { 0.271031439F,                 // re
      0.684547186F                     // im
    }, { 0.315452814F,                 // re
      0.728968561F                     // im
    }, { 0.362576F,                    // re
      0.770513237F                     // im
    }, { 0.412214756F,                 // re
      0.809017F                        // im
    }, { 0.464173138F,                 // re
      0.844327867F                     // im
    }, { 0.518246293F,                 // re
      0.876306653F                     // im
    }, { 0.574220657F,                 // re
      0.904827058F                     // im
    }, { 0.631875396F,                 // re
      0.92977649F                      // im
    }, { 0.690983F,                    // re
      0.95105654F                      // im
    }, { 0.75131011F,                  // re
      0.968583167F                     // im
    }, { 0.812618673F,                 // re
      0.982287228F                     // im
    }, { 0.87466675F,                  // re
      0.992114723F                     // im
    }, { 0.937209487F,                 // re
      0.998026729F                     // im
    } };

  static const int8_T d_0[50]{ 1, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39,
    38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20,
    19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 };

  static const creal32_T reconVar2[50]{ { 1.0F,// re
      1.0F                             // im
    }, { 1.06279051F,                  // re
      0.998026729F                     // im
    }, { 1.12533319F,                  // re
      0.992114723F                     // im
    }, { 1.18738127F,                  // re
      0.982287228F                     // im
    }, { 1.24868989F,                  // re
      0.968583167F                     // im
    }, { 1.30901694F,                  // re
      0.95105654F                      // im
    }, { 1.3681246F,                   // re
      0.92977649F                      // im
    }, { 1.42577934F,                  // re
      0.904827058F                     // im
    }, { 1.48175371F,                  // re
      0.876306653F                     // im
    }, { 1.53582692F,                  // re
      0.844327867F                     // im
    }, { 1.58778524F,                  // re
      0.809017F                        // im
    }, { 1.63742399F,                  // re
      0.770513237F                     // im
    }, { 1.68454719F,                  // re
      0.728968561F                     // im
    }, { 1.72896862F,                  // re
      0.684547186F                     // im
    }, { 1.7705133F,                   // re
      0.637424F                        // im
    }, { 1.80901694F,                  // re
      0.587785244F                     // im
    }, { 1.84432793F,                  // re
      0.535826862F                     // im
    }, { 1.87630665F,                  // re
      0.481753707F                     // im
    }, { 1.90482712F,                  // re
      0.425779313F                     // im
    }, { 1.92977643F,                  // re
      0.368124574F                     // im
    }, { 1.95105648F,                  // re
      0.309017F                        // im
    }, { 1.96858311F,                  // re
      0.248689905F                     // im
    }, { 1.98228717F,                  // re
      0.187381327F                     // im
    }, { 1.99211478F,                  // re
      0.125333235F                     // im
    }, { 1.99802673F,                  // re
      0.0627905205F                    // im
    }, { 2.0F,                         // re
      0.0F                             // im
    }, { 1.99802673F,                  // re
      -0.0627905205F                   // im
    }, { 1.99211478F,                  // re
      -0.125333235F                    // im
    }, { 1.98228717F,                  // re
      -0.187381327F                    // im
    }, { 1.96858311F,                  // re
      -0.248689905F                    // im
    }, { 1.95105648F,                  // re
      -0.309017F                       // im
    }, { 1.92977643F,                  // re
      -0.368124574F                    // im
    }, { 1.90482712F,                  // re
      -0.425779313F                    // im
    }, { 1.87630665F,                  // re
      -0.481753707F                    // im
    }, { 1.84432793F,                  // re
      -0.535826862F                    // im
    }, { 1.80901694F,                  // re
      -0.587785244F                    // im
    }, { 1.7705133F,                   // re
      -0.637424F                       // im
    }, { 1.72896862F,                  // re
      -0.684547186F                    // im
    }, { 1.68454719F,                  // re
      -0.728968561F                    // im
    }, { 1.63742399F,                  // re
      -0.770513237F                    // im
    }, { 1.58778524F,                  // re
      -0.809017F                       // im
    }, { 1.53582692F,                  // re
      -0.844327867F                    // im
    }, { 1.48175371F,                  // re
      -0.876306653F                    // im
    }, { 1.42577934F,                  // re
      -0.904827058F                    // im
    }, { 1.3681246F,                   // re
      -0.92977649F                     // im
    }, { 1.30901694F,                  // re
      -0.95105654F                     // im
    }, { 1.24868989F,                  // re
      -0.968583167F                    // im
    }, { 1.18738127F,                  // re
      -0.982287228F                    // im
    }, { 1.12533319F,                  // re
      -0.992114723F                    // im
    }, { 1.06279051F,                  // re
      -0.998026729F                    // im
    } };

  for (i = 0; i < 64; i++) {
    ju = ((i + 1) << 1) - 2;
    hcostab[i] = b[ju];
    hsintab[i] = c[ju];
    hcostabinv[i] = costabinv[ju];
    hsintabinv[i] = sintabinv[ju];
  }

  for (ju = 0; ju < 50; ju++) {
    i = (ju << 1) + xoffInit;
    temp_re = x[i];
    temp_im = x[i + 1];
    twid_re = wwc[ju + 49].re;
    twid_im = wwc[ju + 49].im;
    ytmp[ju].re = twid_re * temp_re + twid_im * temp_im;
    ytmp[ju].im = twid_re * temp_im - twid_im * temp_re;
  }

  std::memset(&fy[0], 0, sizeof(creal32_T) << 7U);
  iy = 0;
  ju = 0;
  for (i = 0; i < 49; i++) {
    fy[iy] = ytmp[i];
    iy = 128;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
  }

  fy[iy] = ytmp[49];
  for (i = 0; i <= 126; i += 2) {
    temp_re = fy[i + 1].re;
    temp_im = fy[i + 1].im;
    twid_re = fy[i].re;
    twid_im = fy[i].im;
    fy[i + 1].re = twid_re - temp_re;
    fy[i + 1].im = twid_im - temp_im;
    fy[i].re = twid_re + temp_re;
    fy[i].im = twid_im + temp_im;
  }

  ju = 2;
  iy = 4;
  b_k = 32;
  iheight = 125;
  while (b_k > 0) {
    for (j_i = 0; j_i < iheight; j_i += iy) {
      i = j_i + ju;
      temp_re = fy[i].re;
      temp_im = fy[i].im;
      fy[i].re = fy[j_i].re - temp_re;
      fy[i].im = fy[j_i].im - temp_im;
      fy[j_i].re += temp_re;
      fy[j_i].im += temp_im;
    }

    c_istart = 1;
    for (int32_T c_j{b_k}; c_j < 64; c_j += b_k) {
      twid_re = hcostab[c_j];
      twid_im = hsintab[c_j];
      j_i = c_istart;
      c_ihi = c_istart + iheight;
      while (j_i < c_ihi) {
        i = j_i + ju;
        temp_im = fy[i].im;
        ytmp_re_tmp = fy[i].re;
        temp_re = ytmp_re_tmp * twid_re - temp_im * twid_im;
        temp_im = temp_im * twid_re + ytmp_re_tmp * twid_im;
        fy[i].re = fy[j_i].re - temp_re;
        fy[i].im = fy[j_i].im - temp_im;
        fy[j_i].re += temp_re;
        fy[j_i].im += temp_im;
        j_i += iy;
      }

      c_istart++;
    }

    b_k /= 2;
    ju = iy;
    iy += iy;
    iheight -= ju;
  }

  std::memset(&fv[0], 0, sizeof(creal32_T) << 7U);
  iy = 0;
  ju = 0;
  for (i = 0; i < 98; i++) {
    fv[iy] = wwc[i];
    iy = 128;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
  }

  fv[iy] = wwc[98];
  for (i = 0; i <= 126; i += 2) {
    temp_re = fv[i + 1].re;
    temp_im = fv[i + 1].im;
    twid_re = fv[i].re;
    twid_im = fv[i].im;
    fv[i + 1].re = twid_re - temp_re;
    fv[i + 1].im = twid_im - temp_im;
    fv[i].re = twid_re + temp_re;
    fv[i].im = twid_im + temp_im;
  }

  ju = 2;
  iy = 4;
  b_k = 32;
  iheight = 125;
  while (b_k > 0) {
    for (j_i = 0; j_i < iheight; j_i += iy) {
      i = j_i + ju;
      temp_re = fv[i].re;
      temp_im = fv[i].im;
      fv[i].re = fv[j_i].re - temp_re;
      fv[i].im = fv[j_i].im - temp_im;
      fv[j_i].re += temp_re;
      fv[j_i].im += temp_im;
    }

    c_istart = 1;
    for (int32_T c_j{b_k}; c_j < 64; c_j += b_k) {
      twid_re = hcostab[c_j];
      twid_im = hsintab[c_j];
      j_i = c_istart;
      c_ihi = c_istart + iheight;
      while (j_i < c_ihi) {
        i = j_i + ju;
        temp_im = fv[i].im;
        ytmp_re_tmp = fv[i].re;
        temp_re = ytmp_re_tmp * twid_re - temp_im * twid_im;
        temp_im = temp_im * twid_re + ytmp_re_tmp * twid_im;
        fv[i].re = fv[j_i].re - temp_re;
        fv[i].im = fv[j_i].im - temp_im;
        fv[j_i].re += temp_re;
        fv[j_i].im += temp_im;
        j_i += iy;
      }

      c_istart++;
    }

    b_k /= 2;
    ju = iy;
    iy += iy;
    iheight -= ju;
  }

  for (i = 0; i < 128; i++) {
    temp_re = fy[i].re;
    temp_im = fy[i].im;
    twid_re = fv[i].im;
    twid_im = fv[i].re;
    fy[i].re = temp_re * twid_im - temp_im * twid_re;
    fy[i].im = temp_re * twid_re + temp_im * twid_im;
  }

  iy = 0;
  ju = 0;
  for (i = 0; i < 127; i++) {
    fv[iy] = fy[i];
    iy = 128;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
  }

  fv[iy] = fy[127];
  for (i = 0; i <= 126; i += 2) {
    temp_re = fv[i + 1].re;
    temp_im = fv[i + 1].im;
    twid_re = fv[i].re;
    twid_im = fv[i].im;
    fv[i + 1].re = twid_re - temp_re;
    fv[i + 1].im = twid_im - temp_im;
    fv[i].re = twid_re + temp_re;
    fv[i].im = twid_im + temp_im;
  }

  ju = 2;
  iy = 4;
  b_k = 32;
  iheight = 125;
  while (b_k > 0) {
    for (j_i = 0; j_i < iheight; j_i += iy) {
      i = j_i + ju;
      temp_re = fv[i].re;
      temp_im = fv[i].im;
      fv[i].re = fv[j_i].re - temp_re;
      fv[i].im = fv[j_i].im - temp_im;
      fv[j_i].re += temp_re;
      fv[j_i].im += temp_im;
    }

    c_istart = 1;
    for (int32_T c_j{b_k}; c_j < 64; c_j += b_k) {
      twid_re = hcostabinv[c_j];
      twid_im = hsintabinv[c_j];
      j_i = c_istart;
      c_ihi = c_istart + iheight;
      while (j_i < c_ihi) {
        i = j_i + ju;
        temp_im = fv[i].im;
        ytmp_re_tmp = fv[i].re;
        temp_re = ytmp_re_tmp * twid_re - temp_im * twid_im;
        temp_im = temp_im * twid_re + ytmp_re_tmp * twid_im;
        fv[i].re = fv[j_i].re - temp_re;
        fv[i].im = fv[j_i].im - temp_im;
        fv[j_i].re += temp_re;
        fv[j_i].im += temp_im;
        j_i += iy;
      }

      c_istart++;
    }

    b_k /= 2;
    ju = iy;
    iy += iy;
    iheight -= ju;
  }

  for (i = 0; i < 128; i++) {
    fv[i].re *= 0.0078125F;
    fv[i].im *= 0.0078125F;
  }

  for (i = 0; i < 50; i++) {
    twid_re = wwc[i + 49].re;
    twid_im = wwc[i + 49].im;
    temp_re = fv[i + 49].re;
    temp_im = fv[i + 49].im;
    ytmp[i].re = twid_re * temp_re + twid_im * temp_im;
    ytmp[i].im = twid_re * temp_im - twid_im * temp_re;
  }

  for (i = 0; i < 50; i++) {
    real32_T tmp;
    real32_T tmp_0;
    real32_T ytmp_im_tmp;
    int8_T d;
    temp_re = reconVar1[i].re;
    temp_im = reconVar1[i].im;
    d = d_0[i];
    twid_re = reconVar2[i].re;
    twid_im = reconVar2[i].im;
    ytmp_re_tmp = ytmp[d - 1].re;
    ytmp_im_tmp = -ytmp[d - 1].im;
    tmp = ytmp[i].re;
    tmp_0 = ytmp[i].im;
    y[i].re = ((tmp * temp_re - tmp_0 * temp_im) + (ytmp_re_tmp * twid_re -
                ytmp_im_tmp * twid_im)) * 0.5F;
    y[i].im = ((tmp * temp_im + tmp_0 * temp_re) + (ytmp_re_tmp * twid_im +
                ytmp_im_tmp * twid_re)) * 0.5F;
    y[i + 50].re = ((tmp * twid_re - tmp_0 * twid_im) + (ytmp_re_tmp * temp_re -
      ytmp_im_tmp * temp_im)) * 0.5F;
    y[i + 50].im = ((tmp * twid_im + tmp_0 * twid_re) + (ytmp_re_tmp * temp_im +
      ytmp_im_tmp * temp_re)) * 0.5F;
  }
}

real32_T rt_hypotf_snf(real32_T u0, real32_T u1)
{
  real32_T a;
  real32_T b;
  real32_T y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = std::sqrt(a * a + 1.0F) * b;
  } else if (a > b) {
    b /= a;
    y = std::sqrt(b * b + 1.0F) * a;
  } else if (std::isnan(b)) {
    y = (rtNaNF);
  } else {
    y = a * 1.41421354F;
  }

  return y;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void smooth_simu::smooth_simu_merge(int32_T idx[51], real32_T x[51], int32_T
  offset, int32_T np, int32_T nq, int32_T iwork[51], real32_T xwork[51])
{
  if ((np != 0) && (nq != 0)) {
    int32_T iout;
    int32_T offset1;
    int32_T p;
    int32_T q;
    offset1 = np + nq;
    for (q = 0; q < offset1; q++) {
      iout = offset + q;
      iwork[q] = idx[iout];
      xwork[q] = x[iout];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] >= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < offset1) {
          q++;
        } else {
          offset1 = iout - p;
          for (q = p + 1; q <= np; q++) {
            iout = offset1 + q;
            idx[iout] = iwork[q - 1];
            x[iout] = xwork[q - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void smooth_simu::smooth_simu_sort(real32_T x[51], int32_T idx[51])
{
  int32_T iwork[51];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T ib;
  int32_T nNaNs;
  int32_T nNonNaN;
  int32_T perm_0;
  real32_T xwork[51];
  real32_T x4[4];
  real32_T tmp;
  real32_T tmp_0;
  int8_T idx4[4];
  int8_T perm[4];
  std::memset(&idx[0], 0, 51U * sizeof(int32_T));
  x4[0] = 0.0F;
  idx4[0] = 0;
  x4[1] = 0.0F;
  idx4[1] = 0;
  x4[2] = 0.0F;
  idx4[2] = 0;
  x4[3] = 0.0F;
  idx4[3] = 0;
  nNaNs = 0;
  ib = -1;
  for (i = 0; i < 51; i++) {
    if (std::isnan(x[i])) {
      idx[50 - nNaNs] = i + 1;
      xwork[50 - nNaNs] = x[i];
      nNaNs++;
    } else {
      ib++;
      idx4[ib] = static_cast<int8_T>(i + 1);
      x4[ib] = x[i];
      if (ib + 1 == 4) {
        ib = i - nNaNs;
        if (x4[0] >= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (x4[2] >= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        tmp = x4[i3 - 1];
        tmp_0 = x4[i1 - 1];
        if (tmp_0 >= tmp) {
          tmp_0 = x4[i2 - 1];
          if (tmp_0 >= tmp) {
            nNonNaN = i1;
            perm_0 = i2;
            i1 = i3;
            i2 = i4;
          } else if (tmp_0 >= x4[i4 - 1]) {
            nNonNaN = i1;
            perm_0 = i3;
            i1 = i2;
            i2 = i4;
          } else {
            nNonNaN = i1;
            perm_0 = i3;
            i1 = i4;
          }
        } else {
          tmp = x4[i4 - 1];
          if (tmp_0 >= tmp) {
            if (x4[i2 - 1] >= tmp) {
              nNonNaN = i3;
              perm_0 = i1;
              i1 = i2;
              i2 = i4;
            } else {
              nNonNaN = i3;
              perm_0 = i1;
              i1 = i4;
            }
          } else {
            nNonNaN = i3;
            perm_0 = i4;
          }
        }

        idx[ib - 3] = idx4[nNonNaN - 1];
        idx[ib - 2] = idx4[perm_0 - 1];
        idx[ib - 1] = idx4[i1 - 1];
        idx[ib] = idx4[i2 - 1];
        x[ib - 3] = x4[nNonNaN - 1];
        x[ib - 2] = x4[perm_0 - 1];
        x[ib - 1] = x4[i1 - 1];
        x[ib] = x4[i2 - 1];
        ib = -1;
      }
    }
  }

  if (ib + 1 > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    switch (ib + 1) {
     case 1:
      perm[0] = 1;
      break;

     case 2:
      if (x4[0] >= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
      break;

     default:
      if (x4[0] >= x4[1]) {
        if (x4[1] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      break;
    }

    for (i = 0; i <= ib; i++) {
      nNonNaN = perm[i];
      i1 = ((i - nNaNs) - ib) + 50;
      idx[i1] = idx4[nNonNaN - 1];
      x[i1] = x4[nNonNaN - 1];
    }
  }

  i = (nNaNs >> 1) + 51;
  for (nNonNaN = 0; nNonNaN <= i - 52; nNonNaN++) {
    ib = (nNonNaN - nNaNs) + 51;
    i1 = idx[ib];
    idx[ib] = idx[50 - nNonNaN];
    idx[50 - nNonNaN] = i1;
    x[ib] = xwork[50 - nNonNaN];
    x[50 - nNonNaN] = xwork[ib];
  }

  if ((static_cast<uint32_T>(nNaNs) & 1U) != 0U) {
    ib = i - nNaNs;
    x[ib] = xwork[ib];
  }

  std::memset(&iwork[0], 0, 51U * sizeof(int32_T));
  nNonNaN = 51 - nNaNs;
  if (51 - nNaNs > 1) {
    std::memset(&iwork[0], 0, 51U * sizeof(int32_T));
    ib = (51 - nNaNs) >> 2;
    i = 4;
    while (ib > 1) {
      if ((static_cast<uint32_T>(ib) & 1U) != 0U) {
        ib--;
        i1 = i * ib;
        i2 = 51 - (nNaNs + i1);
        if (i2 > i) {
          smooth_simu_merge(idx, x, i1, i, i2 - i, iwork, xwork);
        }
      }

      i2 = i << 1;
      ib >>= 1;
      for (i1 = 0; i1 < ib; i1++) {
        smooth_simu_merge(idx, x, i1 * i2, i, i, iwork, xwork);
      }

      i = i2;
    }

    if (51 - nNaNs > i) {
      smooth_simu_merge(idx, x, 0, i, 51 - (nNaNs + i), iwork, xwork);
    }
  }

  if ((nNaNs > 0) && (51 - nNaNs > 0)) {
    for (i = 0; i < nNaNs; i++) {
      ib = (i - nNaNs) + 51;
      xwork[i] = x[ib];
      iwork[i] = idx[ib];
    }

    for (i = nNonNaN; i >= 1; i--) {
      ib = (nNaNs + i) - 1;
      x[ib] = x[i - 1];
      idx[ib] = idx[i - 1];
    }

    std::memcpy(&x[0], &xwork[0], static_cast<uint32_T>(nNaNs) * sizeof(real32_T));
    std::memcpy(&idx[0], &iwork[0], static_cast<uint32_T>(nNaNs) * sizeof
                (int32_T));
  }
}

// Model step function
void smooth_simu::step()
{
  creal32_T Y[100];
  int32_T iidx[51];
  int32_T a_tmp;
  int32_T b;
  int32_T c_ii;
  int32_T currentInd;
  int32_T windowEnd;
  int32_T windowStart;
  real32_T P2[100];
  real32_T P1[51];
  real32_T h;
  real32_T hsum;
  boolean_T nanMask[100];
  boolean_T hasNaNs;
  boolean_T nanMask_0;
  static const creal32_T wwc[99]{ { 0.998026729F,// re
      0.0627905205F                    // im
    }, { 0.968583167F,                 // re
      0.248689905F                     // im
    }, { 0.844327927F,                 // re
      0.535826802F                     // im
    }, { 0.535826743F,                 // re
      0.844327927F                     // im
    }, { -4.37113883E-8F,              // re
      1.0F                             // im
    }, { -0.637424F,                   // re
      0.770513296F                     // im
    }, { -0.998026729F,                // re
      0.0627902225F                    // im
    }, { -0.637423813F,                // re
      -0.770513356F                    // im
    }, { 0.368124694F,                 // re
      -0.92977643F                     // im
    }, { 1.0F,                         // re
      0.0F                             // im
    }, { 0.24868983F,                  // re
      0.968583167F                     // im
    }, { -0.929776549F,                // re
      0.368124396F                     // im
    }, { -0.368124694F,                // re
      -0.92977643F                     // im
    }, { 0.968583167F,                 // re
      -0.248689815F                    // im
    }, { -4.37113883E-8F,              // re
      1.0F                             // im
    }, { -0.929776371F,                // re
      -0.368124783F                    // im
    }, { 0.770513177F,                 // re
      -0.637424052F                    // im
    }, { 0.0627905F,                   // re
      0.998026729F                     // im
    }, { -0.770513177F,                // re
      -0.637424111F                    // im
    }, { 1.0F,                         // re
      0.0F                             // im
    }, { -0.844328F,                   // re
      0.535826743F                     // im
    }, { 0.535827F,                    // re
      -0.844327807F                    // im
    }, { -0.24868992F,                 // re
      0.968583167F                     // im
    }, { 0.0627905577F,                // re
      -0.998026729F                    // im
    }, { -4.37113883E-8F,              // re
      1.0F                             // im
    }, { 0.0627905577F,                // re
      -0.998026729F                    // im
    }, { -0.24868992F,                 // re
      0.968583167F                     // im
    }, { 0.535827F,                    // re
      -0.844327807F                    // im
    }, { -0.844328F,                   // re
      0.535826743F                     // im
    }, { 1.0F,                         // re
      0.0F                             // im
    }, { -0.770513177F,                // re
      -0.637424111F                    // im
    }, { 0.0627905F,                   // re
      0.998026729F                     // im
    }, { 0.770513177F,                 // re
      -0.637424052F                    // im
    }, { -0.929776371F,                // re
      -0.368124783F                    // im
    }, { -4.37113883E-8F,              // re
      1.0F                             // im
    }, { 0.968583167F,                 // re
      -0.248689815F                    // im
    }, { -0.368124694F,                // re
      -0.92977643F                     // im
    }, { -0.929776549F,                // re
      0.368124396F                     // im
    }, { 0.24868983F,                  // re
      0.968583167F                     // im
    }, { 1.0F,                         // re
      0.0F                             // im
    }, { 0.368124694F,                 // re
      -0.92977643F                     // im
    }, { -0.637423813F,                // re
      -0.770513356F                    // im
    }, { -0.998026729F,                // re
      0.0627902225F                    // im
    }, { -0.637424F,                   // re
      0.770513296F                     // im
    }, { -4.37113883E-8F,              // re
      1.0F                             // im
    }, { 0.535826743F,                 // re
      0.844327927F                     // im
    }, { 0.844327927F,                 // re
      0.535826802F                     // im
    }, { 0.968583167F,                 // re
      0.248689905F                     // im
    }, { 0.998026729F,                 // re
      0.0627905205F                    // im
    }, { 1.0F,                         // re
      0.0F                             // im
    }, { 0.998026729F,                 // re
      0.0627905205F                    // im
    }, { 0.968583167F,                 // re
      0.248689905F                     // im
    }, { 0.844327927F,                 // re
      0.535826802F                     // im
    }, { 0.535826743F,                 // re
      0.844327927F                     // im
    }, { -4.37113883E-8F,              // re
      1.0F                             // im
    }, { -0.637424F,                   // re
      0.770513296F                     // im
    }, { -0.998026729F,                // re
      0.0627902225F                    // im
    }, { -0.637423813F,                // re
      -0.770513356F                    // im
    }, { 0.368124694F,                 // re
      -0.92977643F                     // im
    }, { 1.0F,                         // re
      0.0F                             // im
    }, { 0.24868983F,                  // re
      0.968583167F                     // im
    }, { -0.929776549F,                // re
      0.368124396F                     // im
    }, { -0.368124694F,                // re
      -0.92977643F                     // im
    }, { 0.968583167F,                 // re
      -0.248689815F                    // im
    }, { -4.37113883E-8F,              // re
      1.0F                             // im
    }, { -0.929776371F,                // re
      -0.368124783F                    // im
    }, { 0.770513177F,                 // re
      -0.637424052F                    // im
    }, { 0.0627905F,                   // re
      0.998026729F                     // im
    }, { -0.770513177F,                // re
      -0.637424111F                    // im
    }, { 1.0F,                         // re
      0.0F                             // im
    }, { -0.844328F,                   // re
      0.535826743F                     // im
    }, { 0.535827F,                    // re
      -0.844327807F                    // im
    }, { -0.24868992F,                 // re
      0.968583167F                     // im
    }, { 0.0627905577F,                // re
      -0.998026729F                    // im
    }, { -4.37113883E-8F,              // re
      1.0F                             // im
    }, { 0.0627905577F,                // re
      -0.998026729F                    // im
    }, { -0.24868992F,                 // re
      0.968583167F                     // im
    }, { 0.535827F,                    // re
      -0.844327807F                    // im
    }, { -0.844328F,                   // re
      0.535826743F                     // im
    }, { 1.0F,                         // re
      0.0F                             // im
    }, { -0.770513177F,                // re
      -0.637424111F                    // im
    }, { 0.0627905F,                   // re
      0.998026729F                     // im
    }, { 0.770513177F,                 // re
      -0.637424052F                    // im
    }, { -0.929776371F,                // re
      -0.368124783F                    // im
    }, { -4.37113883E-8F,              // re
      1.0F                             // im
    }, { 0.968583167F,                 // re
      -0.248689815F                    // im
    }, { -0.368124694F,                // re
      -0.92977643F                     // im
    }, { -0.929776549F,                // re
      0.368124396F                     // im
    }, { 0.24868983F,                  // re
      0.968583167F                     // im
    }, { 1.0F,                         // re
      0.0F                             // im
    }, { 0.368124694F,                 // re
      -0.92977643F                     // im
    }, { -0.637423813F,                // re
      -0.770513356F                    // im
    }, { -0.998026729F,                // re
      0.0627902225F                    // im
    }, { -0.637424F,                   // re
      0.770513296F                     // im
    }, { -4.37113883E-8F,              // re
      1.0F                             // im
    }, { 0.535826743F,                 // re
      0.844327927F                     // im
    }, { 0.844327927F,                 // re
      0.535826802F                     // im
    }, { 0.968583167F,                 // re
      0.248689905F                     // im
    }, { 0.998026729F,                 // re
      0.0627905205F                    // im
    } };

  static const real32_T costabinv[129]{ 1.0F, 0.999698818F, 0.99879545F,
    0.997290432F, 0.99518472F, 0.992479563F, 0.989176512F, 0.985277653F,
    0.980785251F, 0.975702107F, 0.970031261F, 0.963776052F, 0.956940353F,
    0.949528158F, 0.941544056F, 0.932992816F, 0.923879504F, 0.914209723F,
    0.903989315F, 0.893224299F, 0.881921232F, 0.870086968F, 0.857728601F,
    0.84485358F, 0.831469595F, 0.817584813F, 0.803207517F, 0.78834641F,
    0.773010433F, 0.757208824F, 0.740951121F, 0.724247098F, 0.707106769F,
    0.689540565F, 0.671559F, 0.653172851F, 0.634393334F, 0.615231633F,
    0.59569931F, 0.575808227F, 0.555570245F, 0.534997642F, 0.514102757F,
    0.492898226F, 0.471396744F, 0.449611336F, 0.427555084F, 0.40524134F,
    0.382683456F, 0.359895051F, 0.336889863F, 0.313681751F, 0.290284663F,
    0.266712785F, 0.242980197F, 0.219101235F, 0.195090324F, 0.170961902F,
    0.146730468F, 0.122410677F, 0.0980171412F, 0.0735645667F, 0.0490676761F,
    0.024541229F, 0.0F, -0.024541229F, -0.0490676761F, -0.0735645667F,
    -0.0980171412F, -0.122410677F, -0.146730468F, -0.170961902F, -0.195090324F,
    -0.219101235F, -0.242980197F, -0.266712785F, -0.290284663F, -0.313681751F,
    -0.336889863F, -0.359895051F, -0.382683456F, -0.40524134F, -0.427555084F,
    -0.449611336F, -0.471396744F, -0.492898226F, -0.514102757F, -0.534997642F,
    -0.555570245F, -0.575808227F, -0.59569931F, -0.615231633F, -0.634393334F,
    -0.653172851F, -0.671559F, -0.689540565F, -0.707106769F, -0.724247098F,
    -0.740951121F, -0.757208824F, -0.773010433F, -0.78834641F, -0.803207517F,
    -0.817584813F, -0.831469595F, -0.84485358F, -0.857728601F, -0.870086968F,
    -0.881921232F, -0.893224299F, -0.903989315F, -0.914209723F, -0.923879504F,
    -0.932992816F, -0.941544056F, -0.949528158F, -0.956940353F, -0.963776052F,
    -0.970031261F, -0.975702107F, -0.980785251F, -0.985277653F, -0.989176512F,
    -0.992479563F, -0.99518472F, -0.997290432F, -0.99879545F, -0.999698818F,
    -1.0F };

  static const real32_T sintabinv[129]{ 0.0F, 0.024541229F, 0.0490676761F,
    0.0735645667F, 0.0980171412F, 0.122410677F, 0.146730468F, 0.170961902F,
    0.195090324F, 0.219101235F, 0.242980197F, 0.266712785F, 0.290284663F,
    0.313681751F, 0.336889863F, 0.359895051F, 0.382683456F, 0.40524134F,
    0.427555084F, 0.449611336F, 0.471396744F, 0.492898226F, 0.514102757F,
    0.534997642F, 0.555570245F, 0.575808227F, 0.59569931F, 0.615231633F,
    0.634393334F, 0.653172851F, 0.671559F, 0.689540565F, 0.707106769F,
    0.724247098F, 0.740951121F, 0.757208824F, 0.773010433F, 0.78834641F,
    0.803207517F, 0.817584813F, 0.831469595F, 0.84485358F, 0.857728601F,
    0.870086968F, 0.881921232F, 0.893224299F, 0.903989315F, 0.914209723F,
    0.923879504F, 0.932992816F, 0.941544056F, 0.949528158F, 0.956940353F,
    0.963776052F, 0.970031261F, 0.975702107F, 0.980785251F, 0.985277653F,
    0.989176512F, 0.992479563F, 0.99518472F, 0.997290432F, 0.99879545F,
    0.999698818F, 1.0F, 0.999698818F, 0.99879545F, 0.997290432F, 0.99518472F,
    0.992479563F, 0.989176512F, 0.985277653F, 0.980785251F, 0.975702107F,
    0.970031261F, 0.963776052F, 0.956940353F, 0.949528158F, 0.941544056F,
    0.932992816F, 0.923879504F, 0.914209723F, 0.903989315F, 0.893224299F,
    0.881921232F, 0.870086968F, 0.857728601F, 0.84485358F, 0.831469595F,
    0.817584813F, 0.803207517F, 0.78834641F, 0.773010433F, 0.757208824F,
    0.740951121F, 0.724247098F, 0.707106769F, 0.689540565F, 0.671559F,
    0.653172851F, 0.634393334F, 0.615231633F, 0.59569931F, 0.575808227F,
    0.555570245F, 0.534997642F, 0.514102757F, 0.492898226F, 0.471396744F,
    0.449611336F, 0.427555084F, 0.40524134F, 0.382683456F, 0.359895051F,
    0.336889863F, 0.313681751F, 0.290284663F, 0.266712785F, 0.242980197F,
    0.219101235F, 0.195090324F, 0.170961902F, 0.146730468F, 0.122410677F,
    0.0980171412F, 0.0735645667F, 0.0490676761F, 0.024541229F, 0.0F };

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Inport: '<Root>/u'

  hasNaNs = false;
  for (windowStart = 0; windowStart < 100; windowStart++) {
    nanMask_0 = std::isnan(smooth_simu_U.u[windowStart]);
    nanMask[windowStart] = nanMask_0;
    if (!hasNaNs) {
      hasNaNs = nanMask_0;
    }
  }

  windowStart = -1;
  windowEnd = 1;
  for (currentInd = 0; currentInd < 100; currentInd++) {
    while ((windowStart + 2 < currentInd + 1) && ((static_cast<real_T>
             (currentInd) + 1.0) - 1.5 > static_cast<real_T>(windowStart + 1) +
            1.0)) {
      windowStart++;
    }

    if (windowEnd < currentInd + 1) {
      windowEnd = currentInd + 1;
    }

    while ((windowEnd < 100) && (static_cast<real_T>(windowEnd) + 1.0 < (
             static_cast<real_T>(currentInd) + 1.0) + 1.5)) {
      windowEnd++;
    }

    P2[currentInd] = 0.0F;
    hsum = 0.0F;
    b = windowEnd - windowStart;
    for (c_ii = 0; c_ii <= b - 2; c_ii++) {
      if ((!hasNaNs) || (!nanMask[(c_ii + windowStart) + 1])) {
        a_tmp = (c_ii + windowStart) + 1;
        h = (((static_cast<real32_T>(currentInd) + 1.0F) - 1.0F) + 1.0F) -
          static_cast<real32_T>(static_cast<real_T>(a_tmp) + 1.0);
        h = std::exp(-(h * h) / 0.72F);
        P2[currentInd] += smooth_simu_U.u[a_tmp] * h;
        hsum += h;
      }
    }

    if (hsum != 0.0F) {
      P2[currentInd] /= hsum;
    } else {
      P2[currentInd] = (rtNaNF);
    }
  }

  FFTImplementationCallback_doHal(P2, 0, Y, wwc, costabinv, sintabinv);
  for (windowStart = 0; windowStart < 100; windowStart++) {
    h = Y[windowStart].re;
    hsum = Y[windowStart].im;
    if (hsum == 0.0F) {
      h /= 100.0F;
      hsum = 0.0F;
    } else if (h == 0.0F) {
      h = 0.0F;
      hsum /= 100.0F;
    } else {
      h /= 100.0F;
      hsum /= 100.0F;
    }

    Y[windowStart].re = h;
    Y[windowStart].im = hsum;
    P2[windowStart] = rt_hypotf_snf(h, hsum);
  }

  std::memcpy(&P1[0], &P2[0], 51U * sizeof(real32_T));
  for (windowStart = 0; windowStart < 49; windowStart++) {
    P1[windowStart + 1] = P2[windowStart + 1] * 2.0F;
  }

  smooth_simu_sort(P1, iidx);

  // Outport: '<Root>/Out1' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function'

  smooth_simu_Y.Out1 = static_cast<real_T>(iidx[1] - 1) * 0.25 * 60.0;
}

// Model initialize function
void smooth_simu::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void smooth_simu::terminate()
{
  // (no terminate code required)
}

// Constructor
smooth_simu::smooth_simu() :
  smooth_simu_U(),
  smooth_simu_Y(),
  smooth_simu_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
smooth_simu::~smooth_simu() = default;

// Real-Time Model get method
smooth_simu::RT_MODEL_smooth_simu_T * smooth_simu::getRTM()
{
  return (&smooth_simu_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
