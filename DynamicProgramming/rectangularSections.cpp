#include<bits/stdc++.h>
using namespace std;


/*
	sum within a  rectangular section 
	of a given big rectangular section 

*/

int main(){

	int mat[][4] = {
					{2,8,9,7},
					{5,8,1,7},
					{5,7,3,5},
					{4,8,7,4}
				};


	int madt[][3] = {
					{1,1,1},
					{1,1,1},
					{1,1,1}
				};




	int n = 4;

	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));


	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = dp[i][j-1]+dp[i-1][j] - dp[i-1][j-1] + mat[i-1][j-1];
		}
	}

	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}


	int q;cin>>q;
	int x1,y1,x2,y2;

	while(q--){
		cin>>x1>>y1>>x2>>y2;

		if(x1==x2 && y1==y2){
			cout<<mat[x1-1][y1-1]<<endl;
		}else if(x1==1 && y1==1){
			cout<<dp[x2][y2]<<endl;
		}else{
            int temp = 0;
            temp = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1]+dp[x1-1][y1-1];
			cout<<temp<<endl;
		}
	}



	return 0;
}
