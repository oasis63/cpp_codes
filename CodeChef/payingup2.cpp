#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

bool isSubsetSum(int arr[],int n,int dSum){

    int p = 1<<n;

    for(int i=1;i<p;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            if((i & (1<<j))){
                sum += arr[j];
            }
        }
        if(sum == dSum )
            return true;
    }

    return false;
}

int main(){
    int t;
    cin>>t;

    while(t-- > 0){
      int notes,sum;
      cin>>notes>>sum;

      int arr[notes];
      for(int i=0;i<notes;i++){
        cin>>arr[i];
      }

      if(isSubsetSum(arr,notes,sum)){
        cout<<"Yes"<<endl;
      }else{
        cout<<"No"<<endl;
      }
    }
}