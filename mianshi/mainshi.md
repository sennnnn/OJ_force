# 面试经验中的 coding 题

* [1. 商汤 CV 算法实习生](https://www.nowcoder.com/discuss/434622?type=2&channel=-2&source_id=discuss_terminal_discuss_hot)
    * [斐波那契数列的 O(logn) 解法](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)  
    [题解](1/fibonacci.cxx) 首先推导出斐波那契数列的转移矩阵, 而后使用矩阵快速幂来求解, [关于快速幂的解释](https://oi-wiki.org/math/quick-pow/)
    * [只出现一次的数字](https://leetcode-cn.com/problems/single-number/)
    [题解](1/single_number.cxx) 直接遍历使用异或即可求得那唯一一个没有重复的数
* [2. 算法面经：百度](https://www.nowcoder.com/discuss/350817)
    * [无序数组找到第k大的数](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)
    [题解](2/quiksort.cxx) 使用快速排序排序好之后, 取出第 K 大的值。