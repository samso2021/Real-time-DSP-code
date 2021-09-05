/*
 * Experiment interpolation using FIR filter - Chapter 3
 * coef16to48.h
 *
 * Description: This is the filter coefficient file for 1:3 interpolation filter
 *
 *  Created on: May 13, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */
#define Q14 16384

Int16 intpFilt16to48[TAPS16to48]={
   (Int16)(0.00039118664405*Q14),
   (Int16)(0.00082887856876*Q14),
   (Int16)(0.00046149067793*Q14),
  (Int16)(-0.00053443800873*Q14),
  (Int16)(-0.00127090672785*Q14),
  (Int16)(-0.00076680271122*Q14),
   (Int16)(0.00093087132468*Q14),
   (Int16)(0.00226039470832*Q14),
   (Int16)(0.00136751576621*Q14),
  (Int16)(-0.00164581562180*Q14),
  (Int16)(-0.00393682937999*Q14),
  (Int16)(-0.00233905686437*Q14),
   (Int16)(0.00276203996319*Q14),
   (Int16)(0.00648476917221*Q14),
   (Int16)(0.00378605929813*Q14),
  (Int16)(-0.00440028437749*Q14),
  (Int16)(-0.01018789426309*Q14),
  (Int16)(-0.00587817880848*Q14),
   (Int16)(0.00676717072570*Q14),
   (Int16)(0.01555870645702*Q14),
   (Int16)(0.00893914020410*Q14),
  (Int16)(-0.01027958290569*Q14),
  (Int16)(-0.02369307751794*Q14),
  (Int16)(-0.01370547087789*Q14),
   (Int16)(0.01595304413635*Q14),
   (Int16)(0.03747598782261*Q14),
   (Int16)(0.02230125272300*Q14),
  (Int16)(-0.02705984402456*Q14),
  (Int16)(-0.06760524896123*Q14),
  (Int16)(-0.04422157068449*Q14),
   (Int16)(0.06271813348156*Q14),
   (Int16)(0.21086994722652*Q14),
   (Int16)(0.31766841283448*Q14),
   (Int16)(0.31766841283448*Q14),
   (Int16)(0.21086994722652*Q14),
   (Int16)(0.06271813348156*Q14),
  (Int16)(-0.04422157068449*Q14),
  (Int16)(-0.06760524896123*Q14),
  (Int16)(-0.02705984402456*Q14),
   (Int16)(0.02230125272300*Q14),
   (Int16)(0.03747598782261*Q14),
   (Int16)(0.01595304413635*Q14),
  (Int16)(-0.01370547087789*Q14),
  (Int16)(-0.02369307751794*Q14),
  (Int16)(-0.01027958290569*Q14),
   (Int16)(0.00893914020410*Q14),
   (Int16)(0.01555870645702*Q14),
   (Int16)(0.00676717072570*Q14),
  (Int16)(-0.00587817880848*Q14),
  (Int16)(-0.01018789426309*Q14),
  (Int16)(-0.00440028437749*Q14),
   (Int16)(0.00378605929813*Q14),
   (Int16)(0.00648476917221*Q14),
   (Int16)(0.00276203996319*Q14),
  (Int16)(-0.00233905686437*Q14),
  (Int16)(-0.00393682937999*Q14),
  (Int16)(-0.00164581562180*Q14),
   (Int16)(0.00136751576621*Q14),
   (Int16)(0.00226039470832*Q14),
   (Int16)(0.00093087132468*Q14),
  (Int16)(-0.00076680271122*Q14),
  (Int16)(-0.00127090672785*Q14),
  (Int16)(-0.00053443800873*Q14),
   (Int16)(0.00046149067793*Q14),
   (Int16)(0.00082887856876*Q14),
   (Int16)(0.00039118664405*Q14)
};