#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int sum = 0;

    for(int i=0;i<n;i++){
        int temp ;cin>>temp;
        sum += temp;
    }

    int val = ceil(sum/(double)n);

    if(val*n > sum)
        cout<<val<<endl;
    else
        cout<<++val<<endl;

}
