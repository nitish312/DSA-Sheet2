// 1. brute ? O(N^2) : O(1)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int longestSubArrayWithSumZero(vector<int> nums){

	int n = nums.size();

	int maxCount = 0, sum;
	for(int i=0; i<n; i++){ 

		sum = 0;
		for(int j=i; j<n; j++){ 

			sum += nums[j];

			if(sum == 0){

				int len = j - i + 1;
				if(len > maxCount) maxCount = len;
			}
		}
	}

	return maxCount;
}

int main(){

	vector<int> nums = {15,-2,2,-8,1,7,10,23};

	int longestLenSumZero = longestSubArrayWithSumZero(nums);
	cout<<longestLenSumZero;

	return 0;
}



// 2. HashMap ? O(N) : O(N)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestSubArrayWithSumZero(vector<int> nums){

	int n = nums.size();

	unordered_map<int, int> sumIndex;

	int maxCount = 0, sum = 0;
	for(int i=0; i<n; i++){

		sum += nums[i];

		if(sum == 0) maxCount = i + 1; 
		else{

			if(sumIndex.find(sum) == sumIndex.end()) // if sum not found in map, make entry of sum with curr index in map
				sumIndex[sum] = i;
			else
				maxCount = max(maxCount, i - sumIndex[sum]); // if sum found, fetch maxCount 
		}
	}

	return maxCount;
}

int main(){

	vector<int> nums = {1, 2, -2, 4, -4};

	int longestLenSumZero = longestSubArrayWithSumZero(nums);
	cout<<longestLenSumZero;

	return 0;
}