// you will be given access to the node to be deleted directly. 
// It is guaranteed that the node to be deleted is not a tail node in the list
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

// swap values ? O(1) : O(1)
void deleteThisNode(ListNode* node){

	swap(node->data, node->next->data);
	ListNode* delNode = node->next;
	node->next = delNode->next;
	delete delNode;
}

int main(){

	ListNode* head = new ListNode(10);
	ListNode* tail = head;

	insertAtEnd(tail, 20);
	insertAtEnd(tail, 30);
	insertAtEnd(tail, 40);
	insertAtEnd(tail, 50);

	printLL(head);

	deleteThisNode(head->next);

	printLL(head);

	return 0;
}