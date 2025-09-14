string devowel(string word) {
    char c;
    for(int i=0; i<word.length(); i++) {
        c = word[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            word[i] = '*';
        }
    }
    return word;
}
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        unordered_set<string> exactMatch;
        unordered_map<string, string> caseMatch;
        unordered_map<string, string> vowelMatch;
        string lower;
        for(string word: wordlist) {
            exactMatch.insert(word);
            lower = word;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if(caseMatch[lower] == "") caseMatch[lower] = word;
            if(vowelMatch[devowel(lower)] == "") vowelMatch[devowel(lower)] = word;
        }
        string devow;
        for(string query: queries){
            if(exactMatch.find(query) != exactMatch.end()) {
                ans.push_back(query);
                continue;
            }
            lower = query;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if(caseMatch[lower] != "") {
                ans.push_back(caseMatch[lower]);
                continue;
            }
            devow = devowel(lower);
            if(vowelMatch[devow] != "") {
                ans.push_back(vowelMatch[devow]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};