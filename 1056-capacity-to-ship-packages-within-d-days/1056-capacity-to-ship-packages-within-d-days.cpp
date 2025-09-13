bool isShippingPossible(int capacity, vector<int>& weights, int days) {
    int ships = 0;
    int load = 0;
    for(int i: weights) {
        if(i > capacity) return false;
        if(load + i > capacity){
            ships++;
            load = i;
        }
        else if (load + i == capacity) {
            ships++;
            load = 0;
        }
        else {
            load += i;
        }
        
    }
    if(load != 0) ships++;
    return ships != 0 && ships <= days;
}
int binarySearch(int low, int high, vector<int>& weights, int days) {
    if(low >= high) {
        return high <= 0 ? low : high;
    }
    int mid = (low+high)/2;
    if(isShippingPossible(mid, weights, days)) {
        int leftSide = binarySearch(low, mid-1, weights, days);
        if(isShippingPossible(leftSide, weights, days)) return leftSide;
        return mid;
    }
    else {
        return binarySearch(mid+1, high, weights, days);
    }
}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mx = INT_MIN;
        int total = 0;
        for(int i: weights) {
            mx = max(mx, i);
            total += i;
        }
        return binarySearch(mx, total, weights, days);
    }
};