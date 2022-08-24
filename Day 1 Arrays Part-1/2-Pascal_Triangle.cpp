// brute ? O(N*M) : O(N^2)
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> mainVec;
        
        for(int i=0; i<numRows; i++){
            
            vector<int> vec(i+1, 1); 
            
            for(int j=1; j<i; j++){ 
                
                vec[j] = mainVec[i-1][j-1] + mainVec[i-1][j]; 
            }
            
            mainVec.push_back(vec);
        }
        
        return mainVec;
    }

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

int main(){

	int n = 5;

	vector<vector<int>> ans = generate(n);
	
	printMatrix(ans);

	return 0;
}



// optimal ? O(N*M) : O(N)
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
        
    vector<vector<int>> vec;
        
    for(int i=0; i<numRows; i++){
            
		vec[i].resize(i+1); 
		vec[i][0] = vec[i][i] = 1;

		for(int j=1; j<i; j++){ 
		                
			vec[j] = vec[i-1][j-1] + vec[i-1][j]; 
		}
	}
        
	return vec;
}

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

int main(){

	int n = 5;

	vector<vector<int>> ans = generate(n);
	
	printMatrix(ans);

	return 0;
}