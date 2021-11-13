#include<bits/stdc++.h>
using namespace std;

int main(){
    int input[] = {4,1,4,5,3};

    sort(input,input+5);

    cout<<binary_search(input,input+5,3)<<endl;

}
