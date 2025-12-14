
const VOWELS = ['a','e','i','o','u'];

const countVowels = (s) => {
    let cnt = 0;
    for(const c of s) {
        cnt += VOWELS.includes(c) ? 1 : 0;
    }
    return cnt;
}

/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    const words = s.split(' ');
    const frst = countVowels(words[0]);
    words.forEach((word, ind) => {
        if(ind === 0) return;
        if(countVowels(word) === frst) {
            words[ind] = [...word].reverse().join('');
        }
    })
    return words.join(' ');
};