#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long


int findBitDifference(int a,int b){

    int count = 0;

    for(int i=0;i<32;i++){

        if(((a >> i) & 1) != (( b >> i) & 1))
            count++;
    }

    return count;
} 

int main(){
    
    cout<<findBitDifference(1,1)<<endl;
    cout<<findBitDifference(2,3)<<endl;
    cout<<findBitDifference(7,8)<<endl;
    cout<<findBitDifference(10,16)<<endl;

}