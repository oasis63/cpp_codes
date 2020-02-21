#include<bits/stdc++.h>
using namespace std;


int main(){

    while(1){
        
        int n;
        cin>>n;
        if(n==-1)
            break;

        int arr[n];
        int sum =0;

        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
        }

        if(sum%n!=0)

            cout<<-1<<endl;

        else{

            int ans=0;
            int t = sum/n;

            for(int i=0;i<n;i++){
                if(arr[i] < t){
                    ans += (t-arr[i]);
                }
            }

            cout<<ans<<endl;

        }


    }


    return 0;
}

