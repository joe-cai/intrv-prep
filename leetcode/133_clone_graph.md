#Clone Graph
##Iterative solution.
```C++
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> clone;
        UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
        clone[node] = root;

        queue<UndirectedGraphNode*> level;
        level.push(node);
        while (!level.empty()) {
            UndirectedGraphNode* old_node = level.front();
            level.pop();
            for (int i = 0; i < old_node->neighbors.size(); i++)
                if (clone.find(old_node->neighbors[i]) == clone.end()) {
                    UndirectedGraphNode* child = new UndirectedGraphNode(old_node->neighbors[i]->label);
                    clone[old_node]->neighbors.push_back(child);
                    clone[old_node->neighbors[i]] = child;
                    level.push(old_node->neighbors[i]);
                } else
                    clone[old_node]->neighbors.push_back(clone[old_node->neighbors[i]]);
        }
        return root;
    }
};
```

##Recursive solution
```C++
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> roster;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        if (roster.count(node) == 0) {
            UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
            roster[node] = new_node;
            for (int i = 0; i < node->neighbors.size(); i++)
                new_node->neighbors.push_back(cloneGraph(node->neighbors[i]));
            return new_node;
        } else
            return roster[node];
    }
};
```