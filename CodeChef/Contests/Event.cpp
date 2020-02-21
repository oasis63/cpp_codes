#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string fff,sss;
int ss;
 int subtract=0;
 int l,r;
       int main()
{unordered_map<string,int> store({{"monday",1},{"tuesday",2},{"wednesday",3},{"thursday",4},{"friday",5},{"saturday",6},{"sunday",7}});
cin>>ss;
       while(ss--)
    {cin>>fff>>sss>>l>>r;
        if(store[fff]<=store[sss])
        {
        subtract=store[sss]-store[fff]+1;
        }
        else
        {subtract=7-(store[fff])+store[sss]+1;
        }
       //     cout<<subtract<<"\n";
        
        int total=0;
        int value=subtract;
        
        for(int i=subtract;i<=100;i+=7)
        {
        	if(i>=l && i<=r)
            {
            	total++;
                value=i;
            }
        }

        if(total>1)
        {
        cout<<"many\n";
            continue;
        }
        if(total==1)
        {
            cout<<value<<"\n";
            continue;
        }

        cout<<"impossible\n";
        continue;}

  
}
