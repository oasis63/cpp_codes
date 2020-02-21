#include<bits/stdc++.h>
using namespace std;

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
    // fout<<word[len-1]<<"\t"<<pCrawl->is_end_of_string<<endl;
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



int main(){

    ifstream fin;
    ofstream fout;
    fin.open("testInput.txt");
    fout.open("testOutput.txt");

    int tc;
    fin>>tc;

    while(tc--){

        int n,i;
        fin>>n;

        string words[n];

        for(i=0;i<n;i++){
            fin>>words[i];
        }

        Node* root = new Node();

        for(i=0;i<n;i++){
            insert(root,words[i]);
        }

        string login;
        fin>>login;

        int len = login.length();

        bool attempt = true;
        string sentence="";

        Node *pCrawl = root;

       for(i=0;i<len;i++){
        int index = login[i]-'a';

        if(pCrawl == NULL){
            attempt = false;
            break;
        }

        if(pCrawl->is_end_of_string){
            sentence += " ";
            pCrawl = root;
        }

        if(!pCrawl->children[index]){
            attempt = false;
            //cout<<login[i]<<endl;
            break;

        }else{

            sentence += login[i];
            pCrawl=pCrawl->children[index];

        }
    }



       if(attempt  && i==len){
            //int ls = sentence.length();
            //string sub = sentence.substr(0,ls-1);
            fout<<sentence<<endl;
       }else{
            fout<<"WRONG PASSWORD"<<endl;
       }


    }

}


    
/*

ifstream fin;
ofstream fout;
fin.open("testInput.txt");
fout.open("testOutput.txt");

*/