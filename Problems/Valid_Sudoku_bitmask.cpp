// set solution with helper function
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char>column;
        for (int i = 0; i <9; i++){
            // check rows
            if (areDigitsUniqueAndValid(board[i])==false) {
                return false;
            }
            // check columns
            column.clear();
            for (int j = 0; j < 9; j++) {
                column.push_back(board[j][i]);
            }
            if (!areDigitsUniqueAndValid(column)) {
                return false;
            }

            //check squares
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    vector<char> square;
                    for (int row = 0; row < 3; row++) {
                        for (int col = 0; col < 3; col++) {
                            char val = board[i * 3 + row][j * 3 + col];
                            square.push_back(val);
                        }
                    }
                    if (!areDigitsUniqueAndValid(square)) {
                        return false;
                    }
                }
            }

        }
        return true;
    }



    bool areDigitsUniqueAndValid(const vector<char>& numbers) {
        set<char> uniqueDigits;
        for (char it : numbers) {
            if ((it < '1' || it > '9') && it != '.') {
                return false;
            }
            if (it != '.') {
                if (uniqueDigits.find(it) != uniqueDigits.end()) {
                    return false;  // Digit already exists in the set.
                }
                uniqueDigits.insert(it);
            }
        }
        return true;
    }

};