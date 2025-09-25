class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int totalRows = triangle.size();
        if(totalRows == 1) return triangle[0][0];
        for(int i = totalRows - 2; i>=0; i--) {
            int totalCols = triangle[i].size();
            for(int j = 0; j<totalCols; j++) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};