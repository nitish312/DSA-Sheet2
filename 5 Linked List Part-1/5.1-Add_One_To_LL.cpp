// 1. O(3N) : O(1)
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

ListNode* reverseLL(ListNode* head){

	ListNode *prePtr, *nxtPtr;
	prePtr = nxtPtr = NULL;

	while(head){

		nxtPtr = head->next;
		head->next = prePtr;
		prePtr = head;
		head = nxtPtr;
	}

	return prePtr;
}

ListNode* addOneToLL(ListNode* head){

	head = reverseLL(head);

	ListNode* prev = NULL;
	ListNode* curr = head;
	
	int carry = 0;

	while(curr){

		int sum = 0;
		
		if(!prev) sum = curr->data + 1;
		else sum = curr->data + carry;

		carry = sum / 10;
		curr->data = sum % 10;

		prev = curr;
		curr = curr->next;
	}

	if(carry){

		ListNode* newNode = new ListNode(1);
		prev->next = newNode;
	}

	head = reverseLL(head);

	return head;	
}

int main(){

	ListNode* head1 = new ListNode(9);
	ListNode* tail1 = head1;

	insertAtEnd(tail1, 9);

	insertAtEnd(tail1, 9);

	printLL(head1);

	ListNode* addOne = addOneToLL(head1);

	printLL(addOne);

	return 0;
}