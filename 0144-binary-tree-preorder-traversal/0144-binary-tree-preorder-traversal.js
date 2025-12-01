/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    const ans = [];
    const st = [root];
    if(!root) {
        return [];
    }
    while(st.length > 0) {
        const last = st.at(-1);
        ans.push(last);
        st.pop();
        if(last.right) {
            st.push(last.right);
        }
        if(last.left) {
            st.push(last.left);
        }
    }
    return ans.map(node => node.val);
};