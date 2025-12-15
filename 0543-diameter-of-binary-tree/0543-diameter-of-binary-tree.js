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
    let maxDiam = 0;
    var heightOfTree = function(node, h = 0) {
        if(!node) return Math.max(h-1,0);
        if(!node.left && !node.right) return h;
        const left = heightOfTree(node.left, h+1) - h;
        const right = heightOfTree(node.right, h+1) - h;
        maxDiam = Math.max(maxDiam, left + right);
        return Math.max(left, right) + h;
    }
    heightOfTree(root);
    return maxDiam;
};

