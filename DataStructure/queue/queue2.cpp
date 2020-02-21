#include<bits/stdc++.h>
using namespace std;

int main(){

    queue<int>q;

    // first in first out // FIFO

    q.push(34);
    q.push(20);
    q.push(12);
    q.push(59);


    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

    cout<<"\nsize = "<<q.size()<<endl;

    int len = q.size();

    cout<<"\nApplying pop operation \n"<<endl;
    q.pop();

    len = q.size();

    cout<<"\nNew Size : "<<q.size()<<endl;

    cout<<"\nElements of the queue \n"<<endl;

    for(int i=0;i<len;i++){
        cout<<q.front()<<" ";
        q.pop();
    }

     cout<<endl;

}
