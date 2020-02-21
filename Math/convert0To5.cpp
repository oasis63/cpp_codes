#include<bits/stdc++.h>
using namespace std;

int convert0To5Util(int num){

    if(num==0)
        return 0;

    int digit = num%10;
    if(digit==0)
        digit=5;

    return convert0To5Util(num/10)*10+digit;
}

int convert0To5(int num){

    if(num==0)
        return 5;
    return convert0To5Util(num);
}


int main(){

    int num = 100;
    cout<<convert0To5(num)<<endl;

    return 0;
}
