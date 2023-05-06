#include <stdio.h>
#include <stdlib.h>

int main()

{

    char name[50];
    int marks;
    int n;
    char buffer[32] = {0};

    printf("Enter number of students: ");
    scanf("%d", &n);

    FILE *studentRecord;

    //open file in write mode
    studentRecord = fopen("studentrecord.txt", "w");
    if (studentRecord == NULL)
    {
        printf("Please create file\n");
        exit(1);
    }

    for (int i = 1; i <= n; i++)
    {
        //scan the name of student
        printf("Please enter student %d name: ", i);
        scanf("%s", &name);

        //scan the marks of student
        printf("Please enter student %d marks: ", i);
        scanf("%d", &marks);

        sprintf(buffer, "Name = %s, marks = %d\n", name, marks);
        fputs(buffer, studentRecord);
    }

    //close the file
    fclose(studentRecord);
    return 0;
}
