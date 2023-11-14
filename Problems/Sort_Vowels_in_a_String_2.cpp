class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string sortVowels(string s) {
        vector<char> vowels;
        // Collect vowels
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        // Sort vowels
        sort(vowels.begin(), vowels.end());

        // Replace vowels in the original string
        int index = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (isVowel(s[i])) {
                s[i] = vowels[index++];
            }
        }

        return s;
    }
};
