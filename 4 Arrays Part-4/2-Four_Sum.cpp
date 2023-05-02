// 1. brute ? O(N^4) : O(1)
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
	vector<vector<int>> mainVec;

	int n = nums.size();

	for(int i=0; i<n-3; i++){

		for(int j=i+1; j<n-2; j++){

			for(int k=j+1; k<n-1; k++){

				for(int l=k+1; l<n; l++){

					if(nums[l] + nums[k] + nums[j] + nums[i] == target){

						vector<int> temp;

						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[k]);
						temp.push_back(nums[l]);

						mainVec.push_back(temp);
					}
				}
			}
		}
	}

	return mainVec;
}

int main(){

	vector<int> nums = {1,0,-1,0,-2,2};
	int target = 0;

	vector<vector<int>> ans = fourSum(nums, target);
	
	int n = ans.size();
	int m = ans[0].size();
	for(int i=0; i<n; i++){
		cout<<"[";
		for(int j=0; j<m; j++){

			cout<<ans[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}

	return 0;
}



// 2. optimal ? O(N*log(N)) + O(N^3) -> O(N^3) log(N) : O(1)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
	sort(nums.begin(), nums.end());

    vector<vector<int>> mainVec;

    int n = nums.size();

    for(int i=0; i<n-3; i++){

        if(i > 0 && nums[i] == nums[i - 1]) continue;

        for(int j=i+1; j<n-2; j++){

            if(j > i+1 && nums[j] == nums[j - 1]) continue;
            
            int fixSum = target - (nums[i] + nums[j]);
            int start = j + 1, end = n - 1;
            while(start < end){

                if(nums[start] + nums[end] == fixSum){

                    vector<int> oneAns = {nums[i], nums[j], nums[start], nums[end]};

                    mainVec.push_back(oneAns);

                    while(start < end && nums[start] == nums[start + 1]) start++;
                    while(start < end && nums[end] == nums[end - 1]) end--;
                    
                    start++;
                    end--;
                }
                else if(nums[start] + nums[end] < fixSum) start++;
                else end--;
            }
        }
    }
      
    return mainVec;
}

int main(){

	vector<int> nums = {1,0,-1,0,-2,2};
	int target = 0;

	vector<vector<int>> ans = fourSum(nums, target);
	
	int n = ans.size();
	int m = ans[0].size();
	for(int i=0; i<n; i++){
		cout<<"[";
		for(int j=0; j<m; j++){

			cout<<ans[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}

	return 0;
}