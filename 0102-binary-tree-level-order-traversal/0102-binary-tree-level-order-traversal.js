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
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if(!root) return [];
    const ans = [];
    const queue = new Queue([root]);
    while(!queue.isEmpty()) {
        const lvl = [];
        let n = queue.size();
        for(let i=0;i<n;i++) {
            const front = queue.front();
            lvl.push(front.val);
            if(front.left) queue.push(front.left);
            if(front.right) queue.push(front.right);
            queue.pop();
        }
        ans.push(lvl);
    }
    return ans;
};

