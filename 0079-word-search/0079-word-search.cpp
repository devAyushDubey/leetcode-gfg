int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
bool existRecur(int x, int y, vector<vector<char>>& board, string& word, int i) {
    int m = board.size();
    int n = board[0].size();
    int len = word.length();
    if(i == len) return true;
    if(x >= n || y >= m || x < 0 || y < 0 || board[y][x] == '$' || board[y][x] != word[i]) {
        return false;
    }
    char letter = board[y][x];
    board[y][x] = '$';
    for(int ind = 0; ind<4; ind++) {
        if(existRecur(x + dirX[ind],y + dirY[ind], board, word, i+1)) return true;
    }
    board[y][x] = letter;
    return false;
}
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int y = 0; y<m; y++) {
            for(int x = 0; x<n; x++) {
                if(board[y][x] != word[0]) continue;
                if(existRecur(x,y,board,word,0)) return true;
            }
        }
        return false;    
    }
};