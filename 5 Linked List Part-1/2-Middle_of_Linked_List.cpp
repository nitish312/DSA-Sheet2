
#include<iostream>
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

		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

void insertAtEnd(ListNode* &tail, int val){

	ListNode* newNode = new ListNode(val);
	tail->next = newNode;
	tail = newNode;
}

// 1. brute ? O(N) + O(N/2) -> O(N) : O(1)
int getLength(ListNode* head){

	ListNode* temp = head;
	int count = 0;

	while(temp){

		count++;
		temp = temp->next;
	}

	return count;
}

ListNode* middleNode(ListNode* head) {

	int len = getLength(head); // O(N)
	len /= 2;

	ListNode* temp = head;
	while(len--){ // O(N/2)

		temp = temp->next;
	}

	return temp;
}


// 2. Two-pointer ? O(N/2) : O(1)
ListNode* middleNode(ListNode* head) {

	ListNode* slow = head;
	ListNode* fast = head;

	while(fast && fast->next){

		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

int main(){

	ListNode* head = new ListNode(10);
	ListNode* tail = head;

	insertAtEnd(tail, 20);
	insertAtEnd(tail, 30);
	insertAtEnd(tail, 40);
	insertAtEnd(tail, 50);
	insertAtEnd(tail, 60);

	printLL(head);

	ListNode* midd = middleNode(head);

	cout<<"Middle Node = "<<midd->data<<endl;

	return 0;
}