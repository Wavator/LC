//
// Created by Zhao on 2020/8/7.
//
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> g(n, vector<pair<int, double>>());
        for (int i = 0; i < edges.size(); ++i) {
            g[edges[i][0]].emplace_back(edges[i][1], log10(succProb[i]));
            g[edges[i][1]].emplace_back(edges[i][0], log10(succProb[i]));
        }
        vector<bool> vis(n, false);
        priority_queue<pair<double, int> > pq;
        pq.emplace(0, start);
        vector<double> distance(n, INT16_MIN);
        distance[start] = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (vis[top.second]) {
                continue;
            }
            vis[top.second] = true;
            for (auto &edge: g[top.second]) {
                if (top.first + edge.second > distance[edge.first]) {
                    distance[edge.first] = top.first + edge.second;
                    pq.emplace(top.first + edge.second, edge.first);
                }
            }
        }
        return distance[end] == INT16_MIN? 0: pow(10, distance[end]);
    }
};