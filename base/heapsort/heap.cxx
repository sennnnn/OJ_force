#include <iostream>
#include <vector>

using namespace std;

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


int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    heapCreate(nums);
    heapSort(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}