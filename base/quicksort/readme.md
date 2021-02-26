# 快速排序

快速排序为通过设置枢纽元素, 使得数组中的元素通过大小关系被分割在枢纽元素的左右两边, 而后再对枢纽元素的左右子数组做同样的操作。

## 递归实现

```c++
void quikSort(vector<int>& nums, int begin, int end) {
    if(begin >= end) return;
    int length = nums.size();
    int key = nums[begin];
    int i = begin, j = end;
    while(i < j) {
        while(i < j && key > nums[j]) j--;
        if(i < j) {nums[i] = nums[j]; i++;}
        while(i < j && key < nums[i]) i++;
        if(i < j) {nums[j] = nums[i]; j--;}
    }
    cout << i << " " << j << endl;
    nums[i] = key;
    quikSort(nums, begin, i-1);
    quikSort(nums, i+1, end);
}
```

## 非递归实现

```c++
int partion_sort(vector<int>& nums, int begin, int end) {
    int i = begin, j = end, key = nums[begin];
    while(i < j) {
        while(i < j && key > nums[j]) j--;
        if(i < j) {nums[i] = nums[j]; i++;}
        while(i < j && key < nums[i]) i++;
        if(i < j) {nums[j] = nums[i]; j--;}
    }
    nums[i] = key;
    return i;
}


void quikSort_(vector<int>& nums) {
    int index, key;
    int begin = 0, end = nums.size() - 1;
    if(begin >= end) return;
    stack<int> index_stack;
    index_stack.push(end);
    index_stack.push(begin);
    while(!index_stack.empty()) {
        begin = index_stack.top(); index_stack.pop();
        end = index_stack.top(); index_stack.pop();
        index = partion_sort(nums, begin, end);
        if(begin < index - 1) {
            index_stack.push(index - 1);
            index_stack.push(begin);
        }
        if(end > index + 1) {
            index_stack.push(end);
            index_stack.push(index + 1);
        }
    }
}
```

## 时间复杂度分析

最优时间下: O(nlogn)  
平均时间下: O(nlogn)  
最差时间下: O(n^2)  

对于算法的时间复杂度应该有以下等式:  
<!-- $$
T(n) = T(i-1) + T(n-i) + cn
$$ --> 

<div align="center"><img style="background: white;" src="https://render.githubusercontent.com/render/math?math=T(n)%20%3D%20T(i-1)%20%2B%20T(n-i)%20%2B%20cn%0D"></div>

### 最好的情况

如果每次都能够恰好将序列分成两半, 那么此时的时间应该是最短的, 则上述等式化为:  
<!-- $$
T(n) = 2T(n/2) + cn
$$ --> 

<div align="center"><img style="background: white;" src="https://render.githubusercontent.com/render/math?math=T(n)%20%3D%202T(n%2F2)%20%2B%20cn%0D"></div>

而后求解递推:  
<!-- $$
\begin{split}
T(n) &= 2T(n/2) + cn\\
     &= 2(2T(n/4) + cn) + cn \\
     &= 2(2(T(n/8) + cn) + cn) + cn \\
     &= ......\\
     &= 2^kT(n/2^k) + kcn 
\end{split}
$$ --> 

<div align="center"><img style="background: white;" src="https://render.githubusercontent.com/render/math?math=%5Cbegin%7Bsplit%7D%0D%0AT(n)%20%26%3D%202T(n%2F2)%20%2B%20cn%5C%5C%0D%0A%20%20%20%20%20%26%3D%202(2T(n%2F4)%20%2B%20cn)%20%2B%20cn%20%5C%5C%0D%0A%20%20%20%20%20%26%3D%202(2(T(n%2F8)%20%2B%20cn)%20%2B%20cn)%20%2B%20cn%20%5C%5C%0D%0A%20%20%20%20%20%26%3D%20......%5C%5C%0D%0A%20%20%20%20%20%26%3D%202%5EkT(n%2F2%5Ek)%20%2B%20kcn%20%0D%0A%5Cend%7Bsplit%7D%0D"></div>

令 <!-- $n/2^k = 1$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=n%2F2%5Ek%20%3D%201">, 则可得 <!-- $k = \log_2n$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=k%20%3D%20%5Clog_2n">, 又知 <!-- $T(1) = 0$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=T(1)%20%3D%200"> 最终推出:  
<!-- $$
\begin{split}
T(n) &= 2^kT(n/2^k) + kcn \\
     &= 2^kT(1) + \log_2(n)cn \\
     &= \log_2(n)cn 
\end{split}
$$ --> 

<div align="center"><img style="background: white;" src="https://render.githubusercontent.com/render/math?math=%5Cbegin%7Bsplit%7D%0D%0AT(n)%20%26%3D%202%5EkT(n%2F2%5Ek)%20%2B%20kcn%20%5C%5C%0D%0A%20%20%20%20%20%26%3D%202%5EkT(1)%20%2B%20%5Clog_2(n)cn%20%5C%5C%0D%0A%20%20%20%20%20%26%3D%20%5Clog_2(n)cn%20%0D%0A%5Cend%7Bsplit%7D%0D"></div>

### 平均情况

平均情况下在基准元素左边的元素个数是无法确定的, 我们只好假定从 0~n 都是有可能的, 每一种情况的概率为 1/N, 则有:

<!-- $$
\begin{split}
T(n)  = \frac{2}{n}[\sum_{i=0}^{n-1}T(i)] + cn \\
nT(n) = 2sum_{i=0}^{n-1}T(i) + cn^2 \\
\end{split}
$$ --> 

<div align="center"><img style="background: white;" src="https://render.githubusercontent.com/render/math?math=%5Cbegin%7Bsplit%7D%0D%0AT(n)%20%20%3D%20%5Cfrac%7B2%7D%7Bn%7D%5B%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7DT(i)%5D%20%2B%20cn%20%5C%5C%0D%0AnT(n)%20%3D%202sum_%7Bi%3D0%7D%5E%7Bn-1%7DT(i)%20%2B%20cn%5E2%20%5C%5C%0D%0A%5Cend%7Bsplit%7D%0D"></div>

而后又可得:  
<!-- $$
(n-1)T(n-1) = 2\sum_{i=0}^{n-2}T(i) + c(n-1)^2
$$ --> 

<div align="center"><img style="background: white;" src="https://render.githubusercontent.com/render/math?math=(n-1)T(n-1)%20%3D%202%5Csum_%7Bi%3D0%7D%5E%7Bn-2%7DT(i)%20%2B%20c(n-1)%5E2%0D"></div>


将 <!-- $T(n-1) - T(n)$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=T(n-1)%20-%20T(n)">:  

<!-- $$
\begin{split}
    nT(n) = (n+1)T(n-1) + 2cn - c
\end{split}
$$ --> 

<div align="center"><img style="background: white;" src="https://render.githubusercontent.com/render/math?math=%5Cbegin%7Bsplit%7D%0D%0A%20%20%20%20nT(n)%20%3D%20(n%2B1)T(n-1)%20%2B%202cn%20-%20c%0D%0A%5Cend%7Bsplit%7D%0D"></div>

又有:  

<!-- $$
\frac{T(n)}{n+1} = \frac{T(n-1)}{n} + \frac{2c}{n+1}
$$ --> 

<div align="center"><img style="background: white;" src="https://render.githubusercontent.com/render/math?math=%5Cfrac%7BT(n)%7D%7Bn%2B1%7D%20%3D%20%5Cfrac%7BT(n-1)%7D%7Bn%7D%20%2B%20%5Cfrac%7B2c%7D%7Bn%2B1%7D%0D"></div>

递推下去得:  

<!-- $$
\begin{split}
&\frac{T(n)}{n+1} = \frac{T(n-1)}{n} + \frac{2c}{n+1} \\
&\frac{T(n)}{n+1} = \frac{T(n-1)}{n} + \frac{2c}{n+1} \\
&...... \\
&\frac{T(3)}{4} = \frac{T(2)}{3} + \frac{2c}{4} \\
&\frac{T(2)}{3} = \frac{T(1)}{2} + \frac{2c}{3} \\
&\end{split}
$$ --> 

<div align="center"><img style="background: white;" src="https://render.githubusercontent.com/render/math?math=%5Cbegin%7Bsplit%7D%0D%0A%26%5Cfrac%7BT(n)%7D%7Bn%2B1%7D%20%3D%20%5Cfrac%7BT(n-1)%7D%7Bn%7D%20%2B%20%5Cfrac%7B2c%7D%7Bn%2B1%7D%20%5C%5C%0D%0A%26%5Cfrac%7BT(n)%7D%7Bn%2B1%7D%20%3D%20%5Cfrac%7BT(n-1)%7D%7Bn%7D%20%2B%20%5Cfrac%7B2c%7D%7Bn%2B1%7D%20%5C%5C%0D%0A%26......%20%5C%5C%0D%0A%26%5Cfrac%7BT(3)%7D%7B4%7D%20%3D%20%5Cfrac%7BT(2)%7D%7B3%7D%20%2B%20%5Cfrac%7B2c%7D%7B4%7D%20%5C%5C%0D%0A%26%5Cfrac%7BT(2)%7D%7B3%7D%20%3D%20%5Cfrac%7BT(1)%7D%7B2%7D%20%2B%20%5Cfrac%7B2c%7D%7B3%7D%20%5C%5C%0D%0A%26%5Cend%7Bsplit%7D%0D"></div>

将上式相加:  

<!-- $$
\begin{split}
&\frac{T(n)}{n+1} = 2c(\frac{1}{3} + \frac{1}{4} + ...... + \frac{1}{n+1}) + \frac{T(1)}{2} \\
&T(n) = 2c(n+1)\sum_{i=3}^{n+1}\frac{1}{i} \\
&T(n) = 2c(n+1)(\log_e(N+1) + \gamma - \frac{3}{2}) \\
&T(n) = O(nlogn) \\
\end{split}
$$ --> 

<div align="center"><img style="background: white;" src="https://render.githubusercontent.com/render/math?math=%5Cbegin%7Bsplit%7D%0D%0A%26%5Cfrac%7BT(n)%7D%7Bn%2B1%7D%20%3D%202c(%5Cfrac%7B1%7D%7B3%7D%20%2B%20%5Cfrac%7B1%7D%7B4%7D%20%2B%20......%20%2B%20%5Cfrac%7B1%7D%7Bn%2B1%7D)%20%2B%20%5Cfrac%7BT(1)%7D%7B2%7D%20%5C%5C%0D%0A%26T(n)%20%3D%202c(n%2B1)%5Csum_%7Bi%3D3%7D%5E%7Bn%2B1%7D%5Cfrac%7B1%7D%7Bi%7D%20%5C%5C%0D%0A%26T(n)%20%3D%202c(n%2B1)(%5Clog_e(N%2B1)%20%2B%20%5Cgamma%20-%20%5Cfrac%7B3%7D%7B2%7D)%20%5C%5C%0D%0A%26T(n)%20%3D%20O(nlogn)%20%5C%5C%0D%0A%5Cend%7Bsplit%7D%0D"></div>

### 最差情况

即每次所有元素都被分割在了基准元素的一边:  

<!-- $$
\begin{split}
&T(n) = T(n-1) + cn \\
&T(n-1) = T(n-2) + cn \\
&T(n-2) = T(n-3) + cn \\
&... \\
&T(2) = T(1) + cn \\
\end{split}
$$ --> 

<div align="center"><img style="background: white;" src="https://render.githubusercontent.com/render/math?math=%5Cbegin%7Bsplit%7D%0D%0A%26T(n)%20%3D%20T(n-1)%20%2B%20cn%20%5C%5C%0D%0A%26T(n-1)%20%3D%20T(n-2)%20%2B%20cn%20%5C%5C%0D%0A%26T(n-2)%20%3D%20T(n-3)%20%2B%20cn%20%5C%5C%0D%0A%26...%20%5C%5C%0D%0A%26T(2)%20%3D%20T(1)%20%2B%20cn%20%5C%5C%0D%0A%5Cend%7Bsplit%7D%0D"></div>

可得: 

<!-- $$
\begin{split}
&T(n) = T(1) + cn^2 \\
&T(n) = cn^2 \\
&T(n) = O(n^2) \\
\end{split}
$$ --> 

<div align="center"><img style="background: white;" src="https://render.githubusercontent.com/render/math?math=%5Cbegin%7Bsplit%7D%0D%0A%26T(n)%20%3D%20T(1)%20%2B%20cn%5E2%20%5C%5C%0D%0A%26T(n)%20%3D%20cn%5E2%20%5C%5C%0D%0A%26T(n)%20%3D%20O(n%5E2)%20%5C%5C%0D%0A%5Cend%7Bsplit%7D%0D"></div>