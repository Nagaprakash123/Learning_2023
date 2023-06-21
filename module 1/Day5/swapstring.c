#include <stdio.h>
#include <string.h>

struct people {
    char name[100];
    int age;
};

void swapFields(struct people* person1, struct people* person2) {
    struct people temp;

    strcpy(temp.name, person1->name);
    strcpy(person1->name, person2->name);
    strcpy(person2->name, temp.name);

    int tempAge = person1->age;
    person1->age = person2->age;
    person2->age = tempAge;
}

int main() {
    struct people person1 = { "naga", 25 };
    struct people person2 = { "prakash", 30 };

    printf("Before swapping:\n");
    printf("%s %d\n", person1.name, person1.age);
    printf("%s %d\n", person2.name, person2.age);

    swapFields(&person1, &person2);

    printf("\nAfter swapping:\n");
    printf("%s %d\n", person1.name, person1.age);
    printf("%s %d\n", person2.name, person2.age);

    return 0;
}