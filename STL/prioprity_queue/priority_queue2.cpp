#include<bits/stdc++.h>
using namespace std;

template<typename T>
void print(T& pq){
    // iterator

    //pq.push(34);

    while(pq.size()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main(){

    priority_queue<int> pq;

    int input[] = {4,2,5,8,9,0,10};

    for(int n : input)
        pq.push(n);

    print(pq);


    priority_queue<int,vector<int>,greater<int> > pq2;

    for(int n : input)
        pq2.push(n);

    print(pq2);

}
