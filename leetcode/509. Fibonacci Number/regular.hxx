int iteration(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return iteration(n-1) + iteration(n-2);
}

class Solution {
public:
    int fib(int n) {
        return iteration(n);
    }
};