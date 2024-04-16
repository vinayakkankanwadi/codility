#include <vector>
#include <unordered_set>

int solution(std::vector<int> &A) {
    std::unordered_set<int> distinctValues;
    
    // Insert each element of array A into the set
    for (int num : A) {
        distinctValues.insert(num);
    }
    
    // Return the size of the set, which represents the number of distinct values
    return distinctValues.size();
}