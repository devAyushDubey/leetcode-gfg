vector<int> nge(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, n);
    for(int i = n-1; i>=0; i--) {
        while(!st.empty() && nums[i] >= nums[st.top()]) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> pgee(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for(int i = 0; i<n; i++) {
        while(!st.empty() && nums[i] > nums[st.top()]) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
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
long long sumSubMin(vector<int>& nums) {
    int n = nums.size();
    vector<int> nses = nse(nums);
    vector<int> psees = psee(nums);
    long long ans = 0;
    for(int i=0; i<n; i++) {
        long long left = i - psees[i];
        long long right = nses[i] - i;
        ans = (ans + (left * right * 1LL * nums[i]));
    }
    return ans;
}
long long sumSubMax(vector<int>& nums) {
    int n = nums.size();
    vector<int> nges = nge(nums);
    vector<int> pgees = pgee(nums);
    long long ans = 0;
    for(int i=0; i<n; i++) {
        long long left = i - pgees[i];
        long long right = nges[i] - i;
        ans = (ans + (left * right * 1LL * nums[i]));
    }
    return ans;
}
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubMax(nums) - sumSubMin(nums);
    }
};