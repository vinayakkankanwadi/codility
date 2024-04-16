#include <cmath>

int solution(int X, int Y, int D) {
    int distance = Y - X;
    int jumps = distance / D; // Integer division truncates the decimal part
    if (distance % D != 0) { // If there is a remainder, one more jump is needed
        jumps++;
    }
    return jumps;
}