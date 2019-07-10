#include "../libs/weekly_pay_t.h"

WEEKLY_PAY_t WEEKLY_PAY_T() {    
  int defaultInt = 0;  
  return (WEEKLY_PAY_t){ defaultInt, PAYMENT_T() };
}

WEEKLY_PAY_t Determine_Weekly_Pay( int hours ) {
  WEEKLY_PAY_t weekly_pay = WEEKLY_PAY_T();

  if( hours <= weekly_pay.hours )
    return weekly_pay;

  weekly_pay.hours = hours;
  weekly_pay.pay = Calculate_Weekly_Pay(hours);

  return weekly_pay;
}