class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].length();
        int concatLength = words.size() * wordLength;
        vector<int> indices;

        if (s.length()<concatLength)
            return indices;



        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            ++wordCount[word];
        }

        // Only iterate through the first wordLength characters
        for (int i = 0; i < wordLength; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> seenWords;

            // Move the window in steps of wordLength
            for (int j = i; j <= s.length() - wordLength; j += wordLength) {
                string word = s.substr(j, wordLength);

                // Check if the word is part of 'words'
                if (wordCount.find(word) != wordCount.end()) {
                    ++seenWords[word];
                    ++count;

                    // Move the left pointer to keep the count in check
                    while (seenWords[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLength);
                        --seenWords[leftWord];
                        --count;
                        left += wordLength;
                    }

                    // If count equals the number of words, add to indices
                    if (count == words.size()) {
                        indices.push_back(left);
                        string leftWord = s.substr(left, wordLength);
                        --seenWords[leftWord];
                        --count;
                        left += wordLength;
                    }
                } else {
                    // Reset if the word is not in 'words'
                    seenWords.clear();
                    count = 0;
                    left = j + wordLength;
                }
            }
        }

        return indices;
    }
};
