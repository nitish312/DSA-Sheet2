#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

// 1. brute (TLE) ? O(N^2) : O(1) 
int trap(vector<int>& height) {
        
    int n = height.size();
    
    int trappedWater = 0;
    
    for(int i=0; i<n; i++){
        
        int leftMax = 0, rightMax = 0;
        
        int j = i;
        while(j >= 0) leftMax = max(leftMax, height[j--]);
        
        j = i;
        while(j < n) rightMax = max(rightMax, height[j++]);
        
        trappedWater += min(leftMax, rightMax) - height[i];
    }
    
    return trappedWater;
}



// 2. prefix-sufix ? O(3*N) : O(2N) 
int trap(vector<int>& nums) {
        
    int n = nums.size();
    
    int trappedWater = 0;
    
    vector<int> prefix(n);
    prefix[0] = nums[0];
    for(int i=1; i<n; i++)
        prefix[i] = max(prefix[i-1], nums[i]);

    vector<int> sufix(n);
    sufix[n-1] = nums[n-1];
    for(int i=n-2; i>=0; i--)
        sufix[i] = max(sufix[i+1], nums[i]);

    for(int i=0; i<n; i++)
        trappedWater += min(prefix[i], sufix[i]) - nums[i];
    
    return trappedWater;
}



// 3. Two-pointer ? O(N) : O(1) 
int trap(vector<int>& height) {
        
    int n = height.size();
    
    int waterTrapped = 0;
    
    int maxLeft = 0, maxRight = 0;
    int left = 0, right = n-1;
    while(left <= right){
        
        if(height[left] <= height[right]){
            
            if(height[left] >= maxLeft)
                maxLeft = height[left];
            else
                waterTrapped += maxLeft - height[left];
            
            left++;
        }
        else{ // height[right] > height[left]
            
            if(height[right] >= maxRight)
                maxRight = height[right];
            else
                waterTrapped += maxRight - height[right];
            
            right--;
        }
    }
    
    return waterTrapped;
}

int main(){

	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

	cout<<trap(height);	

	return 0;
}