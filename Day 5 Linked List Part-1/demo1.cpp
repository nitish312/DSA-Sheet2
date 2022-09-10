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

ListNode* middleNode(ListNode* head)
{
	ListNode *slow = head, *fast = head;
	while(fast && fast->next)
	{
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