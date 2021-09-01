#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc;
    cin>>tc;

    while(tc--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int cntPair = 0;
        // aj−ai=j−i.
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]-arr[i] == j-i){
                    cntPair++;
                }
            }
        }
        cout<<cntPair<<endl;
    }

    return 0;
}
