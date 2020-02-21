#include <bits/stdc++.h>
using namespace  std;

/* Repetition of elements not allowed in set */

int main()
{
    map<int,string> student;

    int n;
    cout<<"\nNo. of students"<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the name of roll no."<<(i+1)<<endl;
        string s;
        cin>>s;

        student[i+1] = s;

    }

    map<int,string>:: iterator itr = student.begin();

    while ( itr != student.end())
    {
        cout<<itr->first<<" "<<itr->second<<endl;
        itr ++;
    }


    cout<<"\nPrinting the data without using iterator "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<student.at(i+1)<<endl;
    }


    return 0;
}