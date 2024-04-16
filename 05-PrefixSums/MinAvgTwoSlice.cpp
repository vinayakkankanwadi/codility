#include <vector>
#include <limits>

int solution(std::vector<int> &A) {
    int N = A.size();
    double min_avg = std::numeric_limits<double>::max();
    int min_avg_index = 0;

    // Iterate through the array to find the minimal average slice
    for (int i = 0; i < N - 1; ++i) {
        // Check slices of length 2
        double avg_2 = (A[i] + A[i + 1]) / 2.0;
        if (avg_2 < min_avg) {
            min_avg = avg_2;
            min_avg_index = i;
        }

        // Check slices of length 3
        if (i < N - 2) {
            double avg_3 = (A[i] + A[i + 1] + A[i + 2]) / 3.0;
            if (avg_3 < min_avg) {
                min_avg = avg_3;
                min_avg_index = i;
            }
        }
    }

    return min_avg_index;
}
