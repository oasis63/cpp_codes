#include <bits/stdc++.h>
using namespace std;

int main(){

	string str1 = "AGGTAB";
	string str2 = "GXTXAYB";

	int len1 = str1.length();
	int len2 = str2.length();

	int dp[len1+1][len2+1];

	for(int i=0;i<=len1;i++){  // horizontal equal to 0
		dp[0][i] = 0;
	}	

	for(int i=0;i<=len2;i++){  // vertical equal to 0
		dp[i][0] = 0;
	}	


	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
 
			// match found
			if(str1[i-1] == str2[j-1]){
				// corner value + 1
				dp[i][j] = dp[i-1][j-1]+1;
			}else{ // match not found
				// maximum of left and top value
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}


	cout<<dp[len1][len2]<<endl;

}