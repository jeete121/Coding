#include <bits/stdc++.h>
using namespace std;

//vector string to hold the each digits
//till the 19
vector<string> digits = { "", "One", "Two", 
            "Three", "Four", "Five", "Six", "Seven", 
            "Eight",  "Nine","Ten", "Eleven", "Twelve",
             "Thirteen", "Fourteen", "Fifteen", "Sixteen",
              "Seventeen", "Eighteen", "Nineteen" };


//vector string to hold the
//tens value
vector<string> ten = { "", "", "Twenty", 
        "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
         "Eighty","Ninety" };


//funtion for convet number to words
string convertNumberToWords(int num) 
{
     // if number is negative
      if (num < 0)
        return "Minus " + convertNumberToWords(-num);
     // if number is zero
       if (num == 0)
         return "";
        // if number less then 20
        if (num < 20) {
            return digits[num];
        }
        // if number less then 100
        if (num <= 99) {
            return ten[num / 10] + ((num % 10 != 0) ? " " : "")
                 + digits[num % 10];
        }
        // if number less then 1000 (Hundreds condition)
        if (num <= 999) {
            return convertNumberToWords(num / 100) + " Hundreds" 
                + ((num % 100 != 0) ? " " : "")
                    + convertNumberToWords(num % 100);
        }
        // Thousanda conditions
        if (num <= 999999) {
            // calling in recurring
            return convertNumberToWords(num / 1000) + " Thousands" 
                + ((num % 1000 != 0) ? " " : "")
                    + convertNumberToWords(num % 1000);
        }
        // Million condition
        if (num <= 999999999) {
            // calling in recurring
            return convertNumberToWords(num / 1000000) + " Million" 
                + ((num % 1000000 != 0) ? " " : "")
                    + convertNumberToWords(num % 1000000);
        }
        // Billion condition and recurring calling
        return convertNumberToWords(num / 1000000000) + " Billion" 
                + ((num % 1000000000 != 0) ? " " : "")
                + convertNumberToWords(num % 1000000000);

    }

int main()
{
    int num = 1392431860;
    string words = convertNumberToWords(num);
    cout<<words<<"\n";
    return 0;
}

