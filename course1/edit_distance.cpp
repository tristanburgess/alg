#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::min;

int edit_distance(const string &str1, const string &str2) {
  int s1L = str1.length();
  int s2L = str2.length();
  vector< vector<int> > ed_dp(s1L + 1, vector<int>(s2L + 1));

  for (int i = 0; i <= s1L; ++i) {
    ed_dp[i][0] = i;
  }

  for (int j = 0; j <= s2L; ++j) {
    ed_dp[0][j] = j;
  }

  for (int j = 1; j <= s2L; ++j) {
    for (int i = 1; i <= s1L; ++i) {
      int insertion = ed_dp[i][j - 1] + 1;
      int deletion = ed_dp[i - 1][j] + 1;
      if (str1[i-1] == str2[j-1]) {
        int match = ed_dp[i - 1][j - 1];
        ed_dp[i][j] = min({insertion, deletion, match});
      } else {
        int mismatch = ed_dp[i - 1][j - 1] + 1;
        ed_dp[i][j] = min({insertion, deletion, mismatch});
      }

      //std::cout << ed_dp[i][j] << " ";
    }
    //std::cout << "\n";
  }

  return ed_dp[s1L][s2L];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
