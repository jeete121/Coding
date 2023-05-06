#include <stdio.h>

int marks_summation(int *marks, int n, char gender)
{
    //Write your code here.
    int ans = 0;
    if (gender == 'b')
    {

        for (int i = 0; i < n; i += 2)
        {
            ans += marks[i];
        }
    }
    else
    {

        for (int i = 1; i < n; i += 2)
        {
            ans += marks[i];
        }
    }
    return ans;
}
int main()
{
    int marks[] = {1, 2, 3, 4, 5};
    char gender = 'g';
    int n = sizeof(marks) / sizeof(marks[0]);

    int sum = marks_summation(marks, n, gender);

    printf("%d", sum);
    return 0;
}