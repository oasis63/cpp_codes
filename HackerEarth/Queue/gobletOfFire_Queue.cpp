#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){

   ll tc;cin>>tc;
   char opt;
   ll s,r;

   deque<pair<int,int>> dq;

   int school[5];  //  4 schools
   memset(school,0,sizeof(school));


   queue<int> sch[5];
   list<int> order;


   while(tc--){
        cin>>opt;
        if(opt == 'E'){
            cin>>s>>r;

            school[s]++; // increment the number of students in the school s
            sch[s].push(r); // add the element to the school s

            if(order.empty()){
                order.push_back(s);
            }else{
                list<int>:: iterator it = order.begin();

                bool found = false;
                while(it!=order.end()){
                    if(*it == s){
                        found = true;
                        break;
                    }
                    it++;
                }

                if(!found){
                    order.push_back(s);
                }
            }
        }
        else if(opt=='D'){
            int f1 = order.front();

            int f2 = sch[f1].front();
            sch[f1].pop();
            school[f1]--;

            if(school[f1] == 0){
                order.pop_front();
            }

            cout<<f1<<" "<<f2<<endl;
        }
   }

}

/*

4
E 1 1
E 2 1
E 4 3
E 1 3
D
D

output:

1 1
1 2

*/

