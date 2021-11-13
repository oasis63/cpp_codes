#include<bits/stdc++.h>
using namespace std;

/*
	Matrix multiplication
*/

int main(){
	
	int m = 3;
	int n = 4;
	int p = 2;

	int A[m][n] =  { 
						{1,2,3,4},
						{5,6,7,8},
						{7,2,6,4}
					};

	int B[n][p] =  {
						{2,2},
						{3,3},
						{4,4},
						{5,5}
					};
	

	int prod[m][p];

	for(int i=0;i<m;i++){
		for(int j = 0;j<p;j++){
			prod[i][j] = 0;
			for(int k=0;k<n;k++){
				prod[i][j] += A[i][k]*B[k][j];
			}
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			cout<<prod[i][j]<<" ";
		}
		cout<<endl;
	}




	return 0;
}