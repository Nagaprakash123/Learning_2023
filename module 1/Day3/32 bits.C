#include <stdio.h>

void print_bits(unsigned int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        unsigned int mask = 1 << i;
        int bit = (num & mask) ? 1 : 0;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);
    printf("Binary representation: ");
    print_bits(num);
    return 0;
}