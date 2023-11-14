class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstOccurrence(26, -1), lastOccurrence(26, -1);
        int answer = 0;

        // Record the first and last occurrence of each character
        for(int i = 0; i < s.length(); i++) {
            if(firstOccurrence[s[i] - 'a'] == -1) firstOccurrence[s[i] - 'a'] = i;
            lastOccurrence[s[i] - 'a'] = i;
        }

        // Count distinct characters between first and last occurrence for each character
        for(int i = 0; i < 26; i++) {
            if(firstOccurrence[i] != -1) {
                unordered_set<char> middleChars;
                for(int j = firstOccurrence[i] + 1; j < lastOccurrence[i]; j++) {
                    middleChars.insert(s[j]);
                }
                answer += middleChars.size();
            }
        }

        return answer;
    }
};
