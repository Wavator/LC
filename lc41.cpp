//
// Created by Zhao on 2020/7/26.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        nums.push_back(nums.size() + 1);
        int n = nums.size();
        for (int &x: nums) {
            if (x <= 0) {
                x = n + 1;
            }
        }
        for (int x: nums) {
            if (abs(x) < n) {
                nums[abs(x)] = -abs(nums[abs(x)]);
            }
        }
        for (auto &x: nums) { cerr << x << ' '; }
        cerr << endl;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > 0) {
                return i;
            }
        }
        return n;
    }
};
//}s;
//
//int main() {
//    vector<int> test1 = {3,4,-1,1};
//    cout << s.firstMissingPositive(test1) << endl;
//    test1 = {1, 2, 3};
//    cout << s.firstMissingPositive(test1) << endl;
//    test1 = {1,0,3,3,0,2};
//    cout << s.firstMissingPositive(test1) << endl;
//    return 0;
//}

/*
给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

提示：

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-missing-positive
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 需要使用原来的数组维护一些东西，首先答案不可能比n+1大，数组的第i位表示数字i有没有出现过即可，所以先把<=0的数全变成正的，然后用负数
 表示这个数出现过。

 * */