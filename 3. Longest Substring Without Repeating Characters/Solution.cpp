class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string longest;
        string current;

        for (char c : s) {
            int pos = current.find(c);
            if (pos == string::npos) {
                current += c;
            } else {
                if (current.length() > longest.length()) {
                    longest = current;
                }
                current = current.substr(pos + 1, current.length());
                current += c;
            }
        }

        if (current.length() > longest.length()) {
            longest = current;
        }
        return longest.length();
    }
};