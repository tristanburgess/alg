#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence_dp(int n) {
  vector<int> sequence;
  vector<int> minOps;
  vector<int> prevs;

  minOps.push_back(0);
  prevs.push_back(0);

  for (int i = 1; i <= n; i++) {
    int x = i;
    minOps.push_back(std::numeric_limits<int>::max());
    prevs.push_back(0);

    if (x >= 1) {
      int res = minOps.at(i - 1) + 1;

      if (res < minOps.at(i)) {
        minOps.at(i) = res;
        prevs.at(i) = i - 1;
      }
    }

    if (x >= 2 && (x % 2 == 0)) {
      int res = minOps.at(i / 2) + 1;

      if (res < minOps.at(i)) {
        minOps.at(i) = res;
        prevs.at(i) = i / 2;
      }
    }

    if (x >= 3 && (x % 3 == 0)) {
      int res = minOps.at(i / 3) + 1;

      if (res < minOps.at(i)) {
        minOps.at(i) = res;
        prevs.at(i) = i / 3;
      }
    }
  }

  int y = n;
  while (y > 0) {
    sequence.push_back(y);
    y = prevs.at(y);
  }

  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_dp(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
