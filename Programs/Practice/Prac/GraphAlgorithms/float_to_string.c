#include <stdio.h>
#include <math.h>

//function to reverse a string
void reverse(char *str, int len)
{
    int i = 0, j = len - 1, temp;

    //apply two pointer approach
    while (i < j)
    {

        //swap the first and last
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        //increment first
        i++;

        //decrement last
        j--;
    }
}

//function to convert interer to string
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x > 0)
    {

        //convert to character
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}

// Converts a floating point number to string.
void ftoa(float n, char *res, int afterpoint)
{
    //integer part
    int ipart = (int)n;

    // floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0)
    {
        //put . to the result
        res[i] = '.';
        fpart = fpart * pow(10, afterpoint);

        //convert into to string after .
        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}
int main()
{
    char res[20];
    float n = 23.896999;

    //only 4 numbers come after decimal
    ftoa(n, res, 4);
    printf("%s",res);
    return 0;
}