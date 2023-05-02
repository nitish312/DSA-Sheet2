#include<iostream>
#include<stack>
using namespace std;

// 1. stack ? O(N+N) : O(N) -> stk n ans string 
string reverseWords(string s)
{
	string ans = "";
	stack<string> stk;

	int n = s.size();
	for(int i=0; i<n; i++)
	{
		string word = "";
		if(s[i] == ' ') continue;

		while(i < n && s[i] != ' ')
		{
			word += s[i++];
		}
		stk.push(word);
	}

	while(!stk.empty())
	{
		ans += stk.top();
		stk.pop();
		if(!stk.empty()) ans += ' ';
	}

	return ans;
}



// 2. Two-pointer Sliding Window ? O(N) : O(N)
string reverseWords(string s)
{
	string ans = "";

	int n = s.size();
	for(int i=n-1; i>=0; i--)
	{
		if(s[i] == ' ') continue;

		int j = i;
		while(i >= 0 && s[i] != ' ') i--;

		if(ans.size() == 0)
			ans += s.substr(i+1, j-i);
		else 
			ans += " " + s.substr(i+1, j-i);
	}

	return ans;
}

int main()
{
	string s = "the sky is blue";
	// string s = "  hello world  ";
	// string s = "a good   example";

	string ans = reverseWords(s);
	cout<<ans;

	return 0;
}