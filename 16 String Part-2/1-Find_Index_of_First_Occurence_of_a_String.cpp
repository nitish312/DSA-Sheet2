#include<iostream>
using namespace std;

// 1. loops ? O(N*M) : O(1)
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
    // string haystack = "leetcode", needle = "leeto";

    // return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
    cout<<strStr(haystack, needle);
    
    return 0;
}