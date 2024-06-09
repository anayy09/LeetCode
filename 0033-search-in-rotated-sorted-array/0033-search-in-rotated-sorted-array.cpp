class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lil = 0, big = nums.size() - 1;
        
        while (lil <= big) {
            int mid = lil + (big - lil) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[lil] <= nums[mid]) {
                if (nums[lil] <= target && target < nums[mid]) {
                    big = mid - 1;
                } else {
                    lil = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[big]) {
                    lil = mid + 1;
                } else {
                    big = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
