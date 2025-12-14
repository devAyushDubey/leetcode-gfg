/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var absDifference = function(nums, k) {
    nums.sort((a,b) => a-b);
    const n = nums.length;
    let small = 0;
    let large = 0;
    nums.forEach((num, ind) => {
        if(ind < k) {
            small += num;
        }
        if(ind >= n-k) {
            large += num;
        }
    })
    return Math.abs(large - small);
};