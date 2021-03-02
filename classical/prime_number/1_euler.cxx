#include <iostream>
#include <vector>

using namespace std;


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


int main() {
    Solution object;
    int n = 150000;
    cout << object.countPrimes(n) << endl;
}