//Array template has fixed size
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> vin;

    cout<<"\nSize is : "<<vin.size()<<endl;
    cout<<"Capacity is : "<<vin.capacity()<<endl;

    for(int i =0;i<4;i++)
    {
        int t;
        cin>>t;

        vin.push_back(t);
    }




    for(int i=0;i<vin.size();i++)
    {
        cout<<vin[i]<<" ";
    }

    cout<<"\nEnter the place where you want to add an element";
    int pos;
    cin>>pos;

    vector <int> :: iterator p;    // iterator is just like a pointer
    p = vin.begin();

    vin.insert(p+pos,43);


     for(int i=0;i<vin.size();i++)
    {
        cout<<vin[i]<<" ";
    }



    cout<<"\nSize is : "<<vin.size()<<endl;
    cout<<"Capacity is : "<<vin.capacity()<<endl;

}
