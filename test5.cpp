#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
#define uli unsigned long int 

int arr[10001];
void show(){
   for(int i=0;i<100;i++){
    cout<<i<<"  "<<arr[i]<<endl;
  }
}
void initialize(){
 arr[1] = 20;
 arr[2] = 36;
 for(int i=3;i<10001;i++){
  if(i%2 == 0)
    arr[i] = arr[i-1] + 10;
  else
    arr[i]  = arr[i-1] + 14;
 }
}

uli solve(uli n){
  if(n==1)
    return 20;
  else if(n==2)
    return 36;
  else{
    if(n%2 == 0)
      return solve(n-1) + 10;
    else
      return solve(n-1) + 14;
  }
}

int main(){
  int tc;cin>>tc;
  // memset(arr,0,sizeof(arr));
  // initialize();
  // show();
  while(tc--){
      uli n;
      cin>>n;
      uli res = solve(n);
      // cout<<arr[n]<<endl;
      cout<<res<<endl;
  }
  return 0;
}

