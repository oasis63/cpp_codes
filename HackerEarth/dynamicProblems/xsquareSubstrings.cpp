#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

bool isBalanced(string str){

    int len = str.length();

    int hash1[26]={0};

    for(int i=0;i<len;i++){
        hash1[str[i]-'a']++;
    }

    for(int i=0;i<26;i++){
        if(hash1[i]%2==1)
            return false;
    }

    return true;
}


int solve(string str){

    if(isBalanced(str)){
        return 1;
    }

    return -1;
}


int main() {
	fast;


	int tc;cin>>tc;
	while(tc--){
	    string str;
	    cin>>str;

	    cout<<solve(str)<<endl;
	}
}
