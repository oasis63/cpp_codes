/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* sumList = NULL;
        
        int carry = 0;
        
        while( l1 != NULL && l2 != NULL){
            int t1 = l1->val;
            int t2 = l2->val;
            
            int s = t1 + t2 + carry;
            
            if(carry == 1)
                carry = 0;
            
            if(s > 9)
              carry = 1;
            
            s = s%10;

            
            if(sumList == NULL){
                sumList = new ListNode(s);
            }else{
                
                ListNode* n = new ListNode(s);
                
                ListNode* temp = sumList;
                
                while(temp->next!=NULL)
                    temp=temp->next;
                
                temp->next=n;
            }
            
            l1=l1->next;
            l2=l2->next;
        }
        
        if(l1!=NULL){
            
            while( l1 != NULL){
            int t1 = l1->val;
            
            int s = t1 + carry;
            
           if(carry == 1)
                carry = 0;
            
            if(s > 9)
              carry = 1;
            
            s = s%10;
            
            if(sumList == NULL){
                sumList = new ListNode(s);
            }else{
                
                ListNode* n = new ListNode(s);
                
                ListNode* temp = sumList;
                
                while(temp->next!=NULL)
                    temp=temp->next;
                
                temp->next=n;
            }
            
            l1=l1->next;
        }
            
        }
        
        
        if(l2!=NULL){
            
            while( l2 != NULL){
            int t2 = l2->val;
            
            int s = t2 + carry;
            
            if(carry == 1)
                carry = 0;
            
            if(s > 9)
              carry = 1;
            
            s = s%10;
            
            if(sumList == NULL){
                sumList = new ListNode(s);
            }else{
                
                ListNode* n = new ListNode(s);
                
                ListNode* temp = sumList;
                
                while(temp->next!=NULL)
                    temp=temp->next;
                
                temp->next=n;
            }
            
            l2=l2->next;
        }
            
        }
        
        if(carry == 1){
            
            ListNode* n = new ListNode(1);
            
            ListNode* temp = sumList;
            while(temp->next != NULL){
                temp = temp->next;
            }
            
            temp->next = n;
            
        }
        
        return sumList;
    }
};