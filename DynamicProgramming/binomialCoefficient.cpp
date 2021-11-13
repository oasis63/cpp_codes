#include <bits/stdc++.h>
using namespace std;


int binoCoeff(int n,int k){

	int C[n+1][k+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=min(i,k);j++){
			if(j==0 || i==j)
				C[i][j] = 1;
			else
				C[i][j] = C[i-1][j]+C[i-1][j-1];
		}
	}

	return C[n][k];

}

// more effiecient algo 

int binomialCoeff(int n, int k) 
{ 
    int C[k + 1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // nC0 is 1 
  
    for (int i = 1; i <= n; i++) { 
        for (int j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j - 1]; 
    } 
    return C[k]; 
} 


int main(){

	int n=5,k=2;
	cout<<binoCoeff(n,k)<<endl;

	n=6,k=3;
	cout<<binoCoeff(n,k)<<endl;

	cout<<binoCoeff(10,4)<<endl;
}
