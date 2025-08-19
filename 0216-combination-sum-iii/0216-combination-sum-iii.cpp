vector<vector<int>> combSum(vector<int> carry, int num, int maxCount, int sum) {
    int n = carry.size();
    if(n == maxCount) {
        if(sum == 0) {
            return {carry};
        }
        return {};
    }
    vector<vector<int>> notTaken;
    if(num > 0){
        notTaken = combSum(carry, num-1, maxCount, sum);
        if(sum >= num) {
            carry.push_back(num);
            vector<vector<int>> taken = combSum(carry, num-1, maxCount, sum-num);
            notTaken.insert(notTaken.end(), taken.begin(), taken.end());
        }
    }
    return notTaken;
}
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return combSum({}, 9, k, n);
    }
};