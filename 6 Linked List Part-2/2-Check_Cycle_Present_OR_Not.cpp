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

// *Imp_Point -> if there is null, there is no cycle

// // 1. HashSet ? O(N) : O(N)
// bool hasCycle(ListNode *head){
        
//     unordered_set<ListNode*> st;
    
//     ListNode* temp = head;
//     while(temp){
        
//         if(st.find(temp) != st.end()) return true;
        
//         st.insert(temp);
//         temp = temp->next;
//     }
    
//     return false;
// }


// 2. Two-pointer ? O(N) : O(1)
bool hasCycle(ListNode *head){
        
    if(!head || !head->next) return false;

    ListNode *slow = head, *fast = head;

    while(fast && fast->next){

    	slow = slow->next;
    	fast = fast->next->next;

    	if(slow == fast) return true;
    }

    return false;
}

int main(){

	ListNode* head = new ListNode(3);
	ListNode* tail = head;

	insertAtEnd(tail, 2); ListNode* cycle = tail;
	insertAtEnd(tail, 0);
	insertAtEnd(tail, 4);
	tail->next = head; // created cycle

	// printLL(head); // dont print // 

	if(hasCycle(head)) cout<<"Yes, there is a cycle"<<endl;
	else cout<<"No, there isn't any cycle"<<endl;

	return 0;
}