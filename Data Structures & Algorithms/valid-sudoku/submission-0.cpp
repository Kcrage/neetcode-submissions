class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<int> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (st.count(board[i][j])) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }

        for (int i = 0; i < 9; i++) {
            unordered_set<int> st;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (st.count(board[j][i])) {
                    return false;
                }
                st.insert(board[j][i]);
            }
        }

         vector<unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    continue;
                }

                int box = (i / 3) * 3 + (j / 3);

                if (boxes[box].count(board[i][j])) {
                    return false;
                }

                boxes[box].insert(board[i][j]);
            }
        }

        return true;

    }
};
