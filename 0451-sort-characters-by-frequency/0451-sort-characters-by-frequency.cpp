// PriorityQueue/Heap based approach O(NlogN)
typedef pair<char, int> P;
class Compare {
public:
	bool operator()(P& a, P& b) {
		return a.second < b.second;
	}
};
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<P, vector<P>, Compare> pq;
        vector<int> mp(75, 0);
        for(char c: s) {
            mp[int(c) - 48]++;
        }
        for(int i = 0; i<75; i++) {
            if(mp[i] == 0) continue;
            char c = i + 48;
            pq.push({c, mp[i]});
        }
        string ans = "";
        while(!pq.empty()) {
            string sub = string(pq.top().second, pq.top().first);
            ans += sub;
            pq.pop();
        }
        return ans;
    }
};