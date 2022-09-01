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

int getLength(ListNode* head){

	int count = 0;
	ListNode* temp = head;
	while(temp){

		count++;
		temp = temp->next;
	}

	return count;
}



// // 1. brute ? O(N*M) -> O(N^2) : O(1)
// traversing entire 2nd list to compare with each element in 1st list 
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        	
    ListNode* temp1 = headA; 
    while(temp1){

        ListNode* temp2 = headB;

        while(temp2){

            if(temp2 == temp1) return temp1;

            temp2 = temp2->next;
        }
        
        temp1 = temp1->next;
    }

    return NULL;
}



// // 2. HashSet ? O(N) + O(M) -> O(N+M) : O(N)
// ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        
//     unordered_set<ListNode*> st;
    
//     ListNode* temp1 = headA;
//     ListNode* temp2 = headB;
//     while(temp1){
        
//         st.insert(temp1);
//         temp1 = temp1->next;
//     }
    
//     while(temp2){
        
//         if(st.find(temp2) != st.end()) return temp2;
        
//         temp2 = temp2->next;
//     }
    
//     return NULL;
// }


// // 3. by length ? O(N+M+diff+N) : O(1)
// ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        
//     int len1 = getLength(headA); // O(N)
//     int len2 = getLength(headB); // O(M)

//     int diff = abs(len1 - len2);

//     if(len1 < len2) // O(diff)
//     	while(diff--) headB = headB->next;
//     else 
//     	while(diff--) headA = headA->next;

//     ListNode* temp1 = headA;
//     ListNode* temp2 = headB;

//     while(temp1 && temp2){ // O(N)

//     	if(temp1 == temp2) return temp1;

//     	temp1 = temp1->next;
//     	temp2 = temp2->next;
//     }

//     return NULL;
// }



int main(){

	ListNode* head1 = new ListNode(4);
	ListNode* tail1 = head1;

	insertAtEnd(tail1, 1);
	insertAtEnd(tail1, 8); ListNode* store = tail1;
	insertAtEnd(tail1, 4);
	insertAtEnd(tail1, 5);

	printLL(head1);

	ListNode* head2 = new ListNode(5);
	ListNode* tail2 = head2;

	insertAtEnd(tail2, 6);
	insertAtEnd(tail2, 1);
	tail2->next = store;

	printLL(head2);

	ListNode* intersectionNode = getIntersectionNode(head1, head2);

	cout<<"Intersection Node's value is "<<intersectionNode->data;

	return 0;
}