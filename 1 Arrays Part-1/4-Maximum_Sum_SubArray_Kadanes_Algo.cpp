#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void printVec(vector<int> nums){

	for(auto i: nums) cout<<i<<" ";
	cout<<endl;
}

// 1. brute ? O(N^3) : O(1)
int maxSumSubArray(vector<int> nums){

	int n = nums.size();

	int maxSum = INT_MIN, sum;

	for(int i=0; i<n; i++){

		for(int j=i; j<n; j++){

			sum = 0;
			for(int k=i; k<=j; k++){

				sum += nums[k];
			}

			if(sum > maxSum) maxSum = sum;
		}
	}

	return maxSum;
}



// 2. better ? O(N^2) : O(1)
int maxSumSubArray(vector<int> nums, pair<int, int>& indices){

	int n = nums.size();

	int maxSum = INT_MIN, sum;

	for(int i=0; i<n; i++){

		sum = 0;
		for(int j=i; j<n; j++){

			sum += nums[j];

			if(sum > maxSum){

				maxSum = sum;
				indices.first = i;
				indices.second = j;
			}
		}
	}

	return maxSum;
}



// 3. kadane's algo ? O(N) : O(1)
int maxSumSubArray(vector<int> nums){

	int n = nums.size();

	int maxSum = INT_MIN;
	int currSum = 0;
	int maxEle = INT_MIN;

	for(int i=0; i<n; i++){

		currSum = max(0, currSum + nums[i]);
		maxSum = max(maxSum, currSum);
		maxEle = max(maxEle, nums[i]);
	}

	if(maxSum == 0) maxSum = maxEle;

	return maxSum;
}

int main(){

	vector<int> nums = {2, 3, -5, 4};

	printVec(nums);

	cout<<maxSumSubArray(nums);

	return 0;
}