class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sorted_index=0;
        int cur_num;
        for(int i = 0 ; i< nums.size(); i++)
        {
            cur_num=nums[i];
            while ((i<nums.size()-1)&&cur_num==nums[i+1])
                i++;
        
            nums[sorted_index]=cur_num;
            sorted_index++;
        }
        
        return sorted_index;
    }
};