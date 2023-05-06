#include <stdio.h>
#include <string.h>

struct Student
{
    char name[100];
    int age;
    char class[10];
    char semester[10];
};

int main()
{
    struct Student s1;
    strcpy(s1.name, "Rahul");
    strcpy(s1.semester, "II");
    strcpy(s1.class, "C2");
    s1.age = 21;

    printf("Student 1 name : %s\n", s1.name);
    printf("Student 1 age : %d\n", s1.age);
    printf("Student 1 class : %s\n", s1.class);
    printf("Student 1 semester : %s\n\n", s1.semester);

    struct Student s2;
    strcpy(s2.name, "Andrew");
    strcpy(s2.semester, "IV");
    strcpy(s2.class, "B2");
    s2.age = 22;

    printf("Student 2 name : %s\n", s2.name);
    printf("Student 2 age : %d\n", s2.age);
    printf("Student 2 class : %s\n", s2.class);
    printf("Student 2 semester : %s\n", s2.semester);

    return 0;
}