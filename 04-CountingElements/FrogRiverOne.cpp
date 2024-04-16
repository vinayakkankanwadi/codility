#include <vector>
#include <unordered_set>
#include <limits>

int solution(int X, std::vector<int> &A) {
    size_t N = A.size(); // Use size_t for the vector size
    std::unordered_set<int> positions;

    // Initialize the earliest time to a large value
    int earliest_time = std::numeric_limits<int>::max();

    for (size_t i = 0; i < N; ++i) { // Use size_t for the loop index
        // Add the position of the leaf to the set
        positions.insert(A[i]);

        // Check if all positions from 1 to X are covered
        if (positions.size() == static_cast<size_t>(X)) { // Compare with size_t
            earliest_time = static_cast<int>(i); // Update the earliest time
            break;
        }
    }

    // If all positions are covered, return the earliest time
    if (positions.size() == static_cast<size_t>(X)) { // Compare with size_t
        return earliest_time;
    } else {
        return -1; // Otherwise, return -1
    }
}