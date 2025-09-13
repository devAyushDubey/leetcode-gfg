bool isPossible(int days, vector<int>& bloomDay, int m, int k) {
    int total = 0;
    int adj = 0;
    for(int bloom: bloomDay) {
        if(bloom <= days) {
            adj++;
        }
        else {
            adj = 0;
        }
        if(adj == k) {
            total++;
            adj = 0;
        }
    }
    return total >= m;
}
int binarySearch(int low, int high, vector<int>& bloomDay, int& m, int& k) {
    if(low >= high) {
        return high <= 0 ? low : high;
    }
    int mid = (low+high)/2;
    if(isPossible(mid, bloomDay, m, k)) {
        int leftSide = binarySearch(low, mid-1, bloomDay, m, k);
        if(isPossible(leftSide, bloomDay, m, k)) return leftSide;
        return mid;
    }
    else {
        return binarySearch(mid+1, high, bloomDay, m, k);
    }
}
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int mx = INT_MIN;
        for(int i: bloomDay) {
            mx = max(mx, i);
        }
        int left = (n / m) / k;
        if(left == 0) return -1;
        int res = binarySearch(1, mx, bloomDay, m, k);
        return isPossible(res, bloomDay, m, k) ? res : -1;
    }
};