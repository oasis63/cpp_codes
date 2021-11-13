// queue using two stacks

#include<bits/stdc++.h>
using namespace std;

stack<int> front,rear;

void enque(int d){
    rear.push(d);
}

int tdeque(){

    int t = INT_MIN;

    if(front.empty()){
        while(!rear.empty()){
            front.push(rear.top());
            rear.pop();
        }
    }

     t=front.top();
     front.pop();

    return t;
}

int main(){
    for(int i =0;i<5;i++)
        enque(i);
    for(int i=0;i<5;i++)
        cout<<tdeque()<<endl;
}
