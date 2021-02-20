#include <iostream>

using namespace std;

long long binpow_1(long long a, long long b) {
    if(b == 0) return 1;
    long long ret = binpow_1(a, b / 2);
    cout << ret << endl;
    if(b % 2) {
        return ret * ret * a;
    }else {
        return ret * ret;
    }
}

long long binpow_2(long long a, long long b) {
    long long ret = 1;
    while(b > 0) {
        if(b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

int main() {
    cout << binpow_1(2, 8) << endl;
    cout << binpow_2(2, 8) << endl;
}