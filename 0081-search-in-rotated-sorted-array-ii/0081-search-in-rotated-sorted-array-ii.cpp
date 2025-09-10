bool binSearch(int low, int high, vector<int>& nums, int target) {
    if(low >= high) {
        if(high < 0) return nums[low] == target;
        return nums[high] == target;
    }
    int mid = (low+high)/2;
    if(nums[mid] > target) {
        bool rightSide = false;
        if(nums[high] <= nums[mid]) {
            rightSide = binSearch(mid+1, high, nums, target);
        }
        bool leftSide = binSearch(low, mid-1, nums, target);
        return leftSide || rightSide;
    }
    else if(nums[mid] < target) {
        bool leftSide = false;
        if(nums[low] >= nums[mid]) {
            leftSide = binSearch(low, mid-1, nums, target);
        }
        bool rightSide = binSearch(mid+1, high, nums, target);
        return leftSide || rightSide;
    }
    else {
        return true;
    }
}
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        return binSearch(0, n-1, nums, target);
    }
};