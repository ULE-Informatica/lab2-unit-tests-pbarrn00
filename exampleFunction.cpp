#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>

extern size_t popcount(uintmax_t);
#define PRECISION(x) popcount(x)

/**
 * 
*/
unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum;
  if (UINT_MAX - ui_a < ui_b) {
    /* Handle error */
    printf("Error: wrapFunctionAdd Overflow!");
    return -1;
  } else {
    usum = ui_a + ui_b;
  }
  
  return usum;
}

/**
 * 
*/
unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  unsigned umul = ui_a;

  if(ui_a == 0 || ui_b == 0){
    return 0;
  }

  if(UINT_MAX / ui_a < ui_b){
    /* Handle error */
    printf("Error: wrapFunctionMul Overflow!");
    return -1;
  }else {
    umul *= ui_b;
  }  

  return umul;
}

/**
 * 
*/
uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
  uint32_t uShift = 0;

  if (ui_b >= PRECISION(UINT_MAX)) {
    /* Handle error */
    printf("Error: wrapFunctionShift wrapping!");
  } else {
    uShift = ui_a << ui_b | ui_a >> (32 - ui_b);  /* (32 - unsigned int) = uint32_t  ???*/
  }

  return uShift;
}
