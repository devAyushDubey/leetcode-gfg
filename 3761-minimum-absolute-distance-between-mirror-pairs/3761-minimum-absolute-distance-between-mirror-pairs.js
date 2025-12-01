var reverse = function(num) {
    let rev = num;
    while(rev % 10 === 0) {
        rev = rev / 10;
    }
    rev = `${rev}`;
    return Number(rev.split('').reverse().join(''));
}

/**
 * @param {number[]} nums
 * @return {number}
 */
var minMirrorPairDistance = function(nums) {
    const n = nums.length;
    let ans = n + 1;
    const mp = {};
    for(let i = n-1; i>=0; i--) {
        const num = nums[i];
        const rev = reverse(num);
        if(mp[rev]) {
            ans = Math.min(ans, mp[rev] - i);
        }
        mp[num] = i;
    }
    return ans === n + 1 ? -1 : ans;
};