#include <iostream>

#define uint64_t unsigned long long

using std::cin;
using std::cout;

uint64_t GCD(uint64_t a, uint64_t b)
{
    if (b == 0) {
      return a;
    }

    return GCD(b, a % b);
}

uint64_t LCM(uint64_t a, uint64_t b) {
    return (a * b) / GCD(a, b);
}

int main() {
  uint64_t a, b;
  cin >> a >> b;
  cout << LCM(a, b) << std::endl;
  return 0;
}
