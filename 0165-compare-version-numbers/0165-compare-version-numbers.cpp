class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1);
        stringstream s2(version2);
        string temp;
        vector<string> revisions1;
        vector<string> revisions2;
        while(getline(s1, temp, '.')) {
            revisions1.push_back(temp);
        }
        while(getline(s2, temp, '.')) {
            revisions2.push_back(temp);
        }
        int n1 = revisions1.size();
        int n2 = revisions2.size();
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1 < n1 && ptr2 < n2) {
            int numRev1 = stoi(revisions1[ptr1]);
            int numRev2 = stoi(revisions2[ptr2]);
            if(numRev1 == numRev2) {
                ptr1++;
                ptr2++;
                continue;
            }
            else if (numRev1 > numRev2) {
                return 1;
            }
            else {
                return -1;
            }
        }
        if(ptr1 == n1 && ptr2 == n2) {
            return 0;
        }
        bool allZero = true;
        while(ptr1 != n1) {
            int numRev1 = stoi(revisions1[ptr1]);
            if(numRev1 != 0) {
                allZero = false;
                break;
            }
            ptr1++;
        }
        if(!allZero) {
            return 1;
        }
        allZero = true;
        while(ptr2 != n2) {
            int numRev2 = stoi(revisions2[ptr2]);
            if(numRev2 != 0) {
                allZero = false;
                break;
            }
            ptr2++;
        }
        if(!allZero) {
            return -1;
        }
        return 0;
    }
};