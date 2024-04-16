#include <vector>
#include <cmath>

std::vector<int> solution(int N, std::vector<int> &P, std::vector<int> &Q) {
    std::vector<int> semiprimes(N + 1, 0);
    std::vector<int> prefixSums(N + 1, 0);
    std::vector<int> result;

    // Find all semiprimes up to N
    for (int i = 2; i * i <= N; ++i) {
        if (semiprimes[i] == 0) { // Found a prime number
            for (int j = i * i; j <= N; j += i) {
                if (semiprimes[j] == 0) { // Mark j as a semiprime if not already marked
                    semiprimes[j] = i;
                }
            }
        }
    }

    // Compute prefix sums for the number of semiprimes up to each index
    for (int i = 1; i <= N; ++i) {
        prefixSums[i] = prefixSums[i - 1];
        if (semiprimes[i] != 0 && semiprimes[i / semiprimes[i]] == 0) {
            prefixSums[i]++;
        }
    }

    // Process queries
    int M = P.size();
    for (int i = 0; i < M; ++i) {
        result.push_back(prefixSums[Q[i]] - prefixSums[P[i] - 1]);
    }

    return result;
}
