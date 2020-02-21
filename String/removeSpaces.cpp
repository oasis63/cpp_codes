#include<bits/stdc++.h>
using namespace std;


string removeLeadTrailSpaces(string str){

    int n = str.length();
    int i=0;
    while(i<n && str[i]==' '){
        i++;
    }
    int j=n-1;
    while(j>=0 && str[j]==' '){
        j--;
    }
    str = str.substr(i,j-i+1);

    return str;
}

int main(){

    string str = " falj afljfa  ";
    cout<<str<<endl;
    cout<<str.length()<<endl;
    str = removeLeadTrailSpaces(str);
    cout<<str<<endl;
    cout<<str.length()<<endl;

    return 0;
}
