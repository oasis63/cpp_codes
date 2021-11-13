#include <bits/stdc++.h>
using namespace std;

// printing the sub array of an array

void printSubstrings(string str){
	int n = str.length();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
        	string sub = str.substr(i,(j-i)+1);
            cout<<sub<<endl;
        }
    }

}



int main(){
    printSubstrings("abcd");
}
