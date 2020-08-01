//
// Created by Zhao on 2020/8/1.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        static const int INF = 1000005;
        set<pair<int,  pair<int, int>> > s;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i].resize(unique(nums[i].begin(), nums[i].end()) - nums[i].begin());
            s.emplace(*nums[i].begin(), make_pair(i, 0));
        }
        int st = -INF, ed = INF, mx = s.rbegin()->first;
        while (s.size() == nums.size()) {
            auto curr = *s.begin();
            s.erase(s.begin());
            if (mx - curr.first < ed - st) {
                ed = mx, st = curr.first;
            }
            if (curr.first != nums[curr.second.first].back()) {
                mx = max(mx, nums[curr.second.first][curr.second.second + 1]);
                s.emplace(nums[curr.second.first][curr.second.second + 1],
                          make_pair(curr.second.first, curr.second.second + 1));
            }
        }
        return vector<int>{st, ed};
    }
};

//int main() {
//    vector<vector<int>> test = {
//            {4,10,15,24,26},
//            {0,9,12,20},
//            {5,18,22,30}
//    };
//    auto ans = s.smallestRange(test);
//    cout << ans[0] << ' ' << ans[1] << endl;
//    return 0;
//}

/*
你有 k 个升序排列的整数数组。找到一个最小区间，使得 k 个列表中的每个列表至少有一个数包含在其中。

我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。

示例 1:

输入:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
输出: [20,24]
解释:
列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
注意:

给定的列表可能包含重复元素，所以在这里升序表示 >= 。
1 <= k <= 3500
-10^5 <= 元素的值 <= 10^5

 这个题可以当作合并k个链表来做，首先保存每个链表的头元素，也就是维护一个k大小的集和，这里用set维护，Ologn的时间确定最小元素，而后将该元素删除并将
 它的下一个元素放入set，在这个过程中对区间的大小进行更新。
 这样做的正确性在于，假设我们k个元素中最小的是来自于数组i的元素x，那么对于所有i_2≠i，区间长度最短的方式一定是分别取i_2中不小于x的最小值。
 而我们的set刚好维护了这k段序列的最小值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */