/**
 * @param {string} s
 * @return {number}
 */
var maxDistinct = function(s) {
    const st = new Set();
    let ans = 0;
    for(let i = 0; i<s.length; i++) {
        if(!st.has(s[i])) {
            st.add(s[i]);
            ans++;
        }
    }
    return ans;
};