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

// 1. brute ? O(N) + O(N) -> O(2N) : O(1)
int getLength(ListNode* head)
{
	int count = 0;
	while(head)
	{
		count++;
		head = head->next;
	}
	return count;
}

ListNode* removeNthFromEnd(ListNode* head, int n){

	int len = getLength(head);

	int ind = len - n;
	// cout<<ind<<endl;

	if(len == n){ // to delete head

		ListNode* delNode = head;
		head = head->next;
		delete(delNode);
		return head;
	}

	ListNode* temp = head;
	while(--ind){ // pre-decrement 
// eg. if(n == 4 && len == 5), len(5) - n(2) = ind(3) 
// so 3 times temp->next only & then delete next one 

		temp = temp->next;
	}

	ListNode* delNode = temp->next;
	temp->next = delNode->next;
	delete(delNode);

	return head;
}


// 2. Two-pointer - In one pass ? O(N) : O(1)
ListNode* removeNthFromEnd(ListNode* head, int n){

	ListNode* dummy = new ListNode(0);
	dummy->next = head;

	ListNode *fast, *slow;
	fast = slow = dummy;

	while(n--){

		fast = fast->next;
	}

	while(fast->next){

		slow = slow->next;
		fast = fast->next;
	}

	if(slow->next == head){

		ListNode* delNode = slow->next;
		head = head->next;
		delete(delNode);
		return head;
	}

	ListNode* delNode = slow->next;
	slow->next = delNode->next;
	delete(delNode);

	return head;
}

int main(){

	ListNode* head = new ListNode(10);
	ListNode* tail = head;

	insertAtEnd(tail, 20);
	insertAtEnd(tail, 30);
	insertAtEnd(tail, 40);
	insertAtEnd(tail, 50);

	printLL(head);

	ListNode* removed = removeNthFromEnd(head, 2);

	printLL(removed);

	return 0;
}