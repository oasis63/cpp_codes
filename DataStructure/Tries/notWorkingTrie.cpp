/*
    Trie Data Structure to Store the Strings 
*/


/*
...... Wrong Implementation 
......  Try Again 

*/

#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode{
public:
   // char data;
    bool is_End_of_String;
    TrieNode *child[26]; 

    TrieNode(){
        is_End_of_String = false;
        for(int i=0;i<ALPHABET_SIZE;i++){
            child[i] = NULL;
        }
    }
};

TrieNode* subNode(TrieNode *root,char c){

    if(!root){
        for(int i=0;i<26;i++){
            if(root->child[c-'a']){
                return root->child[i];
            }
        }
    }

    return NULL;
}

TrieNode* insertInTrie(TrieNode *root,char *word){


    if(!root){  // if it is the start of the root 

        TrieNode* newNode = new TrieNode();
        newNode->child[*word-'a'] = new TrieNode();  // first character of the string word 

        for(int i=0;i<26;i++){
            root->child[i] = NULL;
        }

        if(!*(word+1)){ // next character of the string word ... if not present
            newNode->is_End_of_String = true;
        }else{
            newNode->child[*word-'a'] = insertInTrie(root->child[*word-'a'],word+1);
        }

        return newNode;
    }

    root->child[*word-'a'] = insertInTrie(root->child[*word-'a'],word+1);

    return root;
}

int searchInTrie(TrieNode* root,char *word){

    if(!root)
        return -1;

    if(!*word){
        if(root->is_End_of_String)
            return 1;
        else
            return -1;
    }

    if(root->child[*word-'a'])
        return searchInTrie(root->child[*word-'a'],word+1);

    return -1;

}

int main(){

    TrieNode* root = new TrieNode();

    
    char word[] = {'a'};
    root = insertInTrie(root,word);

    char word1[] = {'a','l','l'};
    root = insertInTrie(root,word1);

    char word2[] = {'a','l','s'};
    root = insertInTrie(root,word2);

    char word3[] = {'a','s'};
    root = insertInTrie(root,word3);

}
