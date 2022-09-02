// 1. inbuilt ? O(N^2) : O(1)
#include<iostream>
#include<algorithm>
using namespace std;

int main(){

	int nums[] = {1, 2, 3};
	int n = sizeof(nums)/sizeof(nums[0]);

	do{
		for(int i=0; i<n; i++) 
			cout<<nums[i]<<" ";
		cout<<endl;
	
	}while(next_permutation(nums, nums + n));

	// for(int i=0; i<n; i++) cout<<nums[i]<<" ";
	// cout<<endl;

	// next_permutation(nums, nums + n);

	// for(int i=0; i<n; i++) cout<<nums[i]<<" ";
	// cout<<endl;

	// prev_permutation(arr, arr + n);

	return 0;
}