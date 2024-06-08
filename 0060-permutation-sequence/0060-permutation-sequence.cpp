class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> nums;
        vector<int> fact(n, 1);

        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }

        for (int i = 1; i < n; ++i) {
            fact[i] = fact[i - 1] * i;
        }

        k--;

        for (int i = n; i > 0; --i) {
            int index = k / fact[i - 1];
            result.push_back('0' + nums[index]);
            nums.erase(nums.begin() + index);
            k %= fact[i - 1];
        }

        return result;
    }
};