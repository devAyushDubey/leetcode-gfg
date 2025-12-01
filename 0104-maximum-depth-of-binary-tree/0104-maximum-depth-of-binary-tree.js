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
 * @return {number}
 */
var maxDepth = function(root, h = 1) {
    if(!root) return h-1;
    if(!root.left && !root.right) return h;
    return Math.max(maxDepth(root.left, h+1), maxDepth(root.right, h+1));
};