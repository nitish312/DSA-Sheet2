#include<iostream>
#include<vector>
using namespace std;

// 1.
// void helper(int i, int j, int m, int n, vector<vector<int>>& visited, int& ans)
// {
//     if(i == m-1 && j == n-1)
//     {
//         ans++;
//         return;
//     }
//     // bottom
//     if(i+1 < m && !visited[i+1][j])
//     {    
//         visited[i+1][j] = 1;
//         helper(i+1, j, m, n, visited, ans);
//         visited[i+1][j] = 0;
//     }
    
//     // right
//     if(j+1 < n && !visited[i][j+1])
//     {    
//         visited[i][j+1] = 1;
//         helper(i, j+1, m, n, visited, ans);
//         visited[i][j+1] = 0;
//     }
// }

int helper(int i, int j, int m, int n)
{
	if(i == m-1 && j == n-1) return 1;

	if(i >= m || j >= n) return 0;

	return helper(i+1, j, m, n) + helper(i, j+1, m, n);
}

int uniquePaths(int m, int n) 
{
	int i = 0, j = 0;
    return helper(i, j, m, n);
}

int main(){

    int m = 3, n = 7;

    int paths = uniquePaths(m, n);

    cout<<"Total no. of possible unique paths = "<<paths<<endl;

    return 0;
}