#include<bits/stdc++.h>
using namespace std;

/*
    Given a list of non negative integers, 
    arrange them such that they form the largest number.

    For example:

    Given [3, 30, 34, 5, 9], the largest formed number is 9534330

*/

bool myComp(string a,string b){
    return a + b > b + a;
}


string largestNumber(const vector<int> &A) {

    string ans = "";
    vector<string> str;

    for(int i=0;i<A.size();i++){
        str.push_back(to_string(A[i]));
    }

    sort(str.begin(),str.end(),myComp);

    for(int i=0;i<str.size();i++){
        ans += str[i];
    }

    int i = 0;

    // remove 0 from the begining of the number 
    while(ans[i] == '0' && i < ans.size()-1)
        i++;

    return ans.substr(i);
}


int main(){
	   
	
    vector<int> vect{ 980, 674, 250, 359, 98, 969, 143}; //379, 363, 106, 838, 923, 969, 880, 997, 664, 152, 329, 975, 377, 995, 943, 369, 515, 722, 302, 496, 124, 692, 993, 341, 785, 400, 113, 302, 563, 121, 230, 358, 911, 437, 438, 494, 599, 168, 866, 689, 444, 684, 365, 470, 176, 910, 204, 324, 657, 161, 884, 623, 814, 231, 694, 399, 126, 426};	

    // vector<int> vect { 0,0,0,0};

	cout<<largestNumber(vect)<<endl;
	
	return 0;
}