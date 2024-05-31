#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; 

                int left = j + 1;
                int right = n - 1;
                long long target_sum = (long long)target - nums[i] - nums[j];

                while (left < right) {
                    long long two_sum = nums[left] + nums[right];
                    if (two_sum < target_sum) {
                        ++left;
                    } else if (two_sum > target_sum) {
                        --right;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right; 
                        ++left;
                        --right;
                    }
                }
            }
        }

        return result;
    }
};
