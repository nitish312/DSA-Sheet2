#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPlaceCows(vector<int> &stalls, int k, int mid, int n) 
{    
    int placed = stalls[0], count = 1;
    
    for(int i=1; i<n; i++)
    {
        if(stalls[i] - placed >= mid)
        {
            count++;
            if(count == k) return true;
            placed = stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    
    int start = 1, end = stalls[n-1], mid, ans = 0;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(canPlaceCows(stalls, k, mid, n)) 
        {
            ans = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    return ans;
}

int main()
{
    vector<int> stalls = {4, 2, 1, 3, 6};
    int k = 2; // output = 5

    cout<<aggressiveCows(stalls, k); 

    return 0;
}