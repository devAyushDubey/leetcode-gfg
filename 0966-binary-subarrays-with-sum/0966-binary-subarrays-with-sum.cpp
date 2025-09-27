int subsWithLessOrEqual(vector<int>& nums, int goal) {
    if(goal < 0) return 0;
    int n = nums.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    int ans = 0;
    while(r<n) {
        sum += nums[r];
        while(l<=r && sum > goal) {
            sum -= nums[l];
            l++;
        }
        ans += (r-l+1);
        r++;
    }
    return ans;
}
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subsWithLessOrEqual(nums, goal) - subsWithLessOrEqual(nums, goal-1);
    }
};