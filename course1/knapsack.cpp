#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &items) {
  int N = items.size();
  vector< vector<int> > value(W+1, vector<int>(N+1));

  for (size_t i = 0; i < items.size(); ++i) {
    for (int j = 1; j <= W; ++j) {
      value[j][i+1] = value[j][i];

      if (items.at(i) <= j) {
        int val = value[j - items.at(i)][i] + items.at(i);
        //std::cout << "TEST BEFORE: " << " " << i << " " << j << " " << val << " " << value[j][i+1] << "\n";
        if (value[j][i+1] < val) {
          value[j][i+1] = val;
        }
        //std::cout << "TEST AFTER: " << " " << i << " " << j << " " << val << " " << value[j][i+1] << "\n";
      }
    }
  }

  return value[W-1][N-1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
