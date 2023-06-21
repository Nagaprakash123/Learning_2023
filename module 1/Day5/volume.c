#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box* box) {
    return box->length * box->width * box->height;
}

double calculateSurfaceArea(struct Box* box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {

    struct Box myBox = { 5.0, 3.0, 2.0 };

    struct Box* ptrBox = &myBox;

    double volume = (*ptrBox).length * (*ptrBox).width * (*ptrBox).height;
    double surfaceArea = 2 * ((*ptrBox).length * (*ptrBox).width + (*ptrBox).length * (*ptrBox).height + (*ptrBox).width * (*ptrBox).height);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    volume = ptrBox->length * ptrBox->width * ptrBox->height;
    surfaceArea = 2 * (ptrBox->length * ptrBox->width + ptrBox->length * ptrBox->height + ptrBox->width * ptrBox->height);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}