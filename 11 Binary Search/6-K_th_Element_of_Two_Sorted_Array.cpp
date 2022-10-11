#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1. brute - new arr ? O(N + M + N*log(N+M)) : O(N+M)
int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    vector<int> nums;
    for(int i=0; i<n; i++) nums.push_back(arr1[i]);
    for(int i=0; i<m; i++) nums.push_back(arr2[i]);
    sort(nums.begin(), nums.end());
    return nums[k-1];
}



// 2. Naive ? O(k) : O(1)
int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int counter = 0, ans = 0;

    int i = 0, j = 0; 
    while(i<n && j<m)
    {
        if(counter == k) break;
        else if(arr1[i] < arr2[j]) ans = arr1[i++];
        else ans = arr2[j++];
        ++counter;
    }
    if(counter != k) 
    {
        if(i != n-1) ans = arr1[k-counter];
        else ans = arr2[k-counter];
    }

    return ans;
}


// wrong ans of GFG
// 3. optimal ? O(log(min(n,m))) : O(1)
int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if(n > m)
    {
        return kthElement(arr2, arr1, m, n, k);
    }

    int start = max(0, k-n);
    int end = min(k, m);
    while(start <= end)
    {
        int cut1 = start + (end - start)/2; 
        int cut2 = k - cut1; 
        int l1 = (!cut1) ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = (!cut2) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : arr1[cut1]; 
        int r2 = (cut2 == n) ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) return max(l1, l2);
        else if (l1 > r2) end = cut1 - 1;
        else start = cut1 + 1; 
    }

    return 1;
}

int main()
{
    int arr1[] = {2, 3, 6, 7, 9};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {1, 4, 8, 10};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int k = 5;

    cout<<kthElement(arr1, arr2, n, m, k);

    return 0;
}