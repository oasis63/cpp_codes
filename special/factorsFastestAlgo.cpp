#include<bits/stdc++.h>
using namespace std;

int factors(int num){
    int ans = 1;

    int n = num;

    for(int i=2;i<=sqrt(n);i++){
        int count = 0;
        while(num%i==0){
            count++;
            num=num/i;
        }
 
        //cout<<count<<endl;

       if(count != 0 )
             ans *= (count+1);
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
