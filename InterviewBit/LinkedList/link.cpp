/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode * ret = NULL;
    ListNode * head = ret;
    
    while(A!=NULL && B!=NULL){
        if(A->val < B->val){
            if(ret==NULL){
                ret = A;// new ListNode(A->val);
            }else{
                ret->next = A;// new ListNode(A->val);
            }
            A=A->next;
        }else{
             if(ret==NULL){
                ret = B; //new ListNode(B; //B->val);
            }else{
                ret->next = B; //new ListNode(B->val);
            }
            B=B->next;
            
        }
        ret = ret->next;
    }
    
    while(A!=NULL){
        if(ret==NULL){
            ret = A;//new ListNode(A->val);
        }else{
            ret->next = A;//new ListNode(A->val);
        }
        ret = ret->next;
        A=A->next;
    }
    
    while(B!=NULL){
        if(ret==NULL){
            ret = B;//new ListNode(B->val);
        }else{
            ret->next = B;//new ListNode(B->val);
        }
        ret = ret->next;
        B=B->next;
    }
    return head;
}

