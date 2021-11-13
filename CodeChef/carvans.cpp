#include<bits/stdc++.h>
using namespace std;


int main(){
    
    int t;
    cin>>t;

    while(t--){
        int n;cin>>n;
        
        int prev_max = 0;
        cin>>prev_max;
        int ans = 1;

        n--;

        int temp = 0;

        for(int i=0;i<n;i++){
            cin>>temp;
            if(temp <= prev_max){
                ans++;
                prev_max = temp;
            }
        }
        cout<<ans<<endl;
    }    
    

    return 0;
}