#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long 

int main(){

    regex str_expr("[a-z0-9]"); // initialize the regex 

    string str = "abc 3fdfasd,refd red";

    smatch sm;
    regex_match (str,sm,str_expr);

    cout << "the matches are: ";
    for (unsigned i=0; i<sm.size(); ++i) {
        cout << "[" << sm[i] << "] ";
    }


    return 0;
}