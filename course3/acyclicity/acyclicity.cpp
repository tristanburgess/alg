#include <iostream>
#include <vector>

using std::vector;

int dfs_cycle_detected(vector<vector<int> > &adj, vector<bool> &visited, vector<bool> &cycleDetect, int x) {
  if (!visited.at(x)) {
    visited.at(x) = true;
    cycleDetect.at(x) = true;
    
    for (auto it = adj.at(x).begin(); it != adj.at(x).end(); ++it) {
      // propagate result
      if (!visited.at(*it) && dfs_cycle_detected(adj, visited, cycleDetect, *it)) {
          return 1;
      } 
      // Repeated vertex (found cycle)
      else if (cycleDetect.at(*it)) {
        return 1;
      }
    }
  }
  
  // Cannot extend (found sink)
  cycleDetect.at(x) = false;
  return 0;
}

int acyclic(vector<vector<int> > &adj) {
  vector<bool> visited(adj.size());
  vector<bool> cycleDetect(adj.size());
  for (auto i = 0; i < adj.size(); ++i) {
    if (dfs_cycle_detected(adj, visited, cycleDetect, i)) {
      return 1;
    }
  }
  
  return 0;
}


int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
