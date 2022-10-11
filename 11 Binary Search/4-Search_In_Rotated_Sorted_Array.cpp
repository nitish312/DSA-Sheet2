#include<iostream>
#include<vector>
using namespace std;

// 1. linearSearch ? O(N) : O(1)
int search(vector<int>& nums, int target)
{
    int n = nums.size();
    for(int i=0; i<n; i++)
        if(nums[i] == target) 
            return i;
    
    return -1;
}



// 2. binarySearch ? O(log(N)) : O(1)
int search(vector<int>& nums, int target)
{
    int start = 0, end = nums.size() - 1, mid;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        
        if(nums[mid] == target) return mid;
        
        // check whether left side is sorted 
        if(nums[start] <= nums[mid])
        { // if sorted, search target in left side
            if(target >= nums[start] && target <= nums[mid])
            {
                end = mid - 1;
            }
            else start = mid + 1;
        }
        else // left side is not sorted
        { // search target in right side
            if(target >= nums[mid] && target <= nums[end])
            {
                start = mid + 1;
            }
            else end = mid - 1;
        }
    }
    
    return -1;
}

int main()
{
	vector<int> nums = {4,5,6,7,0,1,2};
	int target = 0;

	cout<<search(nums, target);

	return 0;
}