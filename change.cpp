#include <iostream>

int get_change(int n) {
  const int denomCnt = 3;
  int denominations[denomCnt] = {10, 5, 1};
  int coins = 0;

  for (int i = 0; i < denomCnt; ++i) {
    int denom = denominations[i];
    while (denom <= n) {
      n -= denom;
      ++coins;
    }
  }

  if (n > 0) {
    return -1;
  }

  return coins;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
