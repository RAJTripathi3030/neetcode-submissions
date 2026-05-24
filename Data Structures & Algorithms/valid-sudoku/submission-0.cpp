class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> rows(9);
        vector<vector<char>> cols(9);
        vector<vector<char>> boxes(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.') continue;

                if (find(rows[r].begin(), rows[r].end(), val) != rows[r].end()) return false;
                rows[r].push_back(val);

                if (find(cols[c].begin(), cols[c].end(), val) != cols[c].end()) return false;
                cols[c].push_back(val);

                int boxIdx = (r / 3) * 3 + (c / 3);
                if (find(boxes[boxIdx].begin(), boxes[boxIdx].end(), val) != boxes[boxIdx].end()) return false;
                boxes[boxIdx].push_back(val);
            }
        }
        return true;
    }
};