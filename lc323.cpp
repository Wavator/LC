//
// Created by Zhao on 2020/8/6.
//

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int> > g(n, vector<int>());
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        queue<int> q;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ++ans;
                vis[i] = true;
                q.push(i);
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    for (auto&y: g[x]) {
                        if (!vis[y]) {
                            vis[y] = true;
                            q.push(y);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
//
//
//int main() {
//    vector<vector<int>> test = {
//            {0, 1},
//            {1, 2},
//            {3, 4}
//    };
//    cout << s.countComponents(test.size(), test) << endl;
//    return 0;
//}

/*
 给定编号从 0 到 n-1 的 n 个节点和一个无向边列表（每条边都是一对节点），请编写一个函数来计算无向图中连通分量的数目。

示例 1:

输入: n = 5 和 edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4

输出: 2
示例 2:

输入: n = 5 和 edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

输出:  1
注意:
你可以假设在 edges 中不会出现重复的边。而且由于所以的边都是无向边，[0, 1] 与 [1, 0]  相同，所以它们不会同时在 edges 中出现。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-connected-components-in-an-undirected-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


 * */