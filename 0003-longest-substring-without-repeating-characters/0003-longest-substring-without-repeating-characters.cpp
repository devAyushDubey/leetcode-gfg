class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, -1);
        int n = s.length();
        int l = 0;
        int r = 0;
        int mxLen = 0;
        while(r<n) {
            if(mp[int(s[r])] >= l) {
                l = mp[int(s[r])] + 1; 
            }
            mxLen = max(mxLen, r-l+1);
            mp[int(s[r])] = r;
            r++;
        }
        return mxLen;
    }
};