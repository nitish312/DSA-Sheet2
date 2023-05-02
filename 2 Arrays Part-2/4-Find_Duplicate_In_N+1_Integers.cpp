// without modifying array - approach 1 & 2 - not allowed

// // 1. brute ? O(N*log(N)) + O(N) -> O(N*log(N)) : O(1)
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// void printVec(vector<int> nums){

// 	for(auto ele: nums) cout<<ele<<" ";
// 	cout<<endl;
// }

// int findDuplicate(vector<int>& nums){
        
// 	sort(nums.begin(), nums.end());

// 	int n = nums.size();

// 	for(int i=0; i<n-1; i++)
// 		if(nums[i] == nums[i+1]) 
// 			return nums[i];
	
// 	return -1;
// }

// int main(){

// 	vector<int> nums = {3,1,3,4,2};

// 	printVec(nums);

// 	int dup = findDuplicate(nums);
// 	cout<<"Duplicate Number = "<<dup<<endl;

// 	return 0;
// }



// // 2. map ? O(N) + O(N) -> O(N) : O(N)
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;

// void printVec(vector<int> nums){

// 	for(auto ele: nums) cout<<ele<<" ";
// 	cout<<endl;
// }

// int findDuplicate(vector<int>& nums){
        
// 	unordered_map<int, int> freqCount;

// 	for(auto ele: nums) freqCount[ele]++;

// 	for(auto mp: freqCount)
// 		if(mp.second == 2)
// 			return mp.first;

// 	return -1;
// }

// int main(){

// 	vector<int> nums = {3,1,3,4,2};

// 	printVec(nums);

// 	int dup = findDuplicate(nums);
// 	cout<<"Duplicate Number = "<<dup<<endl;

// 	return 0;
// }



// 3. optimal - Assume LL ? O(N) : O(1)
#include<iostream>
#include<vector>
using namespace std;

void printVec(vector<int> nums){

	for(auto ele: nums) cout<<ele<<" ";
	cout<<endl;
}

int findDuplicate(vector<int>& nums){
        
    int slow = nums[0];
    int fast = nums[0];

    do{
    	slow = nums[slow];
    	fast = nums[nums[fast]];

    }while(slow != fast);

    fast = nums[0];

    while(slow != fast){

    	slow = nums[slow];
    	fast = nums[fast];
    }

    return slow;
}

int main(){

	vector<int> nums = {1,3,4,2,2};

	printVec(nums);

	int dup = findDuplicate(nums);
	cout<<"Duplicate Number = "<<dup<<endl;

	return 0;
}