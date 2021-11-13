#include<bits/stdc++.h>
using namespace std;

int main(){

    /* initialize random seed: */
    srand (time(0));        // important

    for(int i=0;i<10;i++){
        int n = rand()%(100+1);
        cout<<n<<endl;
    }

    return 0;
}
