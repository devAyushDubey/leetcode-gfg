class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i: nums) {
            st.insert(i);
        }
        int ans = 0;
        for(auto it: st) {
            int x = it;
            if(st.find(x - 1) == st.end()) {
                int cnt = 0;
                while(st.find(x) != st.end()) {
                    x++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};