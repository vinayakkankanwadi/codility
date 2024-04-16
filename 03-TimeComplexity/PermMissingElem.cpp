#include <vector>

int solution(std::vector<int> &A) {
    long long sum_of_elements = 0; // Use long long to avoid integer overflow
    int N = A.size() + 1; // N is the size of the array + 1 (to include the missing element)

    // Calculate the sum of elements in the array
    for (int num : A) {
        sum_of_elements += num;
    }

    // Calculate the sum of integers from 1 to N
    long long expected_sum = static_cast<long long>(N) * (N + 1) / 2;

    // The missing element is the difference between the expected sum and the sum of elements in the array
    int missing_element = static_cast<int>(expected_sum - sum_of_elements);

    return missing_element;
}
