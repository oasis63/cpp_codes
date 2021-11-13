#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int> p1,pair<int,int>p2){

    if(p1.first < p2.first){
        return 1;
    }else if(p1.first > p2.first){
        return 0;
    }else{
        if(p1.second > p2.second)
            return 1;
        else
            return 0;
    }

}

int main(){

	int s,n;
	cin>>s>>n;

    vector<pair<int,int>> dragons;

	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		dragons.push_back(make_pair(a,b));
	}

	sort(dragons.begin(),dragons.end(),comparator);
    bool flag = true;


    for(int i=0;i<n;i++){
        if(s > dragons[i].first){
            s += dragons[i].second;
        }else{
            flag=false;
            break;
        }
    }

    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }


	return 0;
}
