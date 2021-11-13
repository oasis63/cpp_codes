/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    ListNode* rev = NULL;
    ListNode* head = A;
    while(head!=NULL){
        if(rev==NULL){
            rev = new ListNode(head->val);
        }else{
            ListNode* temp = new ListNode(head->val);
            temp->next = rev;
            rev = temp;
        }
        head = head->next;
    }
    
    int flag = 1;
    head = A;
    while(rev != NULL && head != NULL){
        if(rev->val!=head->val){
            flag = 0;
            break;
        }
        rev=rev->next;
        head=head->next;
    }
    return flag;
}
