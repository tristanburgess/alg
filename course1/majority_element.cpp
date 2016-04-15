#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::cin;
using std::cout;

int get_majority_element(vector<int> &a, int left, int right) {
  map<int, int> elemToCount;
  for (int i = left; i < right; ++i) {
    elemToCount[a[i]]++;
  }

  for (auto& x: elemToCount) {
    if (x.second > a.size()/2) {
      return x.first;
    }
  }

  return -1;
}

void maj_stress() {
  int n = 50000;
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    a.push_back(rand() % 1000);
    cout << i+1 << ": " << a[i] << "\n";
  }
  cout << "ANSWER: " << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}

int main() {
  //maj_stress();
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
