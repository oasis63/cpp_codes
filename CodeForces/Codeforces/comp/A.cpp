#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    int n,k,m;cin>>n>>k>>m;
    string lang[n];
    map<string,int> myMap;

    for(int i=0;i<n;i++){
        cin>>lang[i];
        myMap[lang[i]] = i;
    }

    int cost[n];

    for(int i=0;i<n;i++){
        cin>>cost[i];
    }

    vector<int> *v;    // grouping
    v = new vector<int>[k];

    for(int i=0;i<k;i++){
        int t,c;cin>>t;
        while(t--){
            cin>>c;
            v[i].push_back(c);
        }
    }

    string inputStr[m];

    for(int i=0;i<m;i++){
        cin>>inputStr[i];
    }

    // Choosing the smallest cost

    for(int i=0;i<k;i++){
        int smallest = cost[v[i][0]-1];

        for(int j=1;j<v[i].size();j++){
            if(cost[v[i][j]-1] < smallest){
                smallest = cost[v[i][j]-1];
            }
        }

        for(int j=0;j<v[i].size();j++){
            cost[v[i][j]-1] = smallest;
        }
    }

    int ans = 0 ;

    for(int i=0;i<m;i++){
        ans += cost[myMap[inputStr[i]]];
    }

    cout<<ans<<endl;


    return 0;
}

