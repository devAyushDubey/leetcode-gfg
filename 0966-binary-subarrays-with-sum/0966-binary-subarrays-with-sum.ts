function subsWithSumLessOrEqual(nums: number[], goal: number): number {
    const n = nums.length;
    let sum = 0;
    let r = 0;
    let l = 0;
    let count = 0;
    while(r<n) {
        sum += nums[r];
        while(l<=r && sum > goal) {
            sum -= nums[l];
            l++;
        }
        count += (r-l+1);
        r++;
    }
    return count;
}
function numSubarraysWithSum(nums: number[], goal: number): number {
    return subsWithSumLessOrEqual(nums, goal) - subsWithSumLessOrEqual(nums, goal - 1)
};