// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// O(2^N) for generating every subset and O(K) to insert every subset in another data structure
// 1. brute - HashSet ? O(2^N(logN)*K) : O(2^N*K)
void helper(int ind, vector < int > & nums, vector < int > temp, set < vector < int >> & st) {
    
    if(ind == nums.size()){
        
        st.insert(temp);
        return;
    }

    temp.push_back(nums[ind]); // picked the elem
    helper(ind + 1, nums, temp, st);

    temp.pop_back(); // not picked the elem
    helper(ind + 1, nums, temp, st);
}

vector<vector<int>> subsets(vector<int>& nums){

    vector<vector<int>> ans;

    set<vector<int>> st;
    vector<int> temp;

    helper(0, nums, temp, st);

    for(auto vec: st) ans.push_back(vec);

    return ans;
}

int main(){

    vector<int> nums = {1,2,2};
    int n = nums.size();

    sort(nums.begin(), nums.end());

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