#include<iostream>
#include<vector>
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

// // 1. HashSet ? O(N) : O(N)
// ListNode* detectCycle(ListNode *head){
        
//     unordered_set<ListNode*> st;
    
//     ListNode* temp = head;
    
//     while(temp){
        
//         if(st.find(temp) != st.end()) return temp;
        
//         st.insert(temp);
//         temp = temp->next;
//     }
    
//     return NULL;
// }


// 2. Two-pointer ? O(N) : O(1)
ListNode* detectCycle(ListNode *head){
        
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next){
        
        slow = slow->next;
        fast = fast->next->next;
        
        if(fast == slow) break;
    }
    
    // incase cycle not exist, means we got null in LL
    if(!fast || !fast->next) return NULL;
    
    fast = head;
    while(slow != fast){
        
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}

int main(){

	ListNode* head = new ListNode(3);
	ListNode* tail = head;

	insertAtEnd(tail, 2); ListNode* cycle = tail;
	insertAtEnd(tail, 0);
	insertAtEnd(tail, 4);
	tail->next = cycle; // created cycle

	// printLL(head); // dont print // 

	ListNode* ans = detectCycle(head);
	cout<<ans->data;

	return 0;
}