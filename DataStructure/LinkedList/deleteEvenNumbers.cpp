#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node(int v){
        this->value = v;
        next = NULL;
    }
};

Node *newNode(int val){
    Node* n = new Node(val);
    return n;
}

// insert at the end
Node* insert(Node* head,int val){
    if(head == NULL){
        head = new Node(val);
    }else{
        Node* temp = new Node(val);
        Node* h = head;
        while(h->next!=NULL){
            h=h->next;
        }
        h->next = temp;
    }
    return head;
}


void print(Node *head){
    while(head!=NULL){
        cout<<head->value<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* deleteElem(Node*head,int val){

    Node* h = head;
    Node* prev = NULL;

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

Node* delEven(Node* head){

    Node* h = head;
    Node* prev = NULL;

    while(h!=NULL){
       // cout<<"exe"<<endl;
       bool flag = false;

        if((h->value)%2==0){
            cout<<h->value<<" ";

            Node *temp = h;

            if(h==head){
                head = head->next;
                h=head;
                delete(temp);
                continue;
            }

            h=h->next;
            prev->next = h;

            flag = true;
            delete(temp);
        }

        if(!flag){
            prev = h;
            h=h->next;
        }
    }

    cout<<endl;

    return head;
}

Node* delSm(Node* head){

    Node* h = head;
    Node* ahead = h->next;

    while(h->next!=NULL){

        if(h->value < ahead->value){

            if(h == head){
                head = h->next;

            }
            cout<<"exe ";
            delete(h);
        }
        cout<<h->value<<" "<<ahead->value<<endl;

        h = ahead;
        ahead = h->next;
    }

    return head;
}




int main(){

    Node* head = NULL;
    head = insert(head,24);
    head = insert(head,46);
    head = insert(head,10);
    head = insert(head,77);
    head = insert(head,18);


    print(head);
    head = delEven(head);
    print(head);
}
