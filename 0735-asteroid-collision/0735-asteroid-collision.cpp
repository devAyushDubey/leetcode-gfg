class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
            while(asteroids[i] < 0 && !ans.empty() && ans.back() > 0 && ans.back() < (-1*asteroids[i])) {
                ans.pop_back();
            }
            if(asteroids[i] < 0) {
                if(ans.empty()) {
                    ans.push_back(asteroids[i]);
                }
                else if(ans.back() == (-1*asteroids[i])) {
                    ans.pop_back();
                }
                else if(ans.back() < 0) {
                    ans.push_back(asteroids[i]);
                }
            }
            else {
                ans.push_back(asteroids[i]);
            }            
        }
        return ans;
    }
};