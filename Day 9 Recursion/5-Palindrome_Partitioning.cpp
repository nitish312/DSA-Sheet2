#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool isPalindrome(string s, int start, int end){
        
    while(start < end)
        if(s[start++] != s[end--]) 
            return false;
    
    return true;
}

void helper(int ind, string s, vector<string>& part, vector<vector<string>>& ans){
    
    if(ind == s.size()){
        
        ans.push_back(part);
        return;
    }
    
    for(int i=ind; i<s.size(); i++){
        
        if(isPalindrome(s, ind, i)){
            
            part.push_back(s.substr(ind, i - ind + 1));
            
            helper(i + 1, s, part, ans);
            
            part.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    
    vector<vector<string>> ans;
    vector<string> part;
    
    helper(0, s, part, ans);
    
    return ans;
}

int main(){

    string s = "aab";

    vector<vector<string>> ans =  partition(s);

    for(auto i: ans){
        
        cout<<"[";
        for(auto j: i){

            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}