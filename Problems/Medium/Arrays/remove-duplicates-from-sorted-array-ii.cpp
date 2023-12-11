/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/submissions/1092102898?envType=study-plan-v2&envId=top-interview-150

Runtime Details 3ms
Beats 78.59%of users with C++
Memory Details 12.80MB
Beats 7.48%of users with C++
*/

// solution 1: using c++ set and set_difference
class Solution {
  public:
    int removeDuplicates(std::vector<int> &nums) {
        // Step 1: Create a set of unique numbers
        std::set<int> unique_nums(nums.begin(), nums.end());

        // Step 2: Determine non-unique numbers
        std::vector<int> all_unique_nums(unique_nums.begin(),
                                         unique_nums.end());
        std::vector<int> temp;
        std::set_difference(nums.begin(), nums.end(), all_unique_nums.begin(),
                            all_unique_nums.end(), std::back_inserter(temp));
        std::set<int> non_unique_nums(temp.begin(), temp.end());

        // Step 3: Create the result vector while maintaining the original order
        std::vector<int> result;
        for (int num : nums) {
            if (unique_nums.find(num) != unique_nums.end()) {
                result.push_back(num);
                unique_nums.erase(num);
            }
            if (non_unique_nums.find(num) != non_unique_nums.end()) {
                result.push_back(num);
                non_unique_nums.erase(num);
            }
        }

        nums = result;
        return nums.size();
    }
};





/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/submissions/1092267986?envType=study-plan-v2&envId=top-interview-150

Runtime Details 4ms
Beats 64.66%of users with C++
Memory Details 11.17MB
Beats 72.95%of users with C++
*/

// solution 2: using exponential binary search
class Solution {
  public:
    int exponentialBinarySearchEnd(std::vector<int> &nums, int start) {
        int step = 1;
        int lastMatchingIdx = start;

        // Exponential search
        while (start + step < nums.size() &&
               nums[start + step] == nums[start]) {
            lastMatchingIdx = start + step;
            step *= 2;
        }

        // Binary search between lastMatchingIdx and (start + step) or
        // nums.size()
        int left = lastMatchingIdx;
        int right = std::min(int(nums.size() - 1), start + step);
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == nums[start]) {
                lastMatchingIdx = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return lastMatchingIdx;
    }

    int removeDuplicates(std::vector<int> &nums) {
        if (nums.size() <= 2)
            return nums.size();

        int writeIdx = 0;

        for (int readIdx = 0; readIdx < nums.size();) {
            if (readIdx < nums.size() - 1 &&
                nums[readIdx] == nums[readIdx + 1]) {
                // Call the exponential binary search method only if a duplicate
                // is detected
                int endIdx = exponentialBinarySearchEnd(nums, readIdx);
                int occurrences = endIdx - readIdx + 1;
                int timesToWrite = std::min(occurrences, 2);

                for (int j = 0; j < timesToWrite; ++j) {
                    nums[writeIdx] = nums[readIdx];
                    ++writeIdx;
                }
                readIdx = endIdx + 1;
            } else {
                nums[writeIdx] = nums[readIdx];
                ++writeIdx;
                ++readIdx;
            }
        }

        nums.resize(writeIdx);
        return writeIdx;
    }
};