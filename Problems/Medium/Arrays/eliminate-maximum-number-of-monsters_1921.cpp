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
        // all of them.
        return dist.size();
    }
};




/*
https://leetcode.com/problems/eliminate-maximum-number-of-monsters/submissions/1093489124?envType=daily-question&envId=2023-11-07

Runtime
Details
111ms
Beats 54.67%of users with C++
Memory
Details
83.26MB
Beats 80.80%of users with C++

*/

class Solution {
  public:
    int eliminateMaximum(std::vector<int> &dist, std::vector<int> &speed) {
        std::vector<int> arrivalTimes(dist.size());

        // Calculate the arrival time for each monster.
        for (int i = 0; i < dist.size(); ++i) {
            // Ceiling of dist/speed to get the arrival time
            arrivalTimes[i] = (dist[i] + speed[i] - 1) / speed[i];
        }

        // Sort the arrival times.
        std::sort(arrivalTimes.begin(), arrivalTimes.end());

        // Try to eliminate each monster one by one.
        for (int i = 0; i < arrivalTimes.size(); ++i) {
            // If a monster arrives before or when we are eliminating, we can't
            // eliminate all.
            if (arrivalTimes[i] <= i) {
                return i; // The number of monsters eliminated before one
                          // reaches us.
            }
        }

        // If we've processed all monsters without returning, we can eliminate
        // all of them.
        return arrivalTimes.size();
    }
};
