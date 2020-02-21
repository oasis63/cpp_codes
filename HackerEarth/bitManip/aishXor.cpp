#include <bits/stdc++.h>
using namespace std;

#define size 100001

int input[size]={0};
int xC[size]={0};
int unset[size]={0};


// Using dynamic programming ... storing the calculated value in the two arrays


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,q,l,r;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>input[i];

        if(input[i]==0){
            if(i==0){
                unset[i]=1;
            }
            else{
                unset[i] = unset[i-1]+1;
            }
        }
        else{
            unset[i] = unset[i-1];
        }

        if(i==0){
            xC[i]=input[i];
        }
        else{
            xC[i]=xC[i-1]^input[i];
        }

    }
    
    cin>>q;

    while(q--){
        cin>>l>>r;
        l--;r--;

        if(l==0){
            cout<<xC[r]<<" ";
            cout<<unset[r]<<endl;
        }
        else{
            cout<<(xC[r]^xC[l-1])<<" ";

            cout<<(unset[r]-unset[l-1])<<endl;
        }
    }


}
