// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.
#include<iostream>
#include<vector>
using namespace std;

// Recursive ? O(2^N) : O(2^N)
void helper(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans)
{
    if(i == nums.size())
    {
        ans.push_back(subset);
        return;
    }

    helper(i+1, nums, subset, ans); // ith elem not picked

    subset.push_back(nums[i]); // ith elem picked
    helper(i+1, nums, subset, ans);
    subset.pop_back(); // backtracking
}

vector<vector<int>> subsets2(vector<int>& nums)
{
    vector<vector<int>> ans;

    vector<int> subset;

    helper(0, nums, subset, ans);

    return ans;
}



// Iterative ? O(2^N) : O(2^N)
vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;

    int n = nums.size();

    ans.push_back({});

    for(int i=0; i<n; i++)
    {
        int sz = ans.size();

        for(int j=0; j<sz; j++)
        {
            vector<int> vec = ans[j];
            vec.push_back(nums[i]);

            ans.push_back(vec);
        }
    }

    return ans;
}

int main(){

    vector<int> nums = {1,2,3};
    int n = nums.size();

    vector<vector<int>> ans = subsets2(nums);

    for(auto i: ans){
        cout<<"[";
        for(auto j: i){

            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}