// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


// // doesn't work
// // O(2^N) for generating every subset and O(K) to insert every subset in another data structure
// // 1. brute - HashSet ? O(2^N * (2^N*(log2^N)) * K) : O(2^N*K) + O(2*N*K)
// void helper(int i, vector<int>& nums, vector<int> subset, set<vector<int>> & st) 
// {    
//     if(i == nums.size())
//     {    
//         st.insert(subset);
//         return;
//     }

//     helper(i+1, nums, subset, st); // not picked the elem

//     subset.push_back(nums[i]); // picked the elem
//     helper(i+1, nums, subset, st);
//     subset.pop_back(); // backtrack
// }

// vector<vector<int>> subsets(vector<int>& nums)
// {
//     set<vector<int>> st;
//     vector<int> subset;

//     helper(0, nums, subset, st);

//     vector<vector<int>> ans;
//     for(auto vec: st) 
//         ans.push_back(vec);

//     return ans;
// }




// O(2^n) for generating every subset and O(k)  to insert every subset in another data structure
// optimal ? O(2^N(logN)*K) : O(2^N*K)
void helper(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans, bool prev){

    if(i == nums.size())
    {
        ans.push_back(subset);
        return;
    }

    helper(i+1, nums, subset, ans, false); // ith elem not picked

    if(i > 0 && nums[i] == nums[i-1] && !prev) return;

    subset.push_back(nums[i]); // ith elem picked
    helper(i+1, nums, subset, ans, true);
    subset.pop_back(); // backtracking
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;

    vector<int> subset;

    sort(nums.begin(), nums.end());

    helper(0, nums, subset, ans, false);

    return ans;
}

int main(){

    vector<int> nums = {1,2,2};
    int n = nums.size();

    vector<vector<int>> ans = subsets(nums);

    for(auto i: ans){
        cout<<"[";
        for(auto j: i){

            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}