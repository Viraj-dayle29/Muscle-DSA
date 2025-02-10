#include<iostream>
#include<vector>

bool isValid(std::vector<std::vector<char>> &board,int row,int col,char digit){
    // row - col check - cube check
    for (int i = 0; i < 9; i++)
    {
        if(board[i][col] == digit) return false;
        if(board[row][i] == digit) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == digit) return false;
    }
    return true;
}

bool solve(std::vector<std::vector<char>> &board,int row,int col){
    if(row == 9) return true;
    if(col == 9) return solve(board,row + 1,0);
    if(board[row][col] != '.') return solve(board,row,col + 1);

    for (char i = '1'; i <= '9'; i++)
    {
        if(isValid(board,row,col,i)){
            board[row][col] = i;
            if(solve(board,row,col)) return true;
            board[row][col] = '.';
        }
    }
    return false;
}

void solveSudoku(std::vector<std::vector<char>> &board) {
    solve(board,0,0);
}

int main() {
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);

    for (const std::vector<char> &row : board) {
        for (char num : row) {
            std::cout<<num<< " ";
        }
        std::cout<<std::endl;
    }

    return 0;
}
