#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		string s1,s2;cin>>s1;cin>>s2;

		for(int i=0;i<s1.length();i++){
			toupper(s1[i]);
		}

		for(int i=0;i<s1.length();i++){
			toupper(s1[i]);
		}

		cout<<s1<<endl;
		cout<<s2<<endl;
	}
}