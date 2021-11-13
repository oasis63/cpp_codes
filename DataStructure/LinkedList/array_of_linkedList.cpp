// Binary search tree
#include<bits/stdc++.h>
using namespace std;

// singly linked list

typedef struct node{
    int value;
    node* next;

}node;

// create node

node* newNode(int val){
    node* n;
    n=new node;
    n->value = val;
    n->next = NULL;
    return n;
}

node* insert(node* head,int val){
    if(head==NULL){
        head=newNode(val);
    }
    else{
        node* rel = newNode(val);
        rel->next = head;
        head=rel;
    }
    return head;
}

void print(node* head)
{

    while(head!=NULL){
        cout<<head->value<<" ";
        head=head->next;
    }
    cout<<endl;
}

// inserting at the end

node* insert_end(node* head,int val){

    node* n = newNode(val);

    if(head==NULL)
        head=n;
    else{
        node* temp = head;

        while(temp->next){
            temp = temp->next;
        }
        temp->next = n;
    }

    return head;
}


// insert at the middle

node* insert_middle(node* head,int val,int pos){

    node* n = newNode(val);

    if(head==NULL)
        head=n;
    if(pos==1){
        n->next = head;
        head=n;
    }
    else{
        node* temp = head;

        while(temp->next!=NULL && pos > 2){
            temp = temp->next;
            pos--;
        }
        n->next = temp->next;
        temp->next = n;
    }

    return head;
}

node* delete_head_node(node* head){
    if(head==NULL)
        return head;
    else{
        node* temp = head;
        head=head->next;
        delete temp;
    }

    return head;
}

void printArray(node* headArr[],int n)
{

    for(int i=0;i<n;i++){

        while(headArr[i]!=NULL){
            cout<<headArr[i]->value<<" ";
            headArr[i]=headArr[i]->next;
        }
        cout<<endl;
    }
}



int main(){

   node* head = NULL;
   head = insert(head,53);
   head = insert(head,143);
   head = insert(head,243);
   head = insert(head,953);

   print(head);
   head = insert(head,3);
   head = insert_middle(head,1000,10);
   head = delete_head_node(head);
   print(head);

   // array of linked list

   node* arr[5];

   for(int i=0;i<5;i++){
    arr[i]=NULL;
   }


  for(int i=0;i<5;i++){
    for(int j=0;j<2+i;j++){
        arr[i] = insert(arr[i],j);
    }
  }


  for(int i=0;i<5;i++){
    print(arr[i]);
  }

  cout<<endl<<endl;

  printArray(arr,5);

}

