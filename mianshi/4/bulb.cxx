#include <iostream>
#include <math.h>

using namespace std;


class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};


int main() {
    Solution object;
    cout << object.bulbSwitch(10) << endl;
}