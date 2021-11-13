#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int rev(int n){
	int rev = 0;
	while(n){
		int r = n%10;
		n=n/10;
		if(rev > INT_MAX/10 || (rev == INT_MAX / 10 && r > 7))
			return 0;
		if(rev < INT_MIN/10 || (rev == INT_MIN / 10 && r < -8))
			return 0;
		rev = rev*10 + r;
	}

	return rev;
}

int main(){

	
	cout<<rev(-11434)<<endl;

    return 0;
}