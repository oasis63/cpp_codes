#include<bits/stdc++.h>
using namespace std;

void sortString(char str[],int n,int k,int l,int r){

    int hash[26] ;

    for(int i=0;i<26;i++)
        hash[i]=0;


    for(int i=l;i<r && i<n;i++){
        hash[str[i]-'a']++;
    }


    for(int i=0;i<26;i++){

        if(hash[i])
            k-=hash[i];

        if(k<=0){
            cout<<(char)(i+97)<<endl;
            break;
        }
    }

}

int main(){

    int n,q;
    cin>>n>>q;
    char str[n];
    cin>>str;

    int l,r,k;
    while(q-- >0){
        cin>>l>>r>>k;

        int len = r-l+1;
        l--;

        if(k>len){

            cout<<"Out of range"<<endl;

        }else{


            sortString(str,n,k,l,r);


        }


    }
}
