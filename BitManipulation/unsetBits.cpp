#include <bits/stdc++.h>
using namespace std;

// count the unset bits in binary representation of a  number

int unsetBits(int n){
    int count=0;

    for(int i=1;i<=n;i=i<<1){
        if((n&i)==0)
            count++;
    }
    return count;
}

int main(){
    cout<<unsetBits(8)<<endl;
    cout<<unsetBits(1)<<endl;
    cout<<unsetBits(2)<<endl;

}
