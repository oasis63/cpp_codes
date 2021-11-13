#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string s) {

    int n = s.length();

    int i = 0,j=n-1;

    while(i<j){

        while(i<j && !isalnum(s[i]))
            i++;
		while(i<j && !isalnum(s[j]))
			j--;

        if(toupper(s[i]) != toupper(s[j]))
			return 0;

		i++;
		j--;
    }

    return 1;

}

int main(){

	string str = "A man, a plan, a canal: Panama";
//	string str = "race a car";
	cout<<isPalindrome(str)<<endl;

	return 0;
}
