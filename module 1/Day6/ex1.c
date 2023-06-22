#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseStringAndInitializeStructs(const char* inputString, struct Student* students, int numStudents) {
    char tempName[20];
    float tempMarks;

    sscanf(inputString, "%d %s %f", &students->rollno, tempName, &tempMarks);
    strncpy(students->name, tempName, sizeof(students->name) - 1);
    students->name[sizeof(students->name) - 1] = '\0';
    students->marks = tempMarks;
}

int main() {
    const int numStudents = 1;
    const char* inputString = "1001 Aron 100.00";

    struct Student students[numStudents];
    parseStringAndInitializeStructs(inputString, students, numStudents);

    for (int i = 0; i < numStudents; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}