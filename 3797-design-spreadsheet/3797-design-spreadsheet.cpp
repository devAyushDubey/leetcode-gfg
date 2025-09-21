vector<int> getCellIndex(string st) {
    int row = stoi(st.substr(1));
    int col = int(st[0]) - 65;
    return {row-1, col};
}
vector<string> resolveFormula(string st) {
    string frm = st.substr(1);
    int plusPos = frm.find('+');
    return {frm.substr(0,plusPos), frm.substr(plusPos+1)};
}
class Spreadsheet {
private:
    vector<vector<int>> sheet;
public:
    Spreadsheet(int rows) {
        int i = rows;
        while(i) {
            vector<int> v(26, 0);
            sheet.push_back(v);
            i--;
        }
    }
    
    void setCell(string cell, int value) {
        vector<int> coord = getCellIndex(cell);
        sheet[coord[0]][coord[1]] = value;
    }
    
    void resetCell(string cell) {
        vector<int> coord = getCellIndex(cell);
        sheet[coord[0]][coord[1]] = 0;
    }
    
    int getValue(string formula) {
        vector<string> terms = resolveFormula(formula);
        int valX;
        if(terms[0][0] >= 'A' && terms[0][0] <= 'Z') {
            vector<int> coord = getCellIndex(terms[0]);
            valX = sheet[coord[0]][coord[1]];
        }
        else {
            valX = stoi(terms[0]);
        }
        int valY;
        if(terms[1][0] >= 'A' && terms[1][0] <= 'Z') {
            vector<int> coord = getCellIndex(terms[1]);
            valY = sheet[coord[0]][coord[1]];
        }
        else {
            valY = stoi(terms[1]);
        }
        return valX + valY;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */