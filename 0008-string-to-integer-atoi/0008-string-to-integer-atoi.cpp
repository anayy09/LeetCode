class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int result = 0;
        int sign = 1;

        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};