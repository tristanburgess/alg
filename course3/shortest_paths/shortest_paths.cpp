#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::make_pair;

void shortest_paths(vector<vector<pair<int, int> > > &adj, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  queue<int> q;
  vector<int> visited(adj.size(), 0);
  
  distance.at(s) = 0;
  
  for (auto i = 0; i < adj.size(); ++i) {
    for (auto u = 0; u < adj.size(); ++u) {
      for (auto edge : adj.at(u)) {
        int v = edge.first;
        int w = edge.second;
        if (distance.at(u) != std::numeric_limits<long long>::max() && distance.at(v) > distance.at(u) + w) {
          distance.at(v) = distance.at(u) + w;
        } 
      }
    }
  }
  
  for (auto u = 0; u < adj.size(); ++u) {
    if (distance.at(u) == std::numeric_limits<long long>::max()) {
      reachable.at(u) = 0;
      continue;
    }
    
    for (auto edge : adj.at(u)) {
      int v = edge.first;
      int w = edge.second;
      
      if (distance.at(u) != std::numeric_limits<long long>::max() && distance.at(v) > distance.at(u) + w) {
        q.push(v);
      }
    }
  }
  
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    shortest.at(cur) = 0;
    
    for (auto edge : adj.at(cur)) {
      int v = edge.first;
      if (!visited.at(v)) {
        q.push(v);
        visited.at(v) = 1;
      }
    }
  }
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<pair<int,int> > > adj(n, vector<pair<int,int> >());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(make_pair(y - 1, w));
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 1);
  vector<int> shortest(n, 1);
  shortest_paths(adj, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
