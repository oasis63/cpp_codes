ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode* A = head;

    while(A->next!=NULL){
        ListNode* temp = A->next;
        int currVal = A->val;
        while(temp != NULL && temp->val == currVal){
            temp = temp->next;
        }
        A->next = temp;
        if(A->next)
            A=A->next;
    }
    return head;
}
