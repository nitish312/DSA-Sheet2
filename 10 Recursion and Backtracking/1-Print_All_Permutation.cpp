#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1. brute ? O(N! * N) -> generating N! permutations : O(N) 
void allPermutations(vector<int>& nums, vector<int>& freq, vector<int>& ds, vector<vector<int>>& ans){
        
    if(ds.size() == nums.size()){
        
        ans.push_back(ds);
        return;
    }
    
    for(int i=0; i<nums.size(); i++){
        
        if(!freq[i]){

            ds.push_back(nums[i]);
            freq[i] = 1;
            allPermutations(nums, freq, ds, ans);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> freq(nums.size());

    allPermutations(nums, freq, ds, ans);
    
    return ans;
}



// 2. optimal ? O(N! * N) -> generating N! permutations : O(1) 
void allPermutations(int i, vector<int>& nums, vector<vector<int>>& ans){
        
    if(i == nums.size()){
        
        ans.push_back(nums);
        return;
    }
    
    for(int j=i; j<nums.size(); j++){
        
        swap(nums[i], nums[j]);
        allPermutations(i+1, nums, ans);
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    
    vector<vector<int>> ans;
    
    allPermutations(0, nums, ans);
    
    return ans;
}

int main(){

    vector<int> nums = {1,2,3};

    vector<vector<int>> ans = permute(nums);

    for(auto i: ans){

        cout<<"[ ";
        for(auto j: i){

            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}