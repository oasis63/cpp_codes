#include<bits/stdc++.h>
using namespace std;

// Trie Test

const int ALPHABET_SIZE = 26;
const int NUM_SIZE = 10;

class Node{
public:
	bool is_end_of_string;
	Node *alphaChildren[ALPHABET_SIZE];
	Node *digitChildren[NUM_SIZE];

	Node(){
		is_end_of_string = false;
		for(int i=0;i<ALPHABET_SIZE;i++){
			alphaChildren[i] = NULL;
		}
		for(int i=0;i<NUM_SIZE;i++){
			digitChildren[i]=NULL;
		}
	}
};

void insert(Node* root,string word){

	Node* pCrawl = root;

	int len = word.length();

	int index = -1;


	for(int i=0;i<len;i++){

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

	pCrawl->is_end_of_string = true;

}

bool search(Node* root,string word){
	int len = word.length();
	Node* pCrawl = root;
	int index=-1;

	for(int i=0;i<len;i++){


		if(word[i]>='a' && word[i]<='z'){
			index = word[i]-'a';

			if(!pCrawl->alphaChildren[index]){
				return false;
			}

			pCrawl = pCrawl->alphaChildren[index];
		
		}else{
			
			index = word[i]-'0';
			if(!pCrawl->digitChildren[index]){
				return false;
			}

			pCrawl = pCrawl->digitChildren[index];
		}

	}


	return (pCrawl != NULL && pCrawl->is_end_of_string);
}


void insert2(Node* root,string word){

	Node* pCrawl = root;
	int len = word.length();
	int index = -1;

	string ans="";


	for(int i=0;i<len;i++){

		if(word[i]>='a' && word[i]<='z'){
			index = word[i]-'a';
			
			ans += word[i];

			if(!pCrawl->alphaChildren[index]){
				pCrawl->alphaChildren[index] = new Node();
			}

			pCrawl = pCrawl->alphaChildren[index];
		
		}else{
			
			index = word[i]-'0';

			ans += word[i];
			
			if(!pCrawl->digitChildren[index]){
				pCrawl->digitChildren[index] = new Node();
			}

			pCrawl = pCrawl->digitChildren[index];
		}

	}


	if(pCrawl->is_end_of_string == false){
		pCrawl->is_end_of_string = true;

		cout<<"false  : : " << ans<<endl;

	}else{

		for(int i=0;i<NUM_SIZE;i++){
			if(!pCrawl->digitChildren[i]){
				pCrawl->digitChildren[i] = new Node();
				pCrawl=pCrawl->digitChildren[i];
				ans += (char)i+'0';
				break;
			}
		}

		cout<<ans<<endl;

		pCrawl->is_end_of_string = true;
	}


}




int main(){


	string words[] = {"lebron","lebron0","lebron1","lebron","lebron2"};
	int n = sizeof(words)/sizeof(words[0]);
	
	Node* root = new Node();

	for(int i=0;i<n;i++){
		insert2(root,words[i]);
		cout<<endl;
	}

	// cout<<search(root,"lebron")<<endl;
	/*cout<<search(root,"lebron0111")<<endl;
	cout<<search(root,"lebron11")<<endl;
	cout<<search(root,"lebron2")<<endl;
	*/


}

/*
	Output 

	lebron
	lebron0
	lebron1
	lebron2
	lebron20

*/
