#include<iostream>
#include<unordered_map>
using namespace std;

int strStr(string haystack, string needle) 
{    
    int n = haystack.size();
    int m = needle.size();
    
    for(int i=0; i<n; i++)
    {
        int j = 0;
        while(j < m)
        {    
            if(haystack[i+j] != needle[j]) 
                break;
            j++;
        }
        
        if(j == m) return i;
    }
    
    return -1;
}

int main()
{
    string haystack = "sadbutsad", needle = "sad";

    cout<<strStr(heystack, needle);
	
	return 0;
}