import random
from typing import List
import time


class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        def partition(arr, low, high):
            i = (low - 1)
            pivot = arr[high]

            for j in range(low, high):
                if arr[j] <= pivot:
                    i = i + 1
                    arr[i], arr[j] = arr[j], arr[i]

            arr[i + 1], arr[high] = arr[high], arr[i + 1]
            return (i + 1)

        def quickSelect(arr, low, high, k):
            if low < high:
                pivot_index = partition(arr, low, high)  # Partition the array
                if pivot_index == k:
                    return arr[pivot_index]
                elif pivot_index < k:
                    return quickSelect(arr, pivot_index + 1, high, k)
                else:
                    return quickSelect(arr, low, pivot_index - 1, k)
            return arr[k]


        n = len(piles)
        if (n >= 1):
            print(n)
            k = 1 * n // 3  # Position to find
            # Find the k-th largest element and partition the array
            quickSelect(piles,0,len(piles)-1, k)

            # Cut the list to keep only the top two-thirds
            piles = piles[k:]
            piles.sort()

            # Sum every second element from the cut array
            return sum(piles[i] for i in range(0, len(piles), 2))

        return sum(sorted(piles)[len(piles) // 3::2])


if __name__ == "__main__":
    #random input of numbers from 1 to 10^4 length 10^5
    input_list = [random.randint(1, 20) for i in range(12)]
    stat_time = time.time()
    solution = Solution()
    print(solution.maxCoins(input_list))
    end_time = time.time()
    print("time in ms:", (end_time - stat_time) * 1000)
