class Solution {
public:
    string sortVowels(string s) {
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
        std::size_t replace_index = 0;
        while (!pq.empty()) {
            replace_index = s.find_first_of(' ',replace_index);
            s[replace_index] = pq.top();
            pq.pop();
            replace_index++; 
        }

        return s;
    }


};