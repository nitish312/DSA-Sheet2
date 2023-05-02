#include<iostream>
using namespace std;

struct ListNode{

	int data;
	struct ListNode* next;

	ListNode(int val){

		data = val;
		next = NULL;
	}
};

void insertAtEnd(ListNode* &tail, int value){

	ListNode* newNode = new ListNode(value);
	tail->next = newNode;
	tail = tail->next;
}

void printLL(ListNode* head){

	ListNode* temp = head;
	while(temp){

		cout<<temp->data<<" —> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

// 1. brute ? O(N) * O(K) -> O(N^2) : O(1)
ListNode* rotateRight(ListNode* head, int k){

	if(!head || !head->next) return head;

    for(int i=0; i<k; i++){

        ListNode* temp = head;
        while(temp->next->next) temp = temp->next;

        ListNode* last = temp->next;
        temp->next = NULL;
        last->next = head;
        head = last;
    }

    return head;
}



// 2. optimal ? O(N) + O(N-(k%N)) -> O(N) : O(1)
ListNode* rotateRight(ListNode* head, int k){

	if(!head || !head->next) return head;
        
    ListNode *newHead, *tail;
    newHead = tail = head;
    int len = 1;
    
    while(tail->next){ // thats why len was 1 initially
        
        len++;
        tail = tail->next;
    }
    
    tail->next = head;
    
    k %= len; // k will change if k > len
    
    int shift = len - k;
    while(shift--) tail = tail->next;
    
    newHead = tail->next;
    
    tail->next = NULL;
        
    return newHead;
}

int main(){

	ListNode* head = new ListNode(10);
	ListNode* tail = head;

	insertAtEnd(tail, 20);
	insertAtEnd(tail, 30);
	insertAtEnd(tail, 40);
	insertAtEnd(tail, 50);

	printLL(head);

	int k = 2;

	ListNode* newHead = rotateRight(head, k);

	printLL(newHead);

	return 0;
}