// Variation of Moore's Voting Algorithm
// Think of it like two Political Parties X and Y, these two political parties combined, are the majority (> 2n/3) for us, this is the basis for our calculation at every iteration.
// Now, the approach is to FIRST find the two largest parties, and LATER check if they are individually above n/3 votes.
// So, now you have to understand that these two among themselves cannot dethrone one another from their position of largest and the 2nd largest party -- there has to be a third party / parties that could challenge them, this is the crucial point, by the third party/parties we mean to say votes that don't go to either X or Y! Which is exactly the else condition, this third party will equally damage X and Y from their position, so for every +1 vote for third parties, X's influence as well as Y's influence decreases by 1, i.e. 1 unit of space that X acquired and Y acquired from the entire set is taken by third party.
function majorityElement(nums: number[]): number[] {
    const n = nums.length;
    let el1 = Number.MAX_SAFE_INTEGER;
    let el2 = Number.MAX_SAFE_INTEGER;
    let count1 = 0;
    let count2 = 0;
    nums.forEach(num => {
        if(count1 === 0 && num !== el2) {
            el1 = num;
            count1++;
        }
        else if(count2 === 0 && num !== el1) {
            el2 = num;
            count2++;
        }
        else if(num === el1) count1++;
        else if(num === el2) count2++;
        else {
            count1--;
            count2--;
        }
    })
    const ans = [];
    const threshold = (n/3) | 0;
    count1 = 0;
    count2 = 0;
    nums.forEach(num => {
        if(num === el1) count1++;
        if(num === el2) count2++;
    })
    if(count1 > threshold) ans.push(el1);
    if(count2 > threshold) ans.push(el2);
    return ans;
};