#include<bits/stdc++.h>
using namespace std;

// printing all the subsets of a array

int hasSet(int n,int j){
    if((n&(1<<j)))
        return 1;
    return 0;
}

void subset(int input[],int n){

    int sum=0;

    for(int i=1;i<(1<<n);i++){
        int mn=INT_MAX;
        int mx=INT_MIN;

        for(int j=0;j<n;j++){
            if(hasSet(i,j)){
                cout<<input[j]<<" ";
                if(input[j] > mx)
                    mx=input[j];

                if(input[j] < mn)
                    mn=input[j];
            }
        }

        cout<<"\t\t"<<"min ="<< mn<<"\t Max="<<mx<<"\t min*max="<<mn*mx;

        sum+=mn*mx;

        cout<<endl;
    }
    cout<<endl;

    cout<<"\n\t"<<sum<<endl;
}

int main(){
   int input[]={5,7,2,3,9};
   //int input[]={1,2,3};
   subset(input,5);
}
