#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
/*
AB
BA

*/
int main(){
    
    string str; //="ABAXXBBXXAA";
    cin>>str;

    int len = str.length();

    int al_count[26];
    memset(al_count,0,sizeof(al_count));

    vector<int> inA;
    vector<int> inB;


    for(int i=0;i<len;i++){
        al_count[(int)(str[i]-'A')]++;
        if(str[i]=='A'){
            inA.push_back(i);
        }else if(str[i] == 'B'){
            inB.push_back(i);
        }
    }

    bool visited[100001];
    memset(visited,false,sizeof(visited));

   // cout<<al_count[0]<<endl;
    //cout<<al_count[1]<<endl;

    if(al_count[0] < 2 || al_count[1] < 2){
        cout<<"NO"<<endl;
    }else{
        
        bool fA = false;
        int lenA = inA.size();
        int lenB = inB.size();

        for(int i=0;i<lenA;i++){
            int ia = inA[i];
            if((ia+1) < len  && visited[ia] == false && visited[ia+1] == false){
                if(str[ia+1] == 'B'){
                    fA=true;
                    visited[ia+1] = true;
                    visited[ia]  = true;
                     break;
                }
            }
        }

        bool fB = false;

        for(int i=0;i<lenB;i++){
            int ib = inB[i];
            if((ib+1) < len  && visited[ib] == false &&  visited[ib+1] == false){
                if(str[ib+1] == 'A'){
                    fB=true;
                    visited[ib] = true;
                    visited[ib+1] = true;
                    break;
                }
            }
        }


        if(fB && fA){
            cout<<"YES"<<endl;
        }else{

            memset(visited,false,sizeof(visited));

            fB = false;

            for(int i=0;i<lenB;i++){
                int ib = inB[i];
                if((ib+1) < len  && visited[ib] == false && visited[ib+1] == false){
                    if(str[ib+1] == 'A'){
                        fB=true;
                        visited[ib] = true;
                        visited[ib+1] = true;
                        break;
                    }
                }
            }


            fA = false;


            for(int i=0;i<lenA;i++){
                int ia = inA[i];
                if((ia+1) < len  && visited[ia] == false  && visited[ia+1] == false){
                    if(str[ia+1] == 'B'){
                        fA=true;
                        visited[ia+1] = true;
                        visited[ia] = true;
                        break;
                    }
                }
            }

            if(fB && fA){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }


        }


    }

    return 0;
}