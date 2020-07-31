//
// Created by Zhao on 2020/7/31.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int all_xor = 0;
        for (int &x: nums) {
            all_xor ^= x;
        }
        int test_bit = all_xor & -all_xor;
        vector<int> ans(2, 0);
        for (int &x: nums) {
            ans[(x & test_bit) ? 0 : 1] ^= x;
        }
        return ans;
    }
}s;

/*
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
 

限制：

2 <= nums.length <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 简单问题，一个数组内有2*n+1个数，其中n个数是成对出现的，找出多余的一个数
 这个问题直接把所有数异或起来就是答案了，因为相同值异或=0且异或满足交换律
 现在找两个怎么做，我们设数组size=n，那么2n-2个元素异或=0，对于二进制的每一位异或必然都是0
 所以整个数组的异或值就等于两个要求的答案的异或
 我们把两个答案的二进制表示不同的一位找出来，按照这一位对数组分类，也就是异或这一位等于0的或者1的
 这样分成两组，每一组都是奇数个元素，且一定把两个答案分在了不同组里，对这两个组进行上面提到的简单问题求解。
 实际上不需要额外空间保留某个数具体在哪组，分组的同时异或即可，空间O1，时间On
 * */