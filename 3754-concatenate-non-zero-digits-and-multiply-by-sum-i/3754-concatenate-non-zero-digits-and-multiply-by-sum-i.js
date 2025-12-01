/**
 * @param {number} n
 * @return {number}
 */
var sumAndMultiply = function(n) {
    let nStr = `${n}`;
    nStr = nStr.replaceAll('0', '');
    const sum = nStr.split('').reduce((acc, num) => {
        acc += Number(num);
        return acc;
    }, 0);
    return Number(nStr) * sum;
};