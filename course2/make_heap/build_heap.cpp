#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  
  void SiftDown(int i) {
    int swapI = i;
    int childL = i*2+1;
    int childR = i*2+2;
    
    if (childL < data_.size() && data_[swapI] > data_[childL]) {
      swapI = childL;
    }
    
    if (childR < data_.size() && data_[swapI] > data_[childR]) {
      swapI = childR;
    }
    
    if (swapI != i) {
      swap(data_[i], data_[swapI]);
      swaps_.push_back(make_pair(i, swapI));
      SiftDown(swapI);
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    int n = (data_.size() / 2) - 1;
    for (int i = n; i >= 0; i--) {
      SiftDown(i);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
