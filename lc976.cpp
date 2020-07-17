//
// Created by Zhao on 2020/7/18.
//

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.rbegin(), A.rend());
        int n = A.size();
        for (int i = 0; i + 2 < n; ++i) {
            if (A[i] < A[i + 1] + A[i + 2]) {
                return A[i + 1] + A[i + 2] + A[i];
            }
        }
        return 0;
    }
};
/**
给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。

如果不能形成任何面积不为零的三角形，返回 0。
 3 <= A.length <= 10000
1 <= A[i] <= 10^6
 *
/