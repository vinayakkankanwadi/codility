long long int greatestCommonDivisor(long long int a, long long int b) {
    if ((a % b) == 0) {
        return b;
    }
    return greatestCommonDivisor(b, a%b);
}

// Defined in Codility Chapter 12 - Euclidean Algorithm (12.4)
long long int leastCommonMultiple(long long int a, long long int b) {

   return (a*b)/greatestCommonDivisor(a,b); 
}

int solution(int N, int M) {
    // Algorithm
    // Find Least Common Multiple of {N, M}
    // Answer is LCM/M
    
    long long int lcm = leastCommonMultiple(N, M);
    
    return lcm/M;
}