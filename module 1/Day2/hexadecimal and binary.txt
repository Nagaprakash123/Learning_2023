#include <stdio.h>
#include <stdint.h>

void print_exponent_parts(double x) {
    uint64_t bits;
    memcpy(&bits, &x, sizeof(bits));
    uint64_t exponent = (bits >> 52) & 0x7FF;
    char hex_exponent[16];
    sprintf(hex_exponent, "0x%llX", exponent);
    char binary_exponent[13];
    sprintf(binary_exponent, "0b%.11llb", exponent);
    printf("Exponent in hexadecimal: %s\n", hex_exponent);
    printf("Exponent in binary: %s\n", binary_exponent);
}

int main() {
    double x = 0.7;
    print_exponent_parts(x);
    return 0;
}
