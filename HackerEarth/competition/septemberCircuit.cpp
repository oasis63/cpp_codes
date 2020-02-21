#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCases;cin>>testCases;
    while(testCases--){
        int n;cin>>n;
        int coin[n];
        for(int i=0;i<n;++i) cin>>coin[i];

        string ch = "Charlie";
        string al = "Alan";

        bool get = true;
        int count=0;

        while(get){

            int found=0;

            for(int i=0;i<n;i++){
                if(coin[i]%2==0){
                    coin[i] /=2;
                    found=1;
                    count++;
                    break;
                }
            }

            if(found==0)
                get=false;
        }

        if(count%2==0)
            cout<<al<<endl;
        else
            cout<<ch<<endl;

    }
}
