class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix;
        int sum = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(sum == k) ans++;
            if(prefix[sum-k]) {
                ans += prefix[sum-k];
            }
            prefix[sum] = prefix[sum] + 1;
        }
        return ans;
    }
};