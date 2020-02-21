#include<bits/stdc++.h>
using namespace std;


// convert string into array of integer

vector<int>  convertStrArr(string str){
    int len = str.length();
    vector<int> vect;
    
    int num;
    string temp;
    int  in_idx = 0;

    for(int i=0;i<len;i++){
      if(str[i]==' '){
        temp = str.substr(in_idx,i-in_idx);
        // cout<<"|"<<temp<<"|"<<in_idx<<endl;

        stringstream ss(temp);
        ss>>num;

        vect.push_back(num);
        in_idx = i+1;
      }
    }

    temp = str.substr(in_idx,len-in_idx);
    // cout<<"|"<<temp<<"|"<<in_idx<<endl;
    stringstream sts(temp);
    sts>>num;
    vect.push_back(num);
  
  
    return vect;
}


int main(){
        
    string strNums;
    vector<int> vect;

    getline(cin,strNums);

    // cout<<strNums<<endl;

    vect = convertStrArr(strNums);

    for(int i : vect){
        cout<<i<<endl;
    }


    return 0;
}