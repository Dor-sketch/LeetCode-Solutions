/*
https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/submissions/1094692016

Runtime
Details
0ms
Beats 100.00%of users with C++
Memory
Details
6.21MB
Beats 10.76%of users with C++

*/

class Solution {
  public:
    int getChebyshevDistance(std::pair<int, int> point1,
                             std::pair<int, int> point2) {
        int x_diff = std::abs(point2.first - point1.first);
        int y_diff = std::abs(point2.second - point1.second);
        return std::max(
            x_diff,
            y_diff); // Chebyshev distance is max of the absolute differences
    }

    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // Calculate the Chebyshev distance
        int chebyshevDistance = getChebyshevDistance({sx, sy}, {fx, fy});

        // If the Chebyshev distance is greater than the time, it's not possible
        // to reach the target
        if ((chebyshevDistance > t) || ((!chebyshevDistance) && (t == 1))) {
            return false;
        }

        // If the Chebyshev distance is less than or equal to the time, it's
        // possible to reach the target because you can always use extra steps
        // to adjust your position.
        return true;
    }
};