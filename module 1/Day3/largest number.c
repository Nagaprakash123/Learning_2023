#include <stdio.h>

int find_largest_number(int num) {
    char num_str[5];
    sprintf(num_str, "%d", num);
    int max_num = 0;

    for (int i = 0; i < 4; i++) {
        char new_num_str[4];
        int index = 0;

        for (int j = 0; j < 4; j++) {
            if (j != i) {
                new_num_str[index] = num_str[j];
                index++;
            }
        }

        new_num_str[index] = '\0';
        int new_num = atoi(new_num_str);
        if (new_num > max_num) {
            max_num = new_num;
        }
    }

    return max_num;
}

int main() {
    int number;
    printf("Enter a four-digit number: ");
    scanf("%d", &number);

    int largest_number = find_largest_number(number);

    printf("The largest number obtained by deleting a single digit from %d is %d.\n", number, largest_number);

    return 0;
}