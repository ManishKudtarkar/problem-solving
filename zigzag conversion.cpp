class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: no zigzag needed
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        // Traverse each character and place it in the correct row
        for (char c : s) {
            rows[currentRow] += c;

            // Change direction at the top or bottom
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows to get the final result
        string result;
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};
