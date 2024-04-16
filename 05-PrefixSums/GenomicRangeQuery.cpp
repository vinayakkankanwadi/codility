#include <vector>
#include <string>
#include <algorithm>

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
    int N = S.size();
    
    // Initialize prefix sums for nucleotide occurrences
    std::vector<std::vector<int>> prefix_sums(4, std::vector<int>(N + 1, 0));

    // Calculate prefix sums for nucleotide occurrences
    for (int i = 0; i < N; ++i) {
        char nucleotide = S[i];
        int nucleotide_index = 0;
        if (nucleotide == 'C') nucleotide_index = 1;
        else if (nucleotide == 'G') nucleotide_index = 2;
        else if (nucleotide == 'T') nucleotide_index = 3;

        // Update prefix sums for the current nucleotide
        for (int j = 0; j < 4; ++j) {
            prefix_sums[j][i + 1] = prefix_sums[j][i];
        }
        prefix_sums[nucleotide_index][i + 1]++;
    }

    int M = P.size();
    std::vector<int> result(M, 0);

    // Process each query
    for (int k = 0; k < M; ++k) {
        int start_index = P[k];
        int end_index = Q[k] + 1; // inclusive

        // Check the occurrences of each nucleotide within the query range
        for (int i = 0; i < 4; ++i) {
            int nucleotide_count = prefix_sums[i][end_index] - prefix_sums[i][start_index];
            if (nucleotide_count > 0) {
                // Found the minimal impact factor for this query
                result[k] = i + 1; // Convert index to impact factor
                break;
            }
        }
    }

    return result;
}