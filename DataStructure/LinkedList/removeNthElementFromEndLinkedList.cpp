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


ListNode* removeNthFromEnd(ListNode* A, int B) {

	int n = 0;
	ListNode* temp = A;
	while(temp!=NULL){
		temp=temp->next;
		n++;
	}

    n = n - B + 1;

    if(n<=0)
		n=1;

    if(n==1){
        temp = A;
        A=A->next;
		delete(temp);
        return A;
    }

	temp = A;

    while(temp!=NULL && n > 2){
		n--;
        temp = temp->next;
    }

    if(temp->next != NULL){
		ListNode* temp2 = temp->next;
        temp->next = temp->next->next;
    }

	return A;
}



void solve(){

	ListNode* head2 = NULL;
	head2 = insert(head2,1);
	head2 = insert(head2,2);
	head2 = insert(head2,3);
	head2 = insert(head2,4);
	head2 = insert(head2,5);
	display(head2);

	cout<<"\nAfter Removing the nth element from last \n"<<endl;

	ListNode* ans = removeNthFromEnd(head2,43);
	display(ans);
}


int main(){


	solve();

	return 0;
}
