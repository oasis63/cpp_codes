#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){
    
    int n = 4;  

    string bin = bitset<8>(n).to_string();

    cout<<bin<<endl;

    n = ~n;

    cout<<n<<endl;

    string binary = bitset<8>(n).to_string();

    cout<<binary<<endl;

    return 0;
}