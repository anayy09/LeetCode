class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        int product = 1;
        for (int i = 0; i < n; i++) {
            prefix[i] = product;
            product *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            prefix[i] *= suffix;
            suffix *= nums[i];
        }
        return prefix;
    }
};