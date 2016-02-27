#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

struct KnapsackItem {
  int value, weight;
  double vPerW;
};

bool srtCompare(KnapsackItem i, KnapsackItem j) {
  return (i.vPerW > j.vPerW);
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int N = weights.size();
  vector<KnapsackItem> KnapsackItems(N);

  for (int i = 0; i < N; ++i) {
      KnapsackItems[i].value = values[i];
      KnapsackItems[i].weight = weights[i];
      KnapsackItems[i].vPerW = (double)KnapsackItems[i].value / (double)KnapsackItems[i].weight;
  }

  sort(KnapsackItems.begin(), KnapsackItems.end(), srtCompare);

  for (int i = 0; i < N; ++i) {
    if (capacity == 0) {
      return value;
    }

    int a = min(KnapsackItems[i].weight, capacity);
    KnapsackItems[i].weight -= a;
    capacity -= a;
    value += a * KnapsackItems[i].vPerW;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
