#include <bits/stdc++.h>
using namespace std;

// printing the sub array of an array

void printSubstrings(string str){
	int n = str.length();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
        	string sub = "";
            for(int k=i;k<=j;k++)
                sub += str[k];
            cout<<sub<<endl;
        }
    }

}



int main(){
    printSubstrings("abcd");
}
