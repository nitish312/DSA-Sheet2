// optimal ? O(N^2) : O(1) in-place
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printMatrix(vector<vector<int>> matrix){

	int n = matrix.size();
	int m = matrix[0].size();

	for(int i=0; i<n; i++){

		for(int j=0; j<m; j++){

			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void swapThem(vector<vector<int>>& matrix, int a, int b){

	int temp = matrix[a][b];
	matrix[a][b] = matrix[b][a];
	matrix[b][a] = temp;
}

void rotateMatrix(vector<vector<int>>& matrix){

	reverse(matrix.begin(), matrix.end()); // figure out how to reverse vec<vec>

	printMatrix(matrix);

	int n = matrix.size();
	int m = matrix[0].size();
	for(int i=0; i<n; i++){

		for(int j=i+1; j<m; j++){

			swapThem(matrix, i, j); // swap(matrix[i][j], matrix[j][i])
		}
	}
}

int main(){

	vector<vector<int>> matrix = { {1,2,3}, 
								   {4,5,6},
								   {7,8,9} };

	printMatrix(matrix);

	rotateMatrix(matrix);

	printMatrix(matrix);

	return 0;
}