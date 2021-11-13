#include<bits/stdc++.h>
using namespace std;

// Trie Test

const int ALPHABET_SIZE = 26;

class Node{
public:
	bool is_end_of_string;
	Node *children[ALPHABET_SIZE];
	int priority;

	Node(){
		priority = -1;
		is_end_of_string = false;
		for(int i=0;i<ALPHABET_SIZE;i++){
			children[i] = NULL;
		}
	}
};


void insert(Node* root,string word,int prio){
	Node* pCrawl = root;
	int len = word.length();

	for(int i=0;i<len;i++){
		int index = word[i]-'a';

		if(!pCrawl->children[index]){
			pCrawl->children[index] = new Node();
		}
		pCrawl = pCrawl->children[index];

		if(pCrawl->priority < prio)
			pCrawl->priority = prio;
	}

	pCrawl->is_end_of_string = true;

}



void search(Node* root,string word){
	int len = word.length();
	Node* pCrawl = root;

	for(int i=0;i<len;i++){
		int index = word[i]-'a';

		if(!pCrawl->children[index]){
			cout<<-1<<endl;
			return ;
		}

		pCrawl=pCrawl->children[index];
	}
	

	cout<<pCrawl->priority<<endl;

}




int main(){

	string words[] = {"hackerearth","hackerrank"};
	int priority[] = {10,9};
	int n = sizeof(words)/sizeof(words[0]);
	
	Node* root = new Node();

	for(int i=0;i<n;i++){
		insert(root,words[i],priority[i]);
	}


	search(root,"hacker");
}

