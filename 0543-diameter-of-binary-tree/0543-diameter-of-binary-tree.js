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
var diameterOfBinaryTree = function(root) {
    if(!root) return 0;
    const diameter = heightOfTree(root.left) + heightOfTree(root.right);
    const left = diameterOfBinaryTree(root.left);
    const right = diameterOfBinaryTree(root.right);
    return Math.max(diameter, left, right);
};

var heightOfTree = function(node, h = 1) {
    if(!node) return h-1;
    if(!node.left && !node.right) return h;
    return Math.max(heightOfTree(node.left, h+1), heightOfTree(node.right, h+1));
}