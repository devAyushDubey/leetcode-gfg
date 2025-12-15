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
var zigzagLevelOrder = function(root) {
    const ans = [];
    if(!root) return ans;
    const q = new Queue([root]);
    let lvlCnt = 0;
    while(!q.isEmpty()) {
        const lvl = [];
        let n = q.size();
        while(n--) {
            const front = q.front();
            lvl.push(front.val);
            if(front.left) q.push(front.left);
            if(front.right) q.push(front.right);
            q.pop();
        }
        if(Math.floor(lvlCnt%2) != 0) {
            lvl.reverse();
        }
        ans.push(lvl);
        lvlCnt++;
    }
    return ans;
};