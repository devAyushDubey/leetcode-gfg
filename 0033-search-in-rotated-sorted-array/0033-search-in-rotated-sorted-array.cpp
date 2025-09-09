int binSearch(int low, int high, vector<int>& nums, int target) {
    if(low >= high) {
        return high < 0 ? low : high;
    }
    int mid = (low+high)/2;
    if(nums[mid] > target) {
        if(nums[high] < nums[mid]) {
            int rightSide = binSearch(mid+1, high, nums, target);
            if(nums[rightSide] == target) return rightSide;
        }
        return binSearch(low, mid-1, nums, target);
    }
    else if (nums[mid] < target) {
        if(nums[low] > nums[mid]) {
            int leftSide = binSearch(low, mid-1, nums, target);
            if(nums[leftSide] == target) return leftSide;
        }
        return binSearch(mid+1, high, nums, target);
    }
    else {
        return mid;
    }
}
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int result = binSearch(0, n-1, nums ,target);
        return nums[result] == target ? result : -1;
    }
};