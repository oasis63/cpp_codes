#include<bits/stdc++.h>
using namespace std;

int maxLen = 100001;
int freq[100001];
int input[100001];

//  Amazing Question .. taking modulo with maxLen 


int main(){
    int tc,n,q;cin>>tc;
    while(tc--){
        cin>>n>>q;
        for(int i=0;i<n;i++)
            cin>>input[i];
            
        for(int i=0;i<maxLen;i++)
            freq[i]=0;
        
        for(int i=0;i<n;i++)
            freq[input[i]%maxLen] ++;
            
        int index;
        
        while(q--){
            cin>>index;
            cout<<freq[index%maxLen]<<endl;
        }
    }
    
}
