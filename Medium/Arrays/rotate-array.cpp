/*
https://leetcode.com/problems/rotate-array/submissions/1093053459?envType=study-plan-v2&envId=top-interview-150

Runtime 17ms
Beats 89.62%of users with C++
Memory 25.29MB
Beats 77.99%of users with C++
*/

class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        if (k)
            std::rotate(nums.rbegin(), nums.rbegin() + (k % nums.size()),
                        nums.rend());
    }
};