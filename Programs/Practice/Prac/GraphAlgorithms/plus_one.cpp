#include <bits/stdc++.h>
using namespace std;

//function to add 1 into
//the number formed by list
vector<int> plusOne(vector<int>& digits)
{
    //lenght of number
    int n=digits.size();

    //varible to hold the carry
    int carry=0;

    //vector array to hold the 
    //final result
    vector<int> res;


    //iterate for all the digits 
    //from end
   for(int i=n-1;i>=0;i--)
        {
          //if at last digit
            if(i==n-1)
            {
                //push into the result after adding
                //1 and convert into single digit
                res.push_back((carry+digits[i]+1)%10);

               //get carry for next iteration
                carry=(carry+digits[i]+1)/10;
            }
          //not at last digit
         else
            {
            //simply add the current digit with
            //the carry and convert into
            //single digit
            res.push_back((carry+digits[i])%10);

            //take carry  for next round
            carry=(carry+digits[i])/10;
            }
        }
     //if after all iteration
     //if carry then push into
     //the final reuslt
        if(carry)
              res.push_back(carry);
    
    //revers the final result
        reverse(res.begin(),res.end());

    //return the final result
        return res; 
}
int main()
{
    vector<int> digits={9,9};
    vector<int> plusone=plusOne(digits);
    for(int i=0;i<plusone.size();i++)
       cout<<plusone[i]<<" ";
    return 0;

}