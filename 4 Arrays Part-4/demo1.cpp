// 1. Sliding window + HashSet ? O(N) : O(N)
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s){

	int n = s.size();

	int ans = 0;

	int start = 0, end = 0;

	unordered_set<char> st;

	while(end < n){

		if(st.find(s[end]) == st.end()){ // if not found

			ans = max(ans, end - start + 1); // count length & insert into set & increment end
			st.insert(s[end]); 
			end++;
		}
		else{ // if found, remove it & increment start

			st.erase(s[start]);
			start++;
		}
	}

	return ans;
}

int main(){

	string s = "abcabcbb"; // 3 -> abc, bca, cab

	int ans = lengthOfLongestSubstring(s);
	cout<<ans;
	// return substring without having repeating chars 

	return 0;
}