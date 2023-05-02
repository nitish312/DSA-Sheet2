#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVec(vector<int> nums){

	for(auto i: nums) cout<<i<<" ";
	cout<<endl;
}

// 1. inbuilt ? O(N*logN) : O(1)
void sortZeroOneTwo(vector<int>& nums){

	sort(nums.begin(), nums.end());
}



// 2. better ? O(N) + O(N) -> O(N) : O(1)
void sortZeroOneTwo(vector<int>& nums){

	int zeroCount = 0, oneCount = 0, twoCount = 0;

	for(auto i: nums){

		if(i == 0) zeroCount++;
		else if(i == 1) oneCount++;
		else twoCount++;
	}

	int i = 0;
	while(zeroCount--) nums[i++] = 0;
	while(oneCount--) nums[i++] = 1;
	while(twoCount--) nums[i++] = 2;
}



// 3. Three-pointer ? O(N) : O(1)
void sortZeroOneTwo(vector<int>& nums){

	int n = nums.size();
	int start = 0, curr = 0, end = n-1;
	while(curr <= end){

		if(nums[curr] == 0) swap(nums[start++], nums[curr++]);
		else if(nums[curr] == 1) curr++;
		else if(nums[curr] == 2) swap(nums[curr], nums[end--]);
	}
}

int main(){

	vector<int> nums = {2,0,2,1,1,0};

	printVec(nums);

	sortZeroOneTwo(nums);

	printVec(nums);

	return 0;
}