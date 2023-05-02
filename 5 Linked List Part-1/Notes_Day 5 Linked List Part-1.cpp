(Q1) Reverse a LinkedList
	1. Iterative ? O(N) : O(1)
	2. Recursive ? O(N) : O(1)


(Q2) Find the middle of LinkedList
	1. get length, traverse to len/2 ? O(N+N/2) -> O(N) : O(1)
	2. Two-pointer ? O(N/2) : O(1)


(Q3) Merge two sorted Linked List (use method used in mergeSort)
	1. create entire new LL ? O(N1 + N2) : O(N1 + N2)
	2. create single dummy node ? O(N1 + N2) : O(1)
	3. in-place & swaps ? O(N1 + N2) : O(1)


(Q4) Remove N-th node from back of LinkedList
	1. reach len-n-1 node & delete nextNode (handle if its headNode) ? O(N+N) : O(1)
	2. Two-pointer in one pass - create dummy,->head, fast&slow = dummy, move fast->next n times, move both->next til fast->next, delete slow->next
	(handle if its headNode) ? O(N) : O(1)


(Q5) Add two numbers as LinkedList 
	- make sure to ask edge cases - list1 < || > list2 or same
	1. sum & carry ? O(max(l1, l2)) : O(N)


(Q6) Delete a given Node when a node is given. 0(1) solution
	1. swap node's value with its nextNode's value, delete nextNode ? O(1) : O(1)