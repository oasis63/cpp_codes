#include<bits/stdc++.h>
using namespace std;

void solve2(char str[],int len){

    int hash1[255];
    memset(hash1,0,sizeof(hash1));

    int i = 0;
    int k = 0;

    for(i=0;i<len;i++){
        if(hash1[(int)str[i]] == 0){
            str[k] = str[i];
            k++;
            hash1[(int)str[i]] = 1;
        }
    }
    str[k] = '\0';
    cout<<str<<endl;
}


int main(){
	//code
	int tc;
	cin>>tc;
    cin.ignore();
	while(tc--){
        char str[1000];
	   gets(str);
	   int len = strlen(str);
	   //cout<<len<<endl;
	   solve2(str,len);
	}


	return 0;
}
