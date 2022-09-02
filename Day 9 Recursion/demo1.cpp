#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){

    vector<int> nums = {3, 1, 2};
    int n = nums.size();

    vector<int> ans = subsetSum(nums, n);

    for(auto i: ans) cout<<i<<" ";

    return 0;
}