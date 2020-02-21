#include<bits/stdc++.h>
using namespace std;

void display(vector<int> vect){
    int len = vect.size();

    for(int i=0;i<len;i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}

vector<int> setFibonacci(int k){

    vector<int> fibo;

    fibo.push_back(0);
    fibo.push_back(1);
    fibo.push_back(1);

    int i=3,nextItem;

    while(1){
        nextItem = fibo[i-1]+fibo[i-2];

        if(nextItem > k)
            break;

        fibo.push_back(nextItem);
        i++;
    }

   return fibo;
}


int minCount(vector<int> fibo,int k){
    int count=0;

    int len = fibo.size();

    int i = len-1;

    while(k){
        count += k/fibo[i];
        k=k%fibo[i];
        i--;
    }

    return count;
}


int main(){

    vector<int> fibo;
    int k=17;            //
    fibo = setFibonacci(k);
   // display(fibo);

   int count = minCount(fibo,k);   // minimum count of Fibonacci numbers

   cout<<count<<endl;
}
