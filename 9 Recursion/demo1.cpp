#include<iostream>
#include<vector>
using namespace std;

void helper(int i, vector<int>& candidates, int target, vector<int>& subset, vector<vector<int>>& ans, bool prev)
{
    if(target == 0)
    {
        ans.push_back(subset);
        return;
    }

    if(target < 0) return;
    if(i == candidates.size()) return;

    helper(i+1, candidates, target, subset, ans, false);
    if(i > 0 && candidates[i] == candidates[i-1] && !prev) return;

    subset.push_back(candidates[i]);
    helper(i+1, candidates, target - candidates[i], subset, ans, true);
    subset.pop_back();
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> subset;
    int i = 0, n = candidates.size();
    bool prev = false;
    helper(i, candidates, target, subset, ans, prev);
    return ans;
}

int main(){

    vector<int> candidates = {10,1,2,7,6,1,5};

    int target = 8;

    vector<vector<int>> ans = combinationSum(candidates, target);

    for(auto i: ans){
        cout<<"[";
        for(auto j: i){

            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}