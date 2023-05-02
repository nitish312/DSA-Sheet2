#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVec(vector<int> nums){

	for(auto ele: nums) cout<<ele<<" ";
	cout<<endl;
}

// // 1. brute ? O(N+M) : O(N+M)
// void mergeSortedArrays(vector<int>& nums1, int n1, vector<int>& nums2, int n2){
        
//     vector<int> ans(n1 + n2);

//     int i = 0, j = 0, start = 0;
//     while(i < n1 && j < n2)
//     	ans[start++] = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];

//     while(i < n1) ans[start++] = nums1[i++];
//     while(j < n2) ans[start++] = nums2[j++];

//     printVec(ans);
// }



// 2. in-place ? O(N+M) : O(1)
void mergeSortedArrays(vector<int>& nums1, int n1, vector<int>& nums2, int n2){
        
    int i = n1 - 1;
    int j = n2 - 1;
    int target = n1 + n2 - 1;

    int n = n2;
    while(n--) nums1.push_back(0);

    while(i >= 0 && j >= 0){

    	nums1[target--] = (nums1[i] > nums2[j])
    				      ? nums1[i--] : nums2[j--];
    }

	while(i >= 0) nums1[target--] = nums1[i--];
    while(j >= 0) nums1[target--] = nums2[j--];    
}

int main(){

	vector<int> nums1 = {2, 5, 6};
	vector<int> nums2 = {1, 2, 3};

	int n1 = nums1.size();
	int n2 = nums2.size();

	printVec(nums1);
	printVec(nums2);

	mergeSortedArrays(nums1, n1, nums2, n2);

	printVec(nums1);

	return 0;
}