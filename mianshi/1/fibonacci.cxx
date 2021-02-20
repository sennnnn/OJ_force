#include <iostream>

using namespace std;

void matrix_mul(long long m1[2][2], long long m2[2][2], long long product[2][2]) {
    long long temp[2][2];
    temp[0][0] = m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0];
    temp[1][0] = m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0];
    temp[0][1] = m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1];
    temp[1][1] = m1[1][0]*m2[0][1] + m1[1][1]*m2[1][1];
    product[0][0] = temp[0][0] % 1000000007;
    product[1][0] = temp[1][0] % 1000000007;
    product[0][1] = temp[0][1] % 1000000007;
    product[1][1] = temp[1][1] % 1000000007;
}

class Solution {
public:
    long long fib(long long n) {
        long long trans_matrix[2][2] = {{1, 1}, {1, 0}};
        long long init_matrix[2] = {1, 0};
        long long result[2];
        if(n == 0) return 0;
        if(n == 1) return 1;
        long long ret[2][2] = {{1, 0}, {0, 1}};
        n -= 2;
        while(n > 0) {
            if(n & 1) {
                matrix_mul(trans_matrix, ret, ret);
            }
            matrix_mul(trans_matrix, trans_matrix, trans_matrix);
            n >>= 1;
        }
        
        result[0] = init_matrix[0]*ret[0][0] + init_matrix[1]*ret[1][0];
        result[1] = init_matrix[0]*ret[0][1] + init_matrix[1]*ret[1][1];
        return (result[0] + result[1])%1000000007;
    }
};


int main() {
    int n;
    Solution object;
    // long long ret = object.fib(2);
    // cout << ret << endl;
    // cout << ret << endl;
    // cout << "result:" << object.fib(30) << endl;
    for(int i = 0; i < 30; i++) {
        cout << object.fib(i) << endl;
    }
}