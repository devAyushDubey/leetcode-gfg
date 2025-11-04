
const comp = (a,b) => {
    if(a[1] === b[1]) {
        return Number(b[0]) - Number(a[0]);
    }
    return b[1] - a[1];
}
/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findXSum = function(nums, k, x) {
    const n = nums.length;
    const freq = {};
    const ans = [];
    for(let i = 0; i<k; i++) {
        freq[nums[i]] = freq[nums[i]] ? freq[nums[i]] + 1 : 1;
    }
    let freqEntries = Object.entries(freq);
    freqEntries.sort(comp);
    if(freqEntries.length >= x) {
        let sum = 0;
        for(let i = 0; i<x; i++) {
            sum += Number(freqEntries[i][0])*freqEntries[i][1];
        }
        ans.push(sum);
    }
    else {
        let sum = 0;
        freqEntries.forEach(entry => {
            sum += Number(entry[0])*entry[1];
        })
        ans.push(sum);
    }
    for(let i = k; i<n; i++) {
        freq[nums[i]] = freq[nums[i]] ? freq[nums[i]] + 1 : 1;
        freq[nums[i-k]]--;
        freqEntries = Object.entries(freq)
        freqEntries.sort(comp);
        if(freqEntries.length >= x) {
            let sum = 0;
            for(let i = 0; i<x; i++) {
                sum += Number(freqEntries[i][0])*freqEntries[i][1];
            }
            ans.push(sum);
        }
        else {
            let sum = 0;
            freqEntries.forEach(entry => {
                sum += Number(entry[0])*entry[1];
            })
            ans.push(sum);
        }
    }
    return ans;
};