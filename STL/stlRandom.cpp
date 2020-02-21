#include<bits/stdc++.h>
using namespace std;

int main(){

    unsigned s = 2;

    default_random_engine generator(s);

    uniform_int_distribution<int> distribution(1,10);

    cout<<"Some random numbers between 1 and 10 "<<endl;

    for(int i=0;i<10;i++){
        cout<<distribution(generator)<<endl;
    }

    cout<<endl;

    return 0;
}
