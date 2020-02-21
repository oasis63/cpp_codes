#include<bits/stdc++.h>
using namespace std;


bool comparator(pair<string,int> p1,pair<string,int>p2){

    if(p1.second < p2.second){
        return 1;
    }else if(p1.second > p2.second){
        return 0;
    }else{
        if(p1.first < p2.first)
            return 1;
        else
            return 0;
    }

}

int main(){

    map<string,int> mp;
    int n;cin>>n;
    string str;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>str;
        cin>>tmp;
        mp.insert(make_pair(str,tmp));
    }

    vector<pair<string,int>> vect;


    map<string,int>::iterator itr = mp.begin();

    while(itr!=mp.end()){
        //cout<<itr->first<<" "<<itr->second<<endl;
        vect.push_back(*itr);
        itr++;
    }

    int len = vect.size();

    sort(vect.begin(),vect.end(),comparator);

    for(int i=0;i<len;i++){
        cout<<vect[i].first<<"  "<< vect[i].second<<endl;
    }
}

/*

4
rajesh 43
bosak 3342
apple 32
cat 50

*/
