class Solution {
public:
    void helper(int ind, vector<int>& candidates, int target, vector<int>& sol, vector<vector<int>>& ans, bool pre){
        
        if(target == 0){
            ans.push_back(sol);
            return;
        }
        
        if(target < 0 || ind >= candidates.size()) return;
        
        helper(ind + 1, candidates, target, sol, ans, false);
        
        if(ind > 0 && candidates[ind] == candidates[ind-1] && !pre) return;
        
        sol.push_back(candidates[ind]);
        helper(ind+1, candidates, target - candidates[ind], sol, ans, true);
        sol.pop_back();
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> sol;
        
        helper(0, candidates, target, sol, ans, false);
        
        return ans;
    }
};

