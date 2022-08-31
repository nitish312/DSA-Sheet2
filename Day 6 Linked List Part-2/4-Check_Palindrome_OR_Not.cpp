#include<iostream>
#include<vector>
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

// 1. extra space ? O(N) + O(N/2) -> O(N) : O(N)
bool isPalindrome(ListNode* head){
        
    vector<int> nums;
    
    ListNode* temp = head;
    while(temp){
        
        nums.push_back(temp->data);
        temp = temp->next;
    }
    
    int start = 0, end = nums.size() - 1;
    while(start < end){
        
        if(nums[start] != nums[end]) return false;
        start++;
        end--;
    }
    
    return true;
}



// 2. changing structure of LL ? O(N/2) : O(1)
// what if it is not allowed to change original LL
bool isPalindrome(ListNode* head) {
    
    ListNode* temp = head;
    
    ListNode* middle = getMiddleNode(temp);
    
    ListNode* rev = reverseLL(middle);
    
    while(temp && rev){
        
        if(temp->val != rev->val) return false;
        
        temp = temp->next;
        rev = rev->next;
    }
    
    return true;
}


// 3. optimal (keeping before mid) ? O(N/2) : O(1)
ListNode* getMiddleNode(ListNode* &head){
        
    ListNode* slow = head;
    ListNode* fast = head;
    
    // keeping node before mid
    while(fast->next && fast->next->next){
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow; // mid = slow->next;
}

bool isPalindrome(ListNode* head) {
    
    ListNode* slow = getMiddleNode(head);
    // slow is having node before middle

    slow->next = reverseLL(slow->next);
    // reversed from middle 

    printLL(head);

    ListNode *left = head, *right = slow->next;  

    while(left && right){
        
        if(left->data != right->data) return false;
        
        left = left->next;
        right = right->next;
    }

    slow->next = reverseLL(slow->next); 
    // reversed back and attached 

    printLL(head);

    return true;
}

int main(){

	ListNode* head = new ListNode(1);
	ListNode* tail = head;

	insertAtEnd(tail, 2);
	insertAtEnd(tail, 2);
	insertAtEnd(tail, 1);
	// insertAtEnd(tail, 5);
	
	printLL(head); 

	if(isPalindrome(head)) cout<<"Yes, it is palindrome";
	else cout<<"No, its not palindrome";

	return 0;
}