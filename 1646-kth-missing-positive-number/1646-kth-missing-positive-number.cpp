int binarySearch(int low, int high, vector<int>& nums, int k) {
    if(low >= high) {
        return high < 0 ? low : high;
    }
    int mid = (low+high)/2;
    if(nums[mid] < k) {
        int rightSide = binarySearch(mid+1, high, nums, k);
        if(nums[rightSide] < k) return rightSide;
        return mid;
    }
    else {
        return binarySearch(low, mid-1, nums, k);
    }
}
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k < arr[0]) return k;
        int n = arr.size();
        vector<int> answers(n);
        for(int i=0; i<n; i++) {
            int missing = arr[i] - (i+1);
            answers[i] = missing;
        }
        int index = binarySearch(0, n-1, answers, k);
        return arr[index] + (k - answers[index]);
    }
};