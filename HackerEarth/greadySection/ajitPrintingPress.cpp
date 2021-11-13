#include<bits/stdc++.h>
using namespace std;

string solve(string orig,string res){

    sort(res.begin(),res.end());

    int len1 = orig.length();
    int len2 = res.length();

    int visited[len2];
    memset(visited,0,sizeof(visited));


    for(int i=0;i<len1;i++){

        int pos = -1;
        char c = orig[i];

        for(int j=0;j<len2;j++){

            if(!visited[j] && res[j] < c){
                c=res[j];
                pos = j;
                break;
            }
        }

        if(pos!=-1){
            visited[pos] = 1;
            orig[i]=res[pos];
        }

    }


    return orig;
}

int main(){


    int tc;cin>>tc;
    while(tc--){
        string orig,res;
        cin>>orig>>res;
        cout<<solve(orig,res)<<endl;
    }
}
