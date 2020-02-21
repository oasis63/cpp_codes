#include<bits/stdc++.h>
using namespace std;

string operate(string s){
    string ans="";
    int i=0;
    int j=s.length() - 1;
    while(i<=j){
        ans+=s[i];
        if(i!=j)
            ans+=s[j];
        i++;
        j--;
    }
    return ans;
}

string toOriginal(string changed){
    string orig = changed;

    int len = changed.length();

    int i=0;
    int last = len-1;
    int index=0;

    while(i<len){
        orig[index] = changed[i];
        i++;
        if(i!=len)
            orig[last]=changed[i];

        last--;
        i++;
        index++;
    }

    return orig;
}


int main(){

    //int t;cin>>t;
    string input; cin>>input;

   int len = input.length()-1;

   int mid = len/2;

   cout<<input[mid]<<endl;

   string output="";

   for(int i=0;i<mid;i++){
    output += input[i];
    output+=input[len-i];
   }

    output += input[mid];

    cout<<output<<endl;
}
