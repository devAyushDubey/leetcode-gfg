class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = strs[0];
        for(int i = 1; i<n; i++) {
            int limit = min(ans.size(),strs[i].size());
            int j = 0;
            for(j = 0; j<limit; j++) {
                if(strs[i][j] != ans[j]) {
                    break;
                }
            }
            if(j != ans.size()) {
                ans = ans.substr(0, j);
            }
        }
        return ans;
    }
};