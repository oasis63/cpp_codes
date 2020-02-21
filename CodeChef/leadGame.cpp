#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int tc,a,b,temp;cin>>tc;
    
    int lead = 0;
    int win=1;
    int scoreA=0;
    int scoreB=0;

    while(tc--){
        
        cin>>a>>b;
        scoreA += a;
        scoreB += b;

        if(scoreA > scoreB){
            temp = scoreA - scoreB;
            if(temp > lead){
                lead = temp;
                win=1;
            }
        }else{
            temp = scoreB - scoreA;
            if(temp > lead){
                lead = temp;
                win=2;
            }

        }
    }


    cout<<win<<" "<<lead<<endl;


    return 0;
}   