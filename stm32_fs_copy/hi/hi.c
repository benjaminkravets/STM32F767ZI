#include <stdio.h>

int main() {
  int a = 0b10000001;
  int b = 0b10000000;

  printf("%i \r\n", a & b);
}
