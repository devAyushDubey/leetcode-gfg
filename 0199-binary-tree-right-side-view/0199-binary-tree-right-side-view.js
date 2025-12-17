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

var rightSideView = function(root) {
   const mp = {};
   const dfs = (node, r=0, c=0) => {
        if(!node) return;
        dfs(node.right, r+1, c+1);
        if(!mp[r]) {
            mp[r] = {
                node,
                c
            }
        }
        dfs(node.left, r+1, c-1);
   };
   dfs(root)
   const rows = Object.keys(mp).sort((a,b) => Number(a)-Number(b));
   return rows.map(row => mp[row].node.val);
};