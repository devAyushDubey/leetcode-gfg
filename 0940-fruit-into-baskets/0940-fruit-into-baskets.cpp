class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        pair<int, int> basketA = {-1,-1};
        pair<int, int> basketB = {-1,-1};
        int n = fruits.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r<n) {
            // cout<<l<<" "<<r<<endl;
            // cout<<"A "<<basketA.first<<" "<<basketA.second<<endl;
            // cout<<"B "<<basketB.first<<" "<<basketB.second<<endl;
            if(basketA.first == fruits[r]) {
                basketA.second = r;
            }
            else if (basketB.first == fruits[r]) {
                basketB.second = r;
            }
            else {
                if(basketA.first == -1) {
                    basketA = {fruits[r], r};
                }
                else if(basketB.first == -1) {
                    basketB = {fruits[r], r};
                }
                else {
                    if(basketA.second < basketB.second) {
                        l = basketA.second + 1;
                        basketA = {fruits[r], r};
                    }
                    else {
                        l = basketB.second + 1;
                        basketB = {fruits[r], r};
                    }
                }
            }
            // cout<<l<<" "<<r<<endl;
            // cout<<"---------"<<endl;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    } 
};