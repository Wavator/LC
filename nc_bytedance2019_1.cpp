//
// Created by Zhao on 2020/8/5.
//

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    static const int ADD = -INT16_MIN;
    vector<int> cnt(INT16_MAX - INT16_MIN + 1, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x + ADD]++;
    }
    int flush = sqrt(n);
    for (int i = 0; i < cnt.size(); ++i) {
        while (cnt[i]--) {
            cout << i - ADD << ' ';
        }
        if (i != 0 && i % flush == 0) {
            cout.flush();
        }
    }
    cout << endl;
    return 0;
}

/*
 输入：
 n<=一亿个short类型数字
 输出：
 排序后的n个数字

 例输入：
 6
 1 4 2 3 5 7
 输出：
 1 2 3 4 5 7

 思路：桶排序，时间O(n)，空间4*2^16=2^18bytes
 因为输入输出非常巨大，所以我给io解除绑定获取更快速度，并及时将缓冲区刷新到文件
 * */