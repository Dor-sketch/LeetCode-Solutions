/*
https://leetcode.com/problems/trapping-rain-water/submissions/1094309791?envType=study-plan-v2&envId=top-interview-150

Runtime Details 7ms
Beats 93.12%of users with C++
Memory Details 20.02MB
Beats 74.27%of users with C++
*/

class Solution {
  public:
    int trap(vector<int> &height) {

        int cur_left = 0, max_left = 0, total_water = 0;
        int cur_right = height.size() - 1;
        int max_right = cur_right;

        // checking from both sides
        while (cur_left < cur_right) {
            if (height[cur_left] <
                height[cur_right]) // the left in the optimal solution
            {
                if (height[max_left] <= height[cur_left]) {
                    max_left = cur_left;
                } else {
                    total_water += height[max_left] - height[cur_left];
                }
                cur_left++;
            } else {
                if (height[max_right] <= height[cur_right]) {
                    max_right = cur_right;
                } else {
                    total_water += height[max_right] - height[cur_right];
                }
                cur_right--;
            }
        }
        return total_water;
    }

    int total_water_;
};