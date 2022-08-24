// inbuilt ? O(N^2) : O(1)
#include<iostream>
#include<algorithm>
using namespace std;

int main(){

	int arr[] = {1, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	do{
		for(int i=0; i<n; i++) 
			cout<<arr[i]<<" ";
		cout<<endl;
	
	}while(next_permutation(arr, arr + n));

	// prev_permutation(arr, arr + n);

	return 0;
}



// inbuilt ? O(3*O(N)) -> O(N) : O(1)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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