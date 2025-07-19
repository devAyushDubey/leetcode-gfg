class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int i = 1;
        while(i<=numRows) {
            vector<int> vec(i, 1);
            if(i>2) {
                for(int j=0; j<i; j++) {
                    int left = j-1;
                    int right = j;
                    if(left < 0 || right >= i-1) continue;
                    vec[j] = ans[i-2][left] + ans[i-2][right];
                }
            }
            ans.push_back(vec);
            i++;
        }
        return ans;
    }
};