#include <iostream>
using namespace std;

int recPow(int x,int n){
    if(n==0)
        return 1;
    else
        return x*recPow(x,n-1);
}

int main(){
    cout<<recPow(2,6)<<endl;
}
