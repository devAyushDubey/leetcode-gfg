class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> st;
        string ans = "";
        for(int i=0; i<n; i++) {
            int digit = num[i] - '0';
            if(k!=0) {
                while(!st.empty() && k > 0 && digit < st.top()) {
                    st.pop();
                    k--;
                }
            }
            st.push(digit);
        }
        int zeroes = 0;
        while(!st.empty()) {
            if(k > 0) {
                k--;
                st.pop();
                continue;
            }
            if(st.top() == 0) {
                zeroes++;
            }
            else {
                zeroes = 0;
            }
            ans += to_string(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        string trans = ans.substr(zeroes, n-zeroes);
        if(trans == "") {
            return "0";
        }
        return trans;
    }
};