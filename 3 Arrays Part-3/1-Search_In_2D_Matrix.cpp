// 1. brute ? O(N*M) -> O(N^2) : O(1)
#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            if(matrix[i][j] == target)
                return true;

    return false;
}

int main(){

    vector<vector<int>> matrix = { {1,3,5,7},
                                   {10,11,16,20},
                                   {23,30,34,60} };

    int target = 3;

    if(searchMatrix(matrix, target)) cout<<target<<" is present in a matrix";
    else cout<<target<<" is not present";

    return 0;
}