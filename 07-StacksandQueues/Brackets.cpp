#include <stack>
#include <string>

int solution(std::string &S) {
    std::stack<char> brackets;

    for (char c : S) {
        if (c == '(' || c == '{' || c == '[') {
            brackets.push(c);
        } else {
            if (brackets.empty()) {
                return 0; // Unmatched closing bracket
            }

            char top = brackets.top();
            brackets.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return 0; // Mismatched opening/closing brackets
            }
        }
    }

    return brackets.empty() ? 1 : 0;
}
