class Solution {
public:
    string sortVowels(string s) {
        // bubble sort?
        // linked list?
        char lower_case;
        std::priority_queue<int,vector<int>,greater<int> >pq;
        for (auto &letter : s) {
            lower_case = tolower(letter);
            if (lower_case == 'a' ||
                lower_case == 'e' ||
                lower_case == 'i' ||
                lower_case == 'o' ||
                lower_case == 'u') {
                    pq.push(letter);
                    letter = ' ';
                }
        }
        for (auto &final_letter : s) {
            if (final_letter == ' '){
                final_letter = pq.top();
                pq.pop();
            }
        }
        return s;
    }
};