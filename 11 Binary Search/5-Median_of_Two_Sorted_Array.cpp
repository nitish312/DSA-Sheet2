#include<iostream>
#include<vector>
using namespace std;

// 1. mergeSort to merge arrays ? O(N+M) : O(N+M)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> vec(n1 + n2);
    
    int i = 0, j = 0, start = 0;
    while(i < n1 && j < n2)
    {
        vec[start++] = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
    }
        
    while(i < n1) vec[start++] = nums1[i++];
    while(j < n2) vec[start++] = nums2[j++];
    
    int n = n1 + n2;
    if(n % 2 != 0) return vec[n/2];
    else return ((float)vec[n/2] + (float)vec[n/2 - 1])/2;
}



// 2. counter ? O(N+M) : O(1) -> no need for extra data structure, just need mid elems ind
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    double median = 0, number1 = 0, number2 = 0;
    int mid = (n1 + n2)/2;
    
    int i = 0, j = 0, counter = 0;
    while(counter <= mid)
    {
        number1 = number2;
        if(i<n1 && j<n2)
        {
            number2 = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
        }
        else if(i<n1) number2 = nums1[i++];
        else if(j<n2) number2 = nums2[j++];
        
        counter++;
    }
        
    if((n1 + n2) % 2 == 0) median = (number1 + number2)/2; // even
    else median = number2; // odd
    
    return median;
}



// 3. optimal is https://www.youtube.com/watch?v=NTop3VTjmxk&ab_channel=takeUforward

int main()
{
	vector<int> nums1 = {1,2};
	vector<int> nums2 = {3,4};

	double median = findMedianSortedArrays(nums1, nums2);
	cout<<"Median = "<<median;

	return 0;
}