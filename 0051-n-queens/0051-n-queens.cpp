bool isCellSafe(int x, int y, vector<string>& board, unordered_set<int>& rows, unordered_set<int>& cols) {
    int n = board.size();
    int i = x;
    int j = y;
    while(i >= 0 && j >= 0) {
        if(board[j--][i--] == 'Q') return false;
    }
    i = x;
    j = y;
    while(i >= 0 && j < n) {
        if(board[j++][i--] == 'Q') return false;
    }
    return ((rows.find(y) == rows.end()) && (cols.find(x) == cols.end()));
}
void nQueens(int col, vector<string>& board, vector<vector<string>>& ans, unordered_set<int>& rows, unordered_set<int>& cols) {
    int n = board.size();
    for(int row = 0; row<n; row++) {
        if(isCellSafe(col, row, board, rows, cols)) {
            board[row][col] = 'Q';
            if(col == n-1) {
                ans.push_back(board);
                board[row][col] = '.';
                return;
            }
            rows.insert(row);
            cols.insert(col);
            nQueens(col+1, board, ans, rows, cols);
            board[row][col] = '.';
            rows.erase(row);
            cols.erase(col);
        }
    }
    return;
}
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string row(n, '.');
        vector<string> board(n, row);
        vector<vector<string>> ans;
        unordered_set<int> rows;
        unordered_set<int> cols;
        nQueens(0, board, ans, rows, cols);
        return ans;
    }
};