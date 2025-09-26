class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixMap;
        int sum = 0;
        int ans = 0;
        for(int i: nums) {
            sum += i;
            if(sum == goal) {
                ans++;
            }

            if(prefixMap[sum - goal]) {
                ans += prefixMap[sum-goal];
            }

            prefixMap[sum]++;
        }
        return ans;
    }
};