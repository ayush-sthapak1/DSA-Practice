// LC 1922: Count Good Numbers
// Approach: Math + Fast Exponentiation
// Time: O(log n) | Space: O(log n)

class Solution {
    public:
    const long long MOD = 1e9 + 7;

    long long power(long long x, long long n) {
        if (n == 0) return 1;
        long long half = power(x, n / 2);
        long long res = (half * half) % MOD;
        if (n % 2) res = (res * x) % MOD;
        return res;
    }


    int countGoodNumbers(long long n) {
        return (power(5, (n + 1) / 2) * power(4, n / 2)) % MOD;
    }
};