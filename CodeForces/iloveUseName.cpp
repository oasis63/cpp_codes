#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int ans=0;

    // find the number of scores which are strictly greater or strictly lesser than its
    // predecessor


    for(int i=n-1;i>0;i--){

        if(arr[i-1] > arr[i]){
                int j=i-1;
                while(j>=0 && arr[j] > arr[i]){
                        j--;
                }
                if(j==-1)
                    ans++;

        }else if(arr[i-1] < arr[i]){

            int j=i-1;
            while(j>=0 && arr[j] < arr[i]){
                    j--;
            }
            if(j==-1)
                ans++;

        }
    }

    cout<<ans<<endl;

}
