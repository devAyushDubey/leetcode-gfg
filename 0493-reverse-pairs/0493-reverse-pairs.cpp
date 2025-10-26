int merge(vector<int>& nums, int low, int mid, int high) {
    int cnt = 0;
    int left = low;
    int right = mid+1;
    vector<int> temp;

    int l = low;
    int r = mid + 1;

    while(l <= mid && r <= high) {
        double f = nums[l];
        if((f/2) > nums[r]) {
            cnt+= (mid - l + 1);
            r++;
        } 
        else {
            l++;
        }
    }

    while(left <= mid && right <= high) {
        if(nums[left] < nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    for(int i=low; i<=high; i++) {
        nums[i] = temp[i-low];
    }

    return cnt;
}
int mergeSort(vector<int>& nums, int left, int right) {
    int cnt = 0;
    if(left >= right) return cnt;
    int mid = (left + right)/2;
    cnt += mergeSort(nums, left, mid);
    cnt += mergeSort(nums, mid+1, right);
    cnt += merge(nums, left, mid, right);
    return cnt;
}
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};