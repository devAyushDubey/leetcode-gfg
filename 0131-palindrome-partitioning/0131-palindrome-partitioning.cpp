bool isPalindrome(string st) {
    if(st.length() == 0) return false;
    if(st.length() == 1) return true;
    string reversedString = st;
    reverse(reversedString.begin(), reversedString.end());
    return st == reversedString;
}
vector<vector<string>> partRecur(vector<string> carry, string curr, string s, int i) {
    int len = s.length();
    if(i == len) {
        if(curr == "") {
            return {carry};
        }
        return {};
    }

    char c = s[i];
    string newCurr = curr + c;
    vector<vector<string>> ans;
    if(isPalindrome(newCurr)) {
        carry.push_back(newCurr);
        ans = partRecur(carry, "", s, i+1);
        carry.pop_back();
    }
    vector<vector<string>> notTaken = partRecur(carry, newCurr, s, i+1);
    ans.insert(ans.end(), notTaken.begin(), notTaken.end());
    return ans;
}
class Solution {
public:
    vector<vector<string>> partition(string s) {
        return partRecur({}, "", s, 0);
    }
};