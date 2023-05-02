#include<iostream>
using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
    string ans = "";
    sort(strs.begin(), strs.end());
    
    int n = strs.size();
    string smallStr = strs[0];
    string largeStr = strs[n-1];
    
    int smallStrSize = smallStr.size();
    
    for(int i=0; i<smallStr.size(); i++)
    {
        if(smallStr[i] != largeStr[i]) break;
        
        ans += smallStr[i];
    }
    
    return ans;
}

int main()
{
    
	
	return 0;
}