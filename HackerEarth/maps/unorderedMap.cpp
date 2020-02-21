#include<bits/stdc++.h>
using namespace std;

//#define ll long long

int main(){

    int n;
    cin>>n;
    string s;

    unordered_map<string,int>names;

    while(n--){
        cin>>s;

        if(names.find(s) == names.end()){
            names[s]=0;
            cout<<s<<endl;
        }else{

            int k = names[s];
            string temp = s + to_string(k);

            while(names.find(temp) != names.end()){
                k++;
                temp = s + to_string(k);
            }

            cout<<temp<<endl;
            names[temp]=0;
            names[s]=k+1;
        }

    }


}

