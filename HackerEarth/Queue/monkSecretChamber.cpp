#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){

    ll n,x,v;
    cin>>n>>x;

    queue<pair<int,int>> elem;

    for(int i=1;i<=n;i++){
        cin>>v;
        elem.push(make_pair(v,i));
    }

    v = x;

    while(v--){


        int t = x;
        queue<pair<int,int>> temp;
        pair<int,int> p(INT_MIN,-1);

        pair<int,int> tt;

        if(elem.size() > x){

            while(t--){
                tt = elem.front();
                elem.pop();
                temp.push(tt);

                if(tt.first > p.first){
                    p.first = tt.first;
                    p.second = tt.second;
                }
            }

            while(!temp.empty()){
                tt = temp.front();
                temp.pop();

                int f1 = tt.first;
                int s1 = tt.second;

                if(s1 != p.second){

                    if(f1 == 0)
                        elem.push(make_pair(f1,s1));
                    else
                        elem.push(make_pair(f1-1,s1));
                }
            }

            cout<<p.second<<" ";

        }else{

            while(!elem.empty()){
                tt = elem.front();
                elem.pop();
                temp.push(tt);

                if(tt.first > p.first){
                    p.first = tt.first;
                    p.second = tt.second;
                }
            }

            while(!temp.empty()){
                tt = temp.front();
                temp.pop();
                int f1 = tt.first;
                int s1 = tt.second;

                if(s1 != p.second){

                        if(f1 == 0)
                                elem.push(make_pair(f1,s1));
                        else
                            elem.push(make_pair(f1-1,s1));
                }
            }


            cout<<p.second<<" ";

        }
    }


    return 0;

}

/*

6 5
1 2 2 3 4 5

5 6 4 1 2


*/
