#include <iostream>
#include <vector>

using cin;
using cout;
using vector;
using swap;

// Maintains the bounds of the <, =, and > partitions
struct pt_limits {
  int j;
  int k;
};

pt_limits partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  pt_limits m = {l, r};
  
  for (int i = l + 1; i <= m.k; i++) {
    if (a[i] < x) {
      // add element to < partition
      swap(a[i], a[m.j]);
      m.j++;
    } else if (a[i] > x) {
      // add element to > partition
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
  
  // Choose pivot
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  
  // Split into 3 partitions around the pivot (< > and =)
  pt_limits m = partition3(a, l, r);
  
  // Run quicksort on the < and > partitions
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
  
  // Choose pivot
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  
  // Break into 2 partitions around the pivot (<= and >)
  int m = partition2(a, l, r);
  
  // Run quicksort on the <= and > partitions
  randomized_quick_sort2(a, l, m - 1);
  randomized_quick_sort2(a, m + 1, r);
}

// Randomized stress test that validates integrity of improved solution for
// performing QuickSort with 3 partitions against a reference solution for 
// QuickSort with 2 partitions.
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
        cout << "Original array: ";
        for (int i = 0; i < n; ++i) {
          cout << a[i] << " ";
        }
        cout << "\n";

        cout << "Wrong answer result: " << a[i] << ' ' << b[i] << "\n";
        cout << "Wrong answer array: ";
        for (int i = 0; i < n; ++i) {
          cout << a[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; ++i) {
          cout << b[i] << " ";
        }
        cout << "\n";
        success = false;
        break;
      }
    }

    if (success) {
      cout << "OK!\n";
    }
  }
}

int main() {
  //qs_stress();

  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  randomized_quick_sort3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }

}
