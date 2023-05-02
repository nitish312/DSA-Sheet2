// 1. individual ? O(N) + O(N) -> O(N) : O(1)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> nums){

	for(auto ele: nums) cout<<ele<<" ";
	cout<<endl;
}

int getDuplicate(vector<int>& nums){ // O(N)

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

int getMissing(vector<int>& nums, int dup){ // O(N)

	int numsSum = 0;
	numsSum = accumulate(nums.begin(), nums.end(), numsSum); // O(N)

	numsSum -= dup;

	int n = nums.size();

	int firstNSum = n * (n + 1)/2;

	return firstNSum - numsSum;
}

pair<int, int> findMissingAndRepeating(vector<int>& nums){ // O(N) + O(N)
        
    pair<int, int> ans;

    ans.first = getDuplicate(nums); 
    ans.second = getMissing(nums, ans.first); 

    return ans;
}

int main(){

	vector<int> nums = {1, 3, 5, 4, 4};

	printVec(nums);

	pair<int, int> ans = findMissingAndRepeating(nums);
	cout<<"Duplicate Number = "<<ans.first<<endl;
	cout<<"Missing Number = "<<ans.second<<endl;

	return 0;
}



// 2. math ? O(N) : O(1)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> nums){

	for(auto ele: nums) cout<<ele<<" ";
	cout<<endl;
}

int getDuplicate(vector<int>& nums){ // O(N)

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

int getMissing(vector<int>& nums, int dup){ // O(N)

	int numsSum = 0;
	numsSum = accumulate(nums.begin(), nums.end(), numsSum); // O(N)

	numsSum -= dup;

	int n = nums.size();

	int firstNSum = n * (n + 1)/2;

	return firstNSum - numsSum;
}

pair<int, int> findMissingAndRepeating(vector<int>& nums){ // O(N)
        
    int n = nums.size();

    int numSum = n * (n + 1)/2; // sum of all elements of first N numbers
    int sqrSum = n*(n + 1) * (2*n + 1) / 6; // sum of squares of all ...
    int missing = 0, repeating = 0;
     
    for(int i=0; i<n; i++){

       numSum -= nums[i];
       sqrSum -= nums[i] * nums[i];
    }
     
    missing = (numSum + sqrSum/numSum)/2;

    repeating = missing - numSum;

    return {repeating, missing};
}

int main(){

	vector<int> nums = {3,1,2,5,4,6,7,5};

	printVec(nums);

	pair<int, int> ans = findMissingAndRepeating(nums);
	cout<<"Duplicate Number = "<<ans.first<<endl;
	cout<<"Missing Number = "<<ans.second<<endl;

	return 0;
}