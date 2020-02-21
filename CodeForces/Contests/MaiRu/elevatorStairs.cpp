#include<bits/stdc++.h>
using namespace std;

int  main(){

    int x,y,z,t1,t2,t3;
    cin>>x>>y>>z>>t1>>t2>>t3;


    int lift = abs(x-z)*t2+3*t3+abs(x-y)*t2;

    int stairs = abs(x-y)*t1;

    //cout<<lift<<endl;
    //cout<<stairs<<endl;

    if(lift <= stairs)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}
