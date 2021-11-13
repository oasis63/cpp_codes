#include<bits/stdc++.h>
using namespace std;

void printMap(map<int,int> mp){

    for(auto it = mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
}

vector<int> dNums(vector<int> &vect, int k) {

    int n = vect.size();
    vector<int> ans;
    map<int,int> mp;  // element and count

    if(n<k){
        for(int i=0;i<n;i++){
            if(mp.find(vect[i]) != mp.end()){
                mp.insert(make_pair(vect[i],1));
            }else{
                mp[vect[i]]++;
            }
        }

        ans.push_back(mp.size());

        return ans;
    }

     for(int i=0;i<k;i++){
        if(mp.find(vect[i]) == mp.end()){   // element is absent
            mp.insert(make_pair(vect[i],1));
        }else{
            mp[vect[i]]++;
        }
    }

    ans.push_back(mp.size());

    for(int i=1;i<=(n-k);i++){

        int firstElem = vect[i-1];
        int currElem = vect[i+k-1];  // last element to be added to the map

        if(firstElem == currElem){
            ans.push_back(mp.size());
            continue;
        }

        mp[currElem]++;

        if(mp[firstElem] == 1){
            mp.erase(firstElem);
        }else{
            mp[firstElem]--;
        }

        ans.push_back(mp.size());
    }

    return ans;
}


int main() {

    vector<int> vect{1, 2, 1, 3, 4, 3};
    int k = 3;

    vector<int> ans = dNums(vect,k);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";


    return 0;
}
