int binary(int low, int high, vector<int>& nums) {
    if(low >= high) {
        return high < 0 ? low : high;
    }
    int mid = (low+high)/2;
    if(mid == 0) {
        if(nums[mid+1] < nums[mid]) return mid;
        else return binary(mid+1, high, nums);
    }
    else if((nums[mid-1] < nums[mid]) && (nums[mid+1] < nums[mid])) {
        return mid;
    }
    else if(nums[mid+1] > nums[mid]) {
        return binary(mid+1, high, nums);
    }
    else {
        return binary(low, mid-1, nums);
    }
}
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return binary(0, n-1, nums);
    }
};