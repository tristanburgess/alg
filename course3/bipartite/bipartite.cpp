#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bfs(vector<vector<int> > &adj, int s, int t) {
  queue<int> q;
  vector<int> distance(adj.size(), INT_MAX);
  int cur = s;
  q.push(cur);
  distance.at(cur) = 0;
  
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    if (cur == t) return distance.at(t);
    
    for (auto i : adj.at(cur)) {
      if (distance.at(i) == INT_MAX) {
        q.push(i);
        distance.at(i) = distance.at(cur) + 1;
      }
    }
    
  }
  
  return -1;
}

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
