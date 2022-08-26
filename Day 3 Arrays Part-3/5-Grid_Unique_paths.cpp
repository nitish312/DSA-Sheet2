// // 1. Recursive ? exponential : recursive stack space exponential
// #include<iostream>
// #include<vector>
// using namespace std;

// int countPaths(int i, int j, int m, int n){

//     if(i == m-1 && j == n-1) return 1;

//     if(i > m-1 || j > n-1) return 0;

//     return countPaths(i+1, j, m, n) + 
//            countPaths(i, j+1, m, n);
// }

// int uniquePaths(int m, int n) {
        
//     return countPaths(0, 0, m, n);
// }

// int main(){

//     int m = 3, n = 7;

//     int paths = uniquePaths(m, n);
//     cout<<"For m = "<<m<<" and n = "<<n<<", "<<endl;
//     cout<<"Total no. of paths will be "<<paths<<endl;

//     return 0;
// }



// 2. DP ? O(N*M) : O(N*M)
#include<iostream>
#include<vector>
using namespace std;

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