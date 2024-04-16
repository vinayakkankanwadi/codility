#include <math.h>

int solution(int A, int B, int K) {
    double k = K;
    return floor(B/k) - ceil(A/k) + 1;
}