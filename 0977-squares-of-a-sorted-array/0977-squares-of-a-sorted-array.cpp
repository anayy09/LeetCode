class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sqr;
        for (int i = 0 ; i < nums.size() ; i++) {
            sqr.push_back(nums[i] * nums[i]);
        }
        sort(sqr.begin(), sqr.end());
        return sqr;
    }
};