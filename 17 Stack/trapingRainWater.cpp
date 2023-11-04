class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size(), waterTrapped = 0, maxLeft = 0, maxRight = 0;
        int left = 0, right = n - 1;
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= maxLeft) maxLeft = height[left];
                else waterTrapped += maxLeft - height[left];
                left++;
            }
            else{
                if(height[right] >= maxRight) maxRight = height[right];
                else waterTrapped += maxRight - height[right];
                right--;
            }
        }
        
        return waterTrapped;
    }
};
