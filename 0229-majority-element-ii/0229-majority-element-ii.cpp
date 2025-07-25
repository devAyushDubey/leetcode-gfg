class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        vector<int> ans;
        for(int i: nums) {
            if(count1 == 0 && i != el2) {
                el1 = i;
                count1++;
            }
            else if(count2 == 0 && i != el1) {
                el2 = i;
                count2++;
            }
            else if(i == el1) count1++;
            else if(i == el2) count2++;
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for(int i : nums) {
            if(el1 == i) count1++;
            if(el2 == i) count2++;
        }

        if(count1 > n/3) ans.push_back(el1);
        if(count2 > n/3) ans.push_back(el2);

        return ans;
    }
};