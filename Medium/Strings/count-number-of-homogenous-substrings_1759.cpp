/*
https://leetcode.com/problems/count-number-of-homogenous-substrings/submissions/1095153671?envType=daily-question&envId=2023-11-09

Runtime
Details
21ms
Beats 90.87%of users with C++
Memory
Details
11.98MB
Beats 85.65%of users with C++


*/

class Solution {
  public:
    static int findLastDup(const string &s, int left_index) {
        auto start = s.begin() + left_index;
        auto end = s.end();

        // Find the first character that is not equal to *start.
        auto non_match = std::find_if_not(
            start, end, [start](char c) { return c == *start; });

        // Calculate the distance from start to the first non-matching
        // character.
        return std::distance(start, non_match);
    }

    int countHomogenous(string s) {
        long long total_substrings = 0;

        for (int i = 0; i < s.length();) {
            int length = findLastDup(s, i);
            // Use the arithmetic series sum formula: n * (n + 1) / 2
            total_substrings += ((long long)length * (length + 1)) / 2;
            i += length; // Adjust i to skip the duplicate characters.
        }
        return (total_substrings % 1000000007);
    }
};
