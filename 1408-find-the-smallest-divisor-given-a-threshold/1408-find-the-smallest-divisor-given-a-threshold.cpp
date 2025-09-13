int totalDivisor(int divisor, vector<int>& nums) {
    double d = 1.0 * divisor;
    int total = 0;
    for(int i: nums) {
        if(i < d) {
            total++;
        }
        else {
            total += ceil(i/d);
        }
    }
    return total;
}
int binarySearch(int low, int high, vector<int>& nums, int threshold) {
    if(low >= high) {
        return high <= 0 ? low : high;
    }
    int mid = (low+high)/2;
    if(totalDivisor(mid, nums) <= threshold) {
        int leftSide = binarySearch(low, mid-1, nums, threshold);
        if(totalDivisor(leftSide, nums) <= threshold) return leftSide;
        return mid;
    }
    else {
        return binarySearch(mid+1, high, nums, threshold);
    }
}
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int mx = INT_MIN;
        for(int i: nums) {
            mx = max(mx, i);
        }
        return binarySearch(1, mx, nums, threshold);
    }
};