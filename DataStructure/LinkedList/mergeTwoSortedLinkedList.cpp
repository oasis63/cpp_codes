#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
	int val;
	ListNode *next;
	ListNode(int val){
		this->val = val;
		next = NULL;
	}
};

ListNode* insert(ListNode*head,int val){
	if(head==NULL){
		head = new ListNode(val);
	}else{
		ListNode* rel = head;
		while(rel->next!=NULL){
			rel = rel->next;
		}
		rel->next = new ListNode(val);
	}

	return  head;
}

void display(ListNode *head){
	while(head!=NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
}


ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode * head = NULL;
    ListNode * tail = head;

	while(A!=NULL && B!=NULL){
        if(A->val < B->val){
			if(head == NULL){
				head = new ListNode(A->val);
				tail = head;  // tail should not point to NULL head pointer .. for next element insertion
			}
			else{
				tail->next = new ListNode(A->val);
				tail = tail->next;
			}
            A=A->next;
        }else{
			if(head == NULL){
				head = new ListNode(B->val);
				tail=head;
			}
			else{
				tail->next = new ListNode(B->val);
				tail = tail->next;
			}
            B=B->next;
        }
//		tail = tail->next;
    }

    while(A!=NULL){

		if(head == NULL){
			head = new ListNode(A->val);
			tail = head;
		}
		else{
			tail->next = new ListNode(A->val);
			tail = tail->next;
		}
		A=A->next;
    }

    while(B!=NULL){

		if(head == NULL){
			head = new ListNode(B->val);
			tail=head;
		}
		else{
			tail->next = new ListNode(B->val);
			tail = tail->next;
		}
		B=B->next;

    }

    return head;
}


ListNode* mergeTwoLists2(ListNode* A, ListNode* B) {
    ListNode * head = NULL;
    ListNode * tail = head;

	while(A!=NULL && B!=NULL){
        if(A->val < B->val){
			if(head == NULL){
				head = A;
				tail = head;  // tail should not point to NULL head pointer .. for next element insertion
			}
			else{
				tail->next = A;
				tail = tail->next;
			}
            A=A->next;
        }else{
			if(head == NULL){
				head = B;
				tail=head;
			}
			else{
				tail->next = B;
				tail = tail->next;
			}
            B=B->next;
        }
//		tail = tail->next;
    }

    while(A!=NULL){

		if(head == NULL){
			head = A;
			tail = head;
		}
		else{
			tail->next = A;
			tail = tail->next;
		}
		A=A->next;
    }

    while(B!=NULL){

		if(head == NULL){
			head = B;
			tail=head;
		}
		else{
			tail->next = B;
			tail = tail->next;
		}
		B=B->next;

    }

    return head;
}




void solve(){

	ListNode* head =  NULL;
	head = insert(head,2);
	head = insert(head,5);
	head = insert(head,20);
	head = insert(head,43);
	head = insert(head,56);
	display(head);


	ListNode* head2 = NULL;
	head2 = insert(head2,3);
	head2 = insert(head2,4);
	head2 = insert(head2,34);
	head2 = insert(head2,40);
	head2 = insert(head2,60);
	display(head2);

	ListNode* ans = mergeTwoLists2(head,head2);

	cout<<"\nMerged List \n"<<endl;
	display(ans);
}


int main(){


	solve();

	return 0;
}
