# Problems Table

Below is a list of problems I've encountered and solved, organized by their complexity and topic for ease of reference and study.

![image](https://github.com/Dor-sketch/LeetCode-Solutions/assets/138825033/3215ba9c-d85f-4083-9763-c0e87b479f54)

---

## Part 1

| # | Level | Topic | Problem Name & Link | Solution Link | Extra Info |
|---|-------|-------|---------------------|---------------|------------|
| 1 | Medium | Linked List | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | [Solution](Medium/LinkedList/add-two-numbers_002.cpp) | <details><summary>Details</summary>Time Complexity: `O(max(m, n))` where `m` and `n` represent the lengths of the two non-empty linked lists.<br>Space Complexity: `O(max(m, n))` accounting for the new list.</details> |
| 2 | Medium | Arrays | [Last Moment Before All Ants Fall Out of a Plank](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/) | [Solution](Medium/Arrays/last-moment-before-all-ants-fall-out-of-a-plank_1503.cpp) | <details><summary>Details</summary>Time Complexity: `O(n)` - direct traversal.<br>Space Complexity: `O(1)` - no additional space utilized beyond variables.</details> |
| 3 | Medium | Arrays | [Find the Winner of an Array Game](https://leetcode.com/problems/find-the-winner-of-an-array-game/) | [Solution](Medium/Arrays/find-the-winner-of-an-array-game_1535.cpp) | <details><summary>Details</summary>Time Complexity: `O(n)` - a single traversal.<br>Space Complexity: `O(1)` - in-place with minimal variable usage.</details> |
| 4 | Medium | Arrays | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | [Solution](Medium/Arrays/remove-duplicates-from-sorted-array-ii.cpp) | <details><summary>Details</summary>Time Complexity: Solution 1: `O(n log n)` - set operations are logarithmic. Solution 2: `O(n log n)` - due to binary search.<br>Space Complexity: Solution 1: `O(n)` - set holds unique elements. Solution 2: `O(1)` - constant space.</details> |
| 5 | Medium | Arrays | [Rotate Array](https://leetcode.com/problems/rotate-array/) | [Solution](Medium/Arrays/rotate-array.cpp) | <details><summary>Details</summary>Time Complexity: `O(n)` - leveraging the mod operation for rotation.<br>Space Complexity: `O(1)` - in-place using C++ algorithms.</details> |
| 6 | Medium | Arrays | [Eliminate Maximum Number of Monsters](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/) | [Solution](Medium/Arrays/eliminate-maximum-number-of-monsters_1921.cpp) | <details><summary>Details</summary>Time Complexity: `O(n log n)` - sorting time.<br>Space Complexity: `O(1)` - in-place with transform operations.</details> |
| 7 | Medium | Strings | [Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings/) | [Solution](Medium/Strings/count-number-of-homogenous-substrings_1759.cpp) | <details><summary>Details</summary>Time Complexity: `O(n)` - Goes through each character of the string only once.<br>Space Complexity: `O(1)` - Fixed amount of space for variables and iterators.</details> |
| 8 | Medium | Design | [Seat Reservation Manager](https://leetcode.com/problems/seat-reservation-manager/) | [Solution](Medium/Design/seat-reservation-manager_1845.cpp) | <details><summary>Details</summary>Time Complexity: `O(n log n)` for setup, `O(log n)` for operations - due to priority queue management.<br>Space Complexity: `O(n)` - storage for seat management.</details> |
| 9 | Medium | Math | [Determine if a Cell is Reachable at a Given Time](https://leetcode.com/problems/determine-if-a-cell-is-reachable-with-exactly-k-jumps/) | [Solution](Medium/Math/determine-if-a-cell-is-reachable-with-exactly-k-jumps_1293.cpp) | <details><summary>Details</summary>Time Complexity: `O(1)` - Computation of Chebyshev distance and reachability check.<br>Space Complexity: `O(1)` - Constant space used for the calculation.</details> |
| 10 | Hard | Arrays | [Candy](https://leetcode.com/problems/candy/) | [Solution](Hard/Arrays/candy.cpp) | <details><summary>Details</summary>Time Complexity: `O(n)` - linear passes to distribute candies.<br>Space Complexity: `O(n)` - auxiliary space for left-to-right and right-to-left scans.</details> |
| 11 | Hard | Arrays | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | [Solution](Hard/Arrays/trapping-rain-water.cpp) | <details><summary>Details</summary>Time Complexity: `O(n)` - using the two-pointer technique.<br>Space Complexity: `O(1)` - constant space with pointers.</details> |

## Part 2 - downloaded via [LeetCode Downloader](download.py)!

| # | Problem | Solution | Difficulty | Tags |
| - | ------- | -------- | ---------- | ---- |
| 1 | [Best Time to Buy and Sell Stock II](https://leetcode.com/submissions/detail/1097876178/) | [Solution](Problems/Best_Time_to_Buy_and_Sell_Stock_II.cpp) | Easy | <details><summary>View Tags</summary>Arrays, Dynamic Programming</details> |
| 2 | [Sort Vowels in a String](https://leetcode.com/submissions/detail/1097813377/) | [Solution](Problems/Sort_Vowels_in_a_String.cpp) | Easy | <details><summary>View Tags</summary>String Manipulation</details> |
| 3 | [Best Time to Buy and Sell Stock](https://leetcode.com/submissions/detail/1096781122/) | [Solution](Problems/Best_Time_to_Buy_and_Sell_Stock.cpp) | Easy | <details><summary>View Tags</summary>Arrays, Dynamic Programming</details> |
| 4 | [Jump Game II](https://leetcode.com/submissions/detail/1098106616/) | [Solution](Problems/Jump_Game_II.cpp) | Medium | <details><summary>View Tags</summary>Dynamic Programming, Greedy, Arrays</details> |
| 5 | [Jump Game II](https://leetcode.com/submissions/detail/1098105174/) | [Solution](Problems/Jump_Game_II_1.cpp) | Medium | <details><summary>View Tags</summary>Dynamic Programming, Greedy, Arrays</details> |
| 6 | [Jump Game](https://leetcode.com/submissions/detail/1098073945/) | [Solution](Problems/Jump_Game.cpp) | Medium | <details><summary>View Tags</summary>Dynamic Programming, Greedy, Arrays</details> |
| 7 | [LRU Cache](https://leetcode.com/submissions/detail/1097928018/) | [Solution](Problems/LRU_Cache.cpp) | Hard | <details><summary>View Tags</summary>Design, Hash Table, Doubly-Linked List</details> |
| 8 | [LRU Cache](https://leetcode.com/submissions/detail/1097927495/) | [Solution](Problems/LRU_Cache_1.cpp) | Hard | <details><summary>View Tags</summary>Design, Hash Table, Doubly-Linked List</details> |
| 9 | [Bus Routes](https://leetcode.com/submissions/detail/1097114054/) | [Solution](Problems/Bus_Routes.cpp) | Hard | <details><summary>View Tags</summary>Graph, Breadth-First Search</details> |
| 10 | [Count Nodes Equal to Average of Subtree](https://leetcode.com/submissions/detail/1096795698/) | [Solution](Problems/Count_Nodes_Equal_to_Average_of_Subtree.cpp) | Medium | <details><summary>View Tags</summary>Tree, Depth-First Search</details> |