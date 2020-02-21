#include<bits/stdc++.h>
using namespace std;

int main(){

    deque<int> q;

    for(int i=0;i<5;i++){
        q.push_back(i);
    }

    deque<int>:: reverse_iterator it = q.rbegin();
   // it++;
    //it++;
    q.insert(it.base(),34);   // inserting from back of the deque


    deque<int>:: iterator itr = q.begin();
    cout<<endl;
    while(itr!=q.end()){
        cout<<*itr<<" ";
        itr++;
    }
    cout<<endl;
}
