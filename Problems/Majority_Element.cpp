// bitwise solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maybe_majority = 0, count = 0;

        for (auto it : nums) {

            if (!count) {
                maybe_majority = it;
                count++;
            }
            else
            {
                if (maybe_majority == it) {
                    if (count++ > (nums.size()/2))
                        return maybe_majority;
                }
                else
                    count--;
            }
        }

        return maybe_majority;


    }
};