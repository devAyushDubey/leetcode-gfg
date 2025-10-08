class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int open = 0;
        for(char &c: s) {
            if(c != '(' && c != ')') continue;
            ans = max(ans, c == '(' ? ++open : --open);
        }
        return ans;
    }
};