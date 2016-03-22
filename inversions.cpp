#include <iostream>
#include <vector>

using std::vector;

long long merge_and_count(vector<int> &a, vector<int> &tmp, size_t left, size_t mid, size_t right)
{
  int i, j, k;
  long long inv_count = 0;

  i = left; // left subarr index
  j = mid; // right subarr index
  k = left; // tmp subarr index

  while ((i < mid) && (j <= right))
  {
    if (a[i] <= a[j])
    {
      tmp[k++] = a[i++];
    }
    else
    {
      tmp[k++] = a[j++];

      // a[i] > a[j] indicates one inversion, but each subarr is already sorted with respect to itself.
      // Thus, a[i+n] > a[i] > a[j] => mid - i inversions.
      inv_count += (mid - i);
    }
  }

  // Copy remaining left subarr elems to end of temp arr
  while (i < mid) {
    tmp[k++] = a[i++];
  }

  // Copy remaining right subarr elems to end of temp arr
  while (j <= right) {
    tmp[k++] = a[j++];
  }

  // rewrite final arr with temp (merge sorted) arr
  for (i = left; i <= right; i++) {
    a[i] = tmp[i];
  }

  return inv_count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left) return number_of_inversions;
  size_t mid = (right + left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, mid);
  number_of_inversions += get_number_of_inversions(a, b, mid+1, right);
  number_of_inversions += merge_and_count(a, b, left, mid+1, right);
  return number_of_inversions;
}

long long naive_get_number_of_inversions(vector<int> &a, int n)
{
  int i, j;
  long long inv_count = 0;

  for(i = 0; i < n; i++) {
    for(j = i+1; j < n; j++) {
      if(a[i] > a[j]) {
        inv_count++;
      }
    }
 }
 return inv_count;
}

void inversions_stress() {
  while (true) {
    int n = 50000;
    vector<int> a;
    vector<int> c;

    for (int i = 0; i < n; ++i) {
      int test = rand() % 1000000000;
      a.push_back(test);
      c.push_back(test);
    }

    vector<int> b(a.size());

    long long x = get_number_of_inversions(a, b, 0, n - 1);
    long long y = naive_get_number_of_inversions(c, n);

    bool success = true;
    for (int i = 0; i < n; i++) {
      if (x != y) {
        std::cout << "Wrong answer result: " << x << ' ' << y << "\n";
        std::cout << "\n";
        std::cout << "Original array: ";
        for (int i = 0; i < n; ++i) {
          std::cout << a[i] << " ";
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
  //inversions_stress();

  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
