#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){

    multiset<int> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    multiset<int>::iterator itr = ms.begin();

    while(itr!= ms.end()){
        cout<<*itr<<endl;
        itr++;
    }

}
