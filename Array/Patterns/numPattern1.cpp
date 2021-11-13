#include<bits/stdc++.h>
using namespace std;


void solve(int n){

    int dashes = n/2;

    for(int i=0;i<dashes;i++){
        cout<<" ";
    }

    dashes--;

    cout<<1<<endl;
    int even = 2;
    int odd = 3;

    int freq=2;
    int tok2=1;    // before mid of the pattern

    for(int i=0;i<n-1;i++){

        if(i%2!=0){ // odd

            for(int i=0;i<dashes;i++){
                cout<<" ";
            }


            for(int j=0;j<freq;j++){
                cout<<odd<<" ";
                odd+=2;
            }


            if(i==n/2)
                tok2=0;

            if(freq <=n/2 && tok2){
                freq++;
                dashes--;
            }else{
                freq--;
                dashes++;
            }

        }else{

            for(int i=0;i<dashes;i++){
                cout<<" ";
            }

            for(int j=0;j<freq;j++){
                cout<<even<<" ";
                even+=2;
            }

            if(i==n/2)
                tok2=0;


            if(freq <=n/2  && tok2){
               freq++;
               dashes--;
            }else{
               freq--;
               dashes++;
            }
        }
        cout<<endl;

    }

}


int main(){

    solve(3);

    cout<<endl;

    solve(5);

}
 