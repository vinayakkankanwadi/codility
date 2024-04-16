#include <vector>

int solution(std::vector<int> &A) {
    int N = A.size();
    std::vector<int> peaks;

    // Find all the peaks
    for (int i = 1; i < N - 1; ++i) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            peaks.push_back(i);
        }
    }

    int numFlags = peaks.size();
    if (numFlags <= 1) {
        return numFlags; // Return the number of peaks if there are 1 or less peaks
    }

    // Try placing flags at different positions
    int maxFlags = 0;
    for (int i = 1; i <= numFlags; ++i) {
        int flagsPlaced = 1; // At least one flag is placed at the first peak
        int prevPeakIndex = peaks[0];
        for (int j = 1; j < numFlags; ++j) {
            if (peaks[j] - prevPeakIndex >= i) {
                flagsPlaced++;
                prevPeakIndex = peaks[j];
            }
        }
        if (flagsPlaced >= i) {
            maxFlags = i; // Update the maximum number of flags if the condition is satisfied
        } else {
            break; // No need to check further if the condition is not satisfied
        }
    }

    return maxFlags;
}