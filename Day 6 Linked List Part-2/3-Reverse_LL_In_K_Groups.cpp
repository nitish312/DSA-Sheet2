#include<iostream>
#include<unordered_set>
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

// 1. Recursive ? O(N) : O(N/K) 
// : O(N/K) -> every recursion call, we r reversing k(constant) nodes and we r telling recursion to do next part
void reverseLL(ListNode* &prePtr, ListNode* &curr, ListNode* nxtPtr, int k){

	// curr will store next pointer of last node in original LL
	// prePtr will be last node of reverse LL
	int count = 0;
	while(curr && count < k){

		nxtPtr = curr->next;
		curr->next = prePtr;
		prePtr = curr;
		curr = nxtPtr;
		count++;
	}
}

ListNode* reverseKGroup(ListNode* head, int k){

	// base case
	if(!head || !head->next || k == 1) return head;

	// check for k nodes
	int count = 0;
	ListNode* temp = head;
	while(count < k){

		if(!temp) return head;

		count++;

		temp = temp->next;
	}

	// reverse logic
	ListNode *prePtr = NULL, *curr = head, *nxtPtr = NULL;

	reverseLL(prePtr, curr, nxtPtr, k);

	// recursive call
	head->next = reverseKGroup(curr, k);

	return prePtr;
}





// 2. Iterative ? O(N) : O(1) 
int getCount(ListNode* head){
        
    ListNode* temp = head;
    int count = 0;
    while(temp->next){

        count++;
        temp = temp->next;
    }
    
    return count;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    
    if(!head || !head->next || k == 1) return head;

    ListNode* dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *prePtr, *curr, *nxtPtr;
    prePtr = curr = nxtPtr = dummy;
    
    int count = getCount(curr);

    while(count >= k){

        curr = prePtr->next;
        nxtPtr = curr->next;
        
        for(int i=1; i<k; i++){
            
            curr->next = nxtPtr->next;
            nxtPtr->next = prePtr->next;
            prePtr->next = nxtPtr;
            nxtPtr = curr->next;
        }
        
        prePtr = curr;
        count -= k;
    }

    return dummy->next;
}

int main(){

	ListNode* head = new ListNode(1);
	ListNode* tail = head;

	insertAtEnd(tail, 2);
	insertAtEnd(tail, 3);
	insertAtEnd(tail, 4);
	insertAtEnd(tail, 5);
	
	printLL(head); 

	int k = 2;
	ListNode* ans = reverseKGroup(head, k);

	printLL(ans);

	return 0;
}