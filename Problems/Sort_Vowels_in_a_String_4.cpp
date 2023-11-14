class Solution {
public:
    string sortVowels(string s) {
        char lower_case;
        std::priority_queue<int,vector<int>,greater<int> >pq;
        pq.push('z');
        for (auto &letter : s) {
            lower_case = tolower(letter);
            // add A only if there other vowls before
            if ((lower_case == 'a' && pq.top()!='Z') || 
                (lower_case == 'e' || lower_case == 'i' ||
                 lower_case == 'o' || lower_case == 'u')) {
                    
                    pq.push(letter);
                    letter = ' ';
                }
        }
        std::size_t replace_index = 0;
        while (pq.top()!='z') {
            replace_index = s.find_first_of(' ',replace_index);
            s[replace_index] = pq.top();
            pq.pop();
            replace_index++; 
        }

        return s;
    }


};