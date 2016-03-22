#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1;
  while (left <= right) {
    int mid = (right + left) / 2;

    if (x == a[mid]) {
      return mid;
    } else if (x > a[mid]) {
      left = mid + 1;
    } else if (x < a[mid]) {
      right = mid - 1;
    }
  }

  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

bool stressTestSrtCmp(int i, int j) { return (i < j); }

void bsearch_stress() {
  while (true) {
    int n = 1000;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
      a.push_back(rand() % 1000);
    }
    for (int i = 0; i < n; ++i) {
      int res1 = linear_search(a, a[i]);
      sort(a.begin(), a.end(), stressTestSrtCmp);
      int res2 = binary_search(a, a[i]);
      if (a[res1] != a[res2]) {
        cout << "Wrong answer result: " << res1 << ' ' << res2 << "\n";
        cout << "Wrong answer array: ";
        for (int i = 0; i < n; ++i) {
          cout << a[i] << " ";
        }
        cout << "\n";
        break;
      }
      else {
        cout << "OK\n";
      }
    }
  }
}

int main() {
  // bsearch_stress();
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    cout << binary_search(a, b[i]) << ' ';
  }
}
