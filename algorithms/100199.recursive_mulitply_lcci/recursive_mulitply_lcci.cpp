class Solution {
public:
    int mul_iter(int n, int product, int sum) {
        return n == 1 ? sum : mul_iter(n - 1, product, sum + product) ;
    }
    int multiply(int A, int B) {
        return A < B ? mul_iter(A, B, B) : mul_iter(B, A, A);
    }
};