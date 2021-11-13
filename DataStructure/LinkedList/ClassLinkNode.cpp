// Binary search tree
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

node* deleteElem(node*head,int val){

    node* h = head;
    node* prev = NULL;

    while(h!=NULL){

        if(h->value == val){

            if(prev == NULL)
                head = h->next;
            else
                prev->next = h->next;

            delete(h);
            break;
        }

        prev = h;
        h=h->next;
    }

    return head;
}

void traversal(node* head)
{

    while(head!=NULL){
        cout<<head->value<<" ";
        head=head->next;
    }
    cout<<endl;
}


int main(){

   node* head = NULL;
   head = insert(head,143);
   head = insert(head,243);
   head = insert(head,343);
   head = insert(head,443);

   traversal(head);
   head = deleteElem(head,243);
   traversal(head);

}

