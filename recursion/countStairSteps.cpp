#include<bits/stdc++.h>
using namespace std;

// a person can climb 1, 2 stairs at a time.

int countWays(int n){
	if(n<=1)
		return 1;
	return countWays(n-1)+countWays(n-2);
}

int main(){
	
	for(int i=0;i<10;i++){
		cout<<i<<"\t"<<countWays(i)<<endl;
	}

	return 0;
} 