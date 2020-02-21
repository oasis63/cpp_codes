#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long


int main(){

    fast;

    ll tc;
    cin>>tc;

    while(tc-- > 0){

        ll n;
        cin>>n;


        map<string,double> wordTime;

        double totalTime=0.0;

        while(n-- > 0){

            string word;
            cin>>word;

            double temp = 0.0;

            if(wordTime[word] != NULL){

                temp = wordTime[word]/2.0;
                totalTime += temp;
                //cout<<word<<" Already Present :"<<temp<<endl;

            }else{

                temp=0.2;

                int len = word.length();

                for(int i=1;i<len;i++){
                    if((word[i]=='d' || word[i]=='f') && (word[i-1]=='j' || word[i-1]=='k')){
                        temp += 0.2;
                    }else if((word[i]=='j' || word[i]=='k') && (word[i-1]=='d' || word[i-1]=='f')){
                        temp += 0.2;
                    }else if((word[i]=='d' || word[i]=='f') && (word[i-1]=='d' || word[i-1]=='f')){
                        temp += 0.4;
                    }else if((word[i]=='j' || word[i]=='k') && (word[i-1]=='j' || word[i-1]=='k')){
                        temp += 0.4;
                    }
                }

                //cout<<temp<<endl;

                //cout<<word<<" "<<temp<<endl;

                totalTime += temp;
                //wordTime.insert(make_pair(word,temp));
                wordTime[word] = temp;
            }

        }


        //cout<<totalTime<<endl;
        cout<<totalTime*10<<endl;



    }

}
