#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll unsigned  long long

ll arr[101];

ll fun(ll n){

    if(arr[n]==0){
        if(n <= 1){
            arr[n] = n+1;
        }else{
            arr[n] = 2*fun(n-1);
        }
    }

    return arr[n];

}


int main(){

  for(ll i=0;i<101;i++){
    arr[i]=0;
  }

 for(ll i=0;i<20;i++){
    fun(i);
  }

    for(ll i=0;i<20;i++){
        cout<<i<<" "<<arr[i]<<endl;
    }

 // int n;
 // cin>>n;

 // cout<<fun(n)<<endl;


  return 0;
}
