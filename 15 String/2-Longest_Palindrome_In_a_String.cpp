#include<iostream>
using namespace std;

// 1. brute ? O(N^3) : O(N^2)
// -> find all substring n check each for palindrome n get longest

// 2. DP ? O(N^2) : O(N^2) 
string longestPalindrome(string s) 
{
    string ans;
    int maxLength = 0;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // filling dp matrix diagonally
    for(int diff=0; diff<n; diff++)
    {
        for(int i = 0, j = i + diff; j < n; i++, j++)
        {
            if(i == j)
            {
                dp[i][j] = 1;
            }
            else if(diff == 1)
            {
                // dp[i][j] = (s[i] == s[j]) ? 2 : 0;
                if(s[i] == s[j]) 
                    dp[i][j] = 2;
            }
            else
            {
                if(s[i] == s[j] && dp[i+1][j-1])
                    dp[i][j] = dp[i+1][j-1] + 2;
            }
            
            if(dp[i][j])
            {
                if(dp[i][j] > maxLength)
                {
                    maxLength = j - i + 1;
                    ans = s.substr(i, maxLength);
                }
            }
        }
    }
    
    return ans;
}

int main()
{
	string s = "babad";
	// string s = "cbbd";

	cout<<longestPalindrome(s);
	
	return 0;
}