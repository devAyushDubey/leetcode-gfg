class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for(char c: brokenLetters) {
            broken.insert(c);
        }
        int ans = 0;
        bool untype = false;
        text = text + " ";
        for(char c: text) {
            if(c == ' ') {
                if(!untype) {
                    ans++;
                }
                else {
                    untype = false;
                }
                continue;
            }
            if(untype) continue;
            if(broken.find(c) != broken.end()) {
                untype = true;
            }
        }
        return ans;
    }
};