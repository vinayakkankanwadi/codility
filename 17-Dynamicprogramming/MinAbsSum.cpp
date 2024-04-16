
#include <algorithm>
#include <numeric>
#include <vector>
#include <numeric>

int solution(std::vector<int> &A) {
    const int N = A.size();
    if (N == 0)
        return 0;
   
    int MaxVal = 0;
    for (int i = 0; i < N; i++) {
        A[i] = abs(A[i]);
        MaxVal = std::max(MaxVal, A[i]);
    }

    const int Sum = std::accumulate(A.begin(), A.end(), 0);
    std::vector<int> count(MaxVal + 1, 0);
    for (int i = 0; i < N; i++)
        count[A[i]]++;

    std::vector<int> dp(Sum + 1, -1);
    dp[0] = 0;
    for (int a = 1; a <= MaxVal; a++) {
        if (count[a]>0) {
            for (int j = 0; j < Sum; j++) {
                if (dp[j] >= 0)
                    dp[j] = count[a];
                else if (j >= a && dp[j - a] > 0)
                    dp[j] = dp[j - a] - 1;
            }
        }
    }
    int result = Sum;
    for (int i = 0; i < Sum / 2 + 1; i++) {
        if (dp[i] >= 0)
            result = std::min(result, Sum - 2 * i);
    }

    return result;
}
