int subsLessOrEqual(vector<int>& nums, int k) {
    if(k < 0) return 0;
    int n = nums.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    int ans = 0;
    while (r<n) {
        sum += nums[r];
        while(sum > k) {
            sum -= nums[l++];
        }
        ans += (r-l+1);
        r++;
    }
    return ans;
}
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++) {
            nums[i] = nums[i] % 2;
        }
        return subsLessOrEqual(nums, k) - subsLessOrEqual(nums, k-1);
    }
};                                       