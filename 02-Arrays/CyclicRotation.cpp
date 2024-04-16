#include <vector>

std::vector<int> solution(std::vector<int> &A, int K) {
    int N = A.size();
    
    // Handle the case where the array is empty
    if (N == 0)
        return A;

    std::vector<int> result(N);

    // Calculate the effective number of rotations
    int effectiveRotations = K % N;

    // If effective rotations are 0, return the original array
    if (effectiveRotations == 0)
        return A;

    // Perform rotation
    for (int i = 0; i < N; ++i) {
        int newPos = (i + effectiveRotations) % N;
        result[newPos] = A[i];
    }

    return result;
}