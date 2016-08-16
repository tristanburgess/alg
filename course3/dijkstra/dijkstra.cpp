#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::queue;
using std::pair;
using std::make_pair;
using std::priority_queue;

struct dijkCompare {
  bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second > p2.second;
  }
};

int distance(vector<vector<pair<int, int> > > &adj, int s, int t) {
  vector<int> dist(adj.size(), INT_MAX);
  dist.at(s) = 0;
  
  priority_queue<pair<int, int>, vector<pair<int, int > >, dijkCompare > pq;
  pq.push(make_pair(s, 0));
  
  while (!pq.empty()) {
    int cur = pq.top().first;
    if (cur == t) { return dist.at(t); }
    pq.pop();
    
    for (auto edge : adj.at(cur)) {
      int v = edge.first;
      int w = edge.second;
      
      if (dist.at(v) > dist.at(cur) + w) {
        dist.at(v) = dist.at(cur) + w;
        pq.push(make_pair(v, dist.at(v)));
      } 
    }
  }
  
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<pair<int, int> > > adj(n, vector<pair<int, int> >());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(make_pair(y - 1, w));
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
