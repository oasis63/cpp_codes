#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE=26;

//#define CHAR_TO_INDEX(c) ((int)c-(int)'a')

class Node{
public:
    bool is_end_of_string;
    Node* children[ALPHABET_SIZE];

	Node(){
		is_end_of_string = false;
		for(int i=0;i<26;i++){
			children[i]=NULL;
		}
	}
};

// child node of char c
Node* childNode(Node* root,char c){
	if(!root){
		for(int i=0;i<ALPHABET_SIZE;i++){
			if(root->children[c-'a'])
				return root->children[i];
		}
	}
	return NULL;
}

void insert(Node* root,string word){

	int len = word.length();
	Node *pCrawl = root;

	for(int i=0;i<len;i++){
		int index = word[i] - 'a';
		if(!pCrawl->children[index])
			pCrawl->children[index] = new Node();
		pCrawl = pCrawl->children[index];
	}
	pCrawl->is_end_of_string = true;
}

bool search(Node* root,string word){
	int len = word.length();
	Node* pCrawl = root;
	for(int i=0;i<len;i++){
		int index = word[i] - 'a';
		if(!pCrawl->children[index])
			return false;
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != NULL && pCrawl->is_end_of_string);
}

bool isLastNode(Node* root){
	for(int i=0;i<ALPHABET_SIZE;i++){
		if(root->children[i])
			return false;
	}
	return true;
}

void suggestionsRec(Node* root,string currPrefix){

	if(root->is_end_of_string){
		cout<<currPrefix<<endl;
	}

	// All children of node pointers are NULL
	if(isLastNode(root))
		return;

	for(int i=0;i<ALPHABET_SIZE;i++){
		if(root->children[i]){
			// append the current character to the currPrefix string
			currPrefix.push_back(97+i);

			// recur over the rest
			suggestionsRec(root->children[i],currPrefix);

			currPrefix.pop_back();
		}
	}


}


int printSuggestions(Node* root,string query){

	Node *pCrawl = root;
	int len = query.length();
	// check if the query is present

	for(int i=0;i<len;i++){
		int index = query[i] - 'a';

		if(!pCrawl->children[index])
			return 0;  // query is not present
		pCrawl = pCrawl->children[index];
	}

	bool isWord = (pCrawl->is_end_of_string == true);

	bool isLast = isLastNode(pCrawl);

	if(isWord && isLast){
		cout<<query<<endl;
		return -1;
	}

	// if there are nodes below last
	if(!isLast){
		string prefix = query;
		suggestionsRec(pCrawl,prefix);
		return 1;
	}
}


int main(){

	string words[] = {"hello","dog","hell","cat","a","hel","help","helps","helping","ant","answer","any"};

	int n = sizeof(words)/sizeof(words[0]);

	Node* root = new Node();

	for(int i=0;i<n;i++){
		insert(root,words[i]);
	}


	int comp = printSuggestions(root,"a");

	if(comp == -1){
		cout<<"No other strings found with this prefix"<<endl;
	}else if(comp == 0){
		cout<<"No string found with this prefix"<<endl;
	}



	return 0;
}
