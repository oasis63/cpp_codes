#include <bits/stdc++.h>
using namespace std;

// uses FILO :- first in first out

#define rec(n) for(int i=0;i<n;i++)

int main()
{
    stack<int> s;
    cout<<s.size()<<endl;

    int n;
    cin>>n;

    rec(n)
    {
        int temp;
        cin>>temp; 
        s.push(temp);
    }

    cout<<s.size()<<endl;

    rec(n)
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    //
    // stack<int>:: iterator itr = s.begin();
    //
    // while( itr < s.end())
    // {
    //     cout<<*itr<<" ";
    //     itr ++;
    // }

    cout<<"\nSize of the stack after poping all the elements"<<endl;
    cout<<s.size()<<endl;

    return 0;
}
