# 面试经验中的 coding 题

* [1. 商汤 CV 算法实习生](https://www.nowcoder.com/discuss/434622?type=2&channel=-2&source_id=discuss_terminal_discuss_hot)
    * [斐波那契数列的 O(logn) 解法](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)  
        * [题解](1/fibonacci.cxx) 首先推导出斐波那契数列的转移矩阵, 而后使用矩阵快速幂来求解, [关于快速幂的解释](https://oi-wiki.org/math/quick-pow/)   
    * [只出现一次的数字](https://leetcode-cn.com/problems/single-number/)  
        * [题解](1/single_number.cxx) 直接遍历使用异或即可求得那唯一一个没有重复的数  
* [2. 算法面经：百度](https://www.nowcoder.com/discuss/350817)
    * [无序数组找到第k大的数](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)  
        * [题解](2/quiksort.cxx) 使用快速排序排序好之后, 取出第 K 大的值。  
        * [题解](2/hash.cxx) 使用无序 map 来做哈希表, 从最大的数开始往最小的数遍历, 直到累计第 K 大的数。  
* [3. 算法面经：字节跳动](https://www.nowcoder.com/discuss/350817)
    * [接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)
        * [题解](3/regular.cxx) 暴力方法, 检索每一个位置的左右两边界柱子, 根据边界柱子的高度即可计算得到该位置能够储存的雨水。  
        * [题解](3/storage.cxx) 暴力方法改进版本, 首先直接检索出每一个位置的左边界柱子和右边界柱子, 然后再遍历每一个位置的高度统计雨水量。  
        * [题解](3/double_pointer.cxx) 双指针法, 首先决定是左指针决定边界还是右指针决定计算基准高度, 而后维护左最高柱子, 和右最高柱子, 在维护的过程中计算储水量, 维护后也及时更新决定计算基准高度。  
        * [题解](3/stack.cxx) 栈配对法, 对于 height[i], 如果其小于栈顶元素则入栈, 如果其大于栈顶元素, 已知栈顶元素必然小于其前一个元素, 那么就可以构成凹陷囤积雨水, 让栈顶元素出栈之后计算栈顶元素所指位置的储水量后, 再进行下一次的栈顶元素与 height[i] 之间的大小判断。  
* [4. 商汤见习计算机视觉实习生](https://youngforest.github.io/2018/12/09/sensetime-intern-interview/)
    * [最长 01 子串](https://blog.csdn.net/SunnyYoona/article/details/41910519)
        * [题解](4/brute_force.cxx) 暴力方法, 统计每一个子串的 0, 1 个数来更新最大 01 子串长度。  
        * [题解](4/dp.cxx) 动态规划法, 通过统计从 0 到每一个下标 0, 1 个数差值, 通过对应两个下标 0, 1 个数差值相等, 可以得知两个下标之间的子串必然有相等的 0, 1 个数。  
    * [灯泡开关](https://leetcode-cn.com/problems/bulb-switcher/)
        * [题解](4/bulb.cxx) 可以将问题转化为求每一个位置的因子数, 因子数为奇数, 那么最后的状态为亮, 因子数为偶, 那么最后的状态为暗, 通过打表统计各个数的因子个数, 可以发现, 当 sqrt(x) 为整数时, 因子个数为奇数, 而当 sqrt(x) 不为整数时, 因子个数为偶数, 这主要是因为 sqrt(x) 为整数时, x 有两个相同的因子 -- sqrt(x), 而在统计时两个相同的因子只被统计为一个, 所以 sqrt(x) 只有奇数个因子, 那么只需要知道 n 以内有多少个 x 的 sqrt(x) 为整数就好了, 显然, 当 sqrt(n) 往下取整得到的整数 α, α^2 <= n, 则此时应该有 α 个开根号为整数的数, 那么则有 α 栈亮着的灯。  
    * [目标和](https://leetcode-cn.com/problems/target-sum/)
        * [题解](4/enumarate.cxx) 枚举法, DFS, 通过枚举所有的符号排列情况, 并统计满足要求的排列个数。  
        * [题解](4/sum_dp.cxx) 动态规划, 根据特性, 用 i 表示已经对几个符号进行选择, 用 j 表示带符号的求和值, 那么就有 dp[i][j] = dp[i-1][j-sum[i-1]] + dp[i-1][j+sum[i-1]] 这样的递推关系, 而后从小到大遍历带符号求和数的组成方案数, 从而得到结果。  
* [5. 商汤见习研究员实习面经](https://zhuanlan.zhihu.com/p/268025607?utm_source=qq&utm_medium=social&utm_oi=890533978682044416)
    * [开立方根](https://leetcode-cn.com/problems/sqrtx/)  
        * [题解](5/1_newton.cxx) 牛顿迭代法, 通过 x_n = x_(n-1) - (f(x_(n-1)) - C) / f'(x_(n-1)) 迭代来求解 x^3 - C = 0, 从而得到 C 的立方根。  
        * [题解](5/1_binary_search.cxx) 二分查找, 由于 C 的立方根, 必定小于 C, 那么 C 的立方根必定在边界 0 ~ C 之内, 所以在 0 ~ C 之内使用二分查找就可以得到结果。  
        * 类似题目: [Pow(x, n)](https://leetcode-cn.com/problems/powx-n/), [有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/), [平方数之和](https://leetcode-cn.com/problems/sum-of-square-numbers/)
    * [递增的三元组](https://leetcode-cn.com/problems/increasing-triplet-subsequence/)
        * [题解](5/2_doublepointer.cxx) 双指针遍历, 设置指针 small, mid 分别代指三元组中的最小那个元素和中间那个元素, 遍历的时候, 遍历到比 small 更小的元素则赋值给 small, 遍历到比 small 大, 但是比 mid 更小的元素则赋值给 mid, 如果比 small, mid 都大, 那么就满足条件得到递增的三元组。  
        * [题解](5/2_dp.cxx) 动态规划, 参考最大上升子序列的动态规划求解方法, 用 dp[i] 代表从 0 到 i 最长的递增子序列长度, 通过状态转移方程, dp[i] = max(dp[i], dp[j]+1) {j∈[0,i)} 来进行转移, 当存在 dp[i] >= 3 时, 则满足递增的三元组的条件。  
        * [题解](5/2_traversal.cxx) 前后遍历, 首先第一遍遍历得到 0 ~ i 的最小值, 而后第二遍遍历得到 n-1 ~ i 的最大值, 而后第三次遍历当满足 nums[i] > min[i] && nums[i] < max[i] 时, 必存在递增的三元组。  
        * 类似题目: [最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)