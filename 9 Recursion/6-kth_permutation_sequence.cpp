#include<bits/stdc++.h>
#include<vector>
using namespace std;

void permutations(int ind, string& s, vector<string>& ans){
        
    if(ind == s.size()){
        
        ans.push_back(s);
        return;
    }
    
    for(int i=ind; i<s.size(); i++){
        
        swap(s[i], s[ind]);
        
        permutations(ind + 1, s, ans);
        
        swap(s[i], s[ind]);
    }
}

// 1. brute ? O(N! * N) O (N! log N!) : O(N)
string getPermutation(int n, int k) {
    
    string s;
    
    for(int i=1; i<=n; i++) s.push_back(i + '0');
    
    vector<string> ans;
    
    permutations(0, s, ans);
    
    sort(ans.begin(), ans.end());
    
    int i = 0;
    for(auto str: ans){
        
        if(i == k - 1) return str;
        i++;
    }
    
    return "";
}



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