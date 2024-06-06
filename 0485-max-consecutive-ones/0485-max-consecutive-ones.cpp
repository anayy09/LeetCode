class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int currCnt = 0;
        
        for (int num : nums) {
            if (num == 1) {
                currCnt++;
                if (currCnt > maxCnt) {
                    maxCnt = currCnt;
                }
            } else {
                currCnt = 0;
            }
        }
        
        return maxCnt;
    }
};