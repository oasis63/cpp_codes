#include<bits/stdc++.h>
using namespace std;

void subset(int num[],int n){

	int p = 1<<n;  // pow(2,n) .. no. of subsets

	for(int i=0;i<p;i++){

		for(int j=0;j<n;j++){
			if((i&(1<<j)))
				cout<<num[j]<<" ";
		}
		cout<<endl;
	}

}

int main(){

    int num[] = {1,2,3};

    subset(num,3);

}
