#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long


int main(){

    map<string,string> words;
    int n,m;
    cin>>n>>m;

    string f,s;
    while(m--){
        cin>>f>>s;
        words.insert(make_pair(f,s));
    }

    while(n--){
        cin>>f;
        s = words[f];
        if(s.length() < f.length())
            cout<<s<<" ";
        else
            cout<<f<<" ";
    }

    return 0;
}

/*

// sample input

5 3
joll wuqrd
euzf un
hbnyiyc rsoqqveh
hbnyiyc joll joll euzf joll

// sample output

codeforces round letter round



*/
