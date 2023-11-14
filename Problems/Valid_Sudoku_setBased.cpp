class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int seenRows[9] = {0}, seenCols[9] = {0}, seenSquares[9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int val = c - '0'; // Convert char to int
                    int bit = 1 << val; // Bitmask for the digit

                    // Check row
                    if (seenRows[i] & bit) return false;
                    seenRows[i] |= bit;

                    // Check column
                    if (seenCols[j] & bit) return false;
                    seenCols[j] |= bit;

                    // Check square
                    int squareIndex = (i / 3) * 3 + j / 3;
                    if (seenSquares[squareIndex] & bit) return false;
                    seenSquares[squareIndex] |= bit;
                }
            }
        }
        return true;
    }
};
