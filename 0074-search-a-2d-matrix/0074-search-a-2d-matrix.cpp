int searchCols(int low, int high, vector<int>& nums, int target) {
    if(low >= high) {
        return high < 0 ? low : high;
    }
    int mid = (low+high)/2;
    if(nums[mid] < target) {
        return searchCols(mid+1, high, nums, target);
    }
    else if(nums[mid] > target) {
        return searchCols(low, mid-1, nums, target);
    }
    else {
        return mid;
    }
}
bool searchRows(int low, int high, vector<vector<int>>& matrix, int target) {
    if(low > high) {
        return false;
    }
    int mid = (low+high)/2;
    int n = matrix[mid].size();
    if (low == high && (target < matrix[mid][0] || target > matrix[mid][n-1])) {
        return false;
    }
    int index = searchCols(0, n-1, matrix[mid], target);
    if(matrix[mid][index] == target) {
        return true;
    }
    else if (matrix[mid][index] < target) {
        if(index + 1 != n) return false;
        return searchRows(mid+1, high, matrix, target);
    }
    else {
        if(index != 0) return false;
        return searchRows(low, mid-1, matrix, target);
    }
}
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        return searchRows(0, n-1, matrix, target);
    }
};