#include <vector>
#include <stack>

int solution(std::vector<int> &A, std::vector<int> &B) {
    int N = A.size();
    std::stack<int> downstreamFish;

    int aliveCount = 0;

    for (int i = 0; i < N; ++i) {
        if (B[i] == 1) { // Downstream fish
            downstreamFish.push(A[i]);
        } else { // Upstream fish
            while (!downstreamFish.empty()) {
                if (A[i] > downstreamFish.top()) {
                    downstreamFish.pop(); // Downstream fish eaten
                } else {
                    break; // Upstream fish survives
                }
            }

            if (downstreamFish.empty()) {
                ++aliveCount; // Upstream fish survives
            }
        }
    }

    return aliveCount + downstreamFish.size();
}
