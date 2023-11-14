class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int jumps = 0;
        int current_jump_end = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);
            
            if (i == current_jump_end) {
                jumps++;
                current_jump_end = farthest;
            }
        }

        return jumps;
    }
};
