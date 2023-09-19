class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int, int> map1;
        for (int i = 0; i < nums.size(); i++) {
            map1[nums[i]]++;
            if (map1[nums[i]] > nums.size() / 2) {
                return nums[i];
            }
        }
        return 0;
    }
};