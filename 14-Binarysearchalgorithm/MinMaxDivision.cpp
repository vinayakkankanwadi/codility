#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int calcNumBlocks(const vector<int>& A, int max_size) {
  int sum = 0, num_blocks = 1;
  for (int a : A) {
    sum += a;
    if (sum > max_size) {
      num_blocks++;
      sum = a;
    }
  }
  return num_blocks;
}

int solution(int K, int M, vector<int>& A) {
  int N = A.size();
  int lbound = *max_element(A.begin(), A.end());
  int ubound = accumulate(A.begin(), A.end(), 0);
  if (N == 1 || N <= K) return lbound;
  while (lbound <= ubound) {
    int mid = 0.5 * (lbound + ubound);
    int num_blocks = calcNumBlocks(A, mid);
    if (num_blocks <= K) {
      ubound = mid - 1;
    } else {
      lbound = mid + 1;
    }
  }
  return lbound;
}