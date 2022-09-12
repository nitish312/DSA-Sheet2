#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1. brute ? O(N^3 logN) : O(N)
vector<vector<int>> threeSum(vector<int>& nums){
     
    sort(nums.begin(), nums.end());

    int n = nums.size();

    set<vector<int>> st;

    for(int i=0; i<n-2; i++){

        for(int j=i+1; j<n-1; ++j){ 

            for(int k=n-1; k>j; k--){

                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0) st.insert({nums[i], nums[j], nums[k]});
                else if(sum > 0) continue;
                else break;
            }
        }
    }

    vector<vector<int>> ans;
    for(auto i: st) ans.push_back(i);

    return ans;
}



// 2. optimal ? O(N^2) : O(3K) -> k is no. of triplets
vector<vector<int>> threeSum(vector<int>& nums) {
     
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> ans;

    for(int i=0; i<n; i++){
        
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int left = i+1, right = n-1;
        while(left < right){
            
            int sum = nums[i] + nums[left] + nums[right];
            
            if(sum < 0) left++;
            else if(sum > 0) right--;
            else{
                
                ans.push_back({nums[i], nums[left], nums[right]});
                int last_left = nums[left], last_right = nums[right];
                
                while(left < right && nums[left] == last_left) left++;
                while(left < right && nums[right] == last_right) right--;
            }
	    }
    }
    
    return ans;
}

void printVecOfVec(vector<vector<int>> ans){

	int n = ans.size();
	int m = ans[0].size();

	for(int i=0; i<n; i++){

		for(int j=0; j<m; j++){

			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){

	vector<int> nums = {-1,0,1,2,-1,-4};

	vector<vector<int>> ans = threeSum(nums);

	printVecOfVec(ans);

	return 0;
}