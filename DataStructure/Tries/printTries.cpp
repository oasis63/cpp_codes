#include<bits/stdc++.h>
using namespace std;

// Trie Test

const int ALPHABET_SIZE = 26;

class Node{
public:
	bool is_end_of_string;
	Node *children[ALPHABET_SIZE];

	Node(){
		is_end_of_string = false;
		for(int i=0;i<ALPHABET_SIZE;i++){
			children[i] = NULL;
		}
	}
};

// child node of char c 
Node* childNode(Node* root,char c){
	if(!root){
		for(int i=0;i<ALPHABET_SIZE;i++){
			if(root->children[c-'a']){
				return root->children[i];
			}
		}
	}
	return NULL;
}

void insert(Node* root,string word){
	Node* pCrawl = root;
	int len = word.length();

	for(int i=0;i<len;i++){
		int index = word[i]-'a';

		if(!pCrawl->children[index]){
			pCrawl->children[index] = new Node();
		}
		pCrawl = pCrawl->children[index];
	}

	pCrawl->is_end_of_string = true;
}

bool search(Node* root,string word){
	int len = word.length();
	Node* pCrawl = root;

	for(int i=0;i<len;i++){
		int index = word[i]-'a';

		if(!pCrawl->children[index])
			return false;
		pCrawl=pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->is_end_of_string);
}

void bfs(Node* root){

	queue<Node*> q;
	q.push(root);

	
	while(!q.empty()){
		Node* temp = q.front(); q.pop();
		// cout<<temp<<" ";
		for(int i=0;i<26;i++){
			if(temp->children[i]){
				q.push(temp->children[i]);
				cout<<(char)(i+97)<<" ";			
			}
		}
	}
	cout<<endl; 
}


void dfsUtil(Node* root,int k){
	cout<<(char)(k+97)<<" ";//<<root->is_end_of_string<<endl;
	
	//if(root->is_end_of_string)
	 //cout<<endl;

	for(int i=0;i<26;i++){
		if(root->children[i]){
			dfsUtil(root->children[i],i);
		}
	}
}

void dfs(Node* root){
	for(int i=0;i<26;i++){
		if(root->children[i]){
			dfsUtil(root->children[i],i);
			cout<<endl;
		}
	}

}



int main(){

	string words[] = {"the","a","all" "there"};//"answer","any"};
	int n = sizeof(words)/sizeof(words[0]);
	
	Node* root = new Node();

	for(int i=0;i<n;i++){
		insert(root,words[i]);
	}

	cout<<search(root,"the")<<endl;
	cout<<search(root,"fdljf")<<endl;

	cout<<"\nDFS  Traversal \n"<<endl;
	dfs(root);

	cout<<endl;
	cout<<"\nBFS Traversal \n"<<endl;
	bfs(root);
}
