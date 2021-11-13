#include <bits/stdc++.h>
using namespace std;

char s[100001];

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // count the number of odd elements  .. i.e. number of ones
    int t,n,count,i;cin>>t;
    
    while(t--){
        cin>>n;
        cin>>s;
        
        count=0;
        
        for(i=0;i<n;i++){
            if(s[i]=='1')
                count++;
        }
        
        cout<<count<<endl;
    }
    
}
