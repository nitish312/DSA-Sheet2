
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

// 1. create new nodes ? O(N1+N2) : O(N1+N2)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){

	if(!list1) return list2;
	if(!list2) return list1;

	ListNode* dummy = new ListNode(0);

	ListNode* temp = dummy;
	
	while(list1 && list2){

		if(list1->data < list2->data){

			ListNode* newNode = new ListNode(list1->data);

			temp->next = newNode;
			list1 = list1->next;
		}
		else{

			ListNode* newNode = new ListNode(list2->data);

			temp->next = newNode;
			list2 = list2->next;
		}

		temp = temp->next;
	}

	if(list1) temp->next = list1;
	if(list2) temp->next = list2;

	temp = dummy->next;
	delete dummy;

	return temp;
}

int main(){

	ListNode* head1 = new ListNode(1);
	ListNode* tail1 = head1;

	insertAtEnd(tail1, 2);
	insertAtEnd(tail1, 4);

	printLL(head1);

	ListNode* head2 = new ListNode(1);
	ListNode* tail2 = head2;

	insertAtEnd(tail2, 3);
	insertAtEnd(tail2, 4);

	printLL(head2);

	ListNode* merged = mergeTwoLists(head1, head2);

	printLL(merged);

	return 0;
}