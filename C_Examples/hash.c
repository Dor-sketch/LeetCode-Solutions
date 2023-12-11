/* This program finds the length of the longest consecutive sequence in an
 * unsorted array of integers.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)

 * It was originally written for leetcode problem 128
 (longest consecutive sequence)
 [https://leetcode.com/problems/longest-consecutive-sequence/]
 */

#include <stdio.h>
#include <stdlib.h>

// Node for the hash table
typedef struct hashNode {
  int key;
  struct hashNode *next;
} hashNode;

// Hash table operations
unsigned int hashFunction(int key, int tableSize) {
  return abs(key % tableSize);
}

void insert(hashNode **table, int key, int tableSize) {
  int index = hashFunction(key, tableSize);
  hashNode *newNode = (hashNode *)malloc(sizeof(hashNode));
  newNode->key = key;
  newNode->next = table[index];
  table[index] = newNode;
}

int search(hashNode **table, int key, int tableSize) {
  int index = hashFunction(key, tableSize);
  hashNode *temp = table[index];
  while (temp) {
    if (temp->key == key) {
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

void freeHashTable(hashNode **table, int tableSize) {
  for (int i = 0; i < tableSize; i++) {
    hashNode *temp = table[i];
    while (temp) {
      hashNode *toDelete = temp;
      temp = temp->next;
      free(toDelete);
    }
  }
  free(table);
}

void printHashTable(hashNode **table, int tableSize) {
  printf("Hash Table:\n");
  for (int i = 0; i < tableSize; i++) {
    printf("Slot %d: ", i);
    if (table[i] != NULL) {
      hashNode *node = table[i];
      // Iterate through the linked list at this table index
      while (node != NULL) {
        printf("Key: %d -> ", node->key);
        node = node->next;
      }
      printf("NULL\n"); // Indicate the end of the linked list
    } else {
      printf("Empty\n");
    }
  }
}

// Function to find longest consecutive sequence
int longestConsecutive(int *nums, int numsSize) {
  int tableSize = numsSize;
  hashNode **hashTable = (hashNode **)calloc(tableSize, sizeof(hashNode *));
  for (int i = 0; i < numsSize; i++) {
    insert(hashTable, nums[i], tableSize);
  }

  int maxLength = 0;
  for (int i = 0; i < numsSize; i++) {
    if (!search(hashTable, nums[i] - 1, tableSize)) {
      int currentNum = nums[i];
      int currentLength = 1;

      while (search(hashTable, currentNum + 1, tableSize)) {
        currentNum += 1;
        currentLength += 1;
      }

      maxLength = (currentLength > maxLength) ? currentLength : maxLength;
    }
  }

  freeHashTable(hashTable, tableSize);
  printHashTable(hashTable, tableSize);
  return maxLength;
}

int main() {
  int nums[] = {100, 4, 200, 1, 3, 2};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  printf("Length of the longest consecutive sequence is %d\n",
         longestConsecutive(nums, numsSize));
  return 0;
}
