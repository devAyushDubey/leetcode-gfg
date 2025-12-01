/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countElements = function(nums, k) {
    nums.sort();
    const mp = {};
    nums.forEach((num, ind) => {
        mp[num] = ind;
    })
    const total = nums.length;
    const bound = total - k;
    const qualified = nums.filter(num => mp[num] < bound);
    return qualified.length;
};