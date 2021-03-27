#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &vect){

    int n = vect.size();
    string pre = "";

    int lenMin = INT_MAX;

    for(int i=0;i<n;i++){
        if(vect[i].length() < lenMin){
            lenMin = vect[i].length();
        }
    }


    for(int i=0;i<lenMin;i++){
        bool flag = false;

        for(int j=0;j<n-1;j++){
            if(vect[j][i] != vect[j+1][i]){
                flag = true;
                break;
            }
        }

        if(flag){
           break;
        }

        pre.push_back(vect[0][i]);  // add char to the prefix string 

    }

    return pre;
}

int main(){

//	vector<string> vect {"abcdefgh","aefghijk","abcefgh" };
	vector<string> vect {"abcdefgh","abcghijk","abcefgh" };

    cout<<longestCommonPrefix(vect)<<endl;

	return 0;
}
