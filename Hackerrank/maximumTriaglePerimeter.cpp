#include <bits/stdc++.h>
using namespace std;

int isTriangle(int a,int b,int c)
{
   return ( (a+b) > c);
}

void print(std::vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> v;
    
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    //sorting in decreasing order

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if( v[j+1] > v[j] && (j+1)< n)
            {
                int temp = v[j+1];
                v[j+1]=v[j];
                v[j]=temp;
            }
        }
    }
    
   // print(v);

    int get = 0;
    
    for(int i=0;i<v.size();i++)
    {
        if( isTriangle(v[i+2],v[i+1],v[i]) && (i+2) < n)
        {
            cout<<v[i+2]<<" "<<v[i+1]<<" "<<v[i]<<endl;
            get=1;
            break;
        }
    }
    
    if( get == 0)
        cout<<-1<<endl;
}