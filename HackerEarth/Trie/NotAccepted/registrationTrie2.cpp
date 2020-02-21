#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

const ll ALPHABET_SIZE = 26;
const ll NUM_SIZE = 10;

class Node{
public:
	bool is_end_of_string;
	Node *alphaChildren[ALPHABET_SIZE];
	Node *digitChildren[NUM_SIZE];

	Node(){
		is_end_of_string = false;
		for(ll i=0;i<ALPHABET_SIZE;i++){
			alphaChildren[i] = NULL;
		}
		for(ll i=0;i<NUM_SIZE;i++){
			digitChildren[i]=NULL;
		}
	}
};



void insert2(Node* root,string word){

	Node* pCrawl = root;
	ll len = word.length();
	ll index = -1;

	string ans="";


	for(ll i=0;i<len;i++){

		if(word[i]>='a' && word[i]<='z'){
			index = word[i]-'a';

			if(!pCrawl->alphaChildren[index]){
				pCrawl->alphaChildren[index] = new Node();
			}

			pCrawl = pCrawl->alphaChildren[index];

		}else{

			index = word[i]-'0';

			if(!pCrawl->digitChildren[index]){
				pCrawl->digitChildren[index] = new Node();
			}

			pCrawl = pCrawl->digitChildren[index];
		}

	}


	if(pCrawl->is_end_of_string == false){
		pCrawl->is_end_of_string = true;

		cout<<word<<endl;

	}else{

        ans = word;

		for(ll i=0;i<NUM_SIZE;i++){
//
//            if(pCrawl->digitChildren[i]  && pCrawl->digitChildren[i]->is_end_of_string)
//                continue;
//
//            if(word=="jn")
//                cout<<"\t"<<i<<endl;

			if(!pCrawl->digitChildren[i] || pCrawl->digitChildren[i]->is_end_of_string==false){
				pCrawl->digitChildren[i] = new Node();
				pCrawl = pCrawl->digitChildren[i];
				ans += (char)i+'0';
				break;
			}
		}

		cout<<ans<<endl;

		pCrawl->is_end_of_string = true;
	}


}




int main(){

    fast;

    ll n;cin>>n;

	string words[n];// = {"lebron","lebron0","lebron1","lebron2"};
	//ll n = sizeof(words)/sizeof(words[0]);

	Node* root = new Node();

	for(ll i=0;i<n;i++){
	    cin>>words[i];
		insert2(root,words[i]);
	}



}
