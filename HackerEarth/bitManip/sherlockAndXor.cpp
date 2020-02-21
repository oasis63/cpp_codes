#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define size 100001

ll input[size]={0};

int main(){
    int t,n,i,j;cin>>t;
    while(t--){
        cin>>n;
        
        unsigned int even=0;
        unsigned int odd=0;
        
        for(i=0;i<n;i++){
            cin>>input[i];
            
            if((input[i]&1))
                odd++;
            else
                even++;
        }
        
        cout<<(odd*even)<<endl;

    }

}
/*
    XOR operatoins 

    odd ^ odd = even
    even ^ even = even 
    odd ^ even  = odd 

*/

