#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) 
{
    unordered_set<string> st;
    for(auto i: wordDict) st.insert(i);
    vector<int> dp(301, -1); 
	int n = s.size();
	for(int i=n-1; i>=0; i--)
	{
		string temp;
		for(int j=i; j<n; j++)
		{
			temp += s[j];
			if(st.find(temp) != st.end())
			{
				dp[i] = dp[j+1];
			}
		}
		dp[i] = 0;
	}
	return dp[0];
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