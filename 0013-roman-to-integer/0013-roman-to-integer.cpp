class Solution {
public:
    int romanToInt(string s) {
        char last;
        int value = 0;
        for(char &c: s) {
            switch(c) {
                case 'I':
                    value += 1;
                    break;
                case 'V':
                    value += (last == 'I' ? 3 : 5 );
                    break;
                case 'X':
                    value += (last == 'I' ? 8 : 10 );
                    break;
                case 'L':
                    value += (last == 'X' ? 30 : 50 );
                    break;
                case 'C':
                    value += (last == 'X' ? 80 : 100 );
                    break;
                case 'D':
                    value += (last == 'C' ? 300 : 500 );
                    break;
                case 'M':
                    value += (last == 'C' ? 800 : 1000 );
                    break;
                default:
                    break;
            }
            last = c;
        }
        return value;
    }
};