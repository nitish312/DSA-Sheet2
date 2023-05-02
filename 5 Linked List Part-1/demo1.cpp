#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Solution{
public:

    void insertAtEnd(Node* &tail, int val){

        Node* nod = new Node(val);
        tail->next = nod;
        tail = nod;
    }

    void printLL(Node* head){

        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    Node* reverseLLIterative(Node* head){

        Node *prev = NULL, *nxtPtr;
        while(head){
            nxtPtr = head->next;
            head->next = prev;
            prev = head;
            head = nxtPtr;
        }
        return prev;
    }

    Node* reverseLLRecursive(Node* head){

        if(head == NULL || head->next == NULL) return head;

        Node* newHead = reverseLLRecursive(head->next);
        Node* lastNode = head->next;
        lastNode->next = head;
        head->next = NULL;

        return newHead;
    }
};

int main()
{
    Node* head = new Node(10);
    Node* tail = head;
    
    Solution obj;
    obj.insertAtEnd(tail, 20);
    obj.insertAtEnd(tail, 30);
    obj.insertAtEnd(tail, 40);
    obj.insertAtEnd(tail, 50);
    obj.printLL(head);

    Node* rev = obj.reverseLLIterative(head);
    obj.printLL(rev);

    head = obj.reverseLLIterative(rev);

    Node* rev2 = obj.reverseLLRecursive(head);
    obj.printLL(rev2);

    return 0;
}