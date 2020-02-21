/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
   
   priority_queue<int,vector<int>,greater<int>> pq;
   
   int n = A.size();
   
   for(int i=0;i<n;i++){
    //   ListNode* head = A[i];
       while(A[i]!=NULL){
           pq.push(A[i]->val);
           A[i]=A[i]->next;
       }
   }
   
   ListNode *head,*ret;
   head = new ListNode(0);    // Don't give NULL here
   ret = head;  
   
   while(!pq.empty()){
        int elem = pq.top();pq.pop();
        head->next = new ListNode(elem);
        head = head->next;
   }
   
   return ret->next;   // so not to include zero (0)
  
}
