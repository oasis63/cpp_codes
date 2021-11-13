#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>>t;

    while( t-- )
    {
        int n;
        cin>>n;

        if( n==1 || n==2 || n==4 || n==7 )
            cout<<-1<<endl;
        else
        {

            int noFive;
            int noThree;

            string s;

            /* dividing first, with 3 to get the number of 5 to be added
                because we want the maximum number  */

            if( n%3 == 0)
            {
                noFive=n;
                noThree=0;
            }
            else if( n%3 == 1)
            {
                noFive=n-10;
                noThree=n-noFive;
            }
            else if( n%3 == 2)
            {
                noFive=n-5;
                noThree=n-noFive;
            }

            for(int i=0;i<noFive;i++)
                s.append("5");
            for (int i = 0; i < noThree; ++i)
            {
                s.append("3");
            }

            cout<<s<<endl;
        }
    }
}