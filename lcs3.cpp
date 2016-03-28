#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  int aL = a.size();
  int bL = b.size();
  int cL = c.size();
  vector< vector< vector<int> > > lcs_dp(cL+1, vector< vector<int> >(bL+1, vector <int>(aL+1)));

  for (int i = 0; i <= aL; ++i) {
    lcs_dp[0][0][i] = 0;
  }

  for (int j = 0; j <= bL; ++j) {
    lcs_dp[0][j][0] = 0;
  }

  for (int k = 0; k <= cL; ++k) {
    lcs_dp[k][0][0] = 0;
  }

  for (int i = 1; i <= cL; ++i) {
    for (int j = 1; j <= bL; ++j) {
      for (int k = 1; k <= aL; ++k) {
        int first = lcs_dp[i-1][j-1][k-1];
        int second = lcs_dp[i-1][j-1][k];
        int third = lcs_dp[i-1][j][k-1];
        int fourth = lcs_dp[i-1][j][k];
        int fifth = lcs_dp[i][j-1][k-1];
        int sixth = lcs_dp[i][j-1][k];
        int seventh = lcs_dp[i][j][k-1];
        if (c[i-1] == b[j-1] && c[i-1] == a[k-1] && b[j-1] == a[k-1]) {
           lcs_dp[i][j][k] = std::max({first + 1, second, third, fourth, fifth, sixth, seventh});
         } else {
           lcs_dp[i][j][k] = std::max({first, second, third, fourth, fifth, sixth, seventh});
         }
      }
    }
  }

 return lcs_dp[c.size()][b.size()][a.size()];
}


int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
