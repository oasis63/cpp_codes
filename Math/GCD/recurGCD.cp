#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int gcd2(int a,int b){
	if(b==0)
		return a;
	else
		return gcd2(b,a%b);
}
 

int main(){
	
	cout<<gcd(18,12)<<endl;
	cout<<gcd(18,12)<<endl;

	return 0;
}