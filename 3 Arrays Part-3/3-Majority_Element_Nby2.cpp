// 1. brute ? O(N^2) : O(1)
#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums){
        
    int n = nums.size();

    int curr, count;
    for(int i=0; i<n; i++){

        curr = nums[i], count = 1;
        for(int j=i+1; j<n; j++){

            if(nums[j] == curr) count++;
        }

        if(count > n/2) return curr;
    }

    return -1;
}

int main(){

    vector<int> nums = {2,2,1,1,1,2,2};

    int ans = majorityElement(nums);
    cout<<"Majority Element = "<<ans<<endl;

    return 0;
}



// 2. space - map ? O(N) + O(N) -> O(N) : O(N)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int majorityElement(vector<int>& nums){
        
    int n = nums.size();
    unordered_map<int, int> freqCount;

    for(auto i: nums) freqCount[i]++;

    for(auto ele: freqCount)
        if(ele.second > n/2)
            return ele.first;

    return -1;
}

int main(){

    vector<int> nums = {2,2,1,1,1,2,2};

    int ans = majorityElement(nums);
    cout<<"Majority Element = "<<ans<<endl;

    return 0;
}



// 3. optimal - Moore’s Voting Algorithm ? O(N) : O(1)
#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums){
        
    int majority = -1, count = 0;

    for(int ele: nums){

        if(count == 0) majority = ele;

        if(ele == majority) count++; 
        else count--; 
    }

    return majority; 
}

int main(){

    vector<int> nums = {2,2,1,1,1,2,2};

    int ans = majorityElement(nums);
    cout<<"Majority Element = "<<ans<<endl;

    return 0;
}