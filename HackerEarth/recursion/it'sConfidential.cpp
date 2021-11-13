#include<bits/stdc++.h>
using namespace std;

string midChar(string str){
    string ans="";
    int len = str.length();

    if(len==1)      // base case
        return str;

    if(len>0){

        int left;
        int right;

        if(len%2==1){
            ans = str[len/2];
            left = len/2;
            right=len/2+1;
        }
        else{
            ans = str[len/2-1]; // middle term
            left = len/2-1;
            right = len/2;
        }
        //cout<<"Executed1 : "<<len<<" "<<ans<<endl;
        if(str.substr(0,left).length() > 0)
            ans += midChar(str.substr(0,left));  // left substring
        //cout<<"Executed2"<<endl;
        if(str.substr(right,len).length()!=0)
            ans += midChar(str.substr(right,len));  // right substring
        //cout<<"Executed3"<<endl;
    }
    return ans;
}

int main(){
    string str = "abc";
    int len = str.length();
    cout<<"Mid Char :"<<str[len/2-1]<<endl;
    cout<<"Left substr :"<<str.substr(0,len/2-1)<<endl;
    cout<<"Righ Substr :"<<str.substr(len/2,len)<<endl;

    cout<<midChar(str)<<endl;
}
