# 堆排序

堆排序为利用堆的性质: 最小堆的根节点必定是全局最小, 最大堆的根节点必定是全局最大, 获取全局最值之后, 通过让其与叶子节点交换后, 剔除该节点, 然后再对剩余的节点进行调整以至达成最小堆或者最大堆这样一直反复取出保留下来的节点中的最值, 从而完成排序。

## 递归实现

```c++
void heapAdjust(vector<int>& nums, int i, int length) {
    // 递归式的最小堆建立的堆调整方式。
    int l = 2*(i+1) - 1;
    int r = 2*(i+1);
    int min_index = i;

    if(l < length && nums[min_index] > nums[l]) {
        min_index = l;
    }

    if(r < length && nums[min_index] > nums[r]) {
        min_index = r;
    }

    if(min_index != i) {
        int temp = nums[i];
        nums[i] = nums[min_index];
        nums[min_index] = temp;
        heapAdjust(nums, min_index, length);
    }
}


void heapCreate(vector<int>& nums) {
    int index = nums.size()/2 - 1;
    while(index >= 0) {
        heapAdjust(nums, index, nums.size());
        index--;
    }
}


void heapSort(vector<int>& nums) {
    int length = nums.size();
    for(int i = length - 1; i > 0; i--) {
        int temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;
        heapAdjust(nums, 0, i);
    }
}
```

## 非递归实现

```c++
void heapAdjust(vector<int>& nums, int i, int length) {
    // 非递归形式的最小堆建立的堆调整方式
    int l, r, min_index, temp;
    while(1) { 
        l = 2*i + 1;
        r = 2*i + 2;
        min_index = i;

        if(l < length && nums[min_index] > nums[l]) min_index = l;
        if(r < length && nums[min_index] > nums[r]) min_index = r;

        if(min_index != i) {
            temp = nums[min_index];
            nums[min_index] = nums[i];
            nums[i] = temp;
            i = min_index;
        }else break;
    }
}


void heapCreate(vector<int>& nums) {
    int index = nums.size()/2 - 1;
    while(index >= 0) {
        heapAdjust(nums, index, nums.size());
        index--;
    }
}


void heapSort(vector<int>& nums) {
    int length = nums.size();
    for(int i = length - 1; i > 0; i--) {
        int temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;
        heapAdjust(nums, 0, i);
    }
}
```