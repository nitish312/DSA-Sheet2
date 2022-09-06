#include<bits/stdc++.h>
#include<vector>
using namespace std;

// 2. optimal ? O(N*N) -> O(N^2) : O(N) 
string getPermutation(int n, int k) {
        
    int fact = 1;
    vector<int> nums;
    for(int i=1; i<n; i++){
        
        fact *= i;
        nums.push_back(i);
    }
    nums.push_back(n);
    
    string ans = "";
    k = k - 1;
    
    while(true){
        
        ans += to_string(nums[k / fact]);
        
        nums.erase(nums.begin() + k / fact);
        
        if(nums.size() == 0) break;
        
        k %= fact;
        
        fact = fact / nums.size();
    }
    
    return ans;
}

int main(){

    int n = 3, k = 3;

    string ans = getPermutation(n, k);

    cout<<ans;

    return 0;
}