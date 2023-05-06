#include <bits/stdc++.h>
using namespace std;
//function to find the each digit square sum
int sumOfSquareDigits(int num) 
{
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num = num / 10;
        }
        return sum;
}
//function to check happy number
bool isHappy(int n) {
    int prev = n;
    // sum of given number
     int next = sumOfSquareDigits(n);
    // iterate untill both equal
    while (prev != next) {
            // previuos sum
        prev = sumOfSquareDigits(prev);
            // next sum
         next = sumOfSquareDigits(sumOfSquareDigits(next));

        if (next == 1)
                return true;
     }

    return prev == 1;
}


//function to find all Happy number
//till given number
vector<int>  checkHappyNumber1ToN(int num) 
{
    // create vector to hold 
    //the happy number
    vector<int> allHa ;
    // iterate from 1 to num
    for (int i = 1; i <= num; i++) {
      // check current number is happy
            if (isHappy(i))
                allHa.push_back(i);
        }
        return allHa;
}
int main()
{
     int num = 14;
     vector<int> allHappy = checkHappyNumber1ToN(num);
     cout<<"All Happy Number are ";
     for(int i=0;i<allHappy.size();i++)
        cout<<allHappy[i]<<" ";
    return 0;
}


