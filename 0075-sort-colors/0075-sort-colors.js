/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    const n = nums.length;
    let low = 0;
    let mid = 0;
    let high = n - 1;
    while(mid <= high) {
        if(nums[mid] === 0) {
            const tmp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = tmp;
            mid++;
            low++
        }
        else if(nums[mid] === 1) {
            mid++;
        }
        else {
            const tmp = nums[high];
            nums[high] = nums[mid];
            nums[mid] = tmp;
            high--;
        }
    }
    return nums;
};