class Solution {
public:
    void helper(int ind, vector<int>& candidates, int target, vector<int> & sol, vector<vector<int>>& ans){
        
        if(target == 0){
            ans.push_back(sol);
            return;
        }
        if(target < 0 || ind == candidates.size()) return;
        
        helper(ind + 1, candidates, target, sol, ans);
        
        sol.push_back(candidates[ind]);
        helper(ind, candidates, target - candidates[ind], sol, ans);
        sol.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> sol;
        
        helper(0, candidates, target, sol, ans);
        
        return ans;
    }
};
