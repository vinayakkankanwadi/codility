#include <vector>
#include <algorithm>

std::vector<int> solution(int N, std::vector<int> &A) {
    std::vector<int> counters(N, 0);
    int maxCounter = 0;
    int lastMaxCounter = 0;

    for (int num : A) {
        if (num >= 1 && num <= N) {
            // Increase operation
            counters[num - 1] = std::max(counters[num - 1], lastMaxCounter) + 1;
            maxCounter = std::max(maxCounter, counters[num - 1]);
        } else if (num == N + 1) {
            // Max counter operation
            lastMaxCounter = maxCounter;
        }
    }

    // Adjust the counters according to the lastMaxCounter
    for (int i = 0; i < N; ++i) {
        counters[i] = std::max(counters[i], lastMaxCounter);
    }

    return counters;
}
