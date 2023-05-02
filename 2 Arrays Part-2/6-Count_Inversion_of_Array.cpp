/*
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:
1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'
*/

// // 1. brute ? O(N^2) : O(1)
// #include<iostream>
// #include<vector>
// using namespace std;

// void printVec(vector<int> nums){

// 	for(auto ele: nums) cout<<ele<<" ";
// 	cout<<endl;
// }

// int getInversionCount(vector<int> nums, int n){

// 	int count = 0;

// 	for(int i=0; i<n-1; i++){

// 		for(int j=i+1; j<n; j++){

// 			if(nums[j] < nums[i]) count++;
// 		}
// 	}

// 	return count;
// }

// int main(){

// 	vector<int> nums = {1, 6, 20, 4, 5}; 
// 	int n = nums.size();

// 	printVec(nums);

// 	int count_of_inversions = getInversionCount(nums, n);
// 	cout<<"Total no. of inversion = "<<count_of_inversions<<endl;

// 	return 0;
// }



// 2. optimal ? O(N*log(N)) : O(N)
#include<iostream>
#include<vector>
using namespace std;

void printVec(vector<int> nums){

	for(auto ele: nums) cout<<ele<<" ";
	cout<<endl;
}

int merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end){

    int inv_count = 0;
    int i = start;
    int j = mid;
    int k = start;
    while((i <= mid-1) && (j <= end)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= end)
        temp[k++] = arr[j++];

    for(i = start ; i <= end ; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

int mergeSort(vector<int>& arr, vector<int>& temp, int start, int end){

	if(start >= end) return 0;

    int inv_count = 0; // new line
   
    int mid = start + (end - start)/2;

    inv_count += mergeSort(arr, temp, start, mid);
    inv_count += mergeSort(arr, temp, mid+1, end);

    inv_count += merge(arr, temp, start, mid+1, end);
    
    return inv_count; // new line
}

int getInversionCount(vector<int>& nums, int n){

	vector<int> temp(n);
	return mergeSort(nums, temp, 0, n-1);
}

int main(){

	vector<int> nums = {1, 6, 20, 4, 5}; 
	int n = nums.size();

	printVec(nums);

	int count_of_inversions = getInversionCount(nums, n);
	cout<<"Total no. of inversion = "<<count_of_inversions<<endl;

	return 0;
}