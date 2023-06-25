#include <stdio.h>

int find_greatest(int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

char calculate_grade(int score) {
    char grade;
    
    if (score >= 90)
        grade = 'A';
    else if (score >= 75)
        grade = 'B';
    else if (score >= 60)
        grade = 'C';
    else if (score >= 50)
        grade = 'D';
    else if (score >= 36)
        grade = 'E';
    else
        grade = 'F';

    return grade;
}

int main() {
    int score = 65;
    char grade = calculate_grade(score);

    switch (grade) {
        case 'A':
            printf("Grade A\n");
            break;
        case 'B':
            printf("Grade B\n");
            break;
        case 'C':
            printf("Grade C\n");
            break;
        case 'D':
            printf("Grade D\n");
            break;
        case 'E':
            printf("Grade E\n");
            break;
        default:
            printf("Grade F\n");
            break;
    }

    return 0;
}