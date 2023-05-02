#include<iostream>
#include<vector>
using namespace std;

// Recursion ? O(2^N*K) : O(2^N*K)
void solve(int i, vector<int>& nums, int sum, vector<int>& subset, vector<vector<int>>& ans)
{        
    if(sum == 0)
    {    
        ans.push_back(subset);
        return;
    }
    if(sum < 0) return;
    if(i == nums.size()) return;
    
    solve(i+1, nums, sum, subset, ans); // not pick the ith element
    
    
    subset.push_back(nums[i]); // pick the ith element, 
    // dont increment index, we might need that elem in future
    solve(i, nums, sum - nums[i], subset, ans);
    subset.pop_back(); // backtracking
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{    
    vector<vector<int>> ans;
    vector<int> subset;
    
    solve(0, candidates, target, subset, ans);
    
    return ans;
}

int main()
{
    vector<int> candidates = {2,3,6,7};

    int target = 7;

    vector<vector<int>> ans = combinationSum(candidates, target);

    int n = ans.size();
    int m = ans[0].size();

    for(auto i: ans)
    {
        cout<<"[";
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}