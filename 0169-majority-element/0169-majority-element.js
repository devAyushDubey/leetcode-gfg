/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let mx = nums[0];
    let cnt = 0;
    nums.forEach(num => {
        if(cnt === 0) mx = num;
        if(mx === num) cnt++;
        else cnt--;
    })
    return mx;
};