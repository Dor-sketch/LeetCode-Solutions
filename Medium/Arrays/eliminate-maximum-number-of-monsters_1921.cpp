/*

https://leetcode.com/problems/eliminate-maximum-number-of-monsters/submissions/1094419012




Runtime
Details
104ms
Beats 77.33%of users with C++
Memory
Details
81.35MB
Beats 95.73%of users with C++



https://leetcode.com/problems/eliminate-maximum-number-of-monsters/submissions/1094417853

Runtime
Details
111ms
Beats 55.20%of users with C++
Memory
Details
81.28MB
Beats 97.87%of users with C++


*/

class Solution {
  public:
    int eliminateMaximum(std::vector<int> &dist, std::vector<int> &speed) {

        // Use std::transform with a lambda function to calculate arrival times
        std::transform(dist.begin(), dist.end(), speed.begin(), dist.begin(),
                       [](int d, int s) { return (d + s - 1) / s; });

        // Sort the arrival times.
        std::sort(dist.begin(), dist.end());

        // Try to eliminate each monster one by one.
        for (int i = 0; i < dist.size(); ++i) {
            // If a monster arrives before or when we are eliminating, we can't
            // eliminate all.
            if (dist[i] <= i) {
                return i; // The number of monsters eliminated before one
                          // reaches us.
            }
        }

        // If we've processed all monsters without returning, we can eliminate
   