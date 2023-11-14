class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string sortVowels(string s) {
        vector<char> vowels;

        // Collect vowels
        for (char &c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
                c = ' ';
            }
        }

        if (!vowels.size())
            return s;

        // Sort vowels
        sort(vowels.begin(), vowels.end(), std::greater<int>());

        // Replace vowels in the original string
        std::size_t replace_index = 0;
        while (vowels.size() > 0) {
            replace_index = s.find_first_of(' ',replace_index);
            s[replace_index] = vowels.back();
            vowels.pop_back();
            replace_index++; 
        }

        return s;
    }
};
