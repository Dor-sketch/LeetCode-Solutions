class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false; // Check for empty array
        if (nums.size() == 1) return true; // Single element array

        int max_jump = nums[0];

        for (int i = 1; (i <= min(static_cast<int>(nums.size()-1), max_jump)); ++i) {
            max_jump = std::max(max_jump, i + nums[i]);
        }

        return (max_jump >= nums.size() - 1);
    }
};
