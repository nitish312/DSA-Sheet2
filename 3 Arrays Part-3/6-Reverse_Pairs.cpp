// 1. brute - not working on LC 
// ? O(N^2) : O(1)
#include<iostream>
#include<vector>
using namespace std;

int reversePairs(vector<int>& nums){
        
    int n = nums.size();

    if(n == 0) return 0;

    int count = 0;

    for(int i=0; i<n; i++){

        for(int j=i+1; j<n; j++){

            if(nums[i] > 2 * nums[j]){

                count++;
            }
        }
    }
        
    return count;
}

int main(){

    vector<int> nums = {1,3,2,3,1};

    int ans = reversePairs(nums);

    cout<<"Total no. of reversed pairs = "<<reversePairs(nums)<<endl;

    return 0;
}


// 2. merged sort ? O(N*log(N)) + O(N) : O(N)