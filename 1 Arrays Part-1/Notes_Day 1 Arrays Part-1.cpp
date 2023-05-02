(Q1) Set Matrix Zeroes
		1. brute -> create vec of pair for {row,col} 
			? O(N*M) + O(N*M) -> O(N*M) : O(N*M)
		2. optimal - (No Extra Space) -> by keeping bools firstRow&firstCol=false
			? O(N*M) + O(N*M) -> O(N*M) : O(1)


(Q2) Pascal’s Triangle
		1. brute 
			? O(N*M) : O(N*M)
		2. by using resize()
			? O(N*M) : O(N*M)


(Q3) Next Permutation
		1. in-built func, do-while for print
			? O(N^2) : O(1)
		2. optimal
			? O(3N) : O(1)


(Q4) Maximum Sum Subarray
		1. brute 
			? O(N^3) : O(1)
		2. better 
			? O(N^2) : O(1)
		3. Kadane`s Algo
			? O(N) : O(1)


(Q5) Sort an array of 0’s 1’s 2’s
		1. in-built sort 
			? O(N*logN) : O(1)
		2. count all 012, iterate array and assign as per counters
			? O(N) + O(N) -> O(N) : O(1)
		3. Three-pointer - (in one pass)
			? O(N) : O(1)


(Q6) Stock buy and Sell
		1. brute 
			? O(N^2) : O(1)
		2. optimal 
			? O(N) : O(1)