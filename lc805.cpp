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
