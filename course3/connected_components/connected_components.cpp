#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int> > &adj, vector<bool> &visited, int i) {
    visited.at(i) = true;
    for (auto it = adj.at(i).begin(); it != adj.at(i).end(); ++it) {
      if (visited.at(*it) == false) {
          explore(adj, visited, *it);
      }
  }
}

int number_of_components(vector<vector<int> > &adj) {
  auto adjSz = adj.size();
  vector<bool> visited(adjSz);
  int cc = 0;
  for (auto i = 0; i < adjSz; ++i) {
      if (visited.at(i) == false) {
          explore(adj, visited, i);
          cc++;
      }
  }
  
  return cc;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
