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
const isEqual = (node1, node2) => {
    if(!node1 || !node2) return !node1 && !node2;
    return isEqual(node1.left, node2.right) && isEqual(node1.right, node2.left) && node1.val === node2.val;
}
var isSymmetric = function(root) {
    if(!root) return true;
    return isEqual(root.left, root.right);
};