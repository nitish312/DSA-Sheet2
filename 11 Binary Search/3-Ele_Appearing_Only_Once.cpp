#include<iostream>
#include<vector>
using namespace std;

// 1. linear by XOR ? O(N) : O(1)
int singleNonDuplicate(vector<int>& nums)
{
	int n = nums.size(), ele = 0;
	// xor property = ele^ele=0 & ele^0=ele
	for(int i=0; i<n; i++)
	{
		ele ^= nums[i];
	}
	return ele;
}



// 2. binarySearch recursive ? O(log(N)) : O(1)
int binarySearch(vector<int>& nums, int start, int end)
{
	// if mid=next, if mid is odd, end=mid-1 else start=mid
	// else mid!=next, if mid is odd, start=mid+1 else end=mid
	if(start == end) return nums[start];
	int mid = start + (end - start)/2;

	if(nums[mid] == nums[mid+1])
	{
		if(mid % 2)
		{
			end = mid - 1;
		}
		else
		{
			start = mid;
		}
	}
	else
	{
		if(mid % 2) start = mid + 1;
		else end = mid;
	}

	return binarySearch(nums, start, end);
}

// 1. bianry search ? O(log(N)) : O(1)
int singleNonDuplicate(vector<int>& nums)
{
	return binarySearch(nums, 0, nums.size());
}

int main()
{
	vector<int> nums = {1,1,2,3,3,4,4,8,8};

	int ans = singleNonDuplicate(nums);
	cout<<ans<<" appears only once in an array";

	return 0;
}