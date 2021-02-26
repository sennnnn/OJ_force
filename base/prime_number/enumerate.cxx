#include <iostream>
#include <vector>

using namespace std;


bool checkIfPrime(int val) {
    bool flag = true;
    for(int i = 2; i*i <= val; i++) {
        if(val % i == 0) flag = false;
    }
    return flag;
}


class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(checkIfPrime(i)) count++;
        }
        return count;
    }
};


int main() {
    Solution object;
    int n = 10000;
    cout << object.countPrimes(n) << endl;
}