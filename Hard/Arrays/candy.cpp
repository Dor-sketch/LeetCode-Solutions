/*
https://leetcode.com/problems/candy/submissions/1093379850?envType=study-plan-v2&envId=top-interview-150

Runtime
Details
14ms
Beats 79.70%of users with C++
Memory
Details
17.96MB
Beats 64.73%of users with C++

*/

class Solution {
  public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Start with one candy for each child

        // Left-to-Right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right-to-Left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Sum up the candies
        return accumulate(candies.begin(), candies.end(), 0);
    }
};