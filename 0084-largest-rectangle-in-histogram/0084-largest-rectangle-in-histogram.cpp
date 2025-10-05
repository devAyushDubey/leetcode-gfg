vector<int> nse(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, n);
    for(int i = n-1; i>=0; i--) {
        while(!st.empty() && nums[i] <= nums[st.top()]) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> pse(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for(int i = 0; i<n; i++) {
        while(!st.empty() && nums[i] <= nums[st.top()]) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nses = nse(heights);
        vector<int> pses = pse(heights);
        int ans = 0;
        int area = 0;
        for(int i = 0; i<n; i++) {
            area = heights[i] * (nses[i] - pses[i] - 1);
            ans = max(ans, area);
        }
        return ans;
    }
};