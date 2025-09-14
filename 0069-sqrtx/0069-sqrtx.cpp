int binarySearch(int low, int high, int k) {
    if(low >= high) {
        return high;
    }
    int mid = (low+high)/2;
    int dividend = k/mid;
    if(dividend > mid) {
        int rightSide = binarySearch(mid+1, high, k);
        if((k/rightSide) >= rightSide) return rightSide;
        return mid;
    }
    else if(dividend < mid) {
        return binarySearch(low, mid-1, k);
    }
    else {
        return mid;
    }
}
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        return binarySearch(1, x/2, x);
    }
};