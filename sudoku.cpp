class Solution {
    
    bool lolu = false;
    vector<vector<char>> bc = vector<vector<char>>(9, vector<char>(9));

    bool isSolved(vector<vector<char>>& v) {
        for (int i = 0; i < 9; i++) {
            set<char> s;
            for (int j = 0; j < 9; j++) {
                if (v[i][j] == '.') continue;
                s.insert(v[i][j]);
            }
            if (s.size() != 9) return false;
        }
        for (int i = 0; i < 9; i++) {
            set<char> s;
            for (int j = 0; j < 9; j++) {
                if (v[j][i] == '.') continue;
                s.insert(v[j][i]);
            }
            if (s.size() != 9) return false;
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                set<char> s;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (v[i + k][j + l] == '.') continue;
                        s.insert(v[i + k][j + l]);
                    }
                }
                if (s.size() != 9) return false;
            }
        }
        return true;
    }

    bool notsolved(vector<vector<char>>& v) {
        for (int i = 0; i < 9; i++) {
            set<char> s;
            for (int j = 0; j < 9; j++) {
                if (v[i][j] == '.') continue;
                if (s.find(v[i][j]) != s.end()) return false;
                s.insert(v[i][j]);
            }
        }
        for (int i = 0; i < 9; i++) {
            set<char> s;
            for (int j = 0; j < 9; j++) {
                if (v[j][i] == '.') continue;
                if (s.find(v[j][i]) != s.end()) return false;
                s.insert(v[j][i]);
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                set<char> s;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (v[i + k][j + l] == '.') continue;
                        if (s.find(v[i + k][j + l]) != s.end()) return false;
                        s.insert(v[i + k][j + l]);
                    }
                }
            }
        }
        return true;
    }

    bool sudoku(vector<vector<char>>& v) {
        if (lolu) return true;
        if (isSolved(v)) {
            lolu = true;
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; j++) {
                    bc[i - 1][j - 1] = v[i - 1][j - 1];
                }
            }
            return true;
        }
        if (!notsolved(v)) {
            return false;
        }
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if (v[i - 1][j - 1] != '.') continue;
                for (int b = 1; b <= 9; b++) {
                    v[i - 1][j - 1] = b + '0'; 
                    if (sudoku(v) == true) return true;
                    v[i - 1][j - 1] = '.';
                }
                return false; 
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);
        if (lolu) {
            board = bc;
        }
    }
};
