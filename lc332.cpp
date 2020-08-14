//
// Created by Zhao on 2020/8/14.
//

class Solution {
public:
    vector<string> ans;
    unordered_map<string, multiset<string>> g;
    void dfs(const string& u) {
        while (!g[u].empty()) {
            auto v = *g[u].begin();
            g[u].erase(g[u].begin());
            dfs(v);
        }
        ans.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const vector<string>&a: tickets) {
            g[a[0]].insert(a[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};