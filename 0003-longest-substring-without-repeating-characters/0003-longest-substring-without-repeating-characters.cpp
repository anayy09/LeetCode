class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int start = 0, end = 0, maxLength = 0;
        
        while (end < s.size()) {
            if (charSet.find(s[end]) == charSet.end()) {
                charSet.insert(s[end]);
                maxLength = max(maxLength, end - start + 1);
                end++;
            } else {
                charSet.erase(s[start]);
                start++;
            }
        }
        
        return maxLength;
    }
};