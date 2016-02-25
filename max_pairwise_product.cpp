#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers)
{
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (((long long)(numbers[i])) * numbers[j] > result) {
        result = ((long long)(numbers[i])) * numbers[j];
      }
    }
  }
  return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers)
{
  int n = numbers.size();

  int maxIdx1 = -1;
  for (int i = 0; i < n; ++i)
    if ((maxIdx1 == -1) || (numbers[i] > numbers[maxIdx1]))
      maxIdx1 = i;

  int maxIdx2 = -1;
  for (int j = 0; j < n; ++j)
    if ((j != maxIdx1) && ((maxIdx2 == -1) || (numbers[j] > numbers[maxIdx2])))
      maxIdx2 = j;

  return ((long long)(numbers[maxIdx1])) * numbers[maxIdx2];
}

void TestMaxPairwiseStress()
{
  while (true) {
    int n = rand() % 5 + 2;
    cout << n << "\n";
    vector<int> a;
    for (int i = 0; i < n; ++i) {
      a.push_back(rand() % 10);
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << "\n";
    long long res1 = MaxPairwiseProduct(a);
    long long res2 = MaxPairwiseProductFast(a);
    if (res1 != res2) {
      cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
      break;
    }
    else {
      cout << "OK\n";
    }
  }
}

int main()
{
  // TestMaxPairwiseStress();
  int n;
  cin >> n;
  vector<int> numbers(n);
  for (int i = 0; i < n; ++i) {
    cin >> numbers[i];
  }

  long long result = MaxPairwiseProductFast(numbers);
  cout << result << "\n";
  return 0;
}
