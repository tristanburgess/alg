#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool srtCompare (int i, int j) { return (i < j); }

int LargestNumber(vector<int> numbers)
{
  sort(numbers.begin(), numbers.end(), srtCompare);

  int i = 0;
  int ans = 0;
  for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    ans += *it * pow(10, i);
    ++i;
  }

  return ans;
}

int main()
{
  vector<int> in;
  int x;
  while (cin >> x) {
    in.push_back(x);
  }

  cout << LargestNumber(in);
}
