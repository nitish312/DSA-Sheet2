// 1. brute ? O(N*M) + O(N*M) -> O(N*M) : O(N)
#include<iostream>
#include<vector>
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

void setZeroes(vector<vector<int>>& matrix){

	int rows = matrix.size();
	int cols = matrix[0].size();

	vector<pair<int, int>> setThem; 
	for(int i=0; i<rows; i++){

		for(int j=0; j<cols; j++){

			if(matrix[i][j] == 0){

				setThem.push_back(make_pair(i, j));
				// (0,0) , (0,3)
			}
		}
	}

	for(int i=0; i<rows; i++){

		for(int j=0; j<cols; j++){

			for(auto ele: setThem){

				matrix[ele.first][j] = 0;
				matrix[i][ele.second] = 0;
			}
		}
	}
}

int main(){

	vector<vector<int>> matrix;
	matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

	printMatrix(matrix);

	setZeroes(matrix);

	printMatrix(matrix);

	return 0;
}



// 2. optimal ? O(N*M) + O(N*M) -> O(2*(N*M)) : O(1)
#include<iostream>
#include<vector>
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

void setZeroes(vector<vector<int>>& matrix){

	int rows = matrix.size();
	int cols = matrix[0].size();
	int col0 = 1;

	for(int i=0; i<rows; i++){

		if(matrix[i][0] == 0) col0 = 0;
		for(int j=0; j<cols; j++){

			if(matrix[i][j] == 0){

				matrix[i][0] = matrix[0][i] = 0;
			}
		}
	}

	for(int i=rows-1; i>=0; i--){

		for(int j=cols-1; j>=1; j--){

			if(matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}

		if(col0 == 0) matrix[i][0] = 0;
	}
}

int main(){

	vector<vector<int>> matrix;
	matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

	printMatrix(matrix);

	setZeroes(matrix);

	printMatrix(matrix);

	return 0;
}