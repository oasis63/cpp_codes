#include <bits/stdc++.h>
using namespace std;

int subArray(int a[],int n)
{
    int size = pow(2,n)-1;

    int sub[size][n]={0};

    int  row=0,col=0;

    int result = 0;


    for(int i=0;i<n;i++)
    {

        for(int j=i;j<n;j++)
        {
            col = 0;

            for(int k=i;k<=j;k++)
            {
                sub[row][col] = a[k];  // subarrays;
                
                col++;
            }


            char sign = 'o';

            for(int m=0;m<col;m++)
            {
            

                if( (m+1) < col)
                {
                    if( sign == 'o')
                    {
                        sub[row][m+1] = sub[row][m+1] | sub[row][m];
                        sign = 'x';
                    }
                    else if( sign == 'x')
                    {
                        sub[row][m+1] = sub[row][m+1] ^ sub[row][m];
                        sign = 'a';
                    }
                    else if( sign == 'a')
                    {
                        sub[row][m+1] = sub[row][m+1] + sub[row][m];
                        sign = 'o';
                    }

                }

                if( sub[row][col-1] > result)
                    result = sub[row][col-1];


            }

            row++;


        }

    }


    //cout<<result<<endl;

    return result;
}

int main()
{ 


    int t;
    cin>>t;

    while( t-- )
    {
        string s;
        cin>>s;

        int n;
        cin>>n;

    
        int num[n];

        for(int i=0;i<n;i++)
        {
            cin>>num[i];
        }

        int result = subArray(num,n);

        string s2;

        if( result & 1)
            s2 = "Odd";
        else
            s2 = "Even";

        if( s==s2)
            cout<<"Monk"<<endl;
        else
            cout<<"Mariam"<<endl;

    }
}