class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_ending_index = m - 1;
        int nums2_ending_index = n - 1;

        // Early return if nums2 is empty
        if (n == 0) {
            return;
        }

        for (int i = m + n - 1; i >= 0; i--) {
            if (nums1_ending_index >= 0 && (nums2_ending_index < 0 || nums1[nums1_ending_index] > nums2[nums2_ending_index])) {
                nums1[i] = nums1[nums1_ending_index--];
            } else {
                nums1[i] = nums2[nums2_ending_index--];
            }
        }
    }
};
