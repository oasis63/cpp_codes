// queue using two stacks

#include<bits/stdc++.h>
using namespace std;

stack<int> f,rear;

void enque(int d){
    rear.push(d);
}

void tdeque(){

    int t = INT_MIN;

    if(f.empty()){
        while(!rear.empty()){
            f.push(rear.top());
            //cout<<rear.top()<<endl;
            rear.pop();
            //cout<<"Executed"<<endl;
        }
    }

     //t=front.top();
     f.pop();

    //return t;
}

void topElem(){
    if(f.empty()){
       while(!rear.empty()){
            f.push(rear.top());
            //cout<<rear.top()<<endl;
            rear.pop();
            //cout<<"Executed"<<endl;
        }
    }
    cout<<f.top()<<endl;
}

int main(){
   int q;cin>>q;
    while(q--){
        int type ;cin>>type;
        if(type==1){
            int x;cin>>x;
            enque(x);
        }
        else if(type==2){
            tdeque();
        }
        else if(type==3){
            topElem();
        }


    }
}
