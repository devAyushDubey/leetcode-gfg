function check(nums: number[]): boolean {
    const n = nums.length;
    let noOfPeaks = 0;
    for(let i = 0; i<n-1; i++) {
        noOfPeaks += nums[i] > nums[i+1] ? 1 : 0;
    }
    if(noOfPeaks !== 1) return noOfPeaks === 0;
    return nums.at(0) >= nums.at(-1);
};