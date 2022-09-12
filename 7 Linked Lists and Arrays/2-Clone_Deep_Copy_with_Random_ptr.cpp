#include<iostream>
#include<unordered_map>
using namespace std;

struct ListNode{

	int data;
	struct ListNode* next;
	struct ListNode* random;  // not implemented

	ListNode(int val){

		data = val;
		next = NULL;
		random = NULL; // all random points to NULL
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


// 1. HashMap ? O(N) + O(N) -> O(N) : O(N)
ListNode* copyRandomList(ListNode* head){
    // deep copy - entire new LL, no pointers to original LL
    unordered_map<ListNode*, ListNode*> mp;
    
    ListNode* temp = head;
    while(temp){
        
        ListNode* copyNode = new ListNode(temp->data);
        
        mp[temp] = copyNode; // mapped every node's addr with its copy's addr
        
        temp = temp->next;
    }
    
    temp = head;
    
    while(temp){
        
// pointing curr's copy's next to curr's next's copy & same for random
        mp[temp]->next = mp[temp->next]; 
        mp[temp]->random = mp[temp->random];
        
        temp = temp->next;
    }
    
    return mp[head]; // copy LL's head
}



// 2. optimal - No extra space ? O(3N) -> O(N) : O(1)
void copyList(ListNode* head){
        
    ListNode *temp = head, *headNxt = head->next;
    while(temp){
        
        ListNode* copy = new ListNode(temp->data);
        
        temp->next = copy;
        copy->next = headNxt;
        temp = headNxt;
        if(headNxt) headNxt = headNxt->next;
    }
    // each node's next will be copy of itself
}

void handleRandom(ListNode* head){
    
    ListNode* temp = head;
    while(temp){
        
        if(temp->random)
            temp->next->random = temp->random->next;
        
        temp = temp->next->next; // cause temp->next is copy of temp
    }
}

ListNode* detach(ListNode* head){
    
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;
    
    ListNode* temp = head; // for iterating
    while(temp){
        
        tail->next = temp->next;
        tail = tail->next;
        temp->next = tail->next;
        temp = temp->next;
    }
    
    return dummy->next;
}

ListNode* copyRandomList(ListNode* head) {
    
    if(!head) return head;
    
    copyList(head);
    handleRandom(head);
    
    ListNode* copyHead = detach(head);
    
    return copyHead;
}

int main(){

	ListNode* head = new ListNode(10);
	ListNode* tail = head;

	insertAtEnd(tail, 20);
	insertAtEnd(tail, 30);
	insertAtEnd(tail, 40);
	insertAtEnd(tail, 50);
	insertAtEnd(tail, 60);
	insertAtEnd(tail, 70);
	insertAtEnd(tail, 80);

	printLL(head);

	ListNode* copyHead = copyRandomList(head);

	printLL(copyHead);

	return 0;
}