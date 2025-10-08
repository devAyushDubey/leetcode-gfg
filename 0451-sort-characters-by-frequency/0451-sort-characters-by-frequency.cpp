// HashMap based approach O(NlogN)
typedef pair<char, int> P;
bool comparator(P& a, P& b) {
    return a.second > b.second;
}
class Solution {
public:
    string frequencySort(string s) {
        vector<P> mp(123, {'0', 0});
        for(char &c: s) {
            int freq = mp[c].second;
            mp[c] = {c, freq + 1};
        }
        sort(mp.begin(), mp.end(), comparator);
        string ans = "";
        for(auto item: mp) {
            if(item.second == 0) break;
            string sub = string(item.second, item.first);
            ans += sub;
        }
        return ans;
    }
};