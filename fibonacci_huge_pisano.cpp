#include <iostream>
#include <vector>

#define uint64_t unsigned long long

using std::vector;
using std::cin;
using std::cout;

int FibHuge(uint64_t n, int m)
{
  vector<int> fibMods;
  fibMods.push_back(0);
  fibMods.push_back(1);

  int piPisano = 2;

  while (true) {
    fibMods.push_back((fibMods.at(piPisano - 1) + fibMods.at(piPisano - 2)) % m);

    if (fibMods.at(piPisano-1) == 0 && fibMods.at(piPisano) == 1) {
      --piPisano;
      break;
    }

    ++piPisano;
  }

  int ansFibMod = n % piPisano;

  return fibMods[ansFibMod];
}

int main() {
    uint64_t n;
    int m;
    cin >> n >> m;
    cout << FibHuge(n, m) << '\n';
}
