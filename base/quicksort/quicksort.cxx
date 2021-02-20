#include <iostream>
#include <vector>
#include <stack>

using namespace std;


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


int main() {
    vector<int> nums = {9, 3, 2, 7, 21, 32};
    quikSort(nums, 0, nums.size() - 1);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}