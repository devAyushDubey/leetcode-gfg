vector<int> nse(vector<int> nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n , n);
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
vector<int> pse(vector<int> nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n , -1);
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
int maxHistogramRect(vector<int> nums) {
    int n = nums.size();
    vector<int> nses = nse(nums);
    vector<int> pses = pse(nums);
    int ans = 0;
    for(int i = 0; i<n; i++) {
        ans = max(ans, (nses[i] - pses[i] - 1)*nums[i]);
    }
    return ans;
}
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> colData(rows, vector<int>(cols, 0));
        vector<vector<int>> rowData(rows, vector<int>(cols, 0));
        for(int i = 0; i<cols; i++) {
            int ones = 0;
            for(int j = 0; j<rows; j++) {
                if(matrix[j][i] == '1') {
                    colData[j][i] = ++ones;
                }
                else {
                    ones = 0;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<rows; i++) {
            ans = max(ans, maxHistogramRect(colData[i]));
        }
        return ans;
    }
};