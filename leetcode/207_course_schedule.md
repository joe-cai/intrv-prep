#Course Schedule
##BFS
```C++
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> precede(numCourses, unordered_set<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            if (prerequisites[i].first == prerequisites[i].second) return false;
            precede[prerequisites[i].second].insert(prerequisites[i].first);
        }
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
            for (auto it = precede[i].begin(); it != precede[i].end(); it++)
                indegree[*it]++;

        queue<int> zeroindeg;
        for (int i = 0; i < indegree.size(); i++)
            if (indegree[i] == 0) zeroindeg.push(i);
        while (!zeroindeg.empty()) {
            int course = zeroindeg.front();
            zeroindeg.pop();
            for (auto it = precede[course].begin(); it != precede[course].end(); it++) {
                indegree[*it]--;
                if (indegree[*it] == 0) zeroindeg.push(*it);
            }
        }
        for (int i = 0; i < indegree.size(); i++)
            if (indegree[i] != 0) return false;
        return true;
    }
};
```

##DFS
```C++
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> precede(numCourses, unordered_set<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            // if (prerequisites[i].first == prerequisites[i].second) return false;
            precede[prerequisites[i].second].insert(prerequisites[i].first);
        }
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
            for (auto it = precede[i].begin(); it != precede[i].end(); it++)
                indegree[*it]++;
        
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && indegree[i] == 0) dfs(precede, indegree, visited, i);
        for (int i = 0; i < visited.size(); i++) if (!visited[i]) return false;
        return true;
    }
    void dfs(vector<unordered_set<int>>& precede, vector<int>& indegree, vector<bool>& visited, int start) {
        visited[start] = true;
        for (auto it = precede[start].begin(); it != precede[start].end(); it++)
            if (!visited[*it] && --indegree[*it] == 0)
                dfs(precede, indegree, visited, *it);
    }
};
```