class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> mp(256);
        vector<bool> mapped(256);
        int n = s.size();
        for(int i = 0; i<n; i++) {
            if(mp[s[i]]) {
                if(t[i] != mp[s[i]]) return false;
            }
            else {
                if(mapped[t[i]]) return false;
                mp[s[i]] = t[i];
                mapped[t[i]] = true;
            }
        }
        return true;
    }
};