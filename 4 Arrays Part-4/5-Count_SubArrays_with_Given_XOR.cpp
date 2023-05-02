// 1. brute ? O(N^2) : O(1)
#include<iostream>
#include<vector>
using namespace std;

int subarraysXor(vector<int> &nums, int x){

	int n = nums.size();

	int count = 0;

	for(int i=0; i<n; i++){

		int curr_xor = 0;
		for(int j=i; j<n; j++){

			curr_xor ^= nums[j];

			if(curr_xor == x) count++;
		}
	}

	return count;
}

int main(){

	vector<int> nums = {4, 2, 2, 6, 4};

	int x = 6;

	int ans = subarraysXor(nums, x);
	cout<<ans; // 2

	return 0;
}



// 2. prefix xor & HashMap ? O(N) : O(N)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraysXor(vector<int> &nums, int x){

	// XR (xor of entire array) = Y (remainning subarray) ^ K (subarray having xor as x)
	// so, Y = XR ^ K
	// eg. 	// 2 ^ 4 = 6,
	 		// 4 ^ 6 = 2,
			// 6 ^ 2 = 4

	int n = nums.size();

	int count = 0;

	unordered_map<int, int> freqCount;

	int curr_xor = 0;

	for(int i=0; i<n; i++){

		curr_xor ^= nums[i]; 

		if(curr_xor == x) count++; 

		if(freqCount.find(curr_xor ^ x) != freqCount.end()) // if xor found in map, 
			count += freqCount[curr_xor ^ x]; 				// increment count to its value in map

		freqCount[curr_xor]++; // make entry into map
	}

	return count;
}

int main(){

	vector<int> nums = {4, 2, 2, 6, 4};

	int x = 6;

	int ans = subarraysXor(nums, x);
	cout<<ans; // 2

	return 0;
}