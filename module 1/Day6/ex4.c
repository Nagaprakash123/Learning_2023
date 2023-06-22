#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int compareStudents(const void* a, const void* b) {
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;

    if (studentA->marks < studentB->marks) {
        return 1;
    } else if (studentA->marks > studentB->marks) {
        return -1;
    }

    return 0;
}

void displayStudents(const struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    const int numStudents = 5;

    struct Student students[numStudents];

    students[0].rollno = 1001;
    strncpy(students[0].name, "naga", sizeof(students[0].name));
    students[0].marks = 100.0;

    students[1].rollno = 1002;
    strncpy(students[1].name, "prakash", sizeof(students[1].name));
    students[1].marks = 95.5;

    students[2].rollno = 1003;
    strncpy(students[2].name, "iswarya", sizeof(students[2].name));
    students[2].marks = 87.0;

    students[3].rollno = 1004;
    strncpy(students[3].name, "vishnu", sizeof(students[3].name));
    students[3].marks = 92.5;

    students[4].rollno = 1005;
    strncpy(students[4].name, "rithik", sizeof(students[4].name));
    students[4].marks = 88.75;

    printf("Before sorting:\n");
    displayStudents(students, numStudents);

    qsort(students, numStudents, sizeof(struct Student), compareStudents);

    printf("After sorting in descending order based on marks:\n");
    displayStudents(students, numStudents);

    return 0;
}