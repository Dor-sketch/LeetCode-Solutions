/*
https://leetcode.com/problems/find-the-winner-of-an-array-game/submissions/1092061156

Runtime Details 75ms
Beats 92.59%of users with C++
Memory Details 63.36MB
Beats 86.11%of users with C++
*/

class Solution {
  public:
    int getWinner(vector<int> &arr, int k) {

        // if the biggest element in the array is stored at the beginnig it will
        // always win
        if (k >= arr.size() ||
            arr[0] == *std::max_element(std::begin(arr), std::end(arr)))
            return *std::max_element(std::begin(arr), std::end(arr));

        int currWinner = arr[0];
        int consecutiveWins = 0;

        for (size_t i = 1; i < arr.size(); i++) {
            if (consecutiveWins == k) {
                return currWinner;
            }
            if (currWinner > arr[i]) {
                consecutiveWins++;
            } else {
                currWinner = arr[i];
                consecutiveWins = 1;
            }
        }
        // If loop finishes and no winner is found, then the currWinner
        // is the overall winner since it has beaten all other numbers.
        return currWinner;
    }
};