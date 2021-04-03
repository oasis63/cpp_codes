#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
#define ui unsigned int
#define uli unsigned long int
#define SIZE  1000001

class Solution {
public:
	void printArr(char c,int arr[],int n){
		cout<<c<<"---> ";
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
    int lengthOfLongestSubstring(string s) {
    	int n = s.length();
    	if(n <= 1)
    		return n;
    	int mxAns = -1;
    	map<char,int> mp;  // char , index 
    	int countArr[n];
   		fill(countArr,countArr+n,1);
   		// printArr(countArr,n);

    	for(int i=0;i<n;i++){
    		if(mp[s[i]] == 0){// char is not present in the map
    			
    			mp[s[i]] = i+1;  // char,present index 
    			if(i>0){
    				countArr[i]=countArr[i-1]+1;
    				mxAns = max(mxAns,countArr[i]); 
    			}

    		}else{

    			int prevIndex = mp[s[i]];
    			int prevValue = countArr[prevIndex-1];
    			mp[s[i]] = i+1;  // setting the current index

    			// update the counter value for this index 
    			for(int j=prevIndex-1;j<i;j++){
    				countArr[j] -= prevValue;
    			}

    			countArr[i]=countArr[i-1]+1;
    			mxAns = max(mxAns,countArr[i]);

    		}
    		// printArr(s[i],countArr,n);
    	}

    	return mxAns;
    }
};


int main(){
  fast;
  Solution obj;
  // string str = "abcabcbbb";
  // string str = "abcabcbb";
  string str = "";
  int ansLen = obj.lengthOfLongestSubstring(str);
  cout<<"ansLen : "<<ansLen<<endl;
 	 
  return 0;
}