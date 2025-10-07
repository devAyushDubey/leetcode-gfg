class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int start = 0;
        int end = n-1;
        while(start < end && ((num[end] - '0')%2 == 0)) {
            end--;
        }
        string ans = num.substr(start, end+1);
        return ans[ans.size() - 1]%2 == 0 ? "" : ans;
    }
};