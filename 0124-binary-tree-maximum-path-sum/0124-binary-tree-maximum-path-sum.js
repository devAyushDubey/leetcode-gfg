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
var maxPathSum = function(root) {
    let maxSum = Number.MIN_SAFE_INTEGER;
    const maxPath = function(node) {
        if(!node) return 0;
        const left = maxPath(node.left);
        const right = maxPath(node.right);
        maxSum = Math.max(maxSum, node.val, left + node.val, right + node.val, left+right+node.val);
        return Math.max(left, right, 0) + node.val;
    }
    maxPath(root)
    return maxSum;
};