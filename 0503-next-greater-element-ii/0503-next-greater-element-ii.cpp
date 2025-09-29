class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n, -1);
        for(int i = 2*n-1; i>=0; i--) {
            int j = i%n;
            while(!st.empty() && nums[j] >= st.top()) {
                st.pop();
            }
            if(!st.empty()) {
                nge[j] = st.top();
            }
            st.push(nums[j]);
        }
        return nge;
    }
};