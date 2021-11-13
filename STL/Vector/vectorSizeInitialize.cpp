#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){

    vector<bool> vect(4);   // initializing vector size

    for(int i=0;i<4;i++){
        vect[i] = true;
    }

    for(int i=0;i<4;i++){
        cout<<vect[i]<<endl;
    }

    return 0;
}
