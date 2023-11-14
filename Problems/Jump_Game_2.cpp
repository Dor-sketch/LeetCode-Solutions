class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false; // Check for empty array
        if (nums.size() == 1) return true; // Single element array

        int max_jump = nums[0];

        for (int i = 1; i < nums.size(); ++i) { // Start from 1 as 0 is always reachable
            if (i > max_jump) return false;

            max_jump = std::max(max_jump, i + nums[i]);
            if (max_jump >= nums.size() - 1) return true; // Early termination
        }

        return true;
    }
};
