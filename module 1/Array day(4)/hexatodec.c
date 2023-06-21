/// convert binary to decimal

#include <stdio.h>
#include <math.h>

// function prototype
int convert(long long);

int main() {
  long long n;
  printf("Enter a binary number: ");
  scanf("%lld", &n);
  printf("%lld in binary = %d in decimal", n, convert(n));
  return 0;
}
// function definition
int convert(long long n) {
  int hex = 0, i = 0, rem;

  while (n>0) {
    rem = n % 10;
    n /= 10;
    hex += rem * pow(16, i);
    ++i;
  }

  return hex;
}