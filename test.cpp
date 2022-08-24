#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){
    
    int i = 0;
    int sum = 0;

    while(i < 100){
        sum = sum + i;
        sum = i + sum;
        i += 1;
    }

    cout<<sum<<endl;

    return 0;
}