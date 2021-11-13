#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){

    string path = "Benga";
    string str1 = "Coim";
    path += " " + str1;

    cout<<path<<endl;

    int pl = path.length();
    int s1 = str1.length();

    cout<<pl<<endl;
    cout<<s1<<endl;

    cout<<path.substr(0,pl-s1-1)<<"|"<<endl;

    return 0;
}
