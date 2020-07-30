//
// Created by Zhao on 2020/7/30.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef long long ll;
    vector<int> getMaxMatrix(vector<vector<int> >& matrix) {
        vector<int> ans(4, 0);
        int n = matrix.size(), m = matrix.back().size();
        vector<vector<ll> > pre_sum(n, vector<ll>(m, 0));
        for (int i = 0; i < m; ++i) {
            pre_sum[0][i] = matrix[0][i];
            for (int j = 1; j < n; ++j) {
                pre_sum[j][i] = pre_sum[j - 1][i] + matrix[j][i];
            }
        }
        ll max_sum = matrix[0][0];
        for (int i = 0; i < n; ++i) {
            for (int i_2 = i; i_2 < n; ++i_2) {
                long long curr_sum = 0;
                int pre_j = 0;
                for (int j = 0; j < m; ++j) {
                    if (i == 0) {
                        curr_sum += pre_sum[i_2][j];
                    } else {
                        curr_sum += pre_sum[i_2][j] - pre_sum[i - 1][j];
                    }
                    if (curr_sum > max_sum) {
                        max_sum = curr_sum;
                        ans = {i, pre_j, i_2, j};
                    }
                    if (curr_sum < 0) {
                        curr_sum = 0;
                        pre_j = j + 1;
                    }
                }
            }
        }
        return ans;
    }
}s;


//int main() {
//    vector<vector<int>> test = {
//            {9,  -8, 1,  3,  -2},
//            {-3, 7,  6,  -2, 4},
//            {6,  -4, -4, 8,  -7}
//    };
//    auto res = s.getMaxMatrix(test);
//    for (auto item: res) {
//        cout << item << ' ';
//    }
//    cout << endl;
//    return 0;
//}

/*
给定一个正整数和负整数组成的 N × M 矩阵，编写代码找出元素总和最大的子矩阵。

返回一个数组 [r1, c1, r2, c2]，其中 r1, c1 分别代表子矩阵左上角的行号和列号，
 r2, c2 分别代表右下角的行号和列号。若有多个满足条件的子矩阵，返回任意一个均可。

1 <= matrix.length, matrix[0].length <= 200

注意：本题相对书上原题稍作改动

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-submatrix-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
输入:
[
   [-1,0],
   [0,-1]
]
输出: [0,1,0,1]
解释: 输入中标粗的元素即为输出所表示的矩阵

 这个题目可以枚举i的上下界，同时确定j的范围。
 上下界可以枚举得到，j的范围的确定可以参考一维，一维问题是：On求出一维数组的连续子序列最大和，这个问题可以用
 dp[i] = max(dp[i - 1] + num[i], num[i]) 来表示
 看到这个式子就明白其实不需要dp数组（只需要存前一个dp值）,而且只需要判断dp[i-1]是不是小于0就可以了。。
 那么这个问题实际上变成了一样的，假设我在上下界确定的情况下，把每一列当成一个元素，就把这个二维问题转化成了一维
 同时我们需要快速知道，既然每一列的i行~i_2行被当成一个元素，那么这个元素的值是多少。
 因为我们现在已经三个for循环了，复杂度高达n*n*m,我们不可以再用Om的方式扫描求得这段元素的和，而是要用前缀和的方式做差求得。
 算法复杂度O(m*n^2),空间O(n*m)
 * */