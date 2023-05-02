#include<iostream>
#include<vector>
using namespace std;

// 1. recursive ? O(2^(m+n)) exponential : O(m+n)
int helper(int i, int j, int m, int n)
{
    if(i == m-1 && j == n-1) return 1; // reached the destination
    
    if(i >= m || j >= n) return 0; // reached out of bounds
    
    return helper(i+1, j, m, n) + helper(i, j+1, m, n);
}

int uniquePaths(int m, int n) 
{
    int i = 0, j = 0;
    return helper(i, j, m, n);
}



// 2. DP-memoization ? O(n*m) : O(n*m) for dp & recursive call stack
int helper(int i, int j, int m, int n, vector<vector<int>>& dp)
{
    if(i == m-1 && j == n-1) return 1;
    
    if(i >= m || j >= n) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    else return dp[i][j] = helper(i+1, j, m, n, dp) + 
                           helper(i, j+1, m, n, dp);
}



// 3. DP-tabulation ? O(m*n) : O(m*n)
int uniquePaths(int m, int n) 
{
    vector<vector<int>> dp(m, vector<int>(n, 1));
    
    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];                
        }
    }
    
    return dp[m-1][n-1];
}

int uniquePaths(int m, int n) 
{
    int i = 0, j = 0;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(i, j, m, n, dp);
}

int uniquePaths(int m, int n) {
        
    vector<vector<int>> dp(m, vector<int>(n, 1));
    
    for(int i=1; i<m; i++){
        
        for(int j=1; j<n; j++){
            
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    
    return dp[m-1][n-1];
}

int main(){

    int m = 3, n = 7;

    int paths = uniquePaths(m, n);
    cout<<"For m = "<<m<<" and n = "<<n<<", "<<endl;
    cout<<"Total no. of paths will be "<<paths<<endl;

    return 0;
}



// 3. Combinatorics Solution ? O(N) or O(M) : O(1)