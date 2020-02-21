/*
    Trie Data Structure to Store the Strings
*/

// Working Code of Trie

#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode{
public:
    bool is_End_of_String;
    TrieNode *children[26];

    TrieNode(){
        is_End_of_String = false;
        for(int i=0;i<ALPHABET_SIZE;i++){
            children[i] = NULL;
        }
    }

};

TrieNode* subNode(TrieNode *root,char c){

    if(!root){
        for(int i=0;i<26;i++){
            if(root->children[c-'a']){
                return root->children[i];
            }
        }
    }

    return NULL;
}

void insert(TrieNode *root,string word){

    TrieNode* pCrawl = root;

    for(int i=0;i<word.length();i++){
        int index = word[i] - 'a';

        if(!pCrawl->children[index]){
            pCrawl->children[index] = new TrieNode();
        }

        pCrawl = pCrawl->children[index];
    }

    pCrawl->is_End_of_String = true;

}

bool search(TrieNode* root,string word){

    TrieNode *pCrawl = root;

    for (int i = 0; i < word.length(); ++i){
        int index = word[i]-'a';

        if(!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->is_End_of_String);
}

int main(){


    string words[] = {"the","a","all","there","answer","any"};

    int n = sizeof(words)/sizeof(words[0]);

    TrieNode* root = new TrieNode();

    for(int i=0;i<n;i++){
        insert(root,words[i]);
    }

    cout<<search(root,"the")<<endl;

    cout<<search(root,"ese")<<endl;


}
