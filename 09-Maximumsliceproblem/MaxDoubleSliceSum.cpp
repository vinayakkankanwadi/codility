#include <vector>
#include <algorithm>

int solution(std::vector<int> &A) {
    int N = A.size();
    std::vector<int> maxEndingHere(N, 0);
    std::vector<int> maxStartingHere(N, 0);

    // Compute the maximum sum ending at each position
    for (int i = 1; i < N - 1; ++i) {
        maxEndingHere[i] = std::max(0, maxEndingHere[i - 1] + A[i]);
    }

    // Compute the maximum sum starting at each position
    for (int i = N - 2; i > 0; --i) {
        maxStartingHere[i] = std::max(0, maxStartingHere[i + 1] + A[i]);
    }

    // Find the maximum sum of double slices
    int maxDoubleSliceSum = 0;
    for (int i = 1; i < N - 1; ++i) {
        maxDoubleSliceSum = std::max(maxDoubleSliceSum, maxEndingHere[i - 1] + maxStartingHere[i + 1]);
    }

    return maxDoubleSliceSum;
}
