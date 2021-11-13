#include<bits/stdc++.h>
using namespace std;

int main(){

	int num = 2324232;

	cout<<"Number of digits in "<<num<<"  : ";

	//cout<<log10(num)<<endl;

    int len = 1 + floor(log10(num));  // or  ceil(log10(num))

    cout<<len<<endl;

	return 0;
}
