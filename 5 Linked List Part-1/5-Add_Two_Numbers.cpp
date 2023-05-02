#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode{

	int data;
	ListNode* next;

	ListNode(int val){

		data = val;
		next = NULL;
	}
};

void printLL(ListNode* head){

	ListNode* temp = head;
	while(temp){

		cout<<temp->data<<" —> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

void insertAtEnd(ListNode* &tail, int data){

	ListNode* newNode = new ListNode(data);
	tail->next = newNode;
	tail = newNode;
}

// only approach ? O(max(l1, l2)) : O(N)
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){

	ListNode* dummy = new ListNode(-1);
	ListNode* temp = dummy;
	int carry = 0;

	while(l1 || l2 || carry){

		int sum = 0;

		if(l1){

			sum += l1->data;
			l1 = l1->next;
		}
		if(l2){

			sum += l2->data;
			l2 = l2->next;
		}

		sum += carry;
		carry = sum / 10;

		ListNode* newNode = new ListNode(sum % 10);
		temp->next = newNode;
		temp = temp->next;
	}

	temp = dummy->next;
	delete(dummy);

	return temp;
}

int main(){

	ListNode* head1 = new ListNode(1);
	ListNode* tail1 = head1;

	insertAtEnd(tail1, 4);
	insertAtEnd(tail1, 3);

	printLL(head1);

	ListNode* head2 = new ListNode(1);
	ListNode* tail2 = head2;

	insertAtEnd(tail2, 6);
	insertAtEnd(tail2, 4);

	printLL(head2);

	ListNode* sum = addTwoNumbers(head1, head2);
	
	printLL(sum);

	return 0;
}