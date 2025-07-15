class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(int x: st) {
            if(st.find(x - 1) == st.end()) {
                int cnt = 0;
                while(st.find(x + cnt) != st.end()) cnt++;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};