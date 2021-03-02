# 记录素数相关问题

## [1. 计数质数](https://leetcode-cn.com/problems/count-primes/solution/ji-shu-zhi-shu-by-leetcode-solution/)

### 枚举法

要判断 x (x ≠ 1) 是否为 y 的因数, 那么就要判断 y/x 是否为整数, x 与 y/x 要么同时为整数, 要么同时为分数, 当 x 与 y/x 同时为整数时, 那么 y 就存在非 1 以外的因数, y 就不是素数, 反之则是素数。

```c++
bool checkIfPrime(int val) {
    int flag = true;
    int boundry = sqrt(val);
    for(int i = 2; i <= boundry; i++) {
        if(val % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}


class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(checkIfPrime(i)) {
                count++;
            }
        }
        return count;
    }
};
```

### 埃氏筛

如果 x 为质数的话, 那么 2x, 3x, 4x,... 一定不是质数, 基于这样的前提, 我们通过一个 ifPrime 数组来打表, 记录一个数是否为素数, 从小到大遍历每一个数, 如果这个数是素数, 那么就从该数开始向后遍历将该数的所有倍数都判定为合数, 如果是合数则跳过, 通过 ifPrime 置 1 判定为素数, 置 0 判定为合数, 最后再遍历 ifPrime 统计素数个数。

```c++
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> ifPrime(n, 1);
        int count = 0;
        for(long long i = 2; i < n; i++) {
            if(ifPrime[i]) {
                count++;
                for(long long j = i*i; j < n; j+=i) {
                    ifPrime[j] = 0;
                }
            }
        }
        return count;
    }
};
```

### 欧拉筛

考虑到埃氏筛的时候, 合数在存在多个因子的情况下, 会被反复标记, 为了保证每个合数只被标记一次, 通过额外使用一个 Prime 向量来保存当前迭代到每个数得到的素数集合, 依然定义 ifPrime 数组来标记每个数是否为素数, 对于 x, 如果为素数, 将其保存到 Prime 向量中, 而后无论是素数还是非素数, 都将其与素数集合 Prime 向量中的各个素数相乘, 标记 x\*Prime[0], x\*Prime[1],x\*Prime[2], ..., 直至 x % Prime[j] == 0, 则停止标记, 这是因为 x \* Prime[j+1] 必然会在遍历到 y = x / Prime[j] \* Prime[j+1] 时被 y \* Prime[j] 标记, 这就保证了每个合数只被最小的质因数筛去。

```c++
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> ifPrime(n, 1);
        vector<int> Prime;
        for(int i = 2; i < n; i++) {
            if(ifPrime[i]) {
                Prime.push_back(i);
            }
            for(int j = 0; j < Prime.size() && i * Prime[j] < n; j++) {
                ifPrime[i * Prime[j]] = 0;
                if(i % Prime[j] == 0) break;
            }
        }
        return Prime.size();
    }
};
```