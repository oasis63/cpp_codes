//Array template has fixed size
#include <iostream>
#include <array>
using namespace std;

int main()
{
    array < int, 5> arr;

    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }

    for(int i = 0;i<5;i++)
    {
        cout<<arr.at(i)<<" ";
    }

    cout<<"\nElement at the front is  " <<arr.front()<<endl;
    cout<<"Element at the back is "<<arr.back()<<endl;

    cout<<"\nBeginnig pointer address is "<<arr.begin()<<endl;
    cout<<"\nEnding pointer address is "<<arr.end()<<endl;

    array <int,5> arr2;
    arr2.fill(5);

    cout<<"\nSize "<<arr.size()<<endl;

    for(int i=0;i<5;i++)
    {
        cout<<arr2[i]<<" ";
    }

    arr.swap(arr2);  

    cout<<"\nAfter swaping the elements from arr2 to arr "<<endl;
    cout<<"\nElements in the array arr"<<endl;

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }

}