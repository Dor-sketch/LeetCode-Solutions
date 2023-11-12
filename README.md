# LeetCode Solutions 🚀

Welcome to my LeetCode solutions repository! Here, I document my journey as a senior software engineering student, tackling algorithmic challenges and enhancing my problem-solving capabilities. As part of this journey, I've explored various algorithmic domains, including graph theory and its applications.

---

![image](https://github.com/Dor-sketch/LeetCode-Solutions/assets/138825033/3215ba9c-d85f-4083-9763-c0e87b479f54)

## Graph Algorithms: An Overview 🌐

Graph algorithms are a fundamental part of computer science, which I've explored and implemented in this repository. These algorithms are crucial for solving complex problems that involve network structures like social networks, computer networks, and biological networks. Below is a brief overview of some of the key graph algorithms and their applications, for examples see [main.cpp](Algorithms/main.cpp):

- **Depth-First Search (DFS)**: This algorithm traverses a graph deeply, exploring as far as possible along each branch before backtracking. It's used in solving puzzles, analyzing networks, and in game playing algorithms.

- **Breadth-First Search (BFS)**: This algorithm traverses a graph broadly, visiting all neighbors at the current depth level before moving to nodes at the next depth level. It's widely used in shortest path algorithms and in social networking applications for finding people within a certain number of steps from a person.

- **Dijkstra's Algorithm**: This is a famous algorithm for finding the shortest path between nodes in a weighted graph. It's widely used in GPS systems for finding the shortest driving route between locations.

- **Bellman-Ford Algorithm**: An algorithm that computes shortest paths from a single source vertex to all of the other vertices in a weighted graph. It's capable of handling graphs with negative weight edges.

- **Floyd-Warshall Algorithm**: A dynamic programming algorithm for finding shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles).

These algorithms are implemented in my repository, demonstrating my understanding of graph theory and its practical applications in solving real-world problems.

## Inside the Repository 📂

The repository is systematically organized by difficulty, each containing a subdivision by topics or data structures like so:

```plaintext
.
├── Easy/
│   ├── Arrays/
│   ├── Strings/
│   └── ...
├── Medium/
│   ├── LinkedList/
│   ├── Trees/
│   └── ...
└── Hard/
    ├── Graphs/
    ├── Dynamic Programming/
    └── ...
```

## Problems 🧩

Below is a list of problems I've encountered and solved, organized by their complexity and topic for ease of reference and study:

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

## Contributing 💡

Although this is a personal repository primarily for self-learning, feedback or improvement suggestions are welcome. Please open an issue or submit a pull request.

## License ⚖️

This project is open source and available under the [MIT License](LICENSE).
