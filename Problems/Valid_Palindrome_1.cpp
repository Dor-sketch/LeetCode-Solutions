class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0, end = s.length()-1;

        while (begin < end)
        {
            while ((!isalnum(s[begin])) && (begin<end))
            {
                begin++;
            }
            if (begin == end){
                if (isalnum(s[begin]))
                    return true;
                else
                    return true;
            }
            while (!isalnum(s[end]))
            {
                end--;
            }
            if (tolower(s[begin])!=tolower(s[end]))
                return false;
            else {
                begin++;
                end--;
            }
        }
        return true;
        
    }
};