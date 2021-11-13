#include<bits/stdc++.h>
using namespace std;

int main(){
   int ans=0,t=0;
   int n;cin>>n;

   int a,b;

   while(n--){
    cin>>a>>b;
    t -= a;
    if(t>ans)
        ans = t;
    t+=b;
    if(t>ans)
        ans=t;

   }

   cout<<ans<<endl;
}
