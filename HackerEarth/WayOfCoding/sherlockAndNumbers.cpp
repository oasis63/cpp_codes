#include <bits/stdc++.h>
using namespace  std;

#define ll long long


int main()
{
    ll tc,n,k,p;cin>>tc;
    while(tc--){
        cin>>n>>k>>p;


        if(n<=100000){   // testcase below 100000
            set<ll> s;
            for (ll i = 0; i < n; ++i)
            {
                s.insert(i+1);  // inserting the element
            }

            for(ll i=0;i<k;i++){
                ll temp;cin>>temp;
                s.erase(temp);
            }

            //printSet(s);

            if(p > s.size()){
                cout<<-1<<endl;
            }
            else{
                set<ll>::iterator itr = s.begin();

                while(itr!=s.end() && p>1){
                    itr++;
                    p--;
                }
                cout<<*itr<<endl;
            }
        }

        else{    // testcases above 100000
            int in=n-k;
            int p1=p;

            for(ll i=0;i<k;i++){
                ll temp;cin>>temp;
                if(p > temp)
                    p++;
                else if(p==temp)
                    p+=2;
            }

            if(p1  > in) {
                cout<<-1<<endl;
            }
            else{
                cout<<p<<endl;
            }
        }

    }
}
