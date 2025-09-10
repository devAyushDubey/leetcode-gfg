int binary(int low, int high, vector<int>& nums) {
    if(low >= high) {
        return high < 0 ? low : high;
    }
    int mid = (low+high)/2;
    if(nums[mid] == nums[mid+1]) {
        return mid%2 == 1 ? binary(low, mid-1, nums) : binary(mid+1, high, nums);
    }
    else if(mid == 0) {
        return mid;
    }
    else if(nums[mid] == nums[mid-1]) {
        return mid%2 == 1 ? binary(mid+1, high, nums) : binary(low, mid-1, nums);
    }
    else {
        return mid;
    }
}
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int index = binary(0, n-1, nums);
        return nums[index];    
    }
};