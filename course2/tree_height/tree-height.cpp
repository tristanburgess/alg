#pragma comment(linker, "/STACK:50000000")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TreeHeight {
  int n;             
  vector<int> parent;
  vector<int> depth;

public:
  void read() {
    cin >> n;
    parent.resize(n);
    depth.resize(n);
    for (int i = 0; i < n; i++)
      cin >> parent[i];
  }

    void depth_at_node(int i)
    {
        // Avoid depth recomputation
        if (depth[i] > 0) {
            return;
        }
     
        // Recurse until we get the depth of the branch up
        // to the current node
        if (depth[parent[i]] == 0) {
            depth_at_node(parent[i]);
        }
     
        // Add on the depth at the level of the current node
        depth[i] = depth[parent[i]] + 1;
    }
 
    int compute_height()
    {
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1 || parent[i] == i) {
                depth[i] = 1;
            } else {
                depth[i] = 0;
            }
        }
     
        for (int i = 0; i < n; i++) {
            depth_at_node(i);
        }
     
       return *max_element(depth.begin(), depth.end());
    }
};

int main() {
  ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  cout << tree.compute_height() << endl;
}