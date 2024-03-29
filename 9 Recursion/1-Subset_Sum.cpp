#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 2. optimal ? O(2^N) + O(2^N(log(2^N))) : O(2^N)
void subsetSumHelper(int i, vector<int>& nums, int n, vector<int>& ans, int sum){

    if(i == n){

        ans.push_back(sum);
        return;
    }

    // not picked
    subsetSumHelper(i+1, nums, n, ans, sum); 

    // picked
    subsetSumHelper(i+1, nums, n, ans, sum + nums[i]);
}

vector<int> subsetSum(vector<int>& nums, int n){

    vector<int> ans;

    subsetSumHelper(0, nums, n, ans, 0);

    // sort(ans.begin(), ans.end());

    return ans;
}

int main(){

    vector<int> nums = {3, 1, 2};
    int n = nums.size();

    vector<int> ans = subsetSum(nums, n);

    for(auto i: ans) cout<<i<<" ";

    return 0;
}