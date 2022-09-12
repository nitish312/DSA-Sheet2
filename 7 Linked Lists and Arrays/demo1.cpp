#include<iostream>
#include<vector>
#include<set>
using namespace std;

void printVec(vector<int> nums){

    for(auto i: nums) cout<<i<<" ";
    cout<<endl;
}

// 1. brute ? O(N) : O(1)
int findMaxConsecutiveOnes(vector<int>& nums){
        
    int n = nums.size();
    
    int maxSequence = 0, currSequence = 0;
    for(int i=0; i<n; i++){
        
        if(nums[i] == 1) currSequence++;
        else currSequence = 0;    

        maxSequence = max(maxSequence, currSequence);        
    }
    
    return maxSequence;
}

int main(){

	vector<int> nums = {1,1,0,1,1,1};

    printVec(nums);

	cout<<findMaxConsecutiveOnes(nums);	

	return 0;
}