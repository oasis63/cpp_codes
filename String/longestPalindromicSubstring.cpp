#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string str){

	int n = str.length();

	for(int i=0,j=n-1;i<=j;i++,j--){
		if(str[i]!=str[j]){
			return false;
		}
	}

	return true;
}

string expandAroundCenter(string str,int c1,int c2){

	int l=c1,r=c2;
	int n = str.length();

	while(l >= 0 && r<= n-1 && str[l]==str[r]){
		l--;
		r++;
	}

	return str.substr(l+1,r-l-1);
}

string longestPalindrome(string str){

    int  n = str.length();

    if(n==0)
		return "";

	string longest = str.substr(0,1);

    for(int i=0;i<n-1;i++){
		string p1 = expandAroundCenter(str,i,i); // odd length palindrome

		if(p1.length() > longest.length()){
			longest = p1;
		}

		string p2 = expandAroundCenter(str,i,i+1);  // even length palindrome
		if(p2.length() > longest.length()){
			longest = p2;
		}
    }

    return longest;

}

int main(){

    string str = "abacdfgdcaba";

    cout<<longestPalindrome(str)<<endl;

    return 0;
}
