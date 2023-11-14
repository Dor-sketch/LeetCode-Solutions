class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>mins (nums.size(), INT_MAX);
        mins[0] = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; (j <= nums[i]); ++j) {
                if (j+i>nums.size()-1)
                    break;

                if ((mins[i]+1)<mins[i+j]) {
                    mins[i+j] = mins[i]+1;
                }
            }
        }
        return mins[nums.size()-1];   
    }
};