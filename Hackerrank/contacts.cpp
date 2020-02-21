#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;cin>>n;
    string opr,val;

    map<string,int> names;

    for(int i=0;i<n;i++){
        cin>>opr>>val;

        if(opr=="add"){

            int len = val.length();
            // use the substrings

            for(int subCount=1;subCount<=len;subCount++){

                    string sub = val.substr(0,subCount);

                    if(!names[sub]){
                        names[sub]=1;
                    }else{
                        names[sub] = names[sub]+1;
                    }
            }

        }else {

            if(!names[val]){
                cout<<0<<endl;
            }else{
                cout<<names[val]<<endl;
            }

        }
    }

}


/*

11
add s
add ss
add sss
add ssss
add sssss
find s
find ss
find sss
find ssss
find sssss
find ssssss



5
4
3
2
1
0




*/
