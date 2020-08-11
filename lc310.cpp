//
// Created by Zhao on 2020/8/11.
//
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<vector<int>> g(n);
        vector<int> degree(n, 0);
        for (auto &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
            ++degree[edge[0]];
            ++degree[edge[1]];
        }
        vector<int> q, curr_q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push_back(i);
            }
        }
        int remains = n;
        while (remains > 2) {
            remains -= q.size();
            curr_q.clear();
            for (int u: q) {
                for (int v: g[u]) {
                    --degree[v];
                    if (degree[v] == 1) {
                        curr_q.push_back(v);
                    }
                }
            }
            q.swap(curr_q);
        }
        return q.empty() ? vector<int>{0} : q;
    }
};