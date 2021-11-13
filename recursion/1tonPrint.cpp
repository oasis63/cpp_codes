#include<iostream>
using namespace std;

void rec(int n){
    if(n==0)
        return;
    rec(n-1);
    cout<<n<<" ";
}

int main()
 {
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;
	    rec(n);
	}
	return 0;
}
