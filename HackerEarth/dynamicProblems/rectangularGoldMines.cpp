#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

	/*ll mat[][4] = {
					{2,8,9,7},
					{5,8,1,7},
					{5,7,3,5},
					{4,8,7,4}
				};


	ll madt[][3] = {
					{1,1,1},
					{1,1,1},
					{1,1,1}
				};
*/

    ll r,c;
    cin>>r>>c;
    ll mat[r][c];
    
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    

	ll dp[r+1][c+1];
	memset(dp,0,sizeof(dp));


	for(ll i=1;i<=r;i++){
		for(ll j=1;j<=c;j++){
			dp[i][j] = dp[i][j-1]+dp[i-1][j] - dp[i-1][j-1] + mat[i-1][j-1];
		}
	}

/*	for(ll i=0;i<=r;i++){
		for(ll j=0;j<=c;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/


	ll q;cin>>q;
	ll x1,y1,x2,y2;

	while(q--){
		cin>>x1>>y1>>x2>>y2;
            ll temp = 0;
            temp = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1]+dp[x1-1][y1-1];
			cout<<temp<<endl;
	
	}



	return 0;
}


/*
	Sample Input:

	4 4
	2 8 9 7
	5 8 1 7
	5 7 3 5
	4 8 7 4
	4
	1 2 4 2
	1 4 2 4
	1 1 4 2
	2 4 2 4


	Sample Output:

	31
	14
	47
	7
	




*/