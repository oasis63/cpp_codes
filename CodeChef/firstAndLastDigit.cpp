#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){
    

   int tc;
   cin>>tc;

   while(tc--){
        int n;
        cin>>n;

        int cntDig = 1 + floor(log10(n));

        int div = pow(10,cntDig-1);

        int lastdigit = n/div;
        int firstDigit = n%10;
        
        cout<<lastdigit+firstDigit<<endl;
   }


    return 0;
}   