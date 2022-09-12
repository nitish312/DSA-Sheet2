#include<bits/stdc++.h>
using namespace std;

// 1. 4 dir recursive calls ? O(4*(M*N)) -> for each cell we try 4 diff. directions : O(M*N) -> visited arr + Maximum Depth of the recursion tree(auxiliary space)
void helper(int i, int j, vector<vector<int>> &maze, int n, vector<vector<int>>& visited, string path, vector<string>& ans)
{
	if(i == n-1 && j == n-1) // base case - reached the destination
	{
		ans.push_back(path);
		return;
	}

	// move down-left-right-up
	// down
	if(i+1 < n && !visited[i+1][j] && maze[i+1][j] == 1)
	{
		visited[i+1][j] = 1;
		path += "D";
		helper(i+1, j, maze, n, visited, path, ans);
		path.pop_back();
		visited[i+1][j] = 0;
	}

	// left
	if(j-1 >= 0 && !visited[i][j-1] && maze[i][j-1] == 1)
	{
		visited[i][j-1] = 1;
		path += "L";
		helper(i, j-1, maze, n, visited, path, ans);
		path.pop_back();
		visited[i][j-1] = 0;
	}

	// right
	if(j+1 < n && !visited[i][j+1] && maze[i][j+1] == 1)
	{
		visited[i][j+1] = 1;
		path += "R";
		helper(i, j+1, maze, n, visited, path, ans);
		path.pop_back();
		visited[i][j+1] = 0;
	}

	// up
	if(i-1 >= 0 && !visited[i-1][j] && maze[i-1][j] == 1)
	{
		visited[i-1][j] = 1;
		path += "U";
		helper(i-1, j, maze, n, visited, path, ans);
		path.pop_back();
		visited[i-1][j] = 0;
	}
}

vector<string> findPath(vector<vector<int>> &maze, int n) 
{
	vector<string> ans;	
	
	vector<vector<int>> visited(n, vector<int>(n, 0));
 	
 	if(maze[0][0] == 1) 
 	{
 		visited[0][0] = 1;
 		helper(0, 0, maze, n, visited, "", ans);
 	}	

	return ans;
}



// 2. single for loop ? same : same
void helper(int i, int j, vector<vector<int>> &maze, int n, vector<vector<int>>& visited, 
			string path, vector<string>& ans, vector<int> di, vector<int> dj)
{
	if(i == n-1 && j == n-1) // base case - reached the destination
	{
		ans.push_back(path);
		return;
	}

	string str = "DLRU";

	for(int ind=0; ind<4; ind++)
	{
		int next_i = i + di[ind];
		int next_j = j + dj[ind];

		if(next_i >= 0 && next_i < n && next_j >= 0 && next_j < n && 
		   !visited[next_i][next_j] && maze[next_i][next_j] == 1)
		{
			visited[next_i][next_j] = 1;
			path.push_back(str[ind]);
			helper(next_i, next_j, maze, n, visited, path, ans, di, dj);
			path.pop_back();
			visited[next_i][next_j] = 0;
		}
	}
}


vector<string> findPath(vector<vector<int>> &maze, int n) 
{
	vector<string> ans;	
	
	vector<vector<int>> visited(n, vector<int>(n, 0));
	// movements - DLRU
	vector<int> di = {1, 0, 0, -1};
	vector<int> dj = {0, -1, 1, 0};
 	
 	if(maze[0][0] == 1) 
 	{
 		visited[0][0] = 1;
 		helper(0, 0, maze, n, visited, "", ans, di, dj);
 	}	

	return ans;
}

int main()
{
	// vector<vector<int>> maze = {{1,0,0,0},
	// 							{1,1,0,1},
	// 							{1,1,0,0},
	// 							{0,1,1,1}};

    vector<vector<int>> maze = {{1,1},
								{1,1}};

	int n = maze.size();

	vector<string> path = findPath(maze, n);

	for(auto str: path) cout<<str<<endl;

	return 0;
}




// // coding ninjas
// void helper(int i, int j, vector<vector<int>>& maze, int n, vector<vector<int>>& visited, vector<vector<int>>& ans, vector<int>& di, vector<int>& dj)
// {
//     if(i == n-1 && j == n-1)
//     {
//         vector<int> path;
//         for(int x=0; x<n; x++)
//         {
//             for(int y=0; y<n; y++)
//             {
//                 path.push_back(visited[x][y]);
//             }
//         }
//         ans.push_back(path);
//         return;
//     }
    
//     for(int ind=0; ind<4; ind++)
//     {
//         int nexti = i + di[ind];
//         int nextj = j + dj[ind];
        
//         if(nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && !visited[nexti][nextj] && maze[nexti][nextj] == 1)
//         {
//             visited[nexti][nextj] = 1;
//             helper(nexti, nextj, maze, n, visited, ans, di, dj);
//             visited[nexti][nextj] = 0;
//         }
//     }
// }

// vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n)
// {
//     vector<vector<int>> ans;
//     vector<vector<int>> visited(n, vector<int>(n, 0));
//     int i = 0, j = 0; // LDRU
//     vector<int> di = {1, 0, 0, -1};
//     vector<int> dj = {0, -1, 1, 0};
//     if(maze[0][0] == 1)
//     {
//         visited[0][0] = 1;
//         helper(i, j, maze, n, visited, ans, di, dj);
//     }
//     return ans;
// }