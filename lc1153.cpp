//
// Created by Zhao on 2020/8/8.
//

class Solution {
public:
    bool canConvert(string str1, string str2) {
        int n = str1.length();
        vector<int> last(128, 0);
        for (int i = 0; i < n; ++i) {
            if (last[str1[i]] == 0) {
                last[str1[i]] = str2[i];
            } else if (last[str1[i]] != str2[i]){
                return false;
            }
        }
        fill(last.begin(), last.end(), 0);
        for (auto&c: str2) {
            last[c - 'a'] = 1;
        }
        partial_sum(last.begin(), last.begin() + 26, last.begin());
        return last[25] != 26 || str1 == str2;
    }
};