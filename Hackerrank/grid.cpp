 #include <bits/stdc++.h>
using namespace std;

void swap(char*a,char *b)
{
    char temp = *a;
    *a=*b;
    *b=temp;
}

void bubbleSort(char*a,int n)     // call by address
{ 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if( a[j+1]<a[j] && (j+1)<n)    // increasing order
                swap(&a[j+1],&a[j]);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    
    while( t-- )    
    {
        int n;
        cin>>n;
        
        char grid[n][n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>grid[i][j];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            bubbleSort(grid[i],n);
        }

        bool row = true;
        bool column = true;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                //cout<<grid[i][j]<<" ";
                if( (grid[i][j+1] < grid[i][j]) && (j+1)<n)  // comparing the elements rowwise
                {
                     row = false;
                     cout<<"In the row"<<endl;
                     cout<<" Values \t"<<grid[i][j+1]<<" "<<grid[i][j]<<endl;
                }   

                if( grid[i+1][j] < grid[i][j] && (i+1)<n)  // comparing the elements columnwise
                {
                    column = false;
                    cout<<"in the column"<<endl;
                }
            }
            //cout<<endl;
        }

       // cout<<(row && column)<<endl;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<endl;

        if( row && column)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }



}