#include<bits/stdc++.h>
using namespace std;


bool isSubsetSum(int set[], int n, int sum){
    
    bool subset[n+1][sum+1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[i][0] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int j = 1; j <= sum; j++)
      subset[0][j] = false;

     // Fill the subset table in botton up manner
     for (int i = 1; i <= n; i++){

       for (int j = 1; j <= sum; j++){

         if(set[i-1] > j)
           subset[i][j] = subset[i-1][j];
         if (set[i-1] <= j)
           subset[i][j] = subset[i-1][j] || subset[i - 1][j-set[i-1]];
       }
     }

     return subset[n][sum];
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
