bool isPalindrome(Node *head)
{
   
   int count=0;
   
    Node* prev = head;
    
    while(prev){
        count++;
        prev=prev->next;
    }
    
    int len =  count;
    
    int arr[len];
    
    int i=0;
    
    Node* prev1 = head;
    
    while(prev1){
        arr[i] = prev1->data;
        i++;
        prev1=prev1->next;
    }
    
    i=len-1;
    
    while(head){
        int data = head->data;
        if(arr[i] != data)
            return 0;
        head=head->next;
        i--;
    }
    
    
    
    return 1;
}