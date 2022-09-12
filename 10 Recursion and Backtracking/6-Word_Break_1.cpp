#include<bits/stdc++.h>
using namespace std;

// 1. brute - recursion (TLE) ? O(2^N)
int helper(int i, string s, unordered_set<string> st)
{ 
    if(i == s.size()) return 1;
    
    string temp;
    for(int j=i; j<s.size(); j++)
    {
        temp.push_back(s[j]);
        if(st.find(temp) != st.end())
        {
            if(helper(j+1, s, st)) return 1;
        }
    }
    return 0;
}

bool wordBreak(string s, vector<string>& wordDict) 
{
    unordered_set<string> st;
    for(auto i: wordDict) st.insert(i);
    int i = 0;
    return helper(i, s, st);
}



// 2. dp - top-down - memoization
int helper(int i, string s, unordered_set<string> st, vector<int>& dp)
{
    if(i == s.size()) return 1;
    
    string temp;
    if(dp[i] != -1) return dp[i];
    for(int j=i; j<s.size(); j++)
    {
        temp.push_back(s[j]);
        if(st.find(temp) != st.end())
        {
            if(helper(j+1, s, st, dp)) return dp[i] = 1;
        }
    }
    return dp[i] = 0;
}

bool wordBreak(string s, vector<string>& wordDict) 
{
    unordered_set<string> st;
    for(auto i: wordDict) st.insert(i);
    int i = 0;
    vector<int> dp(301, -1); // 300 given in constraints
    return helper(i, s, st, dp);
}

int main()
{
	string s = "leetcode";
	vector<string> wordDict = {"leet","code"};

	if(wordBreak(s, wordDict)) 
		cout<<"string can be segmented into a space-separated sequence of one or more dictionary words";
	else cout<<"Not possible";

	return 0;
}