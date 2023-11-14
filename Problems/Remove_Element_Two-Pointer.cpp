class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (val > 50) {
            return nums.size();  // If val is always more than 50, nums is unchanged, return 0.
        }
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }

        return k;  // k is the new length of the array without elements equal to val
    }
};