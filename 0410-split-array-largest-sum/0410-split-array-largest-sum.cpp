int subarrays(int capacity, vector<int>& nums) {
    int subs = 0;
    int load = 0;
    for(int i: nums) {
        load += i;
        if(load >= capacity) {
            load = load == capacity ? 0 : i;
            subs++;
        }
    }
    if(load != 0) subs++;
    cout<<capacity<<" "<<subs<<endl;
    return subs;
}
int binarySearch(int low, int high, vector<int>& nums, int k) {
    if(low >= high) {
        return low;
    }
    int mid = (low+high)/2;
    cout<<low<<" "<<mid<<" "<<high<<endl;
    int subs = subarrays(mid, nums);
    if(subs < k) {
        return binarySearch(low, mid-1, nums, k);
    }
    else if(subs > k) {
        return binarySearch(mid+1, high, nums, k);
    }
    else {
        // if(low == mid) return mid;
        int leftSide = binarySearch(low, mid-1, nums, k);
        if(subarrays(leftSide, nums) == k) return leftSide;
        return mid;
    }
}
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int mx = INT_MIN;
        int total = 0;
        for(int i: nums) {
            total += i;
            mx = max(mx, i);
        }
        return binarySearch(mx, total, nums, k);
    }
};