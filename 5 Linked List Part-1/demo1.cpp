#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& vec, vector<vector<int>>& all)
{
    int n = vec.size();
    for(int i=0; i<n; i++)
    {
        vector<int> subArr;
        for(int j=i; j<n; j++)
        {
            subArr.push_back(vec[j]);
            all.push_back(subArr);
        }
    }
}

bool sumZero(vector<int> vec)
{
    int sum = accumulate(vec.begin(), vec.end(), 0);
    return (sum == 0);
}

int main()
{
    vector<int> vec = {6,-1,-3,4,-2,2,4,6,-12,-7};

    vector<vector<int>> all;
    solve(vec, all);

    int ans = 0;

    for(auto i: all)
        if(sumZero(i)) 
        {
            ans++;
            for(auto j: i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }

    cout<<"Count of subarray with sum 0 = "<<ans<<endl;

    int count = 0;
    for(int i=0; i<vec.size(); i++)
    {
        int currSum = 0;
        for(int j=i; j<vec.size(); j++)
        {
            currSum += vec[j];
            if(currSum == 0) count++;
        }
    }

    cout<<"Count of subarray with sum 0 = "<<count<<endl;

    return 0;
}