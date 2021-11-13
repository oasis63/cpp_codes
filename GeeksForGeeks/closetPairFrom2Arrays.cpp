#include<bits/stdc++.h>
using namespace std;

int main(){
  //code
  int tc;
  cin>>tc;
  
  while(tc--){
      int n,m,ds;
      cin>>n>>m;
      int arr[n],brr[m];
      for(int i=0;i<n;i++){
          cin>>arr[i];
      }
      for(int i=0;i<m;i++){
          cin>>brr[i];
      }
      cin>>ds;
      sort(arr,arr+n);
      sort(brr,brr+m);
     int ans1 , ans2;
     int diff=INT_MAX;


     int l = 0,r=m-1;

     while(l<n && r>=0){
        int temp = arr[l] + brr[r];
        int dTemp = abs(temp-ds);

         if(dTemp < diff){
               diff = dTemp;
               ans1 = arr[l];
               ans2 = brr[r];
          }

          if(temp > ds){
            r--;
          }else{
            l++;
          }

     }

     cout<<ans1<<" "<<ans2<<endl;
  }
  
  
  return 0;
}

  