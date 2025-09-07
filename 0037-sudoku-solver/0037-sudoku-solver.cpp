int getBlock(int i, int j) {
    if(i < 3) {
        return j<3 ? 0 : j<6 ? 1 : 2;
    }
    else if (i < 6) {
        return j<3 ? 3 : j<6 ? 4 : 5;
    }
    else {
        return j<3 ? 6 : j<6 ? 7 : 8;
    }
}
bool sudokuSolver(int i, int j, vector<vector<char>>& board, vector<vector<int>>& rows, vector<vector<int>>& cols, vector<vector<int>>& blocks) {
    if(j == 9) {
        if(i < 8) {
            return(sudokuSolver(i+1, 0, board, rows, cols, blocks));
        }
        return true;
    }
    if(board[i][j] != '.') {
        return sudokuSolver(i, j+1, board, rows, cols, blocks);
    }
    int block = getBlock(i,j);
    for(int k = 1; k<=9; k++) {
        if(!rows[i][k] && !cols[j][k] && !blocks[block][k]) {
            rows[i][k] = true;
            cols[j][k] = true;
            blocks[block][k] = true;
            board[i][j] = k + '0';
            if(sudokuSolver(i, j+1, board, rows, cols, blocks)) return true;
            board[i][j] = '.';
            rows[i][k] = false;
            cols[j][k] = false;
            blocks[block][k] = false;
        }
    }
    return false;
}
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(10, vector<int>(10, 0));
        vector<vector<int>> cols(10, vector<int>(10, 0));
        vector<vector<int>> blocks(10, vector<int>(10, 0));
        int term;
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] == '.') continue;
                term = board[i][j] - '0';
                rows[i][term] = true;
                cols[j][term] = true;
                blocks[getBlock(i,j)][term] = true;
            }
        }
        sudokuSolver(0,0,board,rows,cols,blocks);
    }
};