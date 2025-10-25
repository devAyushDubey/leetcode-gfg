function removeDuplicates(nums: number[]): number {
    const n = nums.length;
    let commander = 0;
    let soldier = commander;
    while(commander < n) {
        if(soldier < commander) {
            nums[soldier] = nums[commander];
        }
        commander++;
        soldier++;
        while(nums[commander] === nums[commander-1]) commander++;
    }
    return soldier;
};