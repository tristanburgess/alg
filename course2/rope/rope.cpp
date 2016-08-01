#include <cstdio>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

struct Vertex
{
  char key;
  long long sizeFrom;
  Vertex* left;
  Vertex* right;
  Vertex* parent;

  Vertex(char key, long long sizeFrom, Vertex* left, Vertex* right, Vertex* parent) :
      key(key), sizeFrom(sizeFrom), left(left), right(right), parent(parent)
  {
  }
};

class Rope
{
  string s;
  Vertex* root;
  public:
  Rope(const string &s) :
      s(s)
  {
    root = NULL;
    for (int w = 0; w < s.length(); w++)
    {
      Vertex* next = new Vertex(s[w], 1ll, NULL, NULL, NULL);
      root = merge(root, next);
    }
  }

  ~Rope()
  {
    free(root);
  }

  void free(Vertex* root)
  {
    if (root != NULL) {
      if (root->left != NULL) {
        free(root->left);
      } 
      if (root->right != NULL) {
        free(root->right);
      }
      delete root;
    }
  }
  
  void update(Vertex* v)
  {
    if (v == NULL)
      return;
    v->sizeFrom = 1 + (v->left != NULL ? v->left->sizeFrom : 0ll) +
                      (v->right != NULL ? v->right->sizeFrom : 0ll);
    if (v->left != NULL) {
      v->left->parent = v;
    }
    if (v->right != NULL) {
      v->right->parent = v;
    }
  }

  void small_rotation(Vertex* v)
  {
    Vertex* parent = v->parent;
    if (parent == NULL) {
      return;
    }
    Vertex* grandparent = v->parent->parent;
    if (parent->left == v) {
      Vertex* m = v->right;
      v->right = parent;
      parent->left = m;
    } else {
      Vertex* m = v->left;
      v->left = parent;
      parent->right = m;
    }
    update(parent);
    update(v);
    v->parent = grandparent;
    if (grandparent != NULL) {
      if (grandparent->left == parent) {
        grandparent->left = v;
      } else {
        grandparent->right = v;
      }
    }
  }

  void big_rotation(Vertex* v)
  {
    if (v->parent->left == v && v->parent->parent->left == v->parent) {
      // Zig-zig
      small_rotation(v->parent);
      small_rotation(v);
    } else if (v->parent->right == v && v->parent->parent->right == v->parent) {
      // Zig-zig
      small_rotation(v->parent);
      small_rotation(v);
    } else {
      // Zig-zag
      small_rotation(v);
      small_rotation(v);
    }
  }

  // Makes splay of the given vertex and makes
  // it the new root.
  void splay(Vertex*& root, Vertex* v)
  {
    if (v == NULL)
      return;
    while (v->parent != NULL) {
      if (v->parent->parent == NULL) {
        small_rotation(v);
        break;
      }
      big_rotation(v);
    }
    root = v;
  }

  // Searches for the node which has n number of nodes
  // in the left side (including itself) in the tree with the given root
  // and calls splay for the deepest visited node after that.
  // If found, returns a pointer to that node
  // Otherwise (only in case n is bigger than the total
  // number of the nodes in the tree), returns NULL
  Vertex* find(Vertex*& root, int n)
  {
    Vertex* v = root;

    while(v != NULL) {
      long long s = (v->left != NULL) ? v->left->sizeFrom : 0ll;
      if (n == (s + 1)) {
        break;
      } else if (n < (s + 1)) {
        v = v->left;
      } else if (n > (s + 1)) {
        v = v->right;
        n = n - s - 1;
      }
    }
    splay(root, v);
    return v;
  }

  void split(Vertex* root, int key, Vertex*& left, Vertex*& right)
  {
    right = find(root, key);
    splay(root, right);
    if (right == NULL) {
      left = root;
      return;
    }
    left = right->left;
    right->left = NULL;
    if (left != NULL) {
      left->parent = NULL;
    }
    update(left);
    update(right);
  }

  Vertex* merge(Vertex* left, Vertex* right)
  {
    if (left == NULL)
      return right;
    if (right == NULL)
      return left;
    Vertex* min_right = right;
    while (min_right->left != NULL) {
      min_right = min_right->left;
    }
    splay(right, min_right);
    right->left = left;
    update(right);
    return right;
  }

  void rope_insert(Vertex*& root, int k, Vertex*& sub)
  {
    Vertex* vl = NULL;
    Vertex* vr = NULL;
    split(root, k, vl, vr);
    root = merge(merge(vl, sub), vr);
  }

  string traverse_in_order(Vertex* r) {
    string out = "";
    if (r == NULL) return out;
    
    stack<Vertex*> s;
    Vertex* p = root;
    
    while (p != NULL) {
      s.push(p);
      p = p->left;
    }

    while (!s.empty()) {
      p = s.top();
      out.push_back(p->key);
      s.pop();
      p = p->right;
      
      while (p != NULL) {
        s.push(p);
        p = p->left;
      }
    }
    
    return out;
  }

  void process(int i, int j, int k)
  {
    Vertex* vl = NULL;
    Vertex* vr = NULL;
    Vertex* vm = NULL;
    split(root, i + 1, vl, vm);
    split(vm, j - i + 2, vm, vr);
    root = merge(vl, vr);
    rope_insert(root, k + 1, vm);
  }

  std::string result()
  {
    s.clear();
    s = traverse_in_order(root);
    return s;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  Rope rope(s);
  int actions;
  cin >> actions;
  for (int action_index = 0; action_index < actions; ++action_index)
  {
    int i, j, k;
    cin >> i >> j >> k;
    rope.process(i, j, k);
  }
  cout << rope.result() << endl;

  return 0;
}