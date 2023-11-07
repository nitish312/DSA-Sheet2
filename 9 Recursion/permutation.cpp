class Solution {
public:
    void helper(int i, vector<int>& nums, int n, vector<vector<int>>& ans){
        
        if(i == n){
            ans.push_back(nums);
            return;
        }
        
        for(int j = i; j < n; j++){
            swap(nums[i], nums[j]);
            helper(i + 1, nums, n, ans);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums){
        
        int n = nums.size();
        vector<vector<int>> ans;
        helper(0, nums, n, ans);
        return ans;
    }
};
