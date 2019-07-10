#include "../libs/payment_t.h"

PAYMENT_t PAYMENT_T() {
  double defaultCurrency = 0.00;  
  return (PAYMENT_t) {defaultCurrency, defaultCurrency, defaultCurrency};
}

PAYMENT_t Calculate_Weekly_Pay( int hours ) {
  PAYMENT_t payment = PAYMENT_T();

  if( hours <= 0.00 )
    return payment;
  
  payment.gross = calculate_overtime_pay(hours) + calculate_regular_pay(hours);  
  payment.taxes = calculate_taxes(payment.gross);
  payment.net = payment.gross - payment.taxes;
  
  return payment;
}