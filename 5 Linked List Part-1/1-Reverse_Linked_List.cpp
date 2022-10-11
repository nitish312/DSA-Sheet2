#include<iostream>
using namespace std;

struct ListNode{

	int data;
	ListNode *next;

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

void insertAtEnd(ListNode* &tail, int value){

	ListNode* newNode = new ListNode(value);
	tail->next = newNode;
	tail = newNode;
}


// 1. Iterative ? O(N) : O(1)
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


// 2. Recursive ? O(N) : O(1)
ListNode* reverseLL(ListNode* head){

	if(!head || !head->next) return head;
        
    ListNode *revHead = reverseList(head->next);
    
    ListNode *lastNode = head->next;
    
    lastNode->next = head;
    
    head->next = NULL;
    
    return revHead;
}

int main(){

	ListNode *head = new ListNode(10);
	ListNode *tail = head;

	insertAtEnd(tail, 20);
	insertAtEnd(tail, 30);
	insertAtEnd(tail, 40);
	insertAtEnd(tail, 50);

	printLL(head);

	ListNode* rev = reverseLL(head);

	printLL(rev);

	return 0;
}