#include<bits/stdc++.h>
using namespace std;

int max(int a,int b,int c){
    return max(a,max(b,c));
}

int rec(vector<string>grid,int i,int j,int m,int n){
    if(i>=m-1 || j>=n-1)
        return 0;
    if(grid[i][j]=='.')
        return 1+max(rec(grid,i+1,j,m,n),rec(grid,i,j+1,m,n),rec(grid,i+1,j+1,m,n));
    else
        return max(rec(grid,i+1,j,m,n),rec(grid,i,j+1,m,n),rec(grid,i+1,j+1,m,n));
}


int rec2(vector<string>grid,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
         dp[i][j]=0;
    } 
  /*  for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }*/
    
    for(int i=1;i<=m-1;i++){
        for(int j=1;j<=n-1;j++){
            
            if(grid[i][j]=='.'){
                dp[i][j]=1;
                
                if(grid[i+1][j]=='.')
                    dp[i][j]++;
                if(grid[i][j+1]=='.')
                    dp[i][j]++;
                if(grid[i+1][j+1]=='.')
                    dp[i][j]++;
                
            }else{
                dp[i][j]=0;
            }
        }
    }
    
    int mx = 0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(dp[i][j] > mx)
                mx = dp[i][j];
        }
    }
    
    return mx;
}



int volume_trapped (vector<string> grid,int m,int n) {
   // Write your code here
  //int ans = rec(grid,1,1,m,n);
  int ans = rec2(grid,m,n);
 
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int M,N;
    cin >> M >> N;
    vector<string> grid(M);
    for(int i_grid=0; i_grid<M; i_grid++)
    {
    	cin >> grid[i_grid];
    }

    int out_;
    out_ = volume_trapped(grid,M,N);
    cout << out_;
    return 0;
}