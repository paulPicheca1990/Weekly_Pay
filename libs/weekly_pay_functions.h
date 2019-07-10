#ifndef __WEEKLY_PAY_FUNCTIONS_H__
#define __WEEKLY_PAY_FUNCTIONS_H__

#include "../libs/weekly_pay_constants.h"

int calculate_overtime_hours( int hours );

double calculate_overtime_pay( int hours );

double calculate_regular_pay( int hours );

double calculate_taxes( double gross_pay );

#endif