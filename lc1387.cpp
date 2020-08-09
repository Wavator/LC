//
// Created by Zhao on 2020/8/9.
//

class Solution {
public:
    unordered_map<int, int> dp;

    int dfs(int x) {
        if (dp[x] || x <= 1)
            return dp[x];
        return dp[x] = 1 + (x & 1? dfs(3 * x + 1): dfs(x >> 1));
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int, int> > vec;
        for (int i = lo; i <= hi; ++i) {
            vec.emplace_back(dfs(i), i);
        }
        nth_element(vec.begin(), vec.begin() + k - 1, vec.end());
        return vec[k - 1].second;
    }
};
//
//int main() {
//    auto s = new Solution();
//    vector<int> ans = {s->getKth(12, 15, 2), s->getKth(1, 1, 1), s->getKth(7, 11, 4),
//                       s->getKth(1, 1000, 777)};
//    for (auto &x: ans) {
//        cout << x << endl;
//    }
//    return 0;
//}