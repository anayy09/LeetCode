class Solution {
public:
    string reverseWords(string s) {
        vector<string> chunks;
        string gobble;

        for (size_t i = 0; i <= s.length(); ++i) {
            if (i == s.length() || s[i] == ' ') {
                if (!gobble.empty()) {
                    chunks.push_back(gobble);
                    gobble.clear();
                }
            } else {
                gobble += s[i];
            }
        }

        reverse(chunks.begin(), chunks.end());

        string spinner;
        for (size_t i = 0; i < chunks.size(); ++i) {
            if (i != 0) spinner += " ";
            spinner += chunks[i];
        }

        return spinner;
    }
};