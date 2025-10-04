vector<int> prefixMax(vector<int>& nums) {
    int n = nums.size();
    vector<int> mx(n, -1);
    mx[0] = nums[0];
    for(int i = 1; i<n; i++) {
        mx[i] = max(mx[i-1], nums[i]);
    }
    return mx;
}
vector<int> suffixMax(vector<int>& nums) {
    int n = nums.size();
    vector<int> mx(n, -1);
    mx[n-1] = nums[n-1];
    for(int i = n-2; i>=0; i--) {
        mx[i] = max(mx[i+1], nums[i]);
    }
    return mx;
}
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> preMax = prefixMax(height);
        vector<int> sufMax = suffixMax(height);
        int ans = 0;
        for(int i = 0; i <n; i++) {
            ans += max(min(preMax[i], sufMax[i]) - height[i], 0);
        }
        return ans;
    }
};