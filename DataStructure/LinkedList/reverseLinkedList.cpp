void reverseLL(Node *head)
{

    Node* prev=NULL;
    Node* next;
    
    while(head){
        next = head->next;
        head->next = prev;
        prev=head;
        head=next;
    }
    
    while(prev){
        cout<<prev->data<<" ";
        prev=prev->next;
    }
    
    cout<<endl;
    
}