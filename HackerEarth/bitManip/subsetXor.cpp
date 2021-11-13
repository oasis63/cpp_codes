#include <bits/stdc++.h>
using namespace std;

int input[100]={0};

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
   int t,n,i;cin>>t;
   
   while(t--){
       cin>>n;
       
       for(i=0;i<n;i++){
         cin>>input[i];
       }
        
       if(n==1)  
        cout<<input[0]<<endl;
        else
            cout<<0<<endl;     
   }

}

/*
  XOR sum of elements of subsets of a set is always is zero(0);


*/

