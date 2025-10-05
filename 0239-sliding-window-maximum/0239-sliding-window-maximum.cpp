class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i<k; i++) {
            while(!dq.empty() && nums[i] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        for(int i = k; i<n; i++) {
            if(!dq.empty() && nums[i-k] == dq.front()) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] > dq.back()) {
                dq.pop_back();
            }
            if(!dq.empty()) {
                ans.push_back(dq.front());
            }
            else {
                ans.push_back(nums[i]);
            }
            dq.push_back(nums[i]);
        }
        return ans;
    }
};