// // 1. brute ? O(N^2) : O(1)
// #include<iostream>
// #include<vector>
// using namespace std;

// vector<int> majorityElement(vector<int>& nums){

//     int n = nums.size();

//     if(n == 0) return {};

//     vector<int> ans;

//     int curr, count;
//     for(int i=0; i<n; i++){

//         curr = nums[i], count = 1;
//         for(int j=i+1; j<n; j++){

//             if(nums[j] == curr) count++;
//         }

//         if(count > n/3) ans.push_back(curr);
//     }

//     return ans;
// }

// int main(){

//     vector<int> nums = {1,2};

//     vector<int> ans = majorityElement(nums);
//     cout<<"Majority Elements = ";

//     for(auto i: ans) cout<<i<<" ";

//     return 0;
// }



// 2. space - map ? O(N) + O(N) -> O(N) : O(N)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> majorityElement(vector<int>& nums){
        
    int n = nums.size();

    if(n == 0) return {};

    vector<int> ans;

    unordered_map<int, int> freqCount;

    for(auto i: nums) freqCount[i]++;

    for(auto ele: freqCount)
        if(ele.second > n/3)
            ans.push_back(ele.first);

    return ans;
}

int main(){

    vector<int> nums = {1,2};

    vector<int> ans = majorityElement(nums);
    cout<<"Majority Elements = ";

    for(auto i: ans) cout<<i<<" ";

    return 0;
}



// // 3. optimal - Extended Boyer Moore’s Voting Algorithm ? O(N) : O(1)
