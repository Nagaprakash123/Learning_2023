#include <stdio.h>

struct Complex {
    double real;
    double imag;
};

void readComplex(struct Complex* num) {
    printf("Enter the real part: ");
    scanf("%lf", &num->real);

    printf("Enter the imaginary part: ");
    scanf("%lf", &num->imag);
}

void writeComplex(struct Complex* num) {
    printf("Complex Number: %.2lf + %.2lfi\n", num->real, num->imag);
}

struct Complex addComplex(struct Complex* num1, struct Complex* num2) {
    struct Complex sum;
    sum.real = num1->real + num2->real;
    sum.imag = num1->imag + num2->imag;
    return sum;
}

struct Complex multiplyComplex(struct Complex* num1, struct Complex* num2) {
    struct Complex product;
    product.real = num1->real * num2->real - num1->imag * num2->imag;
    product.imag = num1->real * num2->imag + num1->imag * num2->real;
    return product;
}

int main() {
    struct Complex num1, num2;

    printf("Enter the first complex number:\n");
    readComplex(&num1);

    printf("Enter the second complex number:\n");
    readComplex(&num2);

    printf("\n");

    printf("First Complex Number:\n");
    writeComplex(&num1);

    printf("Second Complex Number:\n");
    writeComplex(&num2);

    struct Complex sum = addComplex(&num1, &num2);
    printf("Sum of the two complex numbers:\n");
    writeComplex(&sum);

    struct Complex product = multiplyComplex(&num1, &num2);
    printf("Product of the two complex numbers:\n");
    writeComplex(&product);

    return 0;
}