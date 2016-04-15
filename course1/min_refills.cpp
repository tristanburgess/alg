#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MinRefills(vector<int> stations, int n, int L)
{
  int numRefills = 0;
  int currRefill = 0;
  while (currRefill < n) {
    int lastRefill = currRefill;

    while (currRefill < n && ((stations.at(currRefill+1) - stations.at(lastRefill)) <= L)) {
      ++currRefill;
    }

    if (currRefill == lastRefill) {
      return -1;
    }
    if (currRefill < n) {
      ++numRefills;
    }
  }

  return numRefills;
}

int main()
{
  vector<int> in;
  int x, L;
  cin >> L;
  while (cin >> x) {
    in.push_back(x);
  }

  cout << MinRefills(in, in.size()-1, L);
}
