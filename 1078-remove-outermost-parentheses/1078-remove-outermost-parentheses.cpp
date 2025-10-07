class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        if(n<=2) {
            return "";
        }
        string ans = "";
        int open = 0;
        int start = 0;
        for(int i=0; i<n; i++) {
            char c = s[i];
            if((c == '(' ? ++open : --open) == 0)  {
                ans += s.substr(start+1, i-start-1);
                start = i+1;
            }
        }
        return ans;
    }
};