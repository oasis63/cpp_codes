#include<bits/stdc++.h>
using namespace std;


// a person can climb 1, 2, ..m stairs at a time.


int countWays(int n,int m){
	if(n<=1)
		return 1;
	int res = 0;
	for(int i=1;i<=m;i++){
		res += countWays(n-i,m);
	}
	return res;
}

int main(){
	
	int s = 4, m = 2;
    for(int i=0;i<10;i++){
        cout<<i<<"\t"<<countWays(i,m)<<endl;
    }

	return 0;
} 