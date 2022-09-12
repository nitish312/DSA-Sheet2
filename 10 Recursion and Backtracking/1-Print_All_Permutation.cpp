#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1. brute ? O(N! * N) -> generating N! permutations : O(N) 
void allPermutations(vector<int>& nums, vector<int>& freq, vector<int>& temp, vector<vector<int>>& ans){
        
    if(temp.size() == nums.size()){
        
        ans.push_back(temp);
        return;
    }
    
    for(int i=0; i<nums.size(); i++){
        
        if(!freq[i]){

            temp.push_back(nums[i]);
            freq[i] = 1;
            allPermutations(nums, freq, temp, ans);
            freq[i] = 0;
            temp.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> freq(nums.size());

    allPermutations(nums, freq, temp, ans);
    
    return ans;
}



// 2. optimal ? O(N! * N) -> generating N! permutations : O(1) 
void allPermutations(int ind, vector<int>& nums, vector<vector<int>>& ans){
        
    if(ind == nums.size()){
        
        ans.push_back(nums);
        return;
    }
    
    for(int i=ind; i<nums.size(); i++){
        
        swap(nums[i], nums[ind]);
        allPermutations(ind+1, nums, ans);
        swap(nums[i], nums[ind]);
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