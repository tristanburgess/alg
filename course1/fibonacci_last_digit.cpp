#include <iostream>

using std::cin;
using std::cout;

int FibLastDigit(int n)
{
  int* fibsLD = new int[n + 1];
  fibsLD[0] = 0;
  fibsLD[1] = 1;

  for (int i = 2; i <= n; i++) {
    fibsLD[i] = (fibsLD[i-1] + fibsLD[i-2]) % 10;
  }

  return fibsLD[n];
}

int main() {
    int n = 0;
    cin >> n;
    cout << FibLastDigit(n) << '\n';
    return 0;
}
