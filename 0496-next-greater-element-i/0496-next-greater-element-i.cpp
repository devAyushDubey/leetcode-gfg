class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;
        stack<int> st;
        int n = nums2.size();
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                st.push(nums2[i]);
                nge[nums2[i]] = -1;
                continue;
            }
            if(nums2[i] < st.top()) {
                nge[nums2[i]] = st.top();
            }
            else {
                while(!st.empty() && nums2[i] > st.top()) {
                    st.pop();
                }
                if(st.empty()) {
                    nge[nums2[i]] = -1;
                }
                else {
                    nge[nums2[i]] = st.top();
                }
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i: nums1) {
            ans.push_back(nge[i]);
        }
        return ans;
    }
};