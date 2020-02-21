#include <bits/stdc++.h>
using namespace std;

int main(){


    int n = 10;

    int a=0,b=1;

    for(int i=0;i<n;i++){
        cout<<a<<" ";

       a=a+b;
       b=a-b;

    }


}
