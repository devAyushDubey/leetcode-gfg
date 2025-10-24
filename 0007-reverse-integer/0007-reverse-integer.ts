function reverse(x: number): number {
    const isNeg = x < 0;
    const INT_MAX = isNeg ? 2147483648 : 2147483647;
    let ans = 0;
    x = Math.abs(x);
    while(x) {
        ans *= 10;
        if(ans >= INT_MAX) {
            return 0;
        }
        const lastDigit = x%10;
        if(INT_MAX - ans < lastDigit) {
            return 0;
        }
        ans += lastDigit;
        x = (x/10) | 0;
    }
    return isNeg ? -1 * ans : ans;
};