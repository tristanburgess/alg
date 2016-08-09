#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::find;

void explore(vector<vector<int> > &adj, vector<int> &visited, int x) {
  visited.at(x) = true;
  
  for (auto it = adj.at(x).begin(); it != adj.at(x).end(); ++it) {
    if (!visited.at(*it)) {
      explore(adj, visited, *it);
    } 
  }
}

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

vector<vector<int> > transpose(vector<vector<int> > adj) {
  vector<vector<int> > adjR(adj.size(), vector<int>());
  
  for (auto i = 0; i < adj.size(); ++i) {
    for (auto j = 0; j < adj.at(i).size(); ++j) {
      adjR.at(adj.at(i).at(j)).push_back(i);
    }
  }
  
  return adjR;
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  vector<int> visited(adj.size(), 0);
  vector<int> order;

  vector<vector<int> > adjR = transpose(adj);

  dfs(adjR, visited, order);
  reverse(order.begin(), order.end());
  
  
  while (!order.empty()) {
    visited.clear();
    visited.resize(adj.size(), 0);
    explore(adj, visited, order.at(0));
    
    for (auto i = 0; i < visited.size(); ++i) {
      if (visited.at(i)) {
        auto fnd = find(order.begin(), order.end(), i);
        if (fnd != order.end()) {
          order.erase(fnd);
        }
      }
    }
    
    result++;
  }
  
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
