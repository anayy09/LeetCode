class Solution {
public:
    double myPow(double x, int n) {
        long long num = n;
        if (num < 0) {
            x = 1 / x;
            num = -num;
        }
        
        double res = 1.0;
        while (num > 0) {
            if (num % 2 == 1) {
                res *= x;
            }
            x *= x;
            num /= 2;
        }
        
        return res;
    }
};
