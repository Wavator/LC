//
// Created by Zhao on 2020/7/18.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<long long> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp.back();
    }
}s;

/*
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * dp[i]表示i个点可以构成的二叉树个数
 * dp[0] = 1
 * dp[1] = 1
 * dp[2] = 2
 * dp[3] = 5......
 * dp[x] = sigma{i from 0 to x - 1}(dp[i] * dp[x - i - 1])
 * */

