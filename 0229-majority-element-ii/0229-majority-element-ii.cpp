class Solution {
public:
    vector<int> majorityElement(vector<int>& num) {
        int n = num.size();
        vector<int> ls;
        for (int i = 0; i < n; i++) {
            if (ls.size() == 0 || ls[0] != num[i]) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (num[j] == num[i]) {
                        cnt++;
                    }
                }
                if (cnt > (n / 3))
                    ls.push_back(num[i]);
            }
            if (ls.size() == 2) break;
        }
        return ls;
    }
};
