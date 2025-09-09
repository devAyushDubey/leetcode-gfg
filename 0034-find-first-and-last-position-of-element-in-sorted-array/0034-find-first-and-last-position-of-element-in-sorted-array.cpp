int findLowerBound(int low, int high, vector<int>& nums, int target) {
    if(low >= high) {
        return high < 0 ? low : high;
    }
    int mid = (low+high)/2;
    if(nums[mid] >= target) {
        int leftSide = findLowerBound(low, mid-1, nums, target);
        if(nums[leftSide] >= target) return leftSide;
        return mid;
    }
    else {
        return findLowerBound(mid+1, high, nums, target);
    }
}
int findUpperBound(int low, int high, vector<int>& nums, int target) {
    if(low >= high) {
        return high < 0 ? low : high;
    }
    int mid = (low+high)/2;
    if(nums[mid] <= target) {
        int rightSide = findUpperBound(mid+1, high, nums, target);
        if(nums[rightSide] <= target) return rightSide;
        return mid;
    }
    else {
        return findUpperBound(low, mid-1, nums, target);
    }
}
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1,-1};
        int lower = findLowerBound(0, n-1, nums, target);
        int higher = findUpperBound(0, n-1, nums, target);
        if(nums[lower] != target || nums[higher] != target) return {-1,-1};
        return {lower, higher};
    }
};