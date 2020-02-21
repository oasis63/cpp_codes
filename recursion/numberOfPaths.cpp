#include<iostream>
using namespace std;

/*
    Move --- Right
             Down

    .. From Top Left corner to Right Bottom Corner
*/

int numberOfPaths(int m,int n){
    if(m==1 || n==1)
        return 1;
    else
        return numberOfPaths(m-1,n)+numberOfPaths(m,n-1);
}

int main()
 {
	int tc;cin>>tc;
	while(tc--){
	    int m,n;cin>>m>>n;
	    cout<<numberOfPaths(m,n)<<endl;
	}
	return 0;
}
