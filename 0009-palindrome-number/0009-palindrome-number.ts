// Brute-force
function reverse(x: number): number {
    let ans = 0;
    while(x) {
        const last = x%10;
        ans *= 10;
        ans += last;
        x = (x/10) | 0;
    }
    return ans;
}
function isPalindrome(x: number): boolean {
    return x < 0? false : x === reverse(x);
};