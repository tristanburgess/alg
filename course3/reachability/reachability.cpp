#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void reach(vector<vector<int> > &adj, vector<bool> &visited, int x) {
  visited.at(x) = true;
  for (auto it = adj.at(x).begin(); it != adj.at(x).end(); ++it) {
      if (visited.at(*it) == false) {
          reach(adj, visited, *it);
      }
  }
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<bool> visited(n+1);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  reach(adj, visited, x - 1);
  std::cout << visited.at(y-1);
}
