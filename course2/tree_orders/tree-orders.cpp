#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void traverse_in_order(vector<int>* result, int x) {
    if (x == -1) return;
      
    traverse_in_order(result, left[x]);
    result->push_back(key[x]);
    traverse_in_order(result, right[x]);
  }
  
  void traverse_pre_order(vector<int>* result, int x) {
    if (x == -1) return;
      
    result->push_back(key[x]);
    traverse_pre_order(result, left[x]);
    traverse_pre_order(result, right[x]);
  }
  
  void traverse_post_order(vector<int>* result, int x) {
    if (x == -1) return;
      
    traverse_post_order(result, left[x]);
    traverse_post_order(result, right[x]);
    result->push_back(key[x]);
  }

  vector <int> in_order() {
    vector<int> result;
    traverse_in_order(&result, 0);
    return result;
  }

  vector <int> pre_order() {
    vector<int> result;    
    traverse_pre_order(&result, 0);
    return result;
  }

  vector <int> post_order() {
    vector<int> result;  
    traverse_post_order(&result, 0);
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}
