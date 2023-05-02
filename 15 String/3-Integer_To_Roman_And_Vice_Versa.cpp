#include<iostream>
#include<unordered_map>
using namespace std;

// HashMap ? O(N) : O(1) -> only 7 key-values (constant)
int romanToInteger(string s)
{
    // unordered_map<char, int> mp;
    // mp['I'] = 1;
    // mp['V'] = 5;
    // mp['X'] = 10;
    // mp['L'] = 50;
    // mp['C'] = 100;
    // mp['D'] = 500;
    // mp['M'] = 1000;

    unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, 
                  {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int n = s.size();
    int ans = mp[s[n-1]];
    for(int i=n-2; i>=0; i--)
    {
        if(mp[s[i]] < mp[s[i+1]]) ans -= mp[s[i]];
        else ans += mp[s[i]];
    }

    return ans;
}

// Arrays ? O(noOfCharsInAnsStr) : O(1)
string integerToRoman(int num) 
{
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string code[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X",
                   "IX", "V", "IV", "I"};
    string ans = "";
    for(int i=0; i<13; i++)
    {
        while(num >= val[i])
        {
            ans += code[i];
            num -= val[i];
        }
    }
    
    return ans;
}

int main()
{
    string s = "MCMXCIV";
    // string s = "III";
    // string s = "LVIII";
    cout<<s<<endl;
    int ans = romanToInteger(s);
    cout<<ans<<endl;

    string str = integerToRoman(ans);
    cout<<str<<endl;
    
    return 0;
}