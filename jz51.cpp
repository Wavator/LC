//
// Created by Zhao on 2020/7/29.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    inline int lower_bit(int x) {
        return x & (-x);
    }

    void add(vector<int>&a, int x, int add_val) {
        while (x < a.size()) {
            a[x] += add_val;
            x += lower_bit(x);
        }
    }

    int sum(const vector<int> &a, int x) {
        int res = 0;
        while (x) {
            res += a[x];
            x -= lower_bit(x);
        }
        return res;
    }

    int reversePairs(vector<int>& nums) {
        vector<int> a = nums;
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        for (int &x: nums) {
            x = int(lower_bound(a.begin(), a.end(), x) - a.begin() + 1);
        }
        int ans = 0;
        vector<int> sums(a.size() + 1, 0);
        reverse(nums.begin(), nums.end());
        for (int &x: nums) {
            ans += sum(sums, x - 1);
            add(sums, x, 1);
        }
        return ans;
    }
};

/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

 

示例 1:

输入: [7,5,6,4]
输出: 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 假设离散化后用[1, n]的桶记录每个数出现的次数，题目实际上就是快速查找对于x，[1, x - 1]的和，这样的前缀和可以用树状数组维护。
 而因为是要求对于i>j的a_i<a_j，所以逆向查询每个数字-1的前缀和，而后向树状数组中加入该数字

 * */