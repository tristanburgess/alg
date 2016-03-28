#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

long long evalsd(long long a, char op, long long b) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  vector<int> vals;
  vector<char> ops;

  int expL = exp.length();
  for (int i = 0; i < expL; ++i) {
    if (i % 2 == 0) {
      vals.push_back(exp[i] - '0');
    } else {
      ops.push_back(exp[i]);
    }
  }

  int N = vals.size();
  vector< vector<long long> > m(N+1, vector<long long>(N+1));
  vector< vector<long long> > M(N+1, vector<long long>(N+1));

  for (int i = 1; i <= N; ++i) {
    m[i][i] = vals[i-1];
    M[i][i] = vals[i-1];
  }

  for (int s = 1; s <= N-1; ++s) {
    for (int i = 1; i <= N-s; ++i) {
      int j = i + s;

      long long min = std::numeric_limits<long long>::max();
      long long max = std::numeric_limits<long long>::lowest();

      for (int k = i; k <= j - 1; ++k) {
        long long a = evalsd(M[i][k], ops[k-1], M[k+1][j]);
        long long b = evalsd(M[i][k], ops[k-1], m[k+1][j]);
        long long c = evalsd(m[i][k], ops[k-1], M[k+1][j]);
        long long d = evalsd(m[i][k], ops[k-1], m[k+1][j]);

        min = std::min({min, a, b, c, d});
        max = std::max({max, a, b, c, d});

        //std::cout << "TEST: " << min << " " << max << " " << a  << " " << b << " " << c << " " << d;
      }
      std::cout<< "\n";
      m[i][j] = min;
      M[i][j] = max;
    }
  }

  return M[1][N];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
