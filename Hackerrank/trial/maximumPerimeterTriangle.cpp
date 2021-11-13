#include<bits/stdc++.h>
using namespace std;

int min(vector<int> v)
{
    int m=v[0];
    
    for(int i=0;i<v.size();i++)
    {
        if( v[i] < m)
            m=v[i];
    }
    
    return m;
}

int max(vector<int> v)
{
    int m=v[0];
    
    for(int i=0;i<v.size();i++)
    {
        if( v[i] > m)
            m=v[i];
    }
    
    return m;
}

int fact(int n)
{
    int f=1;
    for(int i=1;i<=n;i++)
    {
        f=f*i;
    }
    
    return f;
}
int comb(int n,int r)
{
    int n1 = fact(n);
    int d1=fact(r);
    int d2 = fact(n-r);
    
    return(n1/(d1*d2));
}

bool triangleTest(int a,int b,int c)
{
    bool ans = true;
    
    if( (a+b) <= c)
        ans = false;
    else if ( (a+c) <= b)
        ans = false;
    else if( (b+c) <= a)
        ans = false;
       
    return ans; 
}

int main()
{
    int n;
    cin>>n;
    
    int a[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int cmb = comb(n,3);
    
    vector<int> v[cmb];
    
    int index=0;
    
    int count = 0;
    
    int get=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
           for(int k=j+1;k<n;k++)
           {
               if( triangleTest(a[i],a[j],a[k]) )
               {
                   v[index].push_back(a[i]);
                   v[index].push_back(a[j]);
                   v[index].push_back(a[k]);    
                   index ++;
                  // cout<<"Exexuted"<<endl;
                   get = 1;
               }                   
           }
        }
    }
    
    if( index == 1)
    {
        for(int i=0;i<v[0].size();i++)
        {
            cout<<v[0][i]<<" ";
        }
    }
    else if(index > 1 )
    {
        int pos;
        int maxLen=0;
        int minLen=0;
        
        for(int i=0;i<index;i++)
        {
            int temp = max(v[i]);
            
            if( temp > maxLen)
            {
                maxLen = temp;
                pos = i;
            }
            else if( temp == maxLen)
            {
                int temp2 = min(v[i]);
                if( temp2 > minLen)
                {
                    pos=i;
                }
            }
        }
        
        for(int i=0;i<v[pos].size();i++)
        {
            cout<<v[pos][i]<<" ";
        }
    }
    
    if( get == 0)
        cout<<-1<<endl;
     
}
