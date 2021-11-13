ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }