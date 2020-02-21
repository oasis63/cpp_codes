#include <bits/stdc++.h>
using namespace std;

map<int,int>m;

int count3 = 0;

bool  isAns(vector<int> v)
{
    int g=0;
    int max = v[0];

    for(int i=0;i<v.size();i++)
    {
        if( v[i] > max)
        {
            max=v[i];
            g=i;
        }
    }

    int secondMax;

    if( g == 0)
        secondMax=v[v.size()-1];
    else
        secondMax=v[0];

    int sm = 0;

    for(int i=0;i<v.size();i++)
    {
        if(v[i] > secondMax && i != g)
        {
            secondMax = v[i];
            sm=i;
        }
    }

    // cout<<"\nPassed elements to the function"<<endl;

    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v[i]<<" ";
    // }


    // cout<<"\nmax "<<max<<" Index " <<g<<endl;
    //  cout<<"secondMax "<<secondMax<<"  Index is "<<sm<<endl;

    if( sm < g)
    {
        //cout<<"\nInseted"<<endl;
        m.insert(make_pair(sm+1,g+1));

        map<int,int>::iterator itr = m.find(sm+1);

        if( itr != m.end())
        {
            if( itr->second != (g+1))
                count3++;
        }


        return true;
    }

    return false;

}

void subArray(int arr[], int n)
{
    int size = pow(2,n);

    vector<int>v[size];

    int index = 0;
 
    for (int i=0; i <n; i++) //select the starting element
    {

      for (int j=i; j<n; j++)   //select the ending element
      {
          for (int k=i; k<=j; k++)

          {
             // cout << arr[k] << " "; //print all elements between start and end element.

              v[index].push_back(arr[k]);
          }
        //cout<<endl;
        index++;
      }
    }

    // cout<<"\nprinting using the vector container"<<endl;

    // for(int i=0;i<index;i++)
    // {
    //     for(int j=0;j<v[i].size();j++)
    //     {
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int count = 0;


    for(int i=0;i<index;i++)
    {
        if( v[i].size() >= 2)
        {
            if( isAns(v[i]))
                count++;
        }

    }

   // cout<<count<<endl;

    int count2 = 0;

    map<int,int>::iterator itr = m.begin();

    while( itr != m.end())
    {
        count2 ++;
        //cout<<"\t\tFirst-element "<<itr->first<<"\tSecdond element :"<<itr->second<<endl;

        itr ++;
    }

    cout<<(count2+count3)<<endl;

  //  cout<<"\nCount 3 : "<<count3<<endl;
}

int main()
{
   int n;
   cin>>n;

   int a[n];

    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }

    subArray(a,n);
}

