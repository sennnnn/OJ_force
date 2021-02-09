#include <vector>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int flag = (nums1.size() + nums2.size()) % 2;
        int middle_index = (nums1.size() + nums2.size()) / 2 - !flag;
        double the_value;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]) {
                the_value = nums1[i];
                i++;
            }else {
                the_value = nums2[j];
                j++;
            }
            if((i + j - 1) == middle_index) {
                if(flag) return the_value;
                else {
                    if(i >= nums1.size()) return (the_value + nums2[j]) / 2.0;
                    else if(j >= nums2.size()) return (the_value + nums1[i]) / 2.0;
                    else return (the_value + (nums1[i] < nums2[j] ? nums1[i] : nums2[j])) / 2.0;
                }
            }
        }
        while(i < nums1.size()) {
            the_value = nums1[i];
            i++;
            if((i + j - 1) == middle_index) {
                if(flag) return the_value;
                else return (the_value + nums1[i]) / 2.0;
            }
        }
        while(j < nums2.size()) {
            the_value = nums2[j];
            j++;
            if((i + j - 1) == middle_index) {
                if(flag) return the_value;
                else return (the_value + nums2[j]) / 2.0;
            }
        }
        return 0;
    }
};