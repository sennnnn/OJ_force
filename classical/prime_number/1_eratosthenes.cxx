#include <iostream>
#include <vector>

using namespace std;


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


int main() {
    Solution object;
    int n = 150000;
    cout << object.countPrimes(n) << endl;
}