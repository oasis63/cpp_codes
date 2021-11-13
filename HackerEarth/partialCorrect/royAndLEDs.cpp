#include <bits/stdc++.h>
using namespace std;

int main()
{
    int duration;
    int r,g,b;
    cin>>duration>>r>>g>>b;

    // int redArr[duration] = {0};
    // int greenArr[duration] = {0};
    // int blueArr[duration] = {0};
    
    vector<int>redArr(duration,0);
    vector<int>greenArr(duration,0);
    vector<int>blueArr(duration,0);
    
    // for(int i=0;i<duration;i++)
    // {
    //     redArr[i] = 0;
    // }
    
     for(int i=0;i<duration;i++)
    {
        greenArr[i] = 0;
    }
    
     for(int i=0;i<duration;i++)
    {
        blueArr[i] = 0;
    }

    int count = 0;

    for(int i=0;i<duration;i++)
    {
        if( count == r)
        {
            for(int j=0;j<r;j++)
            {
                redArr[i] = 1;
                i++;
            }
            count = 0;
        }

        count ++;

    }

    count = 0;

    for(int i=0;i<duration;i++)
    {
        if( count == g)
        {
            for(int j=0;j<g;j++)
            {
                greenArr[i] = 1;
                i++;
            }
            count = 0;
        }

        count ++;

    }

    count = 0;

    for(int i=0;i<duration;i++)
    {
        if( count == b)
        {
            for(int j=0;j<b;j++)
            {
                blueArr[i] = 1;
                i++;
            }
            count = 0;
        }

        count ++;

    }


    // cout<<"redArr"<<endl;

    // for(int i=0;i<duration;i++)
    // {
    //     cout<<redArr[i]<<" ";
    // }

    // cout<<"\ngreenArr"<<endl;

    // for(int i=0;i<duration;i++)
    // {
    //     cout<<greenArr[i]<<" ";
    // }

    // cout<<"\nblueArr"<<endl;

    // for(int i=0;i<duration;i++)
    // {
    //     cout<<blueArr[i]<<" ";
    // }

   int red=0,green=0,blue=0,yellow=0,cyan=0,magenta=0,white=0,black=0;

   for(int i=0;i<duration;i++)
   {

        if( redArr[i]==1 && greenArr[i]==0 && blueArr[i]==0)
        {
            red ++;
        }
        else if( redArr[i]==0 && greenArr[i]==1 && blueArr[i]==0 )
        {
            green ++;
        }
        else if( redArr[i]==0 && greenArr[i]==0 && blueArr[i]==1 )
        {
            blue ++;
        }
        else if( redArr[i]==1 && greenArr[i]==1 && blueArr[i]==0)
        {
            yellow ++;
        }
        else if( redArr[i]==0 && greenArr[i]==1 && blueArr[i]==1 )
        {
            cyan ++;
        }
        else if( redArr[i]==1 && greenArr[i]==0 && blueArr[i]==1 )
        {
            magenta ++;
        }
        else if( redArr[i]==1 && greenArr[i]==1 && blueArr[i]==1 )
        {
            white ++;
        }
        else if( redArr[i]==0 && greenArr[i]==0 && blueArr[i]==0 )
        {
            black ++;
        }
   }

   cout<<red<<" "<<green<<" "<<blue<<" "<<yellow<<" "<<cyan<<" "<<magenta<<" "<<white<<" "<<black<<" "<<endl;
}
