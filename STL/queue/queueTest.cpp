#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int>q;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;

        q.push(t);
    }

    for(int i=0;i<n;i++)
    {
        cout<<"Front element "<<q.front()<<" ";
        cout<<"End element "<<q.back()<<" ";
        q.pop();
        cout<<endl;
    }
}

/* Queue uses the first in first out(FIFO) concept
    
    important functios

    1)  push()           // element is pushed at the back of the queue
    2)  pop()           // element from the front of the queue is popped 
    3)  front()         // returns the element at the front of the queue
    4)  back()          // returns the element at the back of the queue
    5)  size()           // returns the size of the queue
    6)  empty()         // checks whether the queue is empty

*/