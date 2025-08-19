
unordered_map<char, string> keypad = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

vector<string> combs(string carry, int ind, string digits) {
    if(ind == digits.length()) {
        if(carry != "")
            return {carry};
        return {};
    }
    char digit = digits[ind];
    string keys = keypad[digit];
    vector<string> ans;
    vector<string> subs;
    for(int i=0; i<keys.length(); i++) {
        subs = combs(carry + keys[i], ind+1, digits);
        ans.insert(ans.end(), subs.begin(), subs.end());
    }
    return ans;
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return combs("", 0, digits);
    }
};