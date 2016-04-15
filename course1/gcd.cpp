#include <iostream>

using std::cin;
using std::cout;

int GCDNaive(int a, int b)
{
    int best = 0;
    int n = a + b;
    for (int i = 1; i <= n; i++) {
      if (a % i == 0 && b % i == 0) {
        best = i;
      }
    }

    return best;
}

int GCDFast(int a, int b)
{
    if (b == 0) {
      return a;
    }

    return GCDFast(b, a % b);
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << GCDFast(a, b) << std::endl;
  return 0;
}
