#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long


vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = '_';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

bool compare(int a,int b){
	return a<b;
}



void solve(string A, vector<string> &B) {
    
    vector<string> goodWords = split_string(A);

    set<string> goodWordSet;

    for(string str : goodWords){
    	goodWordSet.insert(str);
    }

    // cout<<"count of good words " << goodWordSet.size()<<endl;

   /* if(goodWordSet.find("cool") != goodWordSet.end())
    	cout<<"cool is present"<<endl;
    else
    	cout<<"cool is absent"<<endl;*/

    int len = B.size();


    // store the map values in descending order of the key 
    map<int,vector<int>,greater <int> > mp;  // count,indices

    vector<int> ans;

    for(int i=0;i<len;i++){
    	string temp = B[i];
    	vector<string> ret = split_string(temp);
    	int cnt = 0;
    	// cout<<i<<endl;
    	for(string s : ret){
    		if(goodWordSet.find(s) != goodWordSet.end()){
    			// cout<<"\t"<<s<<endl;
    			cnt++;
    		}
    	}
    	mp[cnt].push_back(i);
    }


   for(auto it = mp.begin();it!=mp.end();it++){
       
        vector<int> tp = it->second;
       
        for(int i=0;i<tp.size();i++){
            ans.push_back(tp[i]);
        }
    }


    for(int i : ans){
    	cout<<i<<" ";
    }

}


int main(){
	
	string s = "cool_ice_wifi";
	vector<string> vect{"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};
	
	solve(s,vect);

	return 0;
}