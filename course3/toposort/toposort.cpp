#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::reverse;

void explore(vector<vector<int> > &adj, vector<int> &visited, vector<int> &order, int x) {
  visited.at(x) = true;
  
  for (auto it = adj.at(x).begin(); it != adj.at(x).end(); ++it) {
    if (!visited.at(*it)) {
      explore(adj, visited, order, *it);
    } 
  }
  
  order.push_back(x);
}

void dfs(vector<vector<int> > &adj, vector<int> &visited, vector<int> &order) {
  for (auto i = 0; i < adj.size(); ++i) {
    if (!visited.at(i)) {
      explore(adj, visited, order, i);
    } 
  }
}

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> visited(adj.size(), 0);
  vector<int> order;
  dfs(adj, visited, order);
  reverse(order.begin(), order.end());
  return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
