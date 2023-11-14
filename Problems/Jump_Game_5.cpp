class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::vector <bool> reachables(nums.size(), false);

        reachables[0] = true;

        int max_jump = 0;

        for (int i = 0 ; i<nums.size() ; ++i) {
            if (reachables[i]) {
                max_jump = std::max(max_jump, i + nums[i]);

                if (max_jump > nums.size()-1)
                    return true;

                for (int j = 1 ; j <= nums[i] ; j++)
                    reachables[i+j] = true;
            }
        }

        return reachables[reachables.size()-1];
    }
};