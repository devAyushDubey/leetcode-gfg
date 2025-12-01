
var maxDepth = function(root, h = 1) {
    if(!root) return h-1;
    if(!root.left && !root.right) return h;
    return Math.max(maxDepth(root.left, h+1), maxDepth(root.right, h+1));
}

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
 * @return {boolean}
 */
var isBalanced = function(root) {
    if(!root) return true;
    if(!root.left && !root.right) return true;
    const isNodeBalanced = Math.abs(maxDepth(root.left) - maxDepth(root.right)) <= 1;
    return isNodeBalanced && isBalanced(root.left) && isBalanced(root.right);
};