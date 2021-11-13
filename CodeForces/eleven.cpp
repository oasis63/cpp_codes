#include <bits/stdc++.h>
using namespace std;

int fiboArr[1001]={0};

int fibo(int n){

    if(fiboArr[n] == 0){
        if(n<=1)
            fiboArr[n]=n;
        else
            fiboArr[n] = fibo(n-1) + fibo(n-2);
    }
    return fiboArr[n];
}


int main()
{
    int fiboTest[1001] = {0};

    for(int i=0;i<18;i++){
        int t = fibo(i);
        //cout<<t<<endl;
        if(t<=1000)
            fiboTest[t] = 1;
    }

    /*for(int i=0;i<1001;i++){
        if(fiboTest[i])
            cout<<i<<" ";
    }*/

    string ans = "";

    int n;cin>>n;

    for(int i=1;i<=n;i++){
        if(fiboTest[i]){
            ans+="O";
        }else{
            ans+="o";
        }
    }


    cout<<ans<<endl;

}
