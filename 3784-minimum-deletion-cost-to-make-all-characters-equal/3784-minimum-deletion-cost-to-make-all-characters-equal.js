const isMonotonous = (s) => {
    if(s.length === 0) return false;
    const ch = s[0];
    return s.every(c => c === ch);
}

/**
 * @param {string} s
 * @param {number[]} cost
 * @return {number}
 */
var minCost = function(s, cost) {
    const presence = Array(26);
    const sArr = s.split('');
    sArr.forEach((_, ind) => presence[s.charCodeAt(ind) - 97] = true);
    if(isMonotonous(sArr)) return 0;
    let minCost = Number.MAX_SAFE_INTEGER;
    presence.forEach((letter, pInd) => {
        if(!letter) return;
        const str = String.fromCharCode(pInd + 97);
        let totalCost = 0;
        sArr.forEach((alpha, ind) => {
            if(alpha === str) return;
            totalCost += cost[ind];
        })
        minCost = Math.min(minCost, totalCost);
    })
    return minCost;
};