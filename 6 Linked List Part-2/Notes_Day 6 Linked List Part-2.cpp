(Q1) Find intersection point of Two Linked Lists
	1. brute 
		? O(N1*N2) : O(1)

	2. HashSet - push list1 in set, for list2 - check which node is present in set
		? O(N+M) : O(N)

	3. absolute diff traversal of bigger LL 
		? O(N1+N2+diff+N) : O(1)

	4. Two-pointer - Take 2 dummies, point them to head of lists, iterate over them until they collide, if anyone becomes null, point them to the head of opposite LL else go for their next
		? O(max(N1,N2)) : O(1) 



(Q2) Detect a cycle in Linked List -> *Imp_Point - if there is null, there is no cycle
	1. HashSet - iterate LL, if node is present in set, return true, otherwise keep iterating and inserting node into set
		? O(N) : O(N)

	2. Two-pointer - slow&fast = head, while fast&&fast->next, slow=next & fast=next->next, when slow=fast, return true, otherwise end while loop n return NULL
		? O(N) : O(1)


(Q3) Reverse a LinkedList in groups of k
	1. Recursive 
		? O(N) : O(N/k) -> every recursion call, we r reversing k(constant) nodes and we r telling recursion to do next part

	2. Iterative
		? O(N) : O(1)


(Q4) Check if a LinkedList is palindrome or not
	1. extra space (vector/string) put LL data inside it and return its palindrome
		? O(N) + O(N/2) -> O(N) : O(N)

	2. changing structure of LL -> reversed from middle & traversed head & middle
		? O(N/2) + O(N/2) + O(N/2) -> O(N/2) : O(1)
		(but the original LL structure is changed)

	3. keep beforeMiddle node 
		? : same as previous approach
		(put back LL as it was given to us)


(Q5) Find the starting point of the Loop of LinkedList
	1. HashSet 
		? O(N) : O(N)
	2. Two-pointer - slow&fast=head, while fast&fast->next, slow->next, fast->next->next, if slow=fast break, if !fast||!fast->next return NULL, fast=head, now traverse slow&fast together till they collide n return anyone
		? O(N) : O(1)


(Q6) Flattening of a LinkedList
	{Watch it some other time}

