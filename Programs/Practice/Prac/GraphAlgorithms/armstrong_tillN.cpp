#include <bits/stdc++.h>
using namespace std;

//function used for check armstrong number
bool checkArmstrong(int num) {
        int arm = 0;
        int n = num;
        // Length of given number
        int length = (int)log10(num) + 1;
        while (n > 0) {
            int mod = n % 10;
            arm +=pow(mod, length);
            n = n / 10;
        }
     if (num == arm)
            return true;
    return false;
}

//function to find all armstrong number
//till given number
vector<int> checkArmstrong1ToN(int num) {
    //vector to hold the armstrong
    //number
    vector<int> allArm ;
   // iterate from 1 to num
   for (int i = 1; i <= num; i++) {
      // check current number is armstrong
         if (checkArmstrong(i))
                allArm.push_back(i);
    }
    return allArm;
}
int main()
{
   int num = 1000;
   vector<int> allArm = checkArmstrong1ToN(num);
   cout<<"All Armstrong are ";
   for(int i=0;i<allArm.size();i++)
      cout<<allArm[i]<<" ";;
   return 0;
}

