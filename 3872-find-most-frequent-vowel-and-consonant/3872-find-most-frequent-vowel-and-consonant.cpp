bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
class Solution {
public:
    int maxFreqSum(string s) {
        int maxVow = 0;
        int maxCons = 0;
        vector<int> letterFreq(26, 0);
        for(char c: s) {
            int index = int(c) - 97;
            letterFreq[index]++;
            if(isVowel(c)) {
                if(letterFreq[index] > maxVow) maxVow = letterFreq[index];
            }
            else {
                if(letterFreq[index] > maxCons) maxCons = letterFreq[index];
            }
        }
        return maxVow + maxCons;
    }
};