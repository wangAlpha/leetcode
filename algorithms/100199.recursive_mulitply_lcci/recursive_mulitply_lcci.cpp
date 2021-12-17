class Solution {
public:
    void mul_iter(int n, int product, int &sum) {
        sum += product;
        if (n == 1) {
            return;
        }
        mul_iter(n - 1, product, sum ) ;
    }
    int multiply(int A, int B) {
        int sum = 0;
        if (A < B) {
            mul_iter(A, B, sum);
        } else {
            mul_iter(B, A, sum);
        }
        return sum;
    }
};