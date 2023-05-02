// 1. brute ? O(N*logN) : O(1)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums){

	int n = nums.size();

	if(n < 2) return n;

	sort(nums.begin(), nums.end()); // O(N*logN)

	int maxCount = 0, count = 1;
	for(int i=0; i<n-1; i++){ // O(N)
        
		if(nums[i] + 1 == nums[i+1]) count++;

		if(count > maxCount) maxCount = count;
	}

	return maxCount;
}

int main(){

	vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

	int len = longestConsecutive(nums);
	cout<<len;

	return 0;
}



// 2. HashSet ? O(N) : O(N)
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums){

	int n = nums.size();

	if(n < 2) return n;

	unordered_set<int> st; 

	for(int i=0; i<n; i++) // O(N)
		st.insert(nums[i]); // O(1)

	int ans = 0;
	for(int i=0; i<n; i++){ // O(N)

		int prevEle = nums[i] - 1;
		if(st.find(prevEle) != st.end()) continue;
		else{

			int currEle = nums[i], count = 0;
			while(st.find(currEle++) != st.end()) count++;

			if(count > ans) ans = count;
		}
	}

	return ans;
}

int main(){

	vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

	int len = longestConsecutive(nums);
	cout<<len;

	return 0;
}