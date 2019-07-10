#ifndef __WEEKLY_PAY_T_H__
#define __WEEKLY_PAY_T_H__

#include "payment_t.h"

typedef struct _WEEKLY_PAY_t {
  int hours;
  PAYMENT_t pay;  
} WEEKLY_PAY_t;

WEEKLY_PAY_t WEEKLY_PAY_T();

WEEKLY_PAY_t Determine_Weekly_Pay( int hours );

#endif