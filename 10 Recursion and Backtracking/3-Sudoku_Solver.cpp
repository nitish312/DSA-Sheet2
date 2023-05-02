#include<iostream>
#include<vector>
using namespace std;

void printVecOfVec(vector<vector<char>> ans){

    for(auto i: ans){
        cout<<"[ ";
        for(auto j: i){

            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }
}

// 1. simple ? O(9^m) -> no. of empty places : O(1) -> O(81)-> O(N^2)
bool isSafe(vector<vector<char>>& board, int row, int col, char val){
        
    for(int i=0; i<9; i++){

        // checking in same row
        if(board[row][i] == val) return false;

        // checking in same col
        if(board[i][col] == val) return false;

        // checking in curr 3*3 matrix
        if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == val) 
            return false;
    }
    
    return true;
}

bool solve(vector<vector<char>>& board){
    
    int n = board.size();
    
    for(int i=0; i<n; i++){
        
        for(int j=0; j<n; j++){
         
            if(board[i][j] == '.'){
            
                for(char val='1'; val<='9'; val++){
                    
                    if(isSafe(board, i, j, val)){
                        
                        board[i][j] = val;

                        if(solve(board)) return true;
                        else board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }
  
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    
    solve(board);
}

int main(){

    vector<vector<char>> board = 
                                    {  
                                    {'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}   };

    printVecOfVec(board);

    solveSudoku(board);

    cout<<endl<<endl;

    printVecOfVec(board);

    return 0;
}