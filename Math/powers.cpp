#include<bits/stdc++.h>
using namespace std;

int recursivePower(int x,int n){
    if(n==0)
        return 1;
    else
        return x*recursivePower(x,n-1);
}

int iterativePower(int x,int n){
    int result = 1;

    while(n!=0){
        result *= x;
        n--;
    }

    return result;
}

int main(){
    cout<<recursivePower(3,4)<<endl;
    cout<<iterativePower(3,0)<<endl;
    cout<<iterativePower(5,10)<<endl;

}
