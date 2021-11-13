#include <bits/stdc++.h>
using namespace std;

int countOccur(string str,char c){
  	int len = str.length();
  	int ans = 0;
  	for(int i=0;i<len;i++){
      	if(str[i] == c)
          ans++;
    }
  	return ans;
}

// convert the string into vector of words

vector<string>  convertStrArr(string str){
  	int len = str.length();
  	vector<string> vect;
  	
  	string temp;
  	int	 in_idx = 0;
  	for(int i=0;i<len;i++){
      if(str[i]==' '){
        temp = str.substr(in_idx,i-in_idx);
        // cout<<"|"<<temp<<"|"<<in_idx<<endl;
        vect.push_back(temp);
        in_idx = i+1;
      }
    }

    temp = str.substr(in_idx,len-in_idx);
    // cout<<"|"<<temp<<"|"<<in_idx<<endl;
    vect.push_back(temp);
  
  
  	return vect;
}

int main() {
	//for input use:
	 string str;
   getline(cin,str);
	   // cin>>str;
     // cout<<str<<endl;
  	int n;cin>>n;
  	
  	int len = str.length();
	char c;
  	if(n >= len ){
		c = str[len-1]; 
    }else{
      	c = str[n];
    }
  
  	int count = countOccur(str,c);
  
  	vector<string> wordsVect = convertStrArr(str);
  
  	int wordsCount = wordsVect.size();
	
  	int ex_idx = count;
  
  	if(count >= wordsCount){
      ex_idx = wordsCount;
    }
  	
  	string ans;

    ex_idx--;
    int j = 0;
  	for(;j<wordsCount; j++){
      if(j==ex_idx)
        continue;
      ans += wordsVect[j] + " ";
    }

    // cout<<"|"<<ans<<"|"<<endl;

    len = ans.length();
    if(ans[len-1] == ' '){
      ans = ans.substr(0,len-1);
    }
  	
  // cout<<"|"<<ans<<"|"<<endl;

    cout<<ans<<endl;
  
	return 0;
}