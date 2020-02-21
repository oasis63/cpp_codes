#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;cin>>tc;
    while(tc--){
        int n,k;cin>>n>>k;
        char a[n][n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }

        int count=0,f,b;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='P'){
                    for(int m=1;m<=k;m++){
                        f=j+m;
                        b=j-m;

                        if(a[i][b]=='T' && b>=0){
                            a[i][b]='C';
                            count++;
                            break;
                        }
                        else if(a[i][f]=='T' && f<n){
                            a[i][f]='C';
                            count++;
                            break;
                        }

                    }

                }
            }
        }

        cout<<count<<endl;

    }

}
