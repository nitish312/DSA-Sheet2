#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// // 1. brute 
// void allPermutation(int index, vector<int>& nums, vector<vector<int>>& all){

// 	if(index == nums.size()){

// 		all.push_back(nums);
// 		return;
// 	}

// 	for(int i=index; i<nums.size(); i++){

// 		swap(nums[index], nums[i]);
// 		allPermutation(index + 1, nums, all);
// 		swap(nums[index], nums[i]);
// 	}
// }

// void nextPermutation(vector<int>& nums) {
        
// 	vector<vector<int>> all;

// 	allPermutation(0, nums, all);

// 	for(int i=0; i<all.size(); i++){
// 		for(int j=0; j<all[0].size(); j++){
// 			cout<<all[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// }



// // 2. inbuilt ? O(N^2) : O(1)
// 	do{
// 		for(int i=0; i<n; i++) 
// 			cout<<arr[i]<<" ";
// 		cout<<endl;
	
// 	}while(next_permutation(arr, arr + n));

// 	// prev_permutation(arr, arr + n);




// 3. optimal ? O(3*O(N)) -> O(N) : O(1)
void nextPermutation(vector<int>& nums) {
        
	int n = nums.size();

    int i;
    for(i=n-2; i>=0; i--){

        if(nums[i] < nums[i+1]) break;
    }
        
    int j;
    if(i != -1){

        for(j=n-1; j>=0; j--){

            if(nums[j] > nums[i]) break;
        }

        swap(nums[i], nums[j]);
    }
        
    reverse(nums.begin()+i+1, nums.end());
}

int main(){

	vector<int> nums = {1, 3, 2};

	nextPermutation(nums);

	for(auto i: nums) cout<<i<<" ";

	return 0;
}