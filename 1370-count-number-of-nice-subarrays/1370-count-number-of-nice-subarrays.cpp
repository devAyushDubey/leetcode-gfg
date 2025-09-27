class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixMap;
        int prefixCount = 0;
        int n = nums.size();
        int count = 0;
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] % 2  != 0) {
                prefixCount++;
            }
            if(prefixCount == k) {
                ans += prefixMap[prefixCount - k] + 1;
            }
            else if(prefixCount > k) {
                if(prefixMap[prefixCount - k]) {
                    ans += prefixMap[prefixCount - k];
                }
            }
            prefixMap[prefixCount]++;
        }
        return ans;
    }
};                                       