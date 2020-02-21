#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc;
    cin>>tc;

    while(tc--){

        int n;
        cin>>n;

        //set<char> leftHand = {'d','f'};
        //set<char> rightHand = {'j','k'};
        map<string,int> wordTime;
        string word;

        float totalTime=0.0;

        while(n--){

            cin>>word;

            if(wordTime[word]){
                totalTime += wordTime[word]/2;
                //cout<<"Already Present"<<endl;
            }else{
                float temp=0.2;

                int len = word.length();

                for(int i=1;i<len;i++){
                    if((word[i]=='d' || word[i]=='f') && (word[i-1]=='j' || word[i-1]=='k')){
                        temp += 0.2;
                    }else if((word[i]=='j' || word[i]=='k') && (word[i-1]=='d' || word[i-1]=='f')){
                        temp += 0.2;
                    }else{    // write other full cases ... or check the corrected code for this question
                        temp += 0.4;
                    }
                }

                //cout<<temp<<endl;

                totalTime += temp;
                wordTime.insert(make_pair(word,temp));   //  this was giving wrong answer 
            }

        }

        //cout<<totalTime<<endl;

        int inTime = (int)(totalTime);
        int dec = (int)((totalTime - inTime)*10.0);
        inTime *= 10;
        //cout<<inTime<<endl;
        //cout<<dec<<endl;
        if(dec >= 0.5)
                inTime++;

        cout<<inTime<<endl;


    }

}
