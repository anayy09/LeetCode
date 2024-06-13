class Solution {
public:
    bool isValid(string s) {
        stack<char> funStack;
        unordered_map<char, char> bracketMap = {{')', '('}, {'}', '{'}, {']', '['}};

        for (char curChar : s) {
            if (bracketMap.find(curChar) != bracketMap.end()) {
                if (!funStack.empty() && funStack.top() == bracketMap[curChar]) {
                    funStack.pop();
                } else {
                    return false;
                }
            } else {
                funStack.push(curChar);
            }
        }
        return funStack.empty();
    }
};
