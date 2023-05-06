#include <stdio.h>
#include <stdbool.h>

//function to check the given
//number is perfect or not
bool isPerfectNumber(int num)
{
    int sum = 0;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            if (num / i == i && i != num)
                sum += i;
            else
            {
                if (num / i != num)
                    sum += num / i;
                if (i != num)
                    sum += i;
            }
        }
    }
    //sum of all divisors except it-self is
    //same as the number then
    if (sum == num)
        return true;
    else
        return false;
}
int main()
{
    int num = 6;
    if (isPerfectNumber(num))
    {
        printf("Number is perfect\n");
    }
    else
    {
        printf("Not a perfect Number\n");
    }
    return 0;
}
//Time Complexity: O(sqrt(n))
//Space Complexity:O(1)