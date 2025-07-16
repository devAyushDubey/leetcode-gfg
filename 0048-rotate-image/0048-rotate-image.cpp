class Solution {
public:
    void transpose(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int i = 0;
        while(i<n) {
            int j = i;
            while(j<n) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
                j++;
            }
            i++;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for(int i=0;i<matrix.size();i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};