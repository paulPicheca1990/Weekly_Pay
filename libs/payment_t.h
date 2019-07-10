#ifndef __PAYMENT_T_H__
#define __PAYMENT_T_H__

#include "weekly_pay_functions.h"

typedef struct _PAYMENT_t {  
  double gross;
  double taxes;
  double net;
} PAYMENT_t;

PAYMENT_t PAYMENT_T();

PAYMENT_t Calculate_Weekly_Pay( int hours );

#endif