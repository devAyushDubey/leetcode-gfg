class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        vector<int> mp(26, 0);
        for(int i = 0; i<n; i++) mp[int(s[i]) - 97]++;
        for(int i = 0; i<n; i++) {
            if(mp[int(t[i]) - 97] == 0) return false;
            mp[int(t[i]) - 97]--;
        }
        for(int i: mp) if(i > 0) return false;
        return true;
    }
};