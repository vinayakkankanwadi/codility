#include <stack>
#include <vector>

int solution(std::vector<int> &H) {
    std::stack<int> blockHeights;
    int numBlocks = 0;

    for (int height : H) {
        // Remove blocks until we find a block with equal or smaller height
        while (!blockHeights.empty() && blockHeights.top() > height) {
            blockHeights.pop();
        }

        // If the stack is empty or the top block is higher, add a new block
        if (blockHeights.empty() || blockHeights.top() < height) {
            blockHeights.push(height);
            numBlocks++;
        }
    }

    return numBlocks;
}