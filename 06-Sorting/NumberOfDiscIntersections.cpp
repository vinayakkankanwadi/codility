#include <vector>
#include <algorithm>

int solution(std::vector<int> &A) {
    int N = A.size();
    long long intersectingPairs = 0; // Count of intersecting pairs
    
    // Create vectors to store the left and right boundaries of each disc
    std::vector<long long> leftBoundaries(N, 0);
    std::vector<long long> rightBoundaries(N, 0);
    
    // Populate the left and right boundaries vectors
    for (int i = 0; i < N; ++i) {
        leftBoundaries[i] = i - A[i];
        rightBoundaries[i] = i + A[i];
    }
    
    // Sort the left and right boundaries vectors
    std::sort(leftBoundaries.begin(), leftBoundaries.end());
    std::sort(rightBoundaries.begin(), rightBoundaries.end());
    
    // Calculate the intersecting pairs using prefix sums
    int openDiscs = 0; // Count of open discs
    int j = 0; // Pointer for the right boundaries vector
    
    for (int i = 0; i < N; ++i) {
        while (j < N && rightBoundaries[j] < leftBoundaries[i]) {
            // Close a disc
            openDiscs--;
            j++;
        }
        // Count the number of intersecting pairs with the open discs
        intersectingPairs += openDiscs;
        
        // Increment the count of open discs
        openDiscs++;
    }
    
    // Check if the number of intersecting pairs exceeds the limit
    if (intersectingPairs > 10000000) {
        return -1;
    }
    
    return intersectingPairs;
}
