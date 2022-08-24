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

void rotateMatrix(vector<vector<int>>& matrix){

	int n = matrix.size();
  vector < vector < int >> rotated(n, vector < int > (n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rotated[j][n - i - 1] = matrix[i][j];
    }
  }
  // return rotated;
  printMatrix(rotated);
}

int main(){

	vector<vector<int>> matrix = { {1,2,3}, 
								   {4,5,6},
								   {7,8,9} };

	printMatrix(matrix);

	rotateMatrix(matrix);

	// printMatrix(matrix);

	return 0;
}