#include<bits/stdc++.h>
using namespace std;

int factors(int num){
    int ans = 0;

    for(int i=1;i<=sqrt(num);i++){
        if(num%i==0){
            if(num/i==i){
              // cout<<i<<" "<<num/i<<endl;
                ans += 1;
            }
            else {
                ans += 2;
               // cout<<i<<endl;
            }
        }
    }
    return ans;
}

int main()
{
   int num;
   cout<<"Enter a number to find the total number of factors " <<endl;
   cin>>num;

   cout<<factors(num)<<endl;
}
