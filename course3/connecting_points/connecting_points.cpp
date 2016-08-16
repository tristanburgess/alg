#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;

struct Edge {
  int src;
  int dest;
  double wt;
  
  Edge(int src, int dest, double wt): src(src), dest(dest), wt(wt) {}
  
  bool operator < (const Edge& e) const
  {
      return (wt < e.wt);
  }
};

struct Vertex {
  int x, y, parent, rank;
  
  Vertex(int x, int y, int parent = -1, int rank = 0): x(x), y(y), parent(parent), rank(rank) {}
};

struct DSGraph {
  vector<Vertex> vertices;
  vector<Edge> edges;
  
  void addVertex(int x, int y, int parent) {
    vertices.push_back({x, y, parent});
  }
  
  double calculateWt(int src, int dest) {
    Vertex s = vertices.at(src);
    Vertex d = vertices.at(dest);
    
    return sqrt(pow(s.x - d.x, 2) + pow(s.y - d.y, 2));
  }
  
  void addEdge(int src, int dest) {
    double wt = calculateWt(src, dest);
    edges.push_back({src, dest, wt});
  }
  
  void merge(int x, int y) {
    int xP = find(x);
    int yP = find(y);
    
    if (xP != yP) {
      if (vertices.at(xP).rank > vertices.at(yP).rank) {
        vertices.at(yP).parent = xP;
      } else {
        vertices.at(xP).parent = yP;
        if (vertices.at(xP).rank == vertices.at(yP).rank) {
          vertices.at(yP).rank++;
        }
      }
    }
  }
  
  int find(int x) {
    if (x != vertices.at(x).parent) {
      vertices.at(x).parent = find(vertices.at(x).parent);
    }
    
    return vertices.at(x).parent;
  }
  
  void printGraph() {
    std::cout << "\n\n";
    for (auto v : vertices) {
      std::cout << "V - " << v.x << ", " << v.y << ", " << v.parent << ", " << v.rank << "\n";
    }
    std::cout << "\n\n";
    for (auto edge : edges) {
      std::cout << "E - " << edge.src << ", " << edge.dest << ", " << edge.wt << "\n";
    }
    std::cout << "\n\n";
  }
};

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.0;
  int n = x.size();
  DSGraph g;
  
  for (int i = 0; i < n; ++i) {
    g.addVertex(x.at(i), y.at(i), i);
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        continue;
      }
      
      g.addEdge(i, j);
      
    }
  }
  
  sort(g.edges.begin(), g.edges.end());
  for (auto edge : g.edges) {
    if (g.find(edge.src) != g.find(edge.dest)) {
      result += edge.wt;
      g.merge(edge.src, edge.dest);
    }
  }
  
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
