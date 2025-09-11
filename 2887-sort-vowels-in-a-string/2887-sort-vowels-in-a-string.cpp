bool isVowel(char letter) {
    char c = tolower(letter);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
string merge(string& left, string& right) {
    string ans = "";
    int i = 0;
    int j = 0;
    while(i<left.length() && j<right.length()) {
        if(int(left[i]) < int(right[j])) {
            ans += left[i];
            i++;
        }
        else {
            ans += right[j];
            j++;
        }
    }
    while(i<left.length()) {
        ans += left[i++];
    }
    while(j<right.length()) {
        ans += right[j++];
    }
    return ans;
}
string mergeSort(int low, int high, string& word) {
    if(low == high) {
        string ans(1, word[low]);
        return ans;
    };
    int mid = (low+high)/2;
    string left = mergeSort(low, mid, word);
    string right = mergeSort(mid+1, high, word);
    return merge(left, right);
}
class Solution {
public:
    string sortVowels(string s) {
        string vowels;
        for(char c: s) {
            if(isVowel(c)) {
                vowels += c;
            }
        }
        if(vowels == "") return s;
        string sortedVowels = mergeSort(0, vowels.length()-1, vowels);
        int j = 0;
        for(int i = 0; i<s.length(); i++) {
            if(isVowel(s[i])) {
                s[i] = sortedVowels[j++];
            }
        }
        return s;
    }
};