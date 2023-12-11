/*
https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/submissions/1091445730?envType=daily-question&envId=2023-11-04

Runtime Details 11ms
Beats 97.41%of users with C++
Memory Details 23.14MB
Beats 31.47%of users with C++
*/

#include <algorithm>
#include <vector>

class Solution {
  public:
    int getLastMoment(int n, const std::vector<int> &left,
                      const std::vector<int> &right) {
        return std::max(max_lhs(left), max_rhs(n, right));
    }

    // For the left-facing ants,
    // the maximum time taken is determined by the
    // position of the leftmost ant.
    int max_lhs(const std::vector<int> &lhs) {
        if (lhs.empty())
            return 0;
        return *std::max_element(lhs.begin(), lhs.end());
    }

    // For the right-facing ants,
    // the maximum time taken is determined by the
    // distance the rightmost ant has to cover,
    // which is the plank length minus its starting position.
    int max_rhs(int n, const std::vector<int> &rhs) {
        if (rhs.empty())
            return 0;
        return n - *std::min_element(rhs.begin(), rhs.end());
    }
};
