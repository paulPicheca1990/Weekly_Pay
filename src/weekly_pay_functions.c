#include "../libs/weekly_pay_functions.h"
#include <stdio.h>
int calculate_overtime_hours( int hours ) {
  if( ( hours - OVERTIME_HOURS_THRESHOLD ) <= 0 )
    return 0;  

  int overtime; 
  overtime = ( ( hours - OVERTIME_HOURS_THRESHOLD ) + OVERTIME_HOURS_THRESHOLD ) % OVERTIME_HOURS_THRESHOLD;
  overtime += ( ( hours - OVERTIME_HOURS_THRESHOLD ) / OVERTIME_HOURS_THRESHOLD ) * OVERTIME_HOURS_THRESHOLD;  
  
  return overtime;
}

double calculate_overtime_pay( int hours ) {
  int overtime = calculate_overtime_hours(hours);
  return (double)overtime * (BASIC_PAY_RATE_PER_HOUR * OVERTIME_RATE_SCALER);
}

double calculate_regular_pay( int hours ) {
  return 
    ( hours <= OVERTIME_HOURS_THRESHOLD ) ? 
      (double)hours * BASIC_PAY_RATE_PER_HOUR : 
      (double)OVERTIME_HOURS_THRESHOLD * BASIC_PAY_RATE_PER_HOUR;
}

double calculate_taxes( double gross_pay ) {
  double taxes = 0.00;

  if( gross_pay <= FIRST_TAX_BRACKET_AMOUNT ) {
    taxes = gross_pay * FIRST_TAX_BRACKET_RATE;
  } else if ( gross_pay > FIRST_TAX_BRACKET_AMOUNT && gross_pay <= ( FIRST_TAX_BRACKET_AMOUNT + SECOND_TAX_BRACKET_AMOUNT ) ) {    
    taxes = FIRST_TAX_BRACKET_AMOUNT * FIRST_TAX_BRACKET_RATE;
    taxes += ( gross_pay - FIRST_TAX_BRACKET_AMOUNT ) * SECOND_TAX_BRACKET_RATE;    
  } else {
    taxes = FIRST_TAX_BRACKET_AMOUNT * FIRST_TAX_BRACKET_RATE; 
    taxes += SECOND_TAX_BRACKET_AMOUNT * SECOND_TAX_BRACKET_RATE;
    taxes += ( gross_pay - SECOND_TAX_BRACKET_AMOUNT - FIRST_TAX_BRACKET_AMOUNT) * THIRD_TAX_BRACKET_RATE;                        
  }
  
  return taxes;
}