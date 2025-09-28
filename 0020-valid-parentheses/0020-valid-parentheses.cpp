bool isOpening(char c) {
    return c == '(' || c == '{' || c == '[';
}
bool isSameType(char c, char s) {
    switch(c) {
        case ')':
            return s == '(';
        case '}':
            return s == '{';
        case ']':
            return s == '[';
        default:
            return false;
    }
}
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s) {
            if(isOpening(c)) {
                st.push(c);
            }
            else {
                if(st.empty()) {
                    return false;
                }
                if(isSameType(c, st.top())) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};