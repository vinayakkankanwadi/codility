#include <stack>
#include <string>

int solution(std::string &S) {
    std::stack<char> parentheses;

    for (char c : S) {
        if (c == '(') {
            parentheses.push(c);
        } else {
            if (parentheses.empty() || parentheses.top() != '(') {
                return 0; // Not properly nested
            }
            parentheses.pop(); // Match found for opening parenthesis
        }
    }

    // Check if all opening parentheses have been matched
    return parentheses.empty() ? 1 : 0;
}
