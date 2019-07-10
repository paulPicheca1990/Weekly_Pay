#include <stdio.h>
#include "./libs/weekly_pay_t.h"
#include "./libs/text_formating.h"

void print_weekly_pay(WEEKLY_PAY_t weekly_pay) {
  printf(get_string_format(), get_bar_string());
  printf(get_string_format(), "> Weekly Pay" );
  printf(get_string_format(), get_bar_string());
  printf(get_integer_format(), "Hours", weekly_pay.hours);
  printf(get_decimal_format(), "Gross", weekly_pay.pay.gross);
  printf(get_decimal_format(), "Taxes", weekly_pay.pay.taxes);
  printf(get_decimal_format(), "Net", weekly_pay.pay.net);
}

int main( int argc, char *argv[] ) {
  int hours;
  printf("Please enter the amount of hours worked: ");
  scanf("%d", &hours);
  
  WEEKLY_PAY_t weekly_pay = Determine_Weekly_Pay(hours);
  print_weekly_pay(weekly_pay);
}