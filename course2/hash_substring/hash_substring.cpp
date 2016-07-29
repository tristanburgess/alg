#include <iostream>
#include <string>
#include <vector>
#include <random>

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
    for (auto i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

ull ph(const string& s, const ull p, const ull x) {
    ull hash = 0;
    for (auto i = static_cast<int> (s.size()) - 1; i >= 0; --i)
        hash = (hash * x + s[i]) % p;
    return hash;
}

std::vector<ull> precompute_hashes(const string& t, const string& s, const ull p, const ull x) {
  std::vector<ull> hashes (t.size() - s.size() + 1);
  string sub = t.substr(t.size() - s.size(), t.size());
  hashes[t.size() - s.size()] = ph(sub, p, x);
  
  ull y = 1;
  for (auto i = 1; i <= s.size(); ++i) {
    y = (y * x) % p;
  }
  
  for (auto j = static_cast<int> (t.size() - s.size() - 1); j >= 0; --j) {
    hashes[j] = (((x * hashes[j + 1] + t[j]) - (y * t[j + s.size()] % p)) + p) % p;
  }
  
  return hashes;
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    static const ull p = 500007;
    std::default_random_engine gen;
    std::uniform_int_distribution<ull> dist(1, p - 1);
    static const ull x = dist(gen);
    std::vector<int> ans;
    ull pHash = ph(s, p, x);
    std::vector<ull> hashes = precompute_hashes(t, s, p, x);
    
    for (auto i = 0; i + s.size() <= t.size(); ++i) {
      if (pHash != hashes[i]) {
        continue;
      }
      if (t.substr(i, s.size()) == s) {
        ans.push_back(i);
      }
    }
    
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}