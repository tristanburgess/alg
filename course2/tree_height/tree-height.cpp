#pragma comment(linker, "/STACK:5000000")

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

   // This function fills depth of i'th element in parent[].  The depth is
    // filled in depth[i].
    void fillDepth(int i)
    {
        if (depth[i] > 0)
            return;
     
        // If node at index i is root
        if (parent[i] == -1 || parent[i] == i)
        {
            depth[i] = 1;
            return;
        }
     
        // If depth of parent is not evaluated before, then evaluate
        // depth of parent first
        if (depth[parent[i]] == 0)
            fillDepth(parent[i]);
     
        // Depth of this node is depth of parent plus 1
        depth[i] = depth[parent[i]] + 1;
    }
 
    // This function returns height of binary tree represented by
    // parent array
    int compute_height()
    {
        // Create an array to store depth of all nodes/ and
        // initialize depth of every node as 0 (an invalid
        // value). Depth of root is 1
        for (int i = 0; i < n; i++)
            depth[i] = 0;
     
        // fill depth of all nodes
        for (int i = 0; i < n; i++)
            fillDepth(i);
     
        // The height of binary tree is maximum of all depths.
        // Find the maximum value in depth[] and assign it to ht.
        int ht = depth[0];
        for (int i=1; i<n; i++)
            if (ht < depth[i])
                ht = depth[i];
        return ht;
    }
};

int main() {
  ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  cout << tree.compute_height() << endl;
}
