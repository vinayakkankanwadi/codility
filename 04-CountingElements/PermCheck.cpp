// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <unordered_set>

int solution(std::vector<int> &A) {
    int N = A.size();
    std::unordered_set<int> elements;

    // Iterate through the array
    for (int num : A) {
        // If the element is out of range or already exists in the set, return 0
        if (num < 1 || num > N || elements.find(num) != elements.end()) {
            return 0;
        }
        // Otherwise, add the element to the set
        elements.insert(num);
    }

    // If the size of the set matches the size of the array, return 1
    return (elements.size() == static_cast<size_t>(N)) ? 1 : 0;
}
