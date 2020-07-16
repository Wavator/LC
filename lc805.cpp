//
// Created by Zhao on 2020/7/16.
//
#include <bits/stdc++.h>
using namespace std;
class lc805 {
public:
    bool splitArraySameAverage(vector<int> &A) {
        int n = A.size();
        int ln = n / 2, rn = n - ln;
        int sum = 0;
        for (int &x: A) {
            x *= n;
            sum += x;
        }
        int avg = sum / n;
        for (int &x: A) {
            x -= avg;
        }
        multiset<int> st;
        for (int i = 0; i < (1 << ln); ++i) {
            int s = 0;
            for (int k = 0; k < ln; ++k) {
                if (i & (1 << k)) {
                    s += A[k];
                }
            }
            st.insert(s);
        }
        int ok = 0;
        for (int i = 0; i < (1 << rn); ++i) {
            int s = 0;
            for (int k = 0; k < rn; ++k) {
                if (i & (1 << k)) {
                    s += A[k + ln];
                }
            }
            ok += st.count(-s);
        }
        return ok > 2;
    }
};
/*
 * 给定的整数数组 A ，我们要将 A数组 中的每个元素移动到 B数组 或者 C数组中。（B数组和C数组在开始的时候都为空）

返回true ，当且仅当在我们的完成这样的移动后，可使得B数组的平均值和C数组的平均值相等，并且B数组和C数组都不为空。
A 数组的长度范围为 [1, 30].
A[i] 的数据范围为 [0, 10000].
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-with-same-average
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 做法：折半查找:
 sum(A) / size(A) = sum(B) / size(B) + sum(C) / size(C)
 size(C)= size(A) - size(B)
 avg(B) == avg(C) => sum(B) * (size(A) - size(B)) == sun(C) * (size(B)) => sum(B) * size(A) == sum(A) * size(B)
 => avg(B) == avg(A)
 所以同时将A中元素减去平均值，就变成了找一个大小不为0且不为size(A)的集和使其和为0
 注意A的范围为30，明显不可以指数暴力，但是可以把30对半分，在前面size(A) / 2 个元素里枚举所有的和，用multiset（或map）存储，
 后面size(A) - size(A) / 2个元素中枚举所有的和，在multiset(map)中查找有几个相反数，记录。
 如果总和大于2（因为两个空集+全集算进去了），则true，否则false

 * */
