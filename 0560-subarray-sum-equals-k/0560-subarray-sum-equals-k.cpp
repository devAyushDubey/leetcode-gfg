class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix;
        int sum = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            prefix[sum] = prefix[sum] + 1;
            if(sum == k) ans++;
            if(prefix[sum-k]) {
                ans += k == 0 ? prefix[sum-k] - 1 : prefix[sum-k];
            }
        }
        return ans;
    }
};