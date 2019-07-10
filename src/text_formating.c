#include "../libs/text_formating.h"

const char *get_string_format() {
  return (const char *)"%s\n"; 
}

const char *get_decimal_format() {
  return (const char *)"%7s | $%05.2f\n";
}

const char *get_integer_format() {
  return (const char*)"%7s | %.2d\n";
}

const char *get_bar_string() {
  return (const char *)"**********************************************************";
}