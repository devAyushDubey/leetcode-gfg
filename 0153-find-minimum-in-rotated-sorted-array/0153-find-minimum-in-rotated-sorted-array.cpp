int binSearchMin(int low, int high, vector<int>& nums) {
    if(low >= high) {
        if(high < 0) return low;
        return high;
    }
    int mid = (low+high)/2;
    if(nums[mid] > nums[high]) {
        return binSearchMin(mid+1, high, nums);
    }
    else if(nums[mid] < nums[low]) {
        if(nums[mid-1] > nums[mid]) return mid;
        return binSearchMin(low, mid-1, nums);
    }
    else {
        return low;
    }
    
}
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int index =  binSearchMin(0, n-1, nums);
        return nums[index];
    }
};