#include <stdio.h>
int main()
{
    int englishMarks;
    int hindiMarks;
    int physicsMarks;
    int chemistryMarks;
    int mathsMarks;

    printf("Enter marks of English : ");
    scanf("%d", &englishMarks);

    printf("Enter marks of Hindi : ");
    scanf("%d", &hindiMarks);

    printf("Enter marks of Physics : ");
    scanf("%d", &physicsMarks);

    printf("Enter marks of Chemistry : ");
    scanf("%d", &chemistryMarks);

    printf("Enter marks of Maths : ");
    scanf("%d", &mathsMarks);

    int sum = (englishMarks + hindiMarks + chemistryMarks + physicsMarks + mathsMarks);
    float percentage = ((float)(sum) / 500) * 100;
    printf("Sum of marks are %d\n", sum);
    printf("Percentage of marks is %lf\n", percentage);
    return 0;
}