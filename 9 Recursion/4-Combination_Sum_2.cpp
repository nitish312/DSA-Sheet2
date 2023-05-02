#include<bits/stdc++.h>
#include<vector>
using namespace std;

// Recursion ? O(2^N*K) : O(2^N*K)
void helper(int ind, vector<int>& candidates, int target, vector<int>& sol, vector<vector<int>>& ans, bool prev){
        
    if(target == 0){
        
        ans.push_back(sol);
        return;
    }
    
    if(target < 0) return;
    if(ind == candidates.size()) return;
    
    
    helper(ind + 1, candidates, target, sol, ans, false);
    
    if(ind > 0 && candidates[ind] == candidates[ind-1] && !prev) return;
    
    
    sol.push_back(candidates[ind]);
    helper(ind + 1, candidates, target - candidates[ind], sol, ans, true);
    sol.pop_back();
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    
    sort(candidates.begin(), candidates.end());
    
    vector<vector<int>> ans;
    vector<int> sol;
    
    helper(0, candidates, target, sol, ans, false);
    
    return ans;
}

void helper(int i, vector<int>& candidates, int target, vector<int>& subset, vector<vector<int>>& ans, bool prev)
{
    if(target == 0)
    {
        ans.push_back(subset);
        return;
    }
    if(target < 0) return;
    if(i == candidates.size()) return;
    
    // not pick the ith element
    helper(i+1, candidates, target, subset, ans, false);
    if(i > 0 && candidates[i] == candidates[i-1] && !prev) return;
    
    // pick the ith element, dont increment index, we might need that elem in future
    subset.push_back(candidates[i]);
    helper(i+1, candidates, target - candidates[i], subset, ans, true);
    subset.pop_back();
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    // sort to arrange elem cause we will be comparing ele with prev
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> subset;
    int i = 0;
    bool prev = false;
    helper(i, candidates, target, subset, ans, prev);
    return ans;
}

int main(){

    vector<int> candidates = {10,1,2,7,6,1,5};

    int target = 8;

    vector<vector<int>> ans =  combinationSum2(candidates, target);

    int n = ans.size();
    int m = ans[0].size();

    for(auto i: ans){
        cout<<"[";
        for(auto j: i){

            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}