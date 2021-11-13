#include <bits/stdc++.h>
using namespace std;

int main(){

    int j=1;
    int count=0;
    int sum = 0;
    int divisions = 0;

    for(int i=100,j=1;i>=1 && j<=100 && j<=i;i--,j++){
       sum += i+j;
       count++;

       cout<<i<<" "<<j<<endl;

       if(count==5){
        cout<<"Sum : "<<sum<<"\n\n";
        sum=0;
        count=0;
        divisions++;
       }

    }

    cout<<divisions<<endl;

}
