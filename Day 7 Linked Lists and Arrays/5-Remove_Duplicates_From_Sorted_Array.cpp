#include<iostream>
#include<vector>
#include<set>
using namespace std;

void printVec(vector<int> nums){

    for(auto i: nums) cout<<i<<" ";
    cout<<endl;
}

// 1. hashSet ? O(N*logN) : O(N)
int removeDuplicates(vector<int>& nums){
        
    set<int> st;
    
    for(auto i: nums) st.insert(i); // O(logN) for 1 insert
    
    int n = st.size();
    
    int j = 0;
    for(auto i: st){
        
        nums[j++] = i;
    }

    printVec(nums);
    
    return n;
}



// 2. Two-pointer ? O(N) : O(1)
int removeDuplicates(vector<int>& nums){
        
    int n = nums.size();

    int start = 1;

    for(int i=1; i<n; i++){

        if(nums[i] != nums[i-1]){

            nums[start++] = nums[i];
        }
    }

    printVec(nums);

    return start;
}

int main(){

	vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    printVec(nums);

	cout<<removeDuplicates(nums);	

	return 0;
}