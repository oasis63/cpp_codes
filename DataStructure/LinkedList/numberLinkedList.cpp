#include<bits/stdc++.h>
using namespace std;

// singly linked list

class node{
public:
    int value;
    node* next;
    node(int v){
      this->value = v;
      next = NULL;
    }

};

int num=0;

// create node

node* newNode(int val){  // use it or remove it 
    node* n;  // pointer to the class
    n=new node(val);  // pointing to a memory block of class node
    //n->value = val;
    n->next = NULL;
    return n;
}

node* insert(node* head,int val){
    if(head==NULL){
        head=new node(val);
    }
    else{
        node* rel = new node(val);
        rel->next = head;
        head=rel;
    }
    return head;
}

void traversal(node* head)
{

    while(head!=NULL){
        cout<<head->value<<" ";
        head=head->next;
    }
}


void convertToNumber(node* head){

    if(head==NULL)
      return;
    convertToNumber(head->next);
    num = num*10 + head->value;
}



int main(){

   node* head = NULL;
   head = insert(head,1);
   head = insert(head,3);
   head = insert(head,4);
   head = insert(head,2);

   traversal(head);

    num = 0;

    convertToNumber(head);

    cout<<"\nNumerical Value of the Given Linked list : ";
    cout<<num<<endl;
}

