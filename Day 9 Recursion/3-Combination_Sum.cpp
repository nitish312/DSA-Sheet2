#include<iostream>
#include<vector>
using namespace std;

// Recursion ? O(2^N*K) : O(2^N*K)
void helper(int ind, vector<int>& candidates, int target, vector<int> & sol, vector<vector<int>>& ans){
        
    if(target == 0){
        
        ans.push_back(sol);
        return;
    }
    if(target < 0) return;
    if(ind == candidates.size()) return;
    
    // not pick the ith element
    helper(ind + 1, candidates, target, sol, ans);
    
    // pick the ith element, dont increment index, we might need that elem in future
    sol.push_back(candidates[ind]);
    helper(ind, candidates, target - candidates[ind], sol, ans);
    sol.pop_back(); // backtracking
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
    vector<vector<int>> ans;
    vector<int> sol;
    
    helper(0, candidates, target, sol, ans);
    
    return ans;
}

int main(){

    vector<int> candidates = {2,3,6,7};

    int target = 7;

    vector<vector<int>> ans =  combinationSum(candidates, target);

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