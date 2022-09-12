#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 1. using isSafe() ? O(N! * N) we have N choices in the first row, N-1 in the second row, N-2 in the next and so on.. : O(N^2) Required for board
bool isSafe(vector<string> &board, int row, int col){
        
    int duprow = row;
    int dupcol = col;

    while(row >= 0 && col >= 0){

        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;
    while(col >= 0){
        
        if (board[row][col] == 'Q') return false;  
        col--;
    }

    row = duprow;
    col = dupcol;
    while(row < board.size() && col >= 0){
        
        if(board[row][col] == 'Q') return false;          
        row++;
        col--;
    }

    return true;
}

void nQueen(vector<string> &board, int col, vector<vector<string>>& ans){
    
    if(col == board.size()){
        ans.push_back(board);
        return;
    }
    
    for(int row=0; row<board.size(); row++){
        
        if(isSafe(board, row, col)){
            
            board[row][col] = 'Q';
            nQueen(board, col+1, ans);
            board[row][col] = 'x';
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    
    vector<vector<string>> ans;
    
    vector<string> board(n, string(n, 'x'));
    
    nQueen(board, 0, ans);
    
    return ans;
}



// 2. HashMap ? O(N!) : O(N^2)
void nQueen(int col, vector<string>& board, vector<vector<string>>& ans, unordered_map<int, bool>& leftrow, unordered_map<int, bool>& upperDiagonal, unordered_map<int, bool>& lowerDiagonal, int n){

    if(col == n){

        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++){

        if(!leftrow[row] && !lowerDiagonal[row + col] && !upperDiagonal[n - 1 + col - row]){

            board[row][col] = 'Q';
            leftrow[row] = true;
            lowerDiagonal[row + col] = true;
            upperDiagonal[n - 1 + col - row] = true;

            nQueen(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);

            board[row][col] = '.';
            leftrow[row] = false;
            lowerDiagonal[row + col] = false;
            upperDiagonal[n - 1 + col - row] = false;
        }
    }
}

vector<vector<string>> solveNQueens(int n){

    vector<vector<string>> ans;

    vector<string> board(n, string(n, '.'));

    unordered_map<int, bool> leftrow(n), upperDiagonal(2*n - 1), lowerDiagonal(2*n - 1);

    nQueen(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);

    return ans;
}

int main(){

    int n = 4;

    vector<vector<string>> ans = solveNQueens(n);

    for(auto i: ans){

        for(auto j: i){

            cout<<j<<endl;
        }
        cout<<endl;
    }

    return 0;
}