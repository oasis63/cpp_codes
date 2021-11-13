// dynamic programming solution for 0/1 knapsack

#include<bits/stdc++.h>
using namespace std;

// decreasing order
bool comp(pair<int,int> p1,pair<int,int> p2){
   return p1.second > p2.second;
}

int solve(vector<pair<int,int>> vect,int n,int w){
   
   // val , weight
   
   // maximize the total value
   
   int dp[n+1][w+1];
   
   for(int i=0;i<=n;i++){
       
       for(int j=0;j<=w;j++){   // wieghts
           if(i==0 || j==0){
               
               dp[i][j] = 0;
               
           }else if(vect[i-1].second <= j){  
                                    // add the item                       ,// discard the item    
               dp[i][j] = max(vect[i-1].first + dp[i-1][j-vect[i-1].second],dp[i-1][j]);
               
           }else{  
           
               dp[i][j] = dp[i-1][j];
               
           }
       }
   }
   
   return dp[n][w];
}



int main(){
//code

  int tc;
  cin>>tc;
  while(tc--){
     
     int n,w;
     cin>>n>>w;
     
     int val[n];
     int wt[n];
     
     for(int i=0;i<n;i++)
         cin>>val[i];
     for(int i=0;i<n;i++)
         cin>>wt[i];
         
     vector<pair<int,int>> vect;    // value , weight
     
     for(int i=0;i<n;i++){
         vect.push_back(make_pair(val[i],wt[i]));
     }
     
     sort(vect.begin(),vect.end(),comp);
     
     cout<<solve(vect,n,w)<<endl;
         
  }

  return 0;
}