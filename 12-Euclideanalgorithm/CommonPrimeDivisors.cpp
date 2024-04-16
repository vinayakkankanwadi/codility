#include <vector>

int gcd(int x, int y) { // Greatest Common Divisor
    while (y) {
        x %= y;
        std::swap(x, y);
    }
    return x;
}

bool prime(int x, int y) { // Check for Prime
    while (x != 1) {
        int value = gcd(x, y);
        if (value == 1) break;
        x /= value;
    }
    return (x == 1);
}

int solution(std::vector<int>& A, std::vector<int>& B) {
    int result = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        int value = gcd(A[i], B[i]);
        if (prime(A[i], value) && prime(B[i], value)) {
            result++;
        }
    }
    return result;
}
