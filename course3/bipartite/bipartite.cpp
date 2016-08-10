#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  queue<int> q;
  
  const int NONE = -1;
  const int WHITE = 0;
  const int BLACK = 1;
  
  vector<int> color(adj.size(), NONE);
  
  int cur = 0;
  q.push(cur);
  color.at(cur) = WHITE;
  
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    
    int currentColor = color.at(cur);
    
    for (auto i : adj.at(cur)) {
        if (color.at(i) == currentColor) return 0;
        if (color.at(i) == NONE) {
            q.push(i);
            if (currentColor == WHITE) {
                color.at(i) = BLACK;
            } else if (currentColor == BLACK) {
                color.at(i) = WHITE;
            }
        }
    }
    
  }
  
  return 1;
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
