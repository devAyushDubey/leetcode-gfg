const int MOD = 1e9 + 7;
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
vector<int> psee(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for(int i = 0; i<n; i++) {
        while(!st.empty() && nums[i] < nums[st.top()]) {
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
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nses = nse(arr);
        vector<int> psees = psee(arr);
        int ans = 0;
        for(int i=0; i<n; i++) {
            int left = i - psees[i];
            int right = nses[i] - i;
            ans = (ans + (left * right * 1LL * arr[i])%MOD)%MOD;
        }
        return ans;
    }
};