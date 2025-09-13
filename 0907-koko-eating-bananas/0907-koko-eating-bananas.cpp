long long timeTaken(int rate, vector<int>& piles) {
    double r = 1.0 * rate;
    long long total = 0;
    for(int i: piles) {
        total += ceil(i/r);
    }
    return total;
}
int binarySearch(int low, int high, vector<int>& piles, int& limit) {
    if(low >= high) {
        return high <= 0 ? low : high;
    }
    int mid = (low+high)/2;
    long long time = timeTaken(mid, piles);
    if(time > limit) {
        return binarySearch(mid+1, high, piles, limit);
    }
    else {
        int leftSide = binarySearch(low, mid-1, piles, limit);
        if(timeTaken(leftSide, piles) <= limit) return leftSide;
        return mid;
    }
}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int mx = piles[piles.size() - 1];
        return binarySearch(1, mx, piles, h);
    }
};