#include <stdio.h>
#include <ctype.h>

int findCharType(char ch) {
    if (isupper(ch)) {
        return 1; // Uppercase letters (A-Z)
    } else if (islower(ch)) {
        return 2; // Lowercase letters (a-z)
    } else if (isdigit(ch)) {
        return 3; // Digits (0-9)
    } else if (isgraph(ch)) {
        return 4; // Any other printable symbols
    } else {
        return 5; // Non-printable symbols
    }
}

int main() {
    char character;
    printf("Enter a character: ");
    scanf("%c", &character);
    int type = findCharType(character);
    switch (type) {
        case 1:
            printf("Uppercase letter\n");
            break;
        case 2:
            printf("Lowercase letter\n");
            break;
        case 3:
            printf("Digit\n");
            break;
        case 4:
            printf("Other printable symbol\n");
            break;
        case 5:
            printf("Non-printable symbol\n");
            break;
        default:
            printf("Invalid input\n");
            break;
    }
    return 0;
}