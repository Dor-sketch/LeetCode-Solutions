class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maybe_majority = 0, count = 0;

        for (auto it : nums) {
            if (count > (nums.size()/2))
                return maybe_majority;
            if (!count) {
                maybe_majority = it;
            }
            if (maybe_majority == it)
                count++;
            else
                count--;
        }

        return maybe_majority;
 
        
    }
};