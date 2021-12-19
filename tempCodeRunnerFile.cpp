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

node* insert(node* head,int val){
    node* newNode = new node(val);
     if(head == NULL){
         head = newNode;
    }
    else{
         node* headRef = head;
         while(headRef->next){
             headRef = headRef->next;
         }
         headRef->next = newNode;
        //  head = newNode;
    }
    return head;
}

node* sort(node* head,int B){
    node* before=NULL;
    node* after=NULL;

    // traversal(before);
    // traversal(after);

    while(head!=NULL){
        if(head->value <  B){
            before = insert(before,head->value);
        }else {
            after = insert(after,head->value);
        }
        // traversal(before);
        // traversal(after);
        head=head->next;
    }
    
    node* before_trav = before;
    while(before_trav->next != NULL){
        before_trav = before_trav ->next;
    }

    cout<<"before"<<endl;
    traversal(before);
    cout<<"after"<<endl;
    traversal(after);
    
    // node* tempNode = new node(B);
    // tempNode->next = after;
    // before_trav->next=tempNode;
    before_trav->next=after;

    cout<<"beforedd"<<endl;
    traversal(before);
    cout<<"afterddd"<<endl;
    traversal(after);

    return before;
}



int main(){

   node* head = NULL;
   head = insert(head,1);
//    head = insert(head,4);
//    head = insert(head,3);
//    head = insert(head,2);
//    head = insert(head,5);
//    head = insert(head,2);
   
   
    cout<<"input data : ";
    traversal(head);

   head = sort(head,1);

   //cout<<head<<endl;

    cout<<"result : ";

   traversal(head);

    return 0;
}

