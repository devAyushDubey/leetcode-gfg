

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
var verticalTraversal = function(root, r = 0, c = 0) {
    const mp = {};
    const traverse = function(root, r, c) {
        if(!root) return;
        if(mp[c]) {
            if(mp[c][r]) {
                mp[c][r].push(root.val);
            }
            else {
                mp[c][r] = [root.val];
            }
        }
        else {
            mp[c] = {
                [r]: [root.val]
            }
        }
        traverse(root.left, r+1, c-1);
        traverse(root.right, r+1, c+1);
    }
    traverse(root, r, c);
    const columns = Object.keys(mp).sort((a,b) => Number(a)-Number(b))
    return columns.map(col => {
        const rows = Object.keys(mp[col]).sort((a,b) => Number(a)-Number(b));
        const res = [];
        rows.forEach(row => {
            mp[col][row].sort((a,b) => a-b);
            res.push(...mp[col][row]);
        })
        return res;
    })
};

