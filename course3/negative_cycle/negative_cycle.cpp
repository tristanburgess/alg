#include <iostream>
#include <vector>
#include <climits>

using std::vector;

int negative_cycle(vector<vector<int> > &adj) {
  vector<int> dist(adj.size(), 0);

  for (auto i = 0; i < adj.size(); ++i) {
    for (auto u = 0; u < adj.size(); ++u) {
      for (auto v = 0; v < adj.at(u).size(); ++v) {
        int w = adj.at(u).at(v);
        if (adj[u][v] != 0 && dist.at(v) > dist.at(u) + w) {
          dist.at(v) = dist.at(u) + w;
        } 
      }
    }
  }
  
  for (auto u = 0; u < adj.size(); ++u) {
    for (auto v = 0; v < adj.at(u).size(); ++v) {
      int w = adj.at(u).at(v);
      if (adj[u][v] != 0 && dist.at(v) > dist.at(u) + w) {
        return 1;
      } 
    }
  }

  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>(n));
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1][y-1] = w;
  }
  std::cout << negative_cycle(adj);
}
