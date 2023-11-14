class Solution {
public:
    static int findLastDup(const string& s, int left_index) {
        int right_index = left_index + 1; // Start with the next character.

        while (right_index < s.length() && s[left_index] == s[right_index]) {
            right_index++; // Increment right_index to find the last duplicate.
        }

        return right_index - left_index; // Return the count of duplicate characters.
    }

    int countHomogenous(string s) {
        long long total_substrings = 0; // Initialize to 0, to cover the empty string case

        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || s[i] != s[i - 1]) {
                int length = findLastDup(s, i);
                // Use the arithmetic series sum formula: n * (n + 1) / 2
                total_substrings += ((long long)length * (length + 1)) / 2;
                i += length - 1; // Adjust i to skip the duplicate characters.
            }
        }
        return (total_substrings % 1000000007);
    }
};
