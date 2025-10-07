class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int start = 0;
        string ans = "";
        while(i < n) {
            while(i<n && s[i] == ' ') {
                i++;
            }
            start = i;
            while(i<n && s[i] != ' ') {
                i++;
            }
            if(i == n) {
                if(start == i) {
                    break;
                }
                ans = s.substr(start) + (ans == "" ? "" : " ") + ans;
            }
            else {
                ans = s.substr(start, i-start) + (ans == "" ? "" : " ") + ans;
            }
        }
        return ans;
    }
};