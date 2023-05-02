#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while(start < end)
    {
        if(s[start++] != s[end--]) return false;
    }
    return true;
}

void helper(int i, string s, vector<string>& part, vector<vector<string>>& ans)
{
    if(i == s.size()){

        ans.push_back(part);
        return;
    }

    for(int j=i; j<s.size(); j++){

        if(isPalindrome(s, i, j)){

            part.push_back(s.substr(i, j-i+1));

            helper(j + 1, s, part, ans);

            part.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> part;
    int i = 0;
    helper(i, s, part, ans);
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