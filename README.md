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

Below is a list of problems I've tackled, categorized by difficulty and topic:

### Medium

- **Linked List**
  - Add Two Numbers ([Problem](https://leetcode.com/problems/add-two-numbers/), [Solution](Medium/LinkedList/add-two-numbers_002.cpp))
    - Time and Space Complexity: `O(max(m, n))` where `m` and `n` are the lengths of the two linked lists.
    - Note: The space complexity is for the output linked list. If we were to modify the input linked lists, we could achieve `O(1)` space complexity.

- **Arrays** 🧮
  - Last Moment Before All Ants Fall Out of a Plank ([Problem](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/), [Solution](Medium/Arrays/last-moment-before-all-ants-fall-out-of-a-plank_1503.cpp))
    - Time Complexity: `O(n)` - using a single pass through the array.
    - Space Complexity: `O(1)` - using a few extra variables for indices and counters.

  - Find the Winner of an Array Game ([Problem](https://leetcode.com/problems/find-the-winner-of-an-array-game/), [Solution](Medium/Arrays/find-the-winner-of-an-array-game_1535.cpp))
    - Space Complexity: `O(1)` using a few extra variables for indices and counters.
    - Time Complexity: `O(n)` using a single pass through the array.

  - Remove Duplicates from Sorted Array II ([Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/), [Solution](Medium/Arrays/remove-duplicates-from-sorted-array-ii.cpp))
    - Solution 1: Using C++ Set and Set Difference

      - Time Complexity: `O(n log n)` - using set_difference, which runs in linear time with respect to the number of elements in both input ranges, but the actual finding of differences requires binary searches internally.

      - Space Complexity: `O(n)` - using a set to store the unique elements.

    - Solution 2: Using Exponential Binary Search

      - Time Complexity: `O(n log n)` - using exponential search and binary search.

      - Space Complexity: `O(1)` - using only a few extra variables for indices and counters.

  - Rotate Array ([Problem](https://leetcode.com/problems/rotate-array/), [Solution](Medium/Arrays/rotate-array.cpp))
    - Time Complexity: `O(n)` leveraging the fact that for any `k` greater than `n`, `k % n` is equivalent to `k` rotations.
    - Space Complexity: `O(1)` using `std::rotate` from the `<algorithm>` library.

  - Eliminate Maximum Number of Monsters ([Problem](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/), [Solution](Medium/Arrays/eliminate-maximum-number-of-monsters_1921.cpp))
    - `O(n)` time solution using sorting
    - `O(n)` time solution using a priority queue
    - `O(1)` space complexity  using `std::transform` combined with `lambda functions`

- **Design** 🎨

  - Seat Reservation Manager ([Problem](https://leetcode.com/problems/seat-reservation-manager/), [Solution](Medium/Design/seat-reservation-manager_1845.cpp))
    - The construction of the SeatManager is O(n log n) time complexity and O(n) space complexity. The reserve and unreserve operations both have O(log n) time complexity due to the nature of the heap operations in the priority queue, and both have O(1) space complexity.

### Hard

- **Arrays** 🧮

  - Candy ([Problem](https://leetcode.com/problems/candy/), [Solution](Hard/Arrays/candy.cpp))
    - Soace and Time Complexity: `O(n)` using two passes through the array, two auxiliary arrays, and `std::accumulate` from the `<numeric>` library to sum the elements of the arrays.

  - Trapping Rain Water ([Problem](https://leetcode.com/problems/trapping-rain-water/), [Solution](Hard/Arrays/trapping-rain-water.cpp))
    - `O(n)` time complexity using two pointers
    - `O(1)` space complexity by tracking the maximum height of the left and right sides of the array without using an auxiliary array (dynamic programming approach).

## Contributing 💡

Although this is a personal repository primarily for self-learning, feedback or improvement suggestions are welcome. Please open an issue or submit a pull request.

## License ⚖️

This project is open source and available under the [MIT License](LICENSE).
