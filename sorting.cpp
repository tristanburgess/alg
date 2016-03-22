#include <iostream>
#include <vector>

using std::vector;
using std::swap;

struct pt_limits {
  int j;
  int k;
};

pt_limits partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  pt_limits m = {l, r};

  for (int i = l + 1; i <= m.k; i++) {
    if (a[i] < x) {
      swap(a[i], a[m.j]);
      m.j++;
    } else if (a[i] > x) {
      swap(a[i], a[m.k]);
      m.k--;
      i--;
    }
  }

  return m;
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pt_limits m = partition3(a, l, r);

  randomized_quick_sort3(a, l, m.j - 1);
  randomized_quick_sort3(a, m.k + 1, r);
}

int partition1(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 0; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);

  return j;
}

void randomized_quick_sort2(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort2(a, l, m - 1);
  randomized_quick_sort2(a, m + 1, r);
}

void qs_stress()
{
  while (true) {
    int n = 100000;
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < n; ++i) {
      int test = rand() % 1000000000;
      a.push_back(test);
      b.push_back(test);
    }

    randomized_quick_sort2(a, 0, a.size() - 1);
    randomized_quick_sort3(b, 0, b.size() - 1);

    bool success = true;

    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        std::cout << "Original array: ";
        for (int i = 0; i < n; ++i) {
          std::cout << a[i] << " ";
        }
        std::cout << "\n";

        std::cout << "Wrong answer result: " << a[i] << ' ' << b[i] << "\n";
        std::cout << "Wrong answer array: ";
        for (int i = 0; i < n; ++i) {
          std::cout << a[i] << " ";
        }
        std::cout << "\n";
        for (int i = 0; i < n; ++i) {
          std::cout << b[i] << " ";
        }
        std::cout << "\n";
        success = false;
        break;
      }
    }

    if (success) {
      std::cout << "OK!\n";
    }
  }
}

int main() {
  //qs_stress();

  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }

}
