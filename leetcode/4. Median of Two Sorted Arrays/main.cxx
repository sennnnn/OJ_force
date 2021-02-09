#include <iostream>
#include "regular.hxx"

using namespace std;

int main(){
    Solution object;
    vector<int> a = {1};
    vector<int> b = {3};
    cout << object.findMedianSortedArrays(a, b) << endl;
}