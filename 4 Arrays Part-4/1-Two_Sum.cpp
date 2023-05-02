// 1. brute ? O(N^2) : O(1)
#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    
    int n = nums.size();
        
    if(n == 0) return {};
    
    vector<int> ans;
    
    for(int i=0; i<n-1; i++){

        int ele1 = nums[i];
        for(int j=i+1; j<n; j++){
            
            int ele2 = nums[j];
            if(ele1 + ele2 == target){
                
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    
    return ans;
}

int main(){

    vector<int> nums = {2,7,11,15};

    int target = 9;

    vector<int> ans = twoSum(nums, target);
    for(auto i: ans) cout<<i<<" ";

    return 0;
}



// 2. brute ? O(N*log(N)) : O(N)
#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    
    int n = nums.size();
        
    vector<pair<int, int>> ans(n);
    
    for(int i=0; i<n; i++){
        
        ans[i] = make_pair(nums[i], i);
    }
    
    sort(ans.begin(), ans.end());
    
    int start = 0, end = n-1;
    while(start < end){
        
        int sum = ans[start].first + ans[end].first;
        
        if(sum == target)
            return {ans[start].second, ans[end].second};
        else if(sum < target) start++;
        else end--;
    }
    
    return {};
}

int main(){

    vector<int> nums = {2,7,11,15};

    int target = 9;

    vector<int> ans = twoSum(nums, target);
    for(auto i: ans) cout<<i<<" ";

    return 0;
}