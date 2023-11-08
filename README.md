# LeetCode Solutions 🚀

Welcome to my LeetCode solutions repository! Here, I document my journey as a senior software engineering student, tackling algorithmic challenges and enhancing my problem-solving capabilities.

## What's Inside 📂

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

### Medium

- **Linked List**
  - Add Two Numbers: [Problem](https://leetcode.com/problems/add-two-numbers/) | [Solution](Medium/LinkedList/add-two-numbers_002.cpp)
    - **Time Complexity**: `O(max(m, n))` where `m` and `n` represent the lengths of the two non-empty linked lists.
    - **Space Complexity**: `O(max(m, n))` accounting for the new list.

- **Arrays** 🧮
  - Last Moment Before All Ants Fall Out of a Plank: [Problem](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/) | [Solution](Medium/Arrays/last-moment-before-all-ants-fall-out-of-a-plank_1503.cpp)
    - **Time Complexity**: `O(n)` - direct traversal.
    - **Space Complexity**: `O(1)` - no additional space utilized beyond variables.

  - Find the Winner of an Array Game: [Problem](https://leetcode.com/problems/find-the-winner-of-an-array-game/) | [Solution](Medium/Arrays/find-the-winner-of-an-array-game_1535.cpp)
    - **Time Complexity**: `O(n)` - a single traversal.
    - **Space Complexity**: `O(1)` - in-place with minimal variable usage.

  - Remove Duplicates from Sorted Array II: [Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | [Solution](Medium/Arrays/remove-duplicates-from-sorted-array-ii.cpp)
    - **Solution 1**: C++ Set
      - **Time Complexity**: `O(n log n)` - set operations are logarithmic.
      - **Space Complexity**: `O(n)` - set holds unique elements.

    - **Solution 2**: Exponential & Binary Search
      - **Time Complexity**: `O(n log n)` - due to binary search.
      - **Space Complexity**: `O(1)` - constant space.

  - Rotate Array: [Problem](https://leetcode.com/problems/rotate-array/) | [Solution](Medium/Arrays/rotate-array.cpp)
    - **Time Complexity**: `O(n)` - leveraging the mod operation for rotation.
    - **Space Complexity**: `O(1)` - in-place using C++ algorithms.

  - Eliminate Maximum Number of Monsters: [Problem](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/) | [Solution](Medium/Arrays/eliminate-maximum-number-of-monsters_1921.cpp)
    - **Time Complexity**: `O(n log n)` - sorting time.
    - **Space Complexity**: `O(1)` - in-place with transform operations.

- **Design** 🎨
  - Seat Reservation Manager: [Problem](https://leetcode.com/problems/seat-reservation-manager/) | [Solution](Medium/Design/seat-reservation-manager_1845.cpp)
    - **Time Complexity**: `O(n log n)` for setup, `O(log n)` for operations - due to priority queue management.
    - **Space Complexity**: `O(n)` - storage for seat management.

### Hard

- **Arrays** 🧮
  - Candy: [Problem](https://leetcode.com/problems/candy/) | [Solution](Hard/Arrays/candy.cpp)
    - **Time Complexity**: `O(n)` - linear passes to distribute candies.
    - **Space Complexity**: `O(n)` - auxiliary space for left-to-right and right-to-left scans.


  - Trapping Rain Water: [Problem](https://leetcode.com/problems/trapping-rain-water/) | [Solution](Hard/Arrays/trapping-rain-water.cpp)
    - **Time Complexity**: `O(n)` - using the two-pointer technique.
    - **Space Complexity**: `O(1)` - constant space with pointers.

## Contributing 💡

Although this is a personal repository primarily for self-learning, feedback or improvement suggestions are welcome. Please open an issue or submit a pull request.

## License ⚖️

This project is open source and available under the [MIT License](LICENSE).
