#include <bits/stdc++.h>
using namespace  std;

/* Repetition of elements not allowed in set */

int main()
{
    set<int> s;

    int n;
    cout<<"\nEnter the number of elements\n"<<endl;
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin>>x;

        s.insert(x);  // inserting the element
    }

    cout<<s.size()<<endl;  // size of the set

    set<int>::iterator itr = s.begin();

    while( itr != s.end())
    {
        cout<<*itr<<" ";
        itr ++;
    }

    int val;
    cout<<"Enter a value that you want to erase from the set"<<endl;
    cin>>val;

    s.erase(val);     // erases only the specific value from the set

    s.clear();    // clears all the element of the set

    cout<<s.size()<<endl;

    return 0;
}