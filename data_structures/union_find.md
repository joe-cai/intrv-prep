#Union-Find
##Basic Interface
API | union | find
--- | ----- | ----
Time | ~O(1) (log*n) | ~O(1) (log*n)

##Under the hook
The meat of the union-find data structure is in the implementation of the private method `root`. This is the most basic and critical method that determines the time complexity of the operations that union-find supports.
Two tricks are used to drastically speed up `root`:
- Weighted Union
- Path Compression

##Implementation
```C++
#include <algorithm>
#include <vector>

class union_find {
private:
  std::vector<int> root;
  std::vector<int> set_size;
  int find_root(int id);
public:
  union_find(int size);
  void unions(int id_a, int id_b);
  bool find(int id_a, int id_b);
};

int union_find::find_root(int id) {
  while (root[id] != id) {
    /** path compression **/
    root[id] = root[root[id]];
    id = root[id];
  }
  return id;
}

union_find::union_find(int size) {
  set_size = std::vector<int>(size, 1);
  root = std::vector<int>(size, 0);
  for (int i = 0; i < size; i++) root[i] = i;
}
void union_find::unions(int id_a, int id_b) {
  int root_a = find_root(id_a);
  int root_b = find_root(id_b);
  /** weigthed union **/
  if (set_size[root_a] > set_size[root_b])
    std::swap(root_a, root_b);
  root[root_a] = root_b;
  set_size[root_b] += set_size[root_a];
}
bool union_find::find(int id_a, int id_b) {
  return find_root(id_a) == find_root(id_b);
}
```

##Applications
- dynamic connectivity problems
- image processing (segmentation)
- tarjan's lowest common ancestor algorithm
- kruskal's algorithm
