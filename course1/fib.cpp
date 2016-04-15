#include <iostream>

using std::cin;
using std::cout;

int FibNaive(int n)
{
    if (n <= 1) {
      return n;
    }

    return FibNaive(n-1) + FibNaive(n-2);
}

int FibFast(int n)
{
  int* fibs = new int[n + 1];
  fibs[0] = 0;
  fibs[1] = 1;

  for (int i = 2; i <= n; i++) {
    fibs[i] = fibs[i-1] + fibs[i-2];
  }

  return fibs[n];
}

int main() {
    int n = 0;
    cin >> n;
    cout << FibFast(n) << '\n';
    return 0;
}
