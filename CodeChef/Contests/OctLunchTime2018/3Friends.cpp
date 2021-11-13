#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc,x,y,z,mx,md,mn;
    cin>>tc;

    while(tc--){
        cin>>x>>y>>z;

//        if(x==y && y==z){
//            cout<<"no"<<endl;
//        }else{

            mx=max(x,y);
            mx=max(mx,z);

            mn=min(x,y);
            mn=min(mn,z);

            if((mx==x && mn==y) || (mx==y && mn==x)){
                md=z;
            }else if((mx==x && mn==z) || (mx==z && mn==x)){
                md=y;
            }else if((mx==z && mn==y) || (mx==y && mn==z)){
                md=x;
            }

//            cout<<mx<<" "<<md<<" "<<mn<<endl;

            if((mn+md) == mx){
                cout<<"yes"<<endl;
            }else{
                cout<<"no"<<endl;
            }

        //}
    }
}

