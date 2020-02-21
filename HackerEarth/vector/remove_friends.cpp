#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){
    
    int tc;
    cin>>tc;

    while(tc--){
        int n,k,x=0,v;
        cin>>n>>k;

        vector<int> vect;

        while(n--){
            cin>>v;

            while(!vect.empty() && x < k && vect.back() < v){
                vect.pop_back();
                x++;
            }
            vect.push_back(v);
        }

        while(x < k){
            vect.pop_back();
            x++;
        }

        for(int i=0;i<vect.size();i++){
            cout<<vect[i]<<" ";
        }

        cout<<endl;
    }

    return 0;
}   

/*sample

#1...input
7 3
8 10 6 15 9 4 10


#1...output
15 9 4 10



*/