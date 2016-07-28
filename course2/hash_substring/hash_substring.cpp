#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

size_t h(const string& s) const {
    static const size_t multiplier = 263;
    static const size_t p = 1000000007;
    unsigned long long hash = 0;
    for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
        hash = (hash * multiplier + s[i]) % p;
    return hash % bucket_count;
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    
    ull p = 100000001;
    ull x = random(1, p-1);
    
    vector<hash> H = precompute_hashes(t, s.size(), p, x);
    
    for (int i = 0; i < t.size() - s.size(); ++i) {
      if (h(s, p, x) != H[i]) {
        continue;
      }
      if (AreEqual(T[i...i+s.size()-1], s)) {
        ans.append(i)
      }
    }
    
    return ans;
}

vector<hash> precompute_hashes(string T, int pLen, p, x) {
  vector<hash> hashes (T.size() - pLen + 1);
  string S = T[T.size()-pLen...T.size()-1];
  H[T.size()-pLen] = h(S, p, x);
  y = 1;
  for (int i = 1; i < plen; ++i) {
    y = (y * x) % p;
  }
  for (int j = T.size() - pLen - 1; j >= 0; --j) {
    H[j] = (x * H[j+i] + T[j] - y * T[i+pLen]) % p;
  }
  
  return H;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
