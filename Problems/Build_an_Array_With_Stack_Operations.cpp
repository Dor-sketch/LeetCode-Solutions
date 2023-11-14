class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>operations;
        int cur_target = 0, cur_top = 1;
        for(auto it: target)
            {
                cur_target = it;
                for (cur_top; cur_top<cur_target; cur_top++) {
                    operations.push_back("Push");
                    operations.push_back("Pop");
                }
                operations.push_back("Push");
                cur_top++;
            }
        return operations;
        
    }

};